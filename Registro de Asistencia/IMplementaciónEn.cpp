#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Estructura para representar un registro de asistencia
struct Asistencia {
    string fecha;
    string materia;
    string estado; // "Asistió", "Falta", "Tardanza"
};

// Clase Estudiante
class Estudiante {
private:
    string nombre;
    int edad;
    double promedio;
    vector<string> materias; // Lista de materias
    map<string, vector<Asistencia>> registrosAsistencia; // Clave: materia, valor: lista de asistencias

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

    void registrarAsistencia(const string& materia, const string& fecha, const string& estado) {
        if (find(materias.begin(), materias.end(), materia) != materias.end()) {
            registrosAsistencia[materia].push_back({fecha, materia, estado});
            cout << "Asistencia registrada: [" << materia << ", " << fecha << ", " << estado << "]\n";
        } else {
            cout << "El estudiante no está inscrito en la materia " << materia << ".\n";
        }
    }

    void mostrarAsistencia() const {
        cout << "Registros de Asistencia:\n";
        for (const auto& [materia, asistencias] : registrosAsistencia) {
            cout << "Materia: " << materia << "\n";
            for (const auto& registro : asistencias) {
                cout << "  Fecha: " << registro.fecha
                     << ", Estado: " << registro.estado << "\n";
            }
        }
    }
};

int main() {
    // Crear un estudiante
    Estudiante estudiante("Juan Pérez", 20, 8.9);

    // Agregar materias
    estudiante.agregarMateria("Matemáticas");
    estudiante.agregarMateria("Física");

    // Registrar asistencia
    estudiante.registrarAsistencia("Matemáticas", "2024-11-19", "Asistió");
    estudiante.registrarAsistencia("Física", "2024-11-19", "Tardanza");

    // Mostrar información y asistencia
    estudiante.mostrarEstudiante();
    estudiante.mostrarAsistencia();

    return 0;
}
