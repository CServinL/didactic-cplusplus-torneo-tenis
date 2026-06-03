# Ejercicio Torneo de Tenis en C++

[![Sponsor](https://img.shields.io/badge/Sponsor-CServinL-ea4aaa?logo=github)](https://github.com/sponsors/CServinL)

### Método del círculo (round-robin)
Este algoritmo genera una planificación justa para torneos donde cada jugador debe enfrentar a todos los demás una sola vez, con un partido por día y como máximo un día de descanso.

🔹 Pasos:
1) Inicializar jugadores:
    * Si el número de jugadores 𝑛 es impar, se agrega un jugador ficticio llamado "descansa".
    * Esto asegura que en cada día haya un número par de jugadores (pares de enfrentamientos).

2) Rotaciones:

    * Se disponen los jugadores en un círculo.
    * Cada día, se emparejan jugadores por posiciones opuestas en el círculo.
    * Luego, se rota el arreglo (excepto el primero) para generar nuevos enfrentamientos el día siguiente.

3) Asignación:
    * Se almacena para cada jugador y día si juega contra otro o descansa.

4) Salida:
    * Se imprime una tabla donde cada fila representa a un jugador y cada columna un día, indicando contra quién juega o si descansa.

🧮 Días requeridos:
* Si 𝑛 es par: se requieren 𝑛 − 1 días.
* Si 𝑛 es impar: se requieren 𝑛 días.
