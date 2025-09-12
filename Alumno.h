
#pragma once
#include<iostream>
#include <string>
#include "NodoAlumno.h"
using namespace std;

class Alumno {
private:
    string id;
    string nom;
    string apellido;
    string carrera;
    string inscripcion;
    public:
    Alumno(string id, string firstname, string apellido, string major, string enrollmentDate);
    string getId();
    string getFirstName();
    string getLastName();
    string getMajor();
    string getEnrollmentDate();

    static void registrarAlumno();
    static void buscarAlumno();
    static void eliminarAlumno();

    static bool confirmarAlumnoPorID(const string & id);
    static Alumno* obtenerAlumnoPorId(const string & id);
    static bool alumnoPorNombre(const string& nom);
    static bool ConfirmarAlumnoPorNom(const string & nom);
    static void printAlumEliminar(Alumno * alumno);
    static void eliminarMatricula(Alumno * eliminarAlum);
    static bool borrarAlumnoDelistaPorId(const string & id);


};