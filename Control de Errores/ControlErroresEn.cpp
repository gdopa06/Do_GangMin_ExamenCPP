#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <stdexcept>
#include <algorithm>

using namespace std;

// Excepción personalizada para fecha inválida
class FechaInvalidaException : public runtime_error {
public:
    explicit FechaInvalidaException(const string& mensaje) : runtime_error(mensaje) {}
};

// Excepción personalizada para materias no registradas
class MateriaNoEncontradaException : public runtime_error {
public:
    explicit MateriaNoEncontradaException(const string& mensaje) : runtime_error(mensaje) {}
};

// Excepción personalizada para entrada de datos
class EntradaInvalidaException : public runtime_error {
public:
    explicit EntradaInvalidaException(const string& mensaje) : runtime_error(mensaje) {}
};

// Clase Estudiante
class Estudiante {
private:
    string nombre;
    int edad;
    double promedio;
    vector<string> materias;

    void validarFecha(const string& fecha) const {
        regex formatoFecha("\\d{4}-\\d{2}-\\d{2}");
        if (!regex_match(fecha, formatoFecha)) {
            throw FechaInvalidaException("Formato de fecha inválido: " + fecha + ". Debe ser YYYY-MM-DD.");
        }
    }

public:
    // Constructor
    Estudiante(const string& nombre, int edad, double promedio)
        : nombre(nombre), edad(edad), promedio(promedio) {
        if (edad <= 0 || promedio < 0 || promedio > 10) {
            throw EntradaInvalidaException("Datos inválidos: edad y promedio deben estar en rangos aceptables.");
        }
    }

    // Mostrar información del estudiante
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

    // Agregar una materia
    void agregarMateria(const string& materia) {
        if (materia.empty()) {
            throw EntradaInvalidaException("Nombre de materia vacío.");
        }
        materias.push_back(materia);
        cout << "Materia " << materia << " agregada.\n";
    }

    // Eliminar una materia
    void eliminarMateria(const string& materia) {
        auto it = find(materias.begin(), materias.end(), materia);
        if (it != materias.end()) {
            materias.erase(it);
            cout << "Materia " << materia << " eliminada.\n";
        } else {
            throw MateriaNoEncontradaException("La materia " + materia + " no está registrada.");
        }
    }

    // Registrar asistencia
    void registrarAsistencia(const string& materia, const string& fecha) {
        validarFecha(fecha);
        if (find(materias.begin(), materias.end(), materia) == materias.end()) {
            throw MateriaNoEncontradaException("La materia " + materia + " no está registrada.");
        }
        cout << "Asistencia registrada para " << materia << " en " << fecha << ".\n";
    }
};

// Función principal
int main() {
    try {
        // Crear un estudiante con validaciones
        Estudiante estudiante("Juan Pérez", 20, 8.9);

        // Mostrar información inicial
        estudiante.mostrarEstudiante();

        // Manejar materias
        estudiante.agregarMateria("Matemáticas");
        estudiante.agregarMateria("Historia");

        // Registrar asistencia válida
        estudiante.registrarAsistencia("Matemáticas", "2024-11-19");

        // Intentar registrar asistencia con formato incorrecto
        estudiante.registrarAsistencia("Historia", "19-11-2024");

    } catch (const FechaInvalidaException& e) {
        cerr << "Error: " << e.what() << "\n";
    } catch (const MateriaNoEncontradaException& e) {
        cerr << "Error: " << e.what() << "\n";
    } catch (const EntradaInvalidaException& e) {
        cerr << "Error: " << e.what() << "\n";
    } catch (const exception& e) {
        cerr << "Error inesperado: " << e.what() << "\n";
    }

    return 0;
}
