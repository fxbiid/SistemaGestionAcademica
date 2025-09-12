#include "NodoAlumno.h"
#include "Alumno.h"


NodoAlumno::NodoAlumno(Alumno* infoAlum, NodoAlumno* sig)
    :infoAlum(infoAlum), next(sig){}

NodoAlumno::~NodoAlumno() {
    delete infoAlum;
}
