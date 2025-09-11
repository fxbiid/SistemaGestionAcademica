
#include "NodoMatricula.h"
#include "Alumno.h"
#include "Curso.h"
#include "Nodonota.h"


NodoMatricula::NodoMatricula(Alumno* alumno,Curso* curso,NodoMatricula* sig)
    : alumno(alumno),curso(curso),next(sig){}


NodoMatricula::~NodoMatricula() {
    while(notas!=nullptr) {
        Nodonota* temp=notas;
        notas=notas->next;
        delete temp;
    }
}