#include <iostream>
#include<algorithm>
#include "Nodonota.h"
#include "NodoMatricula.h"
#include "Alumno.h"
#include "Curso.h"
#include "Lista.h"
#include "ControlError.h"
using namespace std;


NodoMatricula::NodoMatricula(Alumno* alumno,Curso* curso,NodoMatricula* sig)
    : alumno(alumno),curso(curso),next(sig){}


//buscar matricula especifica de alumno con curso
NodoMatricula* NodoMatricula::buscarMatriEspe(Alumno* alumno,Curso* curso) {
    for (NodoMatricula* i=cabezaMatri;i!=nullptr;i=i->next) {
        if (i->alumno==alumno && i->curso==curso) {
            return i;
        }
    }
    return nullptr;
}
void NodoMatricula:: borrarListaNotas(Nodonota *&notas) {
    while (notas!=nullptr) {
        Nodonota* actual = notas;
        notas=notas->next;
        delete actual;
    }
}
bool NodoMatricula::alumnoExisteEnCurso(Alumno * alumno,Curso* curso) {
    for (NodoMatricula* i=cabezaMatri;i!=nullptr;i=i->next) {
        if (i->alumno==alumno && i->curso==curso) {
            return true;
        }
    }
    return false;

}

int NodoMatricula::contInscritosCur(Curso * curso) {
    int cont=0;
    for (NodoMatricula*i=cabezaMatri;i!=nullptr;i=i->next) {
        if (i->curso==curso) {
            cont++;
        }
    }
    return cont;
}

void NodoMatricula::inscripcionAlumnosAcurso() {
    cout<<"Inscripcion de alumnos a cursos \n";
    if (cabezaCurso==nullptr) {
        cout << "No hay cursos registrados";
        return;
    }
    if (cabezaAlum==nullptr) {
        cout << "No hay alumnos registrados";
        return;
    }
    string idCurso,idAlumno;

    do {
        cout << "Ingrese el ID del curso: ";
        getline(cin, idCurso);

        if (idCurso.empty()) {
            cout << "El ID de curso no puede ser vacio \n ";
        }
    }while (idCurso.empty());

    do {
        cout << "Ingrese el ID del alumno: ";
        getline(cin, idAlumno);

        if (idAlumno.empty()) {
            cout << "El ID de alumno no puede ser vacio \n ";
        }
    }while (idAlumno.empty());

    Curso* curso = Curso::obtenerCursoPorId(idCurso);
    if (curso==nullptr) {
        cout<<"No se encontro el curso de ese ID"<<idCurso<<"\n";
        return;
    }

    Alumno* alumno = Alumno::obtenerAlumnoPorId(idAlumno);

    if (alumno==nullptr) {
        cout<<"No se encontro el alumno de ese ID"<<idAlumno<<"\n";
        return;
    }
    //si la carrera del alumno no es la misma del curso
    if (alumno->getMajor() != curso->getCarrera()) {
        cout<<"La carrera del alumno ("<<alumno->getMajor()<<") no coincide con la del curso("<<curso->getCarrera()<<")\n";
        return;
    }
    //si el alumno ya existe en el curso
    if (alumnoExisteEnCurso(alumno,curso)) {
        cout<<"El alumno ya esta inscrito a ese curso \n";
        return;
    }
    //si el curso esta lleno
    int inscritosCurso = contInscritosCur(curso);
    if (inscritosCurso>=curso->getCantMaxStudents()) {
        cout<<"El curso esta lleno su cupo maximo es "<<curso->getCantMaxStudents();
        return;
    }

    NodoMatricula* nuevo = new NodoMatricula(alumno,curso,cabezaMatri);
    cabezaMatri = nuevo;
    cout<<"Inscripcion se ha realizado exitosamente \n";
}

