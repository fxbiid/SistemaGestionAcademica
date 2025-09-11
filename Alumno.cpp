
#include "Alumno.h"

Alumno::Alumno(string id, string firstname, string lastName, string major, string enrollmentDate) {
    this->id = id;
    this->nom = firstname;
    this->apellido = lastName;
    this->carrera = major;
    this->inscripcion = enrollmentDate;
}
string Alumno::getId() {
    return id;
}
string Alumno::getFirstName()  {
    return nom;
}
string Alumno::getLastName() {
    return apellido;
}
string Alumno::getMajor() {
    return carrera;
}
string Alumno::getEnrollmentDate() {
    return inscripcion;
}
