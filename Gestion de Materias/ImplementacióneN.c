#include <stdio.h>
#include <string.h>

#define MAX_MATERIAS 10
#define MAX_LONGITUD 50

// Estructura Estudiante
typedef struct {
    char nombre[50];
    int edad;
    double promedio;
    char materias[MAX_MATERIAS][MAX_LONGITUD]; // Arreglo de materias
    int numMaterias; // Número actual de materias
} Estudiante;

// Función para mostrar la información del estudiante
void mostrarEstudiante(const Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);
    printf("Materias inscritas: ");
    if (estudiante->numMaterias == 0) {
        printf("Ninguna\n");
    } else {
        for (int i = 0; i < estudiante->numMaterias; i++) {
            printf("%s ", estudiante->materias[i]);
        }
        printf("\n");
    }
}

// Función para agregar una materia
void agregarMateria(Estudiante* estudiante, const char* materia) {
    if (estudiante->numMaterias < MAX_MATERIAS) {
        strcpy(estudiante->materias[estudiante->numMaterias], materia);
        estudiante->numMaterias++;
        printf("Materia %s agregada.\n", materia);
    } else {
        printf("No se pueden agregar más materias.\n");
    }
}

// Función para eliminar una materia
void eliminarMateria(Estudiante* estudiante, const char* materia) {
    int found = 0;
    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            found = 1;
            // Desplazar el resto de materias
            for (int j = i; j < estudiante->numMaterias - 1; j++) {
                strcpy(estudiante->materias[j], estudiante->materias[j + 1]);
            }
            estudiante->numMaterias--;
            printf("Materia %s eliminada.\n", materia);
            break;
        }
    }
    if (!found) {
        printf("Materia %s no encontrada.\n", materia);
    }
}

int main() {
    // Crear un estudiante
    Estudiante estudiante;
    strcpy(estudiante.nombre, "Juan Pérez");
    estudiante.edad = 20;
    estudiante.promedio = 8.9;
    estudiante.numMaterias = 0;

    // Mostrar información inicial
    mostrarEstudiante(&estudiante);

    // Agregar materias
    agregarMateria(&estudiante, "Matemáticas");
    agregarMateria(&estudiante, "Física");
    agregarMateria(&estudiante, "Química");

    // Mostrar información actualizada
    mostrarEstudiante(&estudiante);

    // Eliminar una materia
    eliminarMateria(&estudiante, "Física");

    // Mostrar información actualizada
    mostrarEstudiante(&estudiante);

    return 0;
}
