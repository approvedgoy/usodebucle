#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

int main() {
    char continuar;


    do {
        int cantidadEstudiantes;
        int aprobados = 0;
        int reprobados = 0;
        double sumaNotaGrupo = 0.0;
        double mejorNota = -1.0; // Se inicia en -1 para asegurar que el primer promedio validado sea mayor
        string mejorEstudiante = "";


        cout << "Cantidad de estudiantes: ";
        cin >> cantidadEstudiantes;
        while (cantidadEstudiantes <= 0) {
            cout << "Error: La cantidad debe ser mayor que 0. Intente nuevamente: ";
            cin >> cantidadEstudiantes;
        }

        for (int i = 1; i <= cantidadEstudiantes; i++) {
            string nombreEstudiante;
            double sumaNotas = 0.0;

            cout << "\n--- Estudiante " << i << " ---\n";
            cout << "Nombre: ";
            cin >> nombreEstudiante; // Se utiliza cin >> para leer el nombre del estudiante.
            getline(cin, nombreEstudiante); //getline para poder escribir el resto de la línea después del nombre.


            for (int j = 1; j <= 4; j++) {
                double nota;
                cout << "Calificacion " << j << ": ";
                cin >> nota;

                while (nota < 0 || nota > 100) {
                    cout << "Error: La calificacion debe estar entre 0 y 100. Calificacion " << j << ": ";
                    cin >> nota;
                }

                sumaNotas += nota; // Acumulador de las 4 notas del estudiante.
            }

            double promedioEstudiante = sumaNotas / 4.0;
            sumaNotaGrupo += promedioEstudiante; 

          
            cout << fixed << setprecision(2); // Se establece la precisión de salida a 2 decimales.
            cout << "Promedio: " << promedioEstudiante << " - ";

            if (promedioEstudiante >= 70.0) {
                cout << "Aprobado\n";
                aprobados++;
            } else {
                cout << "Reprobado\n";
                reprobados++;
            }

            if (promedioEstudiante > mejorNota) {
                mejorNota = promedioEstudiante;
                mejorEstudiante = nombreEstudiante;
            }
        }

    
        double promedioGeneral = sumaNotaGrupo / cantidadEstudiantes; // Cálculo del promedio general del grupo.

        cout << "\n===== RESUMEN =====\n";
        cout << "Aprobados: " << aprobados << " | Reprobados: " << reprobados << "\n";
        cout << fixed << setprecision(2);
        cout << "Promedio del grupo: " << promedioGeneral << "\n";
        cout << "Mejor nota: " << mejorEstudiante << " (" << mejorNota << ")\n";


        cout << "Desea consultar otro grupo? (s/n): " << '\n';
        cin >> continuar;
        cout << "\n";

    } while (continuar == 's' || continuar == 'S');

    cout << "Programa finalizado.\n";
    return 0;
}