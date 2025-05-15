#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void generarCalendario(int n) {
    bool impar = (n % 2 != 0);
    int total_jugadores = impar ? n + 1 : n;
    int dias = total_jugadores - 1;

    // Inicializar matriz de resultados: [jugador][día]
    vector<vector<string>> tabla(n, vector<string>(dias, ""));

    // Lista de jugadores para rotación
    vector<int> jugadores(total_jugadores);
    for (int i = 0; i < total_jugadores; ++i)
        jugadores[i] = i + 1;

    // Generar emparejamientos por día
    for (int d = 0; d < dias; ++d) {
        for (int i = 0; i < total_jugadores / 2; ++i) {
            int j1 = jugadores[i];
            int j2 = jugadores[total_jugadores - 1 - i];

            // Ignorar emparejamientos del jugador fantasma
            if (j1 == n + 1) {
                if (j2 <= n) tabla[j2 - 1][d] = "descansa";
            } else if (j2 == n + 1) {
                if (j1 <= n) tabla[j1 - 1][d] = "descansa";
            } else {
                if (j1 <= n) tabla[j1 - 1][d] = "vs " + to_string(j2);
                if (j2 <= n) tabla[j2 - 1][d] = "vs " + to_string(j1);
            }
        }

        // Rotación de jugadores (excepto el primero)
        int ultimo = jugadores.back();
        for (int i = total_jugadores - 1; i > 1; --i)
            jugadores[i] = jugadores[i - 1];
        jugadores[1] = ultimo;
    }

    // Imprimir tabla
    cout << left << setw(10) << "Jugador";
    for (int d = 0; d < dias; ++d)
        cout << "D" << d + 1 << setw(10) << " ";
    cout << "\n";

    for (int i = 0; i < n; ++i) {
        cout << setw(10) << i + 1;
        for (int d = 0; d < dias; ++d)
            cout << setw(10) << tabla[i][d];
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Ingrese el número de jugadores: ";
    cin >> n;

    if (n < 2) {
        cout << "Se requieren al menos 2 jugadores.\n";
        return 1;
    }

    generarCalendario(n);
    return 0;
}
