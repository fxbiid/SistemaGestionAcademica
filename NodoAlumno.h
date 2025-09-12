#pragma once

class Alumno;

class NodoAlumno {
    public:
    Alumno* infoAlum;
    NodoAlumno* next;

    NodoAlumno(Alumno* infoAlum,NodoAlumno* sig=nullptr);
    ~NodoAlumno();
};

