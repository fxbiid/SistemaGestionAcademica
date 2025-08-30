//
// Created by fabil on 30-08-2025.
//
#include "Alumno.h"

Alumno::Alumno(string id, string firstname, string lastName, string major, string enrollmentDate) {
    this->id = id;
    this->firstname = firstname;
    this->lastName = lastName;
    this->major = major;
    this->enrollmentDate = enrollmentDate;
}
string Alumno::getId() {
    return id;
}
string Alumno::getFirstName()  {
    return firstname;
}
string Alumno::getLastName() {
    return lastName;
}
string Alumno::getMajor() {
    return major;
}
string Alumno::getEnrollmentDate() {
    return enrollmentDate;
}
