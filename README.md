1. Bubble Sort:
    Compara elementos adyacentes y los intercambia si están en el orden incorrecto.
    Repite este proceso hasta que no se realicen más intercambios, lo que indica que el arreglo está ordenado.
    Tiene complejidad de tiempo O(n^2) en el peor caso.

2. Selection Sort:
    Encuentra el elemento mínimo del arreglo y lo coloca al inicio.
    Luego, encuentra el siguiente elemento mínimo desde el subarreglo restante y lo coloca en la segunda posición, y así sucesivamente.
    Tiene complejidad de tiempo O(n^2) en todos los casos.

3. Insertion Sort:
    Divide el arreglo en una parte ordenada y otra desordenada.
    En cada iteración, toma un elemento de la parte desordenada e lo inserta en la parte ordenada en su posición correcta.
    Tiene complejidad de tiempo O(n^2) en el peor caso, pero es eficiente para arreglos pequeños.

4. Merge Sort:
    Divide recursivamente el arreglo en mitades hasta que cada mitad contenga solo un elemento.
    Luego, combina recursivamente las mitades ordenadas para producir subarreglos ordenados más grandes hasta que se recombine todo el arreglo.
    Tiene complejidad de tiempo O(n log n) en todos los casos.

5. Quick Sort:
    Elige un elemento como pivote y coloca todos los elementos menores a su izquierda y los mayores a su derecha.
    Luego, aplica la misma operación recursivamente en las sublistas izquierda y derecha del pivote.
    Tiene complejidad de tiempo O(n^2) en el peor caso, pero en promedio es O(n log n).

6. Bucket Sort:
    Divide el rango de valores en un número finito de intervalos (buckets).
    Luego, distribuye los elementos a ordenar en los buckets.
    Finalmente, ordena cada bucket individualmente y luego concatena los buckets en orden.
    Tiene complejidad de tiempo O(n+k), donde k es el número de buckets.

7. Shell Sort:
    Es una mejora del insertion sort donde los elementos distantes entre sí se comparan y se intercambian.
    Utiliza un intervalo (gap) que se va reduciendo en cada iteración hasta ser 1, donde se aplica el insertion sort estándar.
    Tiene complejidad de tiempo O(n log n) en el mejor caso y O(n^2) en el peor caso.

8. Counting Sort:
    Cuenta el número de elementos que tienen valores distintos y determina su posición en el arreglo ordenado.
    Luego, realiza un escaneo para determinar las posiciones finales de cada elemento basándose en la frecuencia acumulada de elementos menores.
    Tiene complejidad de tiempo O(n + k), donde k es el rango de valores del arreglo.
