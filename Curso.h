//
// Created by fabil on 30-08-2025.
//
#pragma once
#include <string>
#using namespace std;
class Curso {
    private:
    string id;
    string name;
    int cantMaxStudents;
    string carrera;
    string profe;
    public:
    Curso(string id,string name,int cantMaxStudents,string carrera,string profe);
    string getId();
    string getName();
    int getCantMaxStudents();
    string getCarrera();
    string getProfe();

};
