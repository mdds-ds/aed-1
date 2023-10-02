% Contesten aquí la pregunta sobre complejidad.

En el caso de la función jugarPlus, como la complejidad era del orden O(h^n),
con n siendo el tamaño del tablero, si la estructura jugadas fuera una matriz conteniendo
en cada posición la cantidad de minas adyacentes (o -1 si la casilla no fue jugada), 
como la cantidad de elementos que contendrá jugadas será igual a las filas del tablero,
y a su vez cada fila del tablero tendrá la cantidad de columnas del tablero, tendremos
columnas*filas = n elementos en jugadas. Recordando que h = g+m con m el tamaño de jugadas,
quedará una complejidad de peor caso del orden O((g+n)^n), pero el tamaño de jugadas se mantendrá
constante y por lo tanto la complejidad es más estable.

En el caso de la función sugerirAutomatico121, si la estructura jugadas fuera una matriz conteniendo
en cada posición la cantidad de minas adyacentes (o -1 si la casilla no fue jugada), el tamaño de 
la estructura jugadas sería igual a columnas*filas, es decir, el tamaño del tablero, y queda
de este tamaño de forma constante, no se agregan jugadas. 
Por lo tanto, por la forma en que está armada nuestra función sugerirAutomatico121 
la complejidad de peor caso O((g+m)*n^2), con g = b.size(), m = j.size() y n = t.size()
pasaría a ser del orden O((g+n)*n^2) puesto que ahora tendremos n = m, pero el tamaño de
jugadas se mantendrá constante y por lo tanto la complejidad es más estable.