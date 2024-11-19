#include <stdio.h>
#include <string.h>

// Definición de la estructura Estudiante
typedef struct {
    char nombre[50];
    int edad;
    double promedio;
} Estudiante;

// Función para mostrar información del estudiante
void mostrarEstudiante(const Estudiante* estudiante) {
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);
}


int main() {
    // Crear instancia de Estudiante
    Estudiante estudiante;
    strcpy(estudiante.nombre, "Juan Pérez");
    estudiante.edad = 20;
    estudiante.promedio = 8.9;

    // Mostrar información del estudiante
    mostrarEstudiante(&estudiante);

    return 0;
}

