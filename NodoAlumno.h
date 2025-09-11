#pragma once
#include"Alumno.h"

class NodoAlumno {
    public:
    Alumno* infoAlum;
    NodoAlumno* next;

    NodoAlumno(Alumno*alumno,NodoAlumno* sig=nullptr);
    ~NodoAlumno();
};

