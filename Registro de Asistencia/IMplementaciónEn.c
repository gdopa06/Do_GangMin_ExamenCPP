#include <stdio.h>
#include <string.h>

#define MAX_MATERIAS 10
#define MAX_LONGITUD 50
#define MAX_ASISTENCIAS 100

// Estructura para representar un registro de asistencia
typedef struct {
    char fecha[MAX_LONGITUD];
    char materia[MAX_LONGITUD];
    char estado[MAX_LONGITUD]; // "Asistió", "Falta", "Tardanza"
} Asistencia;

// Estructura Estudiante
typedef struct {
    char nombre[MAX_LONGITUD];
    int edad;
    double promedio;
    char materias[MAX_MATERIAS][MAX_LONGITUD];
    int numMaterias;
    Asistencia asistencias[MAX_ASISTENCIAS];
    int numAsistencias;
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

// Función para registrar asistencia
void registrarAsistencia(Estudiante* estudiante, const char* materia, const char* fecha, const char* estado) {
    int found = 0;
    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        if (estudiante->numAsistencias < MAX_ASISTENCIAS) {
            strcpy(estudiante->asistencias[estudiante->numAsistencias].fecha, fecha);
            strcpy(estudiante->asistencias[estudiante->numAsistencias].materia, materia);
            strcpy(estudiante->asistencias[estudiante->numAsistencias].estado, estado);
            estudiante->numAsistencias++;
            printf("Asistencia registrada: [%s, %s, %s]\n", materia, fecha, estado);
        } else {
            printf("No se pueden registrar más asistencias.\n");
        }
    } else {
        printf("El estudiante no está inscrito en la materia %s.\n", materia);
    }
}

// Función para mostrar registros de asistencia
void mostrarAsistencia(const Estudiante* estudiante) {
    printf("Registros de Asistencia:\n");
    for (int i = 0; i < estudiante->numAsistencias; i++) {
        printf("Materia: %s, Fecha: %s, Estado: %s\n",
               estudiante->asistencias[i].materia,
               estudiante->asistencias[i].fecha,
               estudiante->asistencias[i].estado);
    }
}

int main() {
    // Crear un estudiante
    Estudiante estudiante;
    strcpy(estudiante.nombre, "Juan Pérez");
    estudiante.edad = 20;
    estudiante.promedio = 8.9;
    estudiante.numMaterias = 0;
    estudiante.numAsistencias = 0;

    // Agregar materias
    agregarMateria(&estudiante, "Matemáticas");
    agregarMateria(&estudiante, "Física");

    // Registrar asistencia
    registrarAsistencia(&estudiante, "Matemáticas", "2024-11-19", "Asistió");
    registrarAsistencia(&estudiante, "Física", "2024-11-19", "Tardanza");

    // Mostrar información y asistencia
    mostrarEstudiante(&estudiante);
    mostrarAsistencia(&estudiante);

    return 0;
}
