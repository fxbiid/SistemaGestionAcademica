//
// Created by fabil on 30-08-2025.
//
#pragma once
#include <string>
using namespace std;
class Alumno {
private:
    string id;
    string nom;
    string apellido;
    string carrera;
    string inscripcion;
    public:
    Alumno(string id, string firstname, string lastName, string major, string enrollmentDate);
    string getId();
    string getFirstName();
    string getLastName();
    string getMajor();
    string getEnrollmentDate();


};