//borrar matricula al curso
bool NodoMatricula::borrarMatricula(Alumno * alumno, Curso * curso) {
    NodoMatricula* actual = cabezaMatri;
    NodoMatricula* anterior = nullptr;

    while (actual!=nullptr) {
        if (actual->alumno==alumno && actual->curso==curso) {
            borrarListaNotas(actual->notas);

            if (anterior==nullptr) {
                cabezaMatri = actual->next;
            }else {
                anterior->next = actual->next;
            }
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->next;

    }
    return false;
}

void NodoMatricula::EliminarAlumnosDeCursos() {
    cout<<"***Eliminar alumnos de cursos \n";
    if (cabezaCurso==nullptr) {
        cout << "No hay cursos registrados";
        return;
    }
    if (cabezaAlum==nullptr) {
        cout << "No hay alumnos registrados";
    }

    string idCurso,idAlumno;

    do {
        cout << "Ingrese el ID del curso: ";
        getline(cin, idCurso);
        if (idCurso.empty()) {
            cout<<"El ID del curso no puede ser vacio \n";

        }
    }while (idCurso.empty());

    do {
        cout << "Ingrese el ID del alumno: ";
        getline(cin, idAlumno);
        if (idAlumno.empty()) {cout<<"El ID del alumno no puede ser vacio \n";}
    }while (idAlumno.empty());

    Curso* curso = Curso::obtenerCursoPorId(idCurso);
    if (curso==nullptr) {
        cout<<"No se encontro curso con ese ID "<<idCurso;
        return;
    }

    Alumno* alumno = Alumno::obtenerAlumnoPorId(idAlumno);

    if (alumno==nullptr) {
        cout<<"No se encontro alumno con ese ID "<<idAlumno;
        return;
    }

    //primero hay q verificar que el alumno este inscrito pq si no pa que
    if (!(alumnoExisteEnCurso(alumno,curso))) {
        cout<<"El alumno no esta inscrito en ese curso";
        return;
    }

    //ahora si esta en el curso lo echamos
    if (borrarMatricula(alumno,curso)) {
        cout<<"Alumno borrado del curso exitosamente \n";
        cout<<"Alumno: "<<alumno->getFirstName()<<" "<<alumno->getLastName()<<"\n";
        cout<<"Curso: "<<curso->getName()<<"\n";
        cout<<"\n";
    }

}
//control de error para notas
static double leerNota() {
    while (true) {
        string linea;
        getline(cin, linea);
        if (linea.empty()) {
            cout<<"La nota no puede ser vacia. Ingresa una nota valida: ";
            continue;
        }
        linea.erase(remove(linea.begin(),linea.end(),' '),linea.end());
        for (char &c : linea) {
            if (c==',') {
                c='.';
            }
        }
        try {
            size_t posi = 0;
            double nota = stod(linea, &posi);
            if (posi!=linea.size()) {
                cout<<"Error ingresa solo numeros. Ingresa una nota valida: ";
                continue;
            }
            if (nota<1.0||nota>7.0) {
                cout<<"Error nota invalida. Ingresa una nota valida(1.0 a 7.0): ";
                continue;
            }
            return nota;

        }catch (...) {
            cout<<"Error entrada invalida. Ingresa una nota valida(1.0 a 7.0): ";
        }
    }
}

void agregarNota(NodoMatricula * matricula, double notita) {
    Nodonota* x = new Nodonota(notita);
    x->next = matricula->notas;
    matricula->notas=x;
}

//asignacion de notas a alumnos en cursos especificos
void NodoMatricula::gestionDeNotas() {
    cout<<"***Gestion de notas***\n"<<endl;
    if (cabezaCurso==nullptr) {
        cout << "No hay cursos registrados \n";
        cout<<"\n";
        return;
    }

    if (cabezaAlum==nullptr) {
        cout << "No hay alumnos registrados \n";
        cout<<"\n";
        return;
    }
    string idCurso,idAlumno;

    do {
        cout << "Ingrese el ID del curso: ";
        getline(cin, idCurso);
        if (idCurso.empty()) {
            cout<<"El ID del curso no puede ser vacio \n";

        }
    }while (idCurso.empty());

    do {
        cout << "Ingrese el ID del alumno: ";
        getline(cin, idAlumno);
        if (idAlumno.empty()) {cout<<"El ID del alumno no puede ser vacio \n";}
    }while (idAlumno.empty());

    Curso* curso = Curso::obtenerCursoPorId(idCurso);
    if (curso==nullptr) {
        cout<<"No hay un curso con ese ID";
        return;
    }

    Alumno* alumno = Alumno::obtenerAlumnoPorId(idAlumno);
    if (alumno==nullptr) {
        cout<<"No hay un alumno con ese ID";
        return;
    }
    //tambien ver si esta inscrito en ese curso
    if (!alumnoExisteEnCurso(alumno,curso)) {
        cout<<"El alumno no esta inscrito en ese curso";
        return;
    }

    NodoMatricula* matricula = buscarMatriEspe(alumno,curso);

    int opcion=0;
    while (opcion!=4) {
        cout<<"Alumno: "<<alumno->getFirstName()<<" "<<alumno->getLastName();
        cout<<"Curso: "<<curso->getName()<< curso->getId()<<curso->getCarrera()<<"\n";
        cout<<"\n";
        cout<<"1)Agregar notas (1.0 a 7.0)";
        cout<<"2)Volver al menu";
        opcion = leerOp(1,2);
        if (opcion==1) {
            while (true) {
                cout<<"Ingrese nota (1.0 a 7.0): ";
                double nota= leerNota();
                agregarNota(matricula,nota);
                cout<<"Nota agregada exitosamente \n";

                char continuar;
                while (true) {
                    cout<<"¿Agregar otra nota? (s/n): ";
                    if (!(cin>>continuar)) {
                        cin.clear();
                        cin.ignore(1000,'\n');
                        continue;
                    }
                    cin.ignore(1000,'\n');
                    continuar = tolower(static_cast<unsigned char>(continuar));
                    if (continuar=='s' || continuar=='n') {
                        break;
                    }
                    cout<<"Error ingrese s o n\n";
                }
                if (continuar=='n') {
                    break;
                }
            }
        }else if(opcion==2) {
            opcion=4;
            break;
        }



    }


}

NodoMatricula::~NodoMatricula() {
    while(notas!=nullptr) {
        Nodonota* temp=notas;
        notas=notas->next;
        delete temp;
    }
}