import java.util.concurrent.ForkJoinPool
import java.util.concurrent.RecursiveTask
import kotlin.system.measureTimeMillis

// Función que calcula la suma de manera secuencial
fun sumarLista(numeros: List<Int>): Int {
    var suma = 0
    for (numero in numeros) {
        suma += numero
    }
    return suma
}

// Función paralela usando ForkJoinPool
class SumTask(private val numbers: List<Int>) : RecursiveTask<Int>() {
    override fun compute(): Int {
        return if (numbers.size <= 10_000) {
            numbers.sum()
        } else {
            val midpoint = numbers.size / 2
            val left = SumTask(numbers.subList(0, midpoint))
            val right = SumTask(numbers.subList(midpoint, numbers.size))
            left.fork()
            right.compute() + left.join()
        }
    }
}

fun sumarListaParaleloForkJoin(numeros: List<Int>): Int {
    val pool = ForkJoinPool.commonPool()
    return pool.invoke(SumTask(numeros))
}

fun main() {
    val numeros = List(100_000_000) { (1..10).random() }

    // Tiempo de ejecución para la versión secuencial
    val tiempoOriginal = measureTimeMillis {
        println("Suma total (original): ${sumarLista(numeros)}")
    }
    println("Tiempo original: ${tiempoOriginal}ms")

    // Tiempo de ejecución para la versión paralela con ForkJoinPool
    val tiempoParaleloForkJoin = measureTimeMillis {
        println("Suma total (paralelo con ForkJoin): ${sumarListaParaleloForkJoin(numeros)}")
    }
    println("Tiempo paralelo con ForkJoin: ${tiempoParaleloForkJoin}ms")
}
