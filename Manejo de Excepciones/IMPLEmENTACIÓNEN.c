#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MATERIAS 10
#define MAX_LONGITUD 50

// Estructura Estudiante
typedef struct {
    char nombre[MAX_LONGITUD];
    int edad;
    char materias[MAX_MATERIAS][MAX_LONGITUD];
    int numMaterias;
} Estudiante;

// Función para agregar una materia
int agregarMateria(Estudiante* estudiante, const char* materia) {
    if (estudiante->numMaterias >= MAX_MATERIAS) {
        fprintf(stderr, "Error: No se pueden agregar más materias.\n");
        return -1;
    }
    strcpy(estudiante->materias[estudiante->numMaterias], materia);
    estudiante->numMaterias++;
    printf("Materia %s agregada.\n", materia);
    return 0;
}

// Función para validar el formato de la fecha
int validarFecha(const char* fecha) {
    // Validar longitud
    if (strlen(fecha) != 10) {
        fprintf(stderr, "Error: Longitud inválida para la fecha.\n");
        return -1;
    }

    // Validar formato YYYY-MM-DD
    if (!isdigit(fecha[0]) || !isdigit(fecha[1]) || !isdigit(fecha[2]) || !isdigit(fecha[3]) ||
        fecha[4] != '-' || !isdigit(fecha[5]) || !isdigit(fecha[6]) || fecha[7] != '-' ||
        !isdigit(fecha[8]) || !isdigit(fecha[9])) {
        fprintf(stderr, "Error: Formato inválido para la fecha: %s. Debe ser YYYY-MM-DD.\n", fecha);
        return -1;
    }
    return 0;
}

// Función para registrar asistencia
int registrarAsistencia(const Estudiante* estudiante, const char* materia, const char* fecha) {
    // Validar formato de la fecha
    if (validarFecha(fecha) != 0) {
        return -1;
    }

    // Verificar si la materia está registrada
    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            printf("Asistencia registrada: [%s, %s]\n", materia, fecha);
            return 0;
        }
    }

    fprintf(stderr, "Error: La materia %s no está registrada.\n", materia);
    return -1;
}

int main() {
    // Crear un estudiante
    Estudiante estudiante = {"Juan Pérez", 20, {""}, 0};

    // Agregar materias
    agregarMateria(&estudiante, "Matemáticas");
    agregarMateria(&estudiante, "Historia");

    // Registrar asistencia con una fecha válida
    registrarAsistencia(&estudiante, "Matemáticas", "2024-11-19");

    // Registrar asistencia con formato de fecha inválido
    registrarAsistencia(&estudiante, "Historia", "19-11-2024");

    // Registrar asistencia para una materia no registrada
    registrarAsistencia(&estudiante, "Física", "2024-11-19");

    return 0;
}
