#include <iostream>
#include "Alumno.h"
#include "Curso.h"
#include <string>
using namespace std;
struct Nodonota {
    double valorNota;
    Nodonota* next;
};

struct NodoAlumno {
    Alumno* infoAlum;
  NodoAlumno* next;
};

struct NodoCurso {
    Curso* infoCurso;
    NodoCurso* next;
};

struct NodoMatricula {
    Alumno* alumno;
    Curso* curso;
    Nodonota* notas;
    NodoMatricula* next;
};

//cabezas
NodoAlumno* cabezaAlum= nullptr;
NodoCurso* cabezaCurso= nullptr;
NodoMatricula* cabezaMatri= nullptr;


bool confirmarAlumnoPorID(const string & id) {
    for (NodoAlumno* i = cabezaAlum;i!=nullptr;i=i->next) {
        if (i->infoAlum->getId()==id) {
            return true;
        }

    }
    return false;
}

Alumno* obtenerAlumnoPorId(const string & id) {
    for (NodoAlumno* i = cabezaAlum;i!=nullptr;i=i->next) {
        if (i->infoAlum->getId()==id) {
            return i->infoAlum;
        }

    }
    return nullptr;
}


bool ConfirmarAlumnoPorNom(const string & nom) {
    for (NodoAlumno* i = cabezaAlum;i!=nullptr;i=i->next) {
        if (i->infoAlum->getFirstName()==nom) {
           return true;

        }
    }
    return false;
}

void registrarAlumno() {
    cin.ignore(1000,'\n');
    string id, firstname, lastName, major, enrollmentDate;
    cout << "Digite el id: ";
    getline(cin, id);

    //validamos si el id existe
    if (confirmarAlumnoPorID(id)) {
        cout << "ya existe un alumno con ese ID";
        return;
    }
    cout << "Ingrese el nombre: ";
    getline(cin, firstname);
    cout << "Ingrese el apellido: ";
    getline(cin, lastName);
    cout << "Ingrese la carrera: ";
    getline(cin, major);
    cout << "Ingrese la fecha de ingreso (day/month/year): ";
    getline(cin, enrollmentDate);

    Alumno* nuevo = new Alumno(id, firstname, lastName, major, enrollmentDate);
    cabezaAlum = new NodoAlumno{nuevo,cabezaAlum};
    cout << "Alumno registrado con exito ";
}

void buscarAlumno() {
    if (cabezaAlum==nullptr) {
        cout<<"No hay alumnos registrados";
        return;
    }
    int opcion;
    cout << "Buscar por: "
            "1) ID \n"
            "2) Nombre \n "
            "Opcion:";
    while (true) {
        if (cin>>opcion&&(opcion==1||opcion==2)) {
            cin.ignore(1000,'\n');
            break;
        }
        cout << "Opcion invalida. Escribe 1 o 2 ";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    //id
    if (opcion==1) {
        string id;
        do {
            cout << "Ingrese el id: ";
            getline(cin, id);
            if (id.empty()) {
                cout << "El Id no puede ser vacio";
            }
        }while (id.empty());
        bool encontrado = false;
        for (NodoAlumno* i = cabezaAlum;i!=nullptr;i=i->next) {
            if (i->infoAlum->getId()==id) {
                cout << "Alumno encontrado con exito ";
                cout<<"ID:"<<i->infoAlum->getId()<<endl;
                cout<<"Nombre:"<<i->infoAlum->getFirstName()<<" "<<i->infoAlum->getLastName()<<endl;
                cout<<"Carrera:"<<i->infoAlum->getMajor()<<endl;
                cout<<"Fecha de ingreso:"<<i->infoAlum->getEnrollmentDate()<<endl;
                encontrado = true;
                break;

            }

        }
        if (!encontrado) {
            cout << "No se encontro ningun alumno con ese ID";
        }
    }else if (opcion==2) {
        string nom;
        do {
            cout << "Ingrese el nombre: ";
            getline(cin, nom);
            if (nom.empty()) {
                cout << "El nombre no puede ser vacio";
            }
        }while (nom.empty());
        bool encontrado2 = false;
        for (NodoAlumno* i = cabezaAlum;i!=nullptr;i=i->next) {
            if (i->infoAlum->getFirstName()==nom) {
                cout << "Alumno encontrado con exito ";
                cout<<"ID:"<<i->infoAlum->getId()<<endl;
                cout<<"Nombre:"<<i->infoAlum->getFirstName()<<" "<<i->infoAlum->getLastName()<<endl;
                cout<<"Carrera:"<<i->infoAlum->getMajor()<<endl;
                cout<<"Fecha de ingreso:"<<i->infoAlum->getEnrollmentDate()<<endl;
                encontrado2 = true;
                break;

            }
        }
        if (!encontrado2) {
            cout<<"No se encontro ningun alumno con ese nombre ";
        }
    }

//no olvidar cambiar el buscar alumno con funciones mas pequeñas para poder reutilizar en otras funciones
////y tmb hacer funcion de el lista de nombres repetidos


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