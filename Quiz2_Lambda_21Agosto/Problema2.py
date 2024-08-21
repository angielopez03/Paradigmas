palabras = ["perro", "gato", "elefante", "oso", "jirafa"]
palabras_largas = list(filter(lambda palabra: len(palabra) > 5, palabras))
print(palabras_largas)
