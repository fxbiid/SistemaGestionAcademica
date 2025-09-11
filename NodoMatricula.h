#pragma once
#include "Alumno.h"
#include "Curso.h"
#include "Nodonota.h"


class NodoMatricula {
    public:
    Alumno *alumno;
    Curso* curso;
    Nodonota* notas;
    NodoMatricula* next;

    NodoMatricula(Alumno* alumno,Curso* curso,NodoMatricula* next= nullptr);

    ~NodoMatricula();
};


