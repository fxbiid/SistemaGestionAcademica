#include "ReportesTodo.h"
#include "Lista.h"
#include "Alumno.h"
#include "Curso.h"
#include "NodoAlumno.h"
#include "NodoCurso.h"
#include "NodoMatricula.h"
#include"Nodonota.h"
#include"ControlError.h"
#include<iostream>
using  namespace  std;

void ReportesTodo::reportes() {
    int opcion=0;
    while (opcion!=-1) {
        cout<<"***Reportes***"<<endl;
        cout<<"1. Obtener todos los alumnos de una carrera"<<endl;
        cout<<"2. Obtener todos los cursos en los que un alumno esta inscrito"<<endl;
        cout<<"3. Promedio de notas de un alumno en un curso"<<endl;
        cout<<"4. Promedio general de un alumno"<<endl;
        cout<<"5. Volver menu principal"<<endl;
        cout<<"Ingrese una opcion: ";
        int escogido = leerOp(1,5);
        if (escogido==1) {
            string carrera = leerCarrera("Ingrese carrera: ");
            getAlumnosCarrera(carrera);

        }else if(escogido==2) {

            string idAlumno = leerId("Ingrese un id de alumno: ");
            getCursosAlumno(idAlumno);
        }else if(escogido==3) {
            string idAlumno= leerId("Ingrese el ID del alumno: ");
            string idCurso = leerId("Ingrese el ID del curso: ");


            double promedio= 0.0;
            if (promedioNotasAlumCurso(idAlumno,idCurso,promedio)) {
                cout<< "Promedio del alumno en el curso:"<<promedio<<endl;
                cout<<"\n";
            }else {
                cout<<"El alumno no tiene notas en el curso o no esta inscrito";
                cout<<"\n";
            }

        }else if(escogido==4) {
            string idAlumno= leerId("Ingrese el ID del alumno: ");
            double promedioGeneral= 0.0;
            if (calcuPromediGeneralAlumno(idAlumno,promedioGeneral)) {
                cout<<"Promedio general del alumno: "<<promedioGeneral<<endl;
                cout<<"\n";
            }else {
                cout<<"El alumno no tiene cursos con notas";
                cout<<"\n";
            }
        }else if(escogido==5) {
            opcion = -1;
            break;
        }
    }
}

void ReportesTodo::getAlumnosCarrera(const string& carrera) {
    bool encontrado = false;
    string nomCambiado = cambiarAminus(arreglarPalabra(carrera));
    for (NodoAlumno* i=cabezaAlum;i!=nullptr;i=i->next) {
        string nomNodo= cambiarAminus(arreglarPalabra(i->infoAlum->getMajor()));
        if (nomNodo==nomCambiado) {
            cout<<"ID: "<<i->infoAlum->getId()<<endl;
            cout<<"Nombre: "<<i->infoAlum->getFirstName()<<" " << i->infoAlum->getLastName()<<endl;
            cout<<"Ingreso: "<<i->infoAlum->getEnrollmentDate()<<endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout<<"No hay alumnos en inscritos en la carrera "<<carrera<<endl;
    }
}


void ReportesTodo::getCursosAlumno(const string& idAlumno) {
    bool encontrado = false;
    for (NodoMatricula*i=cabezaMatri;i!=nullptr;i=i->next) {
        if (i->alumno->getId()==idAlumno) {
            cout<<"Curso: "<<i->curso->getName()<<endl;
            cout<<"ID: "<<i->curso->getId()<<endl;
            cout<<"Carrera: "<<i->curso->getCarrera()<<endl;
            cout<<"\n";
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout<<"El alumno "<<idAlumno<<" no tiene cursos inscritos";
        cout<<"\n";
    }

}


bool ReportesTodo::promedioNotasAlumCurso(const string& idAlumno,const string& idCurso,double& promedio) {
    double suma=0.0;
    double cant=0.0;
    for (NodoMatricula*i=cabezaMatri;i!=nullptr;i=i->next) {
        if (i->alumno->getId()==idAlumno&&i->curso->getId()==idCurso) {
            for (Nodonota* n = i->notas;n!=nullptr;n=n->next) {
                if (n->valorNota>=1.0&&n->valorNota<=7.0) {
                    suma+=n->valorNota;
                    cant++;
                }
            }
            if (cant==0) {
                return false;
            }
            promedio=suma/cant;
            return true;
        }

    }
    return false;
}


bool ReportesTodo::calcuPromediGeneralAlumno(const string& idAlumno,double& promedioGeneral) {
    double sumPromCursos=0.0;
    int cantiCursosNotas=0;
    for (NodoMatricula*i=cabezaMatri;i!=nullptr;i=i->next) {
        if (i->alumno->getId()==idAlumno) {
            double sumaNotas = 0.0;
            int cant=0;
            for (Nodonota* n = i->notas;n!=nullptr;n=n->next) {
                if (n->valorNota>=1.0&&n->valorNota<=7.0) {
                    sumaNotas+=n->valorNota;
                    cant++;
                }
            }
            if (cant>0) {
                double promedioCurso = sumaNotas/cant;
                sumPromCursos+=promedioCurso;
                cantiCursosNotas++;
            }
        }
    }
    if (cantiCursosNotas==0) {
        return false;
    }
    promedioGeneral = sumPromCursos/cantiCursosNotas;
    return true;

}


