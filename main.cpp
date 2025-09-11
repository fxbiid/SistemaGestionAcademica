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
Nodonota* cabezaNota= nullptr;

bool alumnoPorNombre(const string& nom) {
    bool encontrado = false;
    for (NodoAlumno* i = cabezaAlum;i!=nullptr;i=i->next) {
        if (i->infoAlum->getFirstName()==nom) {
            cout << "Alumno encontrado con exito ";
            cout<<"ID:"<<i->infoAlum->getId()<<endl;
            cout<<"Nombre:"<<i->infoAlum->getFirstName()<<" "<<i->infoAlum->getLastName()<<endl;
            cout<<"Carrera:"<<i->infoAlum->getMajor()<<endl;
            cout<<"Fecha de ingreso:"<<i->infoAlum->getEnrollmentDate()<<endl;
            cout<<"\n";
            encontrado = true;
        }
    }
    return encontrado;
}
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
    cout << "Alumno registrado con exito \n";
}

void buscarAlumno() {
    if (cabezaAlum==nullptr) {
        cout<<"No hay alumnos registrados";
        return;
    }
    int opcion;
    cout << "Buscar por:\n"
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
                cout << "El Id no puede ser vacio \n ";
            }
        }while (id.empty());

        Alumno* encontradito = obtenerAlumnoPorId(id);
        if (encontradito!=nullptr) {
            cout << "Alumno encontrado con exito ";
            cout<<"ID:"<<encontradito->getId()<<endl;
            cout<<"Nombre:"<<encontradito->getFirstName()<<" "<<encontradito->getLastName()<<endl;
            cout<<"Carrera:"<<encontradito->getMajor()<<endl;
            cout<<"Fecha de ingreso:"<<encontradito->getEnrollmentDate()<<endl;
            cout<<"\n";
        }else {
            cout<<"No se encontro ningun alumno con ese ID \n ";
        }


    }else if (opcion==2) {
        string nom;
        do {
            cout << "Ingrese el nombre: ";
            getline(cin, nom);
            if (nom.empty()) {
                cout << "El nombre no puede ser vacio \n ";
            }
        }while (nom.empty());

        if (!alumnoPorNombre(nom)) {
            cout << "No se encontro ningun alumno con ese nombre \n ";
        }
    }

//no olvidar cambiar el buscar alumno con funciones mas pequeñas para poder reutilizar en otras funciones
////y tmb hacer funcion de el lista de nombres repetidos


}


void borrarListaNotas(Nodonota *&notas) {
    while (notas!=nullptr) {
        Nodonota* actual = notas;
        notas=notas->next;
        delete actual;
    }
}

void eliminarMatricula(Alumno * eliminarAlum) {
    NodoMatricula* actual = cabezaMatri;
    NodoMatricula* anterior = nullptr;

    while (actual!=nullptr) {
        if (actual->alumno==eliminarAlum) {
            borrarListaNotas(actual->notas);
            NodoMatricula* NodoEliminar = actual;
            //si el anterior es vacio es pq tenemos la cabeza como el que queremos eliminar
            if (anterior==nullptr) {
                cabezaMatri=actual->next;
            }else {
                //estamos al medio o al final
                anterior->next = actual->next;
            }
            // movemos el actual pq borraremos la apuntada anterior
          actual = actual->next;
            delete NodoEliminar;
        }else {
            //vamos guardando en el nodo que vamos pero en actual lo avanzamos a uno mas para ir moviendonos
            anterior = actual;
            actual = actual->next;
        }
    }
}

void printAlumEliminar(Alumno * alumno) {
    cout <<"ID:"<<alumno->getId()<<endl;
    cout << "Nombre:"<<alumno->getFirstName()<<endl;
    cout<<"Apellido:"<<alumno->getLastName()<<endl;
    cout << "Carrera:"<<alumno->getMajor()<<endl;
    cout << "Fecha:"<<alumno->getEnrollmentDate()<<endl;
}

bool borrarAlumnoDelistaPorId(const string & id) {
    NodoAlumno* actual = cabezaAlum;
    NodoAlumno* anterior = nullptr;
    while (actual!=nullptr) {
        if (actual->infoAlum->getId()==id) {
            break;
        }
        anterior = actual;
        actual = actual->next;

    }
    //no encontramos la id
    if (actual==nullptr) {
        return false;
    }

    if (anterior!=nullptr) {
        anterior->next = actual->next;
    }else {
        cabezaAlum=actual->next; //el else pasara si es q el que queremos borrar es la cabeza entonces movemos la cabeza
    }

    delete actual->infoAlum;
    delete actual;
    return true;
}

void eliminarAlumno() {
    if (cabezaAlum==nullptr) {
        cout << "No hay alumnos registrados \n ";
        return;
    }
    string id;
    do {
        cout << "Ingrese el id que quiere eliminar: \n ";
        getline(cin, id);
        if (id.empty()) {
            cout << "El id no puede ser vacio \n ";
        }
    }while (id.empty());

    Alumno * x = obtenerAlumnoPorId(id);
    if (x!=nullptr) {
        cout << "Alumno a eliminar: \n ";
        printAlumEliminar(x);
        eliminarMatricula(x);


        if (borrarAlumnoDelistaPorId(id)) {
            cout << "Informacion de alumno eliminadas \n";
            cout << "\n ";
        }

    }else {
        cout << "No se encontro el alumno a eliminar \n";
    }
}



void cosasGestionAlum() {
    int Esco = 0;
    while (Esco != -1) {
        cout<<"***Gestion alumnos***"<<endl;
        cout<<"1.Registrar alumno"<<endl;
        cout<<"2.Buscar alumno"<<endl;
        cout<<"3.Eliminar alumno"<<endl;
        cout<<"4.Volver menu principal"<<endl;
        cout<<"Escoge una opcion: ";
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
                    cout<<"Programa finalizado";
                    break;
            }
        }

    return 0;
}