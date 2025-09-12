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
    static void borrarListaNotas(Nodonota *&notas);
    static bool alumnoExisteEnCurso(Alumno * alumno,Curso* curso);
    static int contInscritosCur(Curso * curso);
    static void inscripcionAlumnosAcurso();
    static bool borrarMatricula(Alumno * alumno, Curso * curso);
    static void EliminarAlumnosDeCursos();
    static void gestionDeNotas();
    static NodoMatricula* buscarMatriEspe(Alumno* alumno,Curso* curso);
    ~NodoMatricula();
};


