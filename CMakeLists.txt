cmake_minimum_required(VERSION 3.29)
project(Do_GangMin_ExamenCPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(Do_GangMin_ExamenCPP
    EstructuraEstudiante/ImplementacionEn.cpp
    EstructuraEstudiante/ImplementaciónEn.c
        "Gestion de Materias/ImplementacióneN.cpp"
        "Gestion de Materias/ImplementacióneN.c"
        "Registro de Asistencia/IMplementaciónEn.cpp"
        "Registro de Asistencia/IMplementaciónEn.c"
        "Manejo de Excepciones/IMPLEmENTACIÓNEN.c"
        "Manejo de Excepciones/IMPLEMENTACIONEN.cpp"
        "Control de Errores/ControlErroresEn.cpp"
        "Control de Errores/ControErroresEn.c")
