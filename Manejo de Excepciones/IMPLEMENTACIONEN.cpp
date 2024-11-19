#include <iostream>
#include <string>
#include <vector>
#include <regex> // Para validación de fechas

using namespace std;

// Excepción personalizada para errores de formato de fecha
class FechaInvalidaException : public runtime_error {
public:
    explicit FechaInvalidaException(const string& mensaje) : runtime_error(mensaje) {}
};

// Excepción personalizada para materias no registradas
class MateriaNoEncontradaException : public runtime_error {
public:
    explicit MateriaNoEncontradaException(const string& mensaje) : runtime_error(mensaje) {}
};

// Clase Estudiante
class Estudiante {
private:
    string nombre;
    int edad;
    vector<string> materias;

public:
    // Constructor
    Estudiante(const string& nombre, int edad)
        : nombre(nombre), edad(edad) {}

    void agregarMateria(const string& materia) {
        materias.push_back(materia);
        cout << "Materia " << materia << " agregada.\n";
    }

    void registrarAsistencia(const string& materia, const string& fecha) {
        // Validar formato de la fecha: debe ser YYYY-MM-DD
        regex formatoFecha("\\d{4}-\\d{2}-\\d{2}");
        if (!regex_match(fecha, formatoFecha)) {
            throw FechaInvalidaException("Formato de fecha inválido: " + fecha + ". Debe ser YYYY-MM-DD.");
        }

        // Verificar si la materia está registrada
        if (find(materias.begin(), materias.end(), materia) == materias.end()) {
            throw MateriaNoEncontradaException("La materia " + materia + " no está registrada.");
        }

        cout << "Asistencia registrada para " << materia << " en " << fecha << ".\n";
    }
};

int main() {
    try {
        // Crear un estudiante
        Estudiante estudiante("Juan Pérez", 20);

        // Agregar materias
        estudiante.agregarMateria("Matemáticas");
        estudiante.agregarMateria("Historia");

        // Registrar asistencia con formato válido
        estudiante.registrarAsistencia("Matemáticas", "2024-11-19");

        // Registrar asistencia con formato de fecha inválido
        estudiante.registrarAsistencia("Historia", "19-11-2024");

    } catch (const FechaInvalidaException& e) {
        cerr << "Error: " << e.what() << "\n";
    } catch (const MateriaNoEncontradaException& e) {
        cerr << "Error: " << e.what() << "\n";
    } catch (const exception& e) {
        cerr << "Error inesperado: " << e.what() << "\n";
    }

    return 0;
}
