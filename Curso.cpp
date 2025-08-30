#include "Curso.h"
//
// Created by fabil on 30-08-2025.
//
Curso::Curso(string id, string name, int cantMaxStudents, string carrera, string profe) {
    this->id = id;
    this->name = name;
    this->cantMaxStudents = cantMaxStudents;
    this->carrera = carrera;
    this->profe = profe;
}
string Curso::getId() {
    return id;
}
string Curso::getName() {
    return name;
}
int Curso::getCantMaxStudents() {
    return cantMaxStudents;
}
string Curso::getCarrera() {
    return carrera;
}
string Curso::getProfe() {
    return profe;
}

