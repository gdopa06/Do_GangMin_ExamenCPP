#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Clase Estudiante
class Estudiante {
private:
    string nombre;
    int edad;
    double promedio;
    vector<string> materias; // Lista de materias

public:
    // Constructor
    Estudiante(const string& nombre, int edad, double promedio)
        : nombre(nombre), edad(edad), promedio(promedio) {}

    void mostrarEstudiante() const {
        cout << "Nombre: " << nombre << "\n"
             << "Edad: " << edad << "\n"
             << "Promedio: " << promedio << "\n"
             << "Materias inscritas: ";
        if (materias.empty()) {
            cout << "Ninguna\n";
        } else {
            for (const auto& materia : materias) {
                cout << materia << " ";
            }
            cout << "\n";
        }
    }

    void agregarMateria(const string& materia) {
        materias.push_back(materia);
        cout << "Materia " << materia << " agregada.\n";
    }

    void eliminarMateria(const string& materia) {
        auto it = find(materias.begin(), materias.end(), materia);
        if (it != materias.end()) {
            materias.erase(it);
            cout << "Materia " << materia << " eliminada.\n";
        } else {
            cout << "Materia " << materia << " no encontrada.\n";
        }
    }
};

int main() {
    // Crear un estudiante
    Estudiante estudiante("Juan Pérez", 20, 8.9);

    // Mostrar información inicial
    estudiante.mostrarEstudiante();

    // Agregar materias
    estudiante.agregarMateria("Matemáticas");
    estudiante.agregarMateria("Física");
    estudiante.agregarMateria("Química");

    // Mostrar información actualizada
    estudiante.mostrarEstudiante();

    // Eliminar una materia
    estudiante.eliminarMateria("Física");

    // Mostrar información actualizada
    estudiante.mostrarEstudiante();

    return 0;
}
