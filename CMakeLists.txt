cmake_minimum_required(VERSION 4.0)
project(Taller1EstructuraFabianDiaz)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller1EstructuraFabianDiaz main.cpp
        Alumno.h
        Alumno.cpp
        Curso.h
        Curso.cpp
        Nodonota.cpp
        Nodonota.h
        NodoAlumno.cpp
        NodoAlumno.h
        NodoCurso.cpp
        NodoCurso.h
        NodoMatricula.cpp
        NodoMatricula.h
        Lista.cpp
        Lista.h
        ControlError.cpp
        ControlError.h
        ReportesTodo.cpp
        ReportesTodo.h)
