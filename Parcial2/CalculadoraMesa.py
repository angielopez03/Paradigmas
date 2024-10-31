from mesa import Agent, Model
from mesa.time import RandomActivation
import sympy

class Mensaje:
    def _init_(self, origen, destino, operacion=None, operandos=None, resultado=None):
        self.origen = origen
        self.destino = destino
        self.operacion = operacion
        self.operandos = operandos
        self.resultado = resultado

class AgenteOperacion(Agent):
    def _init_(self, unique_id, model):
        super()._init_(unique_id, model)
        self.inbox = []
        self.resultado = None

    def recibir_mensaje(self, mensaje):
        self.inbox.append(mensaje)

    def enviar_mensaje(self, destino, operacion=None, operandos=None, resultado=None):
        mensaje = Mensaje(self.unique_id, destino, operacion, operandos, resultado)
        self.model.enviar_mensaje(mensaje)

    def realizar_operacion(self, num1, num2):
        raise NotImplementedError("Debe implementarse en las clases hijas")

    def step(self):
        if self.inbox:
            mensaje = self.inbox.pop(0)
            if mensaje.operandos:
                resultado = self.realizar_operacion(*mensaje.operandos)
                self.enviar_mensaje(mensaje.origen, resultado=resultado)
            self.inbox.clear()

class AgenteSuma(AgenteOperacion):
    def realizar_operacion(self, num1, num2):
        return num1 + num2

class AgenteResta(AgenteOperacion):
    def realizar_operacion(self, num1, num2):
        return num1 - num2

class AgenteMultiplicacion(AgenteOperacion):
    def realizar_operacion(self, num1, num2):
        return num1 * num2

class AgenteDivision(AgenteOperacion):
    def realizar_operacion(self, num1, num2):
        if num2 == 0:
            raise ValueError("División por cero")
        return num1 / num2

class AgentePotencia(AgenteOperacion):
    def realizar_operacion(self, num1, num2):
        return num1 ** num2

class AgenteIO(Agent):
    def _init_(self, unique_id, model):
        super()._init_(unique_id, model)
        self.inbox = []
        self.expresion_actual = None
        self.tokens = []
        self.esperando_resultado = False

    def recibir_mensaje(self, mensaje):
        self.inbox.append(mensaje)

    def enviar_mensaje(self, mensaje):
        self.model.enviar_mensaje(mensaje)

    def tokenizar(self, expresion):
        tokens = []
        numero = ""
        
        for char in expresion:
            if char.isdigit() or char == '.':
                numero += char
            else:
                if numero:
                    tokens.append(('NUMERO', float(numero)))
                    numero = ""
                if char in '+-*/^()':
                    tokens.append(('OPERADOR', char))
        
        if numero:
            tokens.append(('NUMERO', float(numero)))
        
        return tokens

    def obtener_agente_operacion(self, operador):
        mapa_operadores = {
            '+': 'suma',
            '-': 'resta',
            '*': 'multiplicacion',
            '/': 'division',
            '^': 'potencia'
        }
        return mapa_operadores.get(operador)

    def procesar_expresion(self, expresion):
        try:
            # Validar la expresión usando sympy
            sympy.sympify(expresion)
            
            self.tokens = self.tokenizar(expresion)
            self.expresion_actual = expresion
            self.esperando_resultado = True
            
            # Convertir a postfija y procesar
            postfija = self.convertir_a_postfija()
            self.procesar_postfija(postfija)
            
        except Exception as e:
            print(f"Error al procesar la expresión: {str(e)}")
            self.esperando_resultado = False

    def convertir_a_postfija(self):
        precedencia = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3}
        asociatividad = {'+': 'L', '-': 'L', '*': 'L', '/': 'L', '^': 'R'}
        operadores = []
        salida = []
        
        for tipo, valor in self.tokens:
            if tipo == 'NUMERO':
                salida.append(('NUMERO', valor))
            elif tipo == 'OPERADOR':
                if valor == '(':
                    operadores.append(valor)
                elif valor == ')':
                    while operadores and operadores[-1] != '(':
                        salida.append(('OPERADOR', operadores.pop()))
                    operadores.pop()  # Eliminar el '('
                else:
                    while (operadores and operadores[-1] != '(' and
                           (precedencia[operadores[-1]] > precedencia[valor] or
                           (precedencia[operadores[-1]] == precedencia[valor] and asociatividad[valor] == 'L'))):
                        salida.append(('OPERADOR', operadores.pop()))
                    operadores.append(valor)
        
        while operadores:
            salida.append(('OPERADOR', operadores.pop()))
        
        return salida

    def procesar_postfija(self, tokens):
        pila = []
        for tipo, valor in tokens:
            if tipo == 'NUMERO':
                pila.append(valor)
            elif tipo == 'OPERADOR':
                if len(pila) >= 2:
                    num2 = pila.pop()
                    num1 = pila.pop()
                    agente_destino = self.obtener_agente_operacion(valor)
                    if agente_destino:
                        # Crear mensaje con la operación y esperar resultado antes de continuar
                        mensaje = Mensaje(self.unique_id, agente_destino, valor, (num1, num2))
                        self.enviar_mensaje(mensaje)
                        
                        # Esperar respuesta
                        while not self.inbox:
                            self.model.paso_simulacion()
                        
                        resultado_mensaje = self.inbox.pop(0)
                        # Añadir el resultado de la operación a la pila para la siguiente operación
                        pila.append(resultado_mensaje.resultado)
                    
        # El último valor en la pila será el resultado final
        if pila:
            resultado = pila.pop()
            print(f"\nResultado de {self.expresion_actual} = {resultado}")
            self.esperando_resultado = False


class CalculadoraAgentes(Model):
    def _init_(self):
        super()._init_()
        self.schedule = RandomActivation(self)
        
        # Crear agentes
        self.agentes = {
            'suma': AgenteSuma('suma', self),
            'resta': AgenteResta('resta', self),
            'multiplicacion': AgenteMultiplicacion('multiplicacion', self),
            'division': AgenteDivision('division', self),
            'potencia': AgentePotencia('potencia', self),
            'io': AgenteIO('io', self)
        }
        
        # Agregar agentes al scheduler
        for agente in self.agentes.values():
            self.schedule.add(agente)

    def enviar_mensaje(self, mensaje):
        agente_destino = self.agentes.get(mensaje.destino)
        if agente_destino:
            agente_destino.recibir_mensaje(mensaje)

    def paso_simulacion(self):
        self.schedule.step()

def main():
    calculadora = CalculadoraAgentes()
    
    while True:
        print("\nCalculadora de Agentes")
        print("Ingrese una expresión matemática (o 'salir' para terminar)")
        print("Operadores disponibles: +, -, *, /, ^ (potencia)")
        expresion = input(">> ").strip()
        
        if expresion.lower() == 'salir':
            break
            
        if expresion:
            calculadora.agentes['io'].procesar_expresion(expresion)
            # Ejecutar varios pasos para asegurar que todos los agentes procesen sus mensajes
            for _ in range(10):  # Número arbitrario de pasos para asegurar el procesamiento
                calculadora.paso_simulacion()

if __name__ == "_main_":
    main()
