#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Definición de la estructura Alumno
struct Alumno {
    string nombre;
    string apellido;
    string codigo;
    float nota;
};

int main() {
    int numAlumnos;

    cout << "Ingrese el nombre del curso: ";
    string nombreCurso;
    cin.ignore();
    getline(cin, nombreCurso);

    cout << "Ingrese el número de alumnos en el curso: ";
    cin >> numAlumnos;

    Alumno* alumnos = new Alumno[numAlumnos];

    // Solicitar y almacenar los datos de los alumnos con validación
    for (int i = 0; i < numAlumnos; i++) {
        cout << "Ingrese el nombre del alumno " << i + 1 << ": ";
        cin.ignore();
        getline(cin, alumnos[i].nombre);

        cout << "Ingrese el apellido del alumno " << i + 1 << ": ";
        getline(cin, alumnos[i].apellido);

        do {
    cout << "Ingrese el código del alumno " << i + 1 << " (8 números): ";
    cin >> alumnos[i].codigo;
    if (alumnos[i].codigo.length() != 8 || !isdigit(alumnos[i].codigo[0]) || !isdigit(alumnos[i].codigo[1]) ||
        !isdigit(alumnos[i].codigo[2]) || !isdigit(alumnos[i].codigo[3]) || !isdigit(alumnos[i].codigo[4]) ||
        !isdigit(alumnos[i].codigo[5]) || !isdigit(alumnos[i].codigo[6]) || !isdigit(alumnos[i].codigo[7])) {
        cout << "El código ingresado es incorrecto.\n";
    }
} while (alumnos[i].codigo.length() != 8 || !isdigit(alumnos[i].codigo[0]) || !isdigit(alumnos[i].codigo[1]) ||
        !isdigit(alumnos[i].codigo[2]) || !isdigit(alumnos[i].codigo[3]) || !isdigit(alumnos[i].codigo[4]) ||
        !isdigit(alumnos[i].codigo[5]) || !isdigit(alumnos[i].codigo[6]) || !isdigit(alumnos[i].codigo[7]));

        do {
            cout << "Ingrese la nota del alumno " << alumnos[i].nombre << " (de 0 a 20): ";
            cin >> alumnos[i].nota;
            if (alumnos[i].nota < 0 || alumnos[i].nota > 20) {
                cout << "La nota ingresada es incorrecta.\n";
            }
        } while (alumnos[i].nota < 0 || alumnos[i].nota > 20);
    }


    // Imprimir las notas menores a 11 y mencionar a los alumnos correspondientes
    cout << "\nAlumnos con notas menores a 11:\n";
    for (int i = 0; i < numAlumnos; i++) {
        if (alumnos[i].nota < 11) {
            cout << alumnos[i].nombre << ": " << alumnos[i].nota << " (Necesita reforzamiento)\n";
        }
    }

    // Calcular el promedio de todas las notas
    float sumaNotas = 0;
    for (int i = 0; i < numAlumnos; i++) {
        sumaNotas += alumnos[i].nota;
    }
    float promedio = sumaNotas / numAlumnos;

    // Imprimir el promedio de notas
    cout << "\nEl promedio de todas las notas es: " << promedio << endl;

    // Ordenar las notas de manera descendente (usando el algoritmo de selección)
    for (int i = 0; i < numAlumnos - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < numAlumnos; j++) {
            if (alumnos[j].nota > alumnos[maxIndex].nota) {
                maxIndex = j;
            }
        }
        // Intercambiar los elementos para ordenar
        Alumno temp = alumnos[i];
        alumnos[i] = alumnos[maxIndex];
        alumnos[maxIndex] = temp;
    }

    // Imprimir las notas ordenadas
    cout << "\nNotas de los alumnos en orden descendente:\n";
    for (int i = 0; i < numAlumnos; i++) {
        cout << alumnos[i].nombre << ": " << alumnos[i].nota << endl;
    }

    // Liberar la memoria del arreglo dinámico
    delete[] alumnos;
    return 0;
}
