#include <iostream>
#include <string>
using namespace std;

// Definición de la clase Estudiante
class Estudiante {
private:
    string nombre;
    int edad;
    double promedio;

public:
    // Constructor
    Estudiante(const string& nombre, int edad, double promedio)
        : nombre(nombre), edad(edad), promedio(promedio) {}

    // Método para mostrar información del estudiante
    void mostrarEstudiante() const {
        cout << "Nombre: " << nombre << "\n"
             << "Edad: " << edad << "\n"
             << "Promedio: " << promedio << "\n";
    }
};

int main() {
    // Crear instancia de Estudiante
    Estudiante estudiante("Juan Pérez", 20, 8.9);

    // Mostrar información del estudiante
    estudiante.mostrarEstudiante();

    return 0;
}
