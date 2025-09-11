//
// Created by fabil on 11-09-2025.
//

#include "NodoAlumno.h"


NodoAlumno::NodoAlumno(Alumno *alumno, NodoAlumno *sig)
    :info(alumno), siguiente(sig){}

NodoAlumno::~NodoAlumno() {
    delete infoAlum;
}
