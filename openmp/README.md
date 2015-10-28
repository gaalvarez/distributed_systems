## OpenMP una librería para programación en paralelo

En este repositorio encontrará dos ejemplos sobre OpenMP para el cálculo del número pi usando dos enfoques diferentes.

# Cálculo del número Pi

Ud. encontrará dos programas en C que sirven para calcular el valor de Pi.

* `pi.c` usa una aproximación a través del cálculo del área bajo la curva. La [gráfica](https://drive.google.com/open?id=0B7n65I8SStKXZXRZdnRxMlV2V00) muestra la aproximación que sigue el programa `.c`.
Este es un programa secuencial que con la directiva "**#pragma omp parallel for shared(step) private(x) reduction(+:sum)**" se convierte en un programa paralelo. Observe que se ha usado una reducción para la operación de suma (+) de la variable sum.

* `montecarlopi.c` usa una aproximación basada en el método Monte Carlo para de forma aleatoria se llegue a la estimación del valor de Pi.
Este es un programa secuencial que con la directiva "**#pragma omp parallel for private(i, x, y, test) reduction(+:Ncirc)" se convierte en un programa paralelo. Observe que se ha usado una reducción para la operación de conteo (+) de la variable Ncirc y las demás variables operadas dentro del ciclo son privadas dado que se trata de un cálculo sobre valores aleatorios.
