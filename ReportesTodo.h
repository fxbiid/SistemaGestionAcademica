#pragma once
class Alumno;
class Curso;
#include<iostream>
#include<string>
using namespace std;

class ReportesTodo {
    public:
    static void getAlumnosCarrera(const string& carrera);
    static void getCursosAlumno(const string& idAlumno);
    static bool promedioNotasAlumCurso(const string& idAlumno,const string& idCurso,double& promedio);
    static bool calcuPromediGeneralAlumno(const string& idAlumno,double& promedioGeneral);
    static void reportes();
};


