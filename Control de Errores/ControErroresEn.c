#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_MATERIAS 10
#define MAX_LONGITUD 50

// Estructura Estudiante
typedef struct {
    char nombre[MAX_LONGITUD];
    int edad;
    double promedio;
    char materias[MAX_MATERIAS][MAX_LONGITUD];
    int numMaterias;
} Estudiante;

// Validar formato de la fecha
int validarFecha(const char* fecha) {
    if (strlen(fecha) != 10) return 0;
    if (!isdigit(fecha[0]) || !isdigit(fecha[1]) || !isdigit(fecha[2]) || !isdigit(fecha[3]) ||
        fecha[4] != '-' || !isdigit(fecha[5]) || !isdigit(fecha[6]) || fecha[7] != '-' ||
        !isdigit(fecha[8]) || !isdigit(fecha[9])) {
        return 0;
    }
    return 1;
}

// Crear estudiante con validaciones
int crearEstudiante(Estudiante* estudiante, const char* nombre, int edad, double promedio) {
    if (edad <= 0 || promedio < 0 || promedio > 10) {
        fprintf(stderr, "Error: Edad o promedio fuera de rango.\n");
        return -1;
    }
    strncpy(estudiante->nombre, nombre, MAX_LONGITUD - 1);
    estudiante->edad = edad;
    estudiante->promedio = promedio;
    estudiante->numMaterias = 0;
    return 0;
}

// Agregar una materia
int agregarMateria(Estudiante* estudiante, const char* materia) {
    if (estudiante->numMaterias >= MAX_MATERIAS) {
        fprintf(stderr, "Error: No se pueden agregar más materias.\n");
        return -1;
    }
    strncpy(estudiante->materias[estudiante->numMaterias], materia, MAX_LONGITUD - 1);
    estudiante->numMaterias++;
    return 0;
}

// Registrar asistencia con validaciones
int registrarAsistencia(const Estudiante* estudiante, const char* materia, const char* fecha) {
    if (!validarFecha(fecha)) {
        fprintf(stderr, "Error: Formato de fecha inválido.\n");
        return -1;
    }

    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i], materia) == 0) {
            printf("Asistencia registrada: [%s, %s]\n", materia, fecha);
            return 0;
        }
    }

    fprintf(stderr, "Error: Materia no registrada.\n");
    return -1;
}

// Mostrar información del estudiante
void mostrarEstudiante(const Estudiante* estudiante) {
    printf("Nombre: %s\nEdad: %d\nPromedio: %.2f\nMaterias:\n", estudiante->nombre, estudiante->edad, estudiante->promedio);
    if (estudiante->numMaterias == 0) {
        printf("Ninguna\n");
    } else {
        for (int i = 0; i < estudiante->numMaterias; i++) {
            printf("- %s\n", estudiante->materias[i]);
        }
    }
}

int main() {
    Estudiante estudiante;

    if (crearEstudiante(&estudiante, "Juan Pérez", 20, 8.9) != 0) return -1;

    agregarMateria(&estudiante, "Matemáticas");
    agregarMateria(&estudiante, "Historia");

    mostrarEstudiante(&estudiante);

    registrarAsistencia(&estudiante, "Matemáticas", "2024-11-19");
    registrarAsistencia(&estudiante, "Historia", "19-11-2024");

    return 0;
}
