#include <iostream>
#include "Alumno.h"
#include "Curso.h"
#include <string>
using namespace std;

void registrarAlumno() {

}

void buscarAlumno() {

}

void eliminarAlumno() {

}

void cosasGestionAlum() {
    int Esco = 0;
    while (Esco != -1) {
        cout<<"***Gestion alumnos***"<<endl;
        cout<<"1.Registrar alumno"<<endl;
        cout<<"2.Buscar alumno"<<endl;
        cout<<"3.Eliminar alumno"<<endl;
        cout<<"4.Volver menu principal"<<endl;
        int escogidoAlumno;
        cin>>escogidoAlumno;
        switch(escogidoAlumno) {
            case 1:
                registrarAlumno();
                break;
            case 2:
                buscarAlumno();
                break;
            case 3:
                eliminarAlumno();
                break;
            case 4:
                Esco = -1;
                break;

        }
    }

}

void crearCurso() {

}

void buscarCurso() {

}

void eliminarCurso() {

}

void cosasGestionCurso() {
    int corte=0;
    while (corte!=-1) {
        cout<<"***Gestion cursos***"<<endl;
        cout<<"1.Crear curso"<<endl;
        cout<<"2.Buscar curso"<<endl;
        cout<<"3.Eliminar curso"<<endl;
        cout<<"4.Volver menu principal"<<endl;
        int escogidoCurso;
        cin>>escogidoCurso;
        switch(escogidoCurso) {
            case 1:
                crearCurso();
                break;
            case 2:
                buscarCurso();
                break;
            case 3:
                eliminarCurso();
                break;
            case 4:
                corte=-1;
                break;
        }
    }


}

void inscripcionAlumnosAcurso() {

}

void EliminarAlumnosDeCursos() {

}

void inscribir() {
    int corte=0;
    while (corte!=-1) {
        cout<<"1.Inscribir a alumnos en cursos"<<endl;
        cout<<"2.Eliminar alumnos de cursos"<<endl;
        int op;
        cin>>op;
        switch(op) {
            case 1:
                inscripcionAlumnosAcurso();
                break;
            case 2:
                EliminarAlumnosDeCursos();
                break;
        }
    }

}
//asignacion de notas a alumnos en cursos especificos
void gestionDeNotas() {

}
//Consultar la información de un alumno (cursos inscritos y notas) y calcular
//promedios de notas por curso y el promedio general del alumno.
void reportes() {

}

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
        int opcion = 0;
        while (opcion != -1) {
            cout<<"1. Gestion de alumnos"<<endl;
            cout<<"2. Gestion de cursos"<<endl;
            cout<<"3. Inscripcion de cursos"<<endl;
            cout<<"4. Gestion de notas"<<endl;
            cout<<"5. Reportes"<<endl;
            cout<<"6. Salir"<<endl;
            cout<<"Escoge una opcion: ";
            int escogido;
            cin>>escogido;
            switch (escogido) {
                case 1:
                    cosasGestionAlum();
                    break;
                case 2:
                    cosasGestionCurso();
                    break;
                case 3:
                    inscribir();
                    break;
                case 4:
                    gestionDeNotas();
                    break;
                case 5:
                    reportes();
                    break;
                case 6:
                    opcion = -1;
                    break;
            }
        }

    return 0;
}