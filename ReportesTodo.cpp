#include "ReportesTodo.h"
#include "lista.h"
#include "Alumno.h"
#include "Curso.h"
#include "NodoAlumno.h"
#include "NodoCurso.h"
#include "NodoMatricula.h"
#include"Nodonota.h"


void ReportesTodo::getAlumnosCarrera(const string& carrera) {
    bool encontrado = false;
    for (NodoAlumno* i=cabezaAlum;i!=nullptr;i=i->next) {
        if (i->infoAlum->getMajor()==carrera) {
            cout<<"ID: "<<i->infoAlum->getId()<<endl;
            cout<<"Nombre: "<<i->infoAlum->getNombre()<<" " << i->infoAlum->getLastName()<<endl;
            cout<<"Ingreso: "<<i->infoAlum->getIngresso()<<endl;
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
        cout<<"El alumno "<<idAlumno<<"no tiene cursos inscritos";
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


bool ReportesTodo::calcuPromediGeneralAlumno(const string& idAlumno,const double& promedio) {

}


