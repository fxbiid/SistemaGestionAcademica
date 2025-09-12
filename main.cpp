#include <iostream>
#include "Alumno.h"
#include "Curso.h"
#include "NodoMatricula.h"
#include "ControlError.h"
using namespace std;

static void cosasGestionAlum() {
    int Esco = 0;
    while (Esco != -1) {
        cout<<"***Gestion alumnos***"<<endl;
        cout<<"1.Registrar alumno"<<endl;
        cout<<"2.Buscar alumno"<<endl;
        cout<<"3.Eliminar alumno"<<endl;
        cout<<"4.Volver menu principal"<<endl;
        cout<<"Escoge una opcion: ";
        int escogidoAlumno = leerOp(1,4);
        switch(escogidoAlumno) {
            case 1:
                Alumno::registrarAlumno();
                break;
            case 2:
                Alumno::buscarAlumno();
                break;
            case 3:
                Alumno::eliminarAlumno();
                break;
            case 4:
                Esco = -1;
                break;

        }
    }

}

static void cosasGestionCurso() {
    int corte=0;
    while (corte!=-1) {
        cout<<"***Gestion cursos***"<<endl;
        cout<<"1.Crear curso"<<endl;
        cout<<"2.Buscar curso"<<endl;
        cout<<"3.Eliminar curso"<<endl;
        cout<<"4.Volver menu principal"<<endl;
        cout<<"Escoge una opcion: ";
        int escogidoCurso = leerOp(1,4);
        switch(escogidoCurso) {
            case 1:
                Curso::crearCurso();
                break;
            case 2:
                Curso::buscarCurso();
                break;
            case 3:
                Curso::eliminarCurso();
                break;
            case 4:
                corte=-1;
                break;
        }
    }


}

static void inscribir() {
    int corte=0;
    while (corte!=-1) {
        cout<<"***Incripcion de cursos***"<<endl;
        cout<<"1.Inscribir a alumnos en cursos"<<endl;
        cout<<"2.Eliminar alumnos de cursos"<<endl;
        cout<<"3.Volver a menu principal"<<endl;
        int op = leerOp(1,3);
        switch(op) {
            case 1:
                NodoMatricula::inscripcionAlumnosAcurso();
                break;
            case 2:
                NodoMatricula::EliminarAlumnosDeCursos();
                break;
            case 3:
                corte=-1;
                break;
        }
    }

}

//Consultar la información de un alumno (cursos inscritos y notas) y calcular
//promedios de notas por curso y el promedio general del alumno.
void reportes() {


}

int main() {
        int opcion = 0;
        while (opcion != -1) {
            cout<<"***Sistema Gestion Academica***"<<endl;
            cout<<"1. Gestion de alumnos"<<endl;
            cout<<"2. Gestion de cursos"<<endl;
            cout<<"3. Inscripcion de cursos"<<endl;
            cout<<"4. Gestion de notas"<<endl;
            cout<<"5. Reportes"<<endl;
            cout<<"6. Salir"<<endl;
            cout<<"Escoge una opcion: ";
            int escogido = leerOp(1,6);
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
                    NodoMatricula::gestionDeNotas();
                    break;
                case 5:
                    reportes();
                    break;
                case 6:
                    opcion = -1;
                    cout<<"Programa finalizado";
                    break;
            }
        }

    return 0;
}