
#include "Alumno.h"
#include "NodoMatricula.h"
#include "Lista.h"


Alumno::Alumno(string id, string firstname, string lastName, string major, string enrollmentDate) {
    this->id = id;
    this->nom = firstname;
    this->apellido = lastName;
    this->carrera = major;
    this->inscripcion = enrollmentDate;
}
int leerOp(int min,int max) {
    int opcion;
    while (!(cin >> opcion)||opcion<min || opcion>max) {
        cout << "Ingresa una opcion correcta "<<min<<" a "<<max << endl;
        cin.clear();
        cin.ignore(1000,'\n');
    }
    cin.ignore(1000,'\n');
    return opcion;
}

bool Alumno::borrarAlumnoDelistaPorId(const string & id) {
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

    delete actual;
    return true;
}

void Alumno::eliminarMatricula(Alumno * eliminarAlum) {
    NodoMatricula* actual = cabezaMatri;
    NodoMatricula* anterior = nullptr;

    while (actual!=nullptr) {
        if (actual->alumno==eliminarAlum) {
            NodoMatricula::borrarListaNotas(actual->notas);
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
void Alumno::printAlumEliminar(Alumno * alumno) {
    cout <<"ID:"<<alumno->getId()<<endl;
    cout << "Nombre:"<<alumno->getFirstName()<<endl;
    cout<<"Apellido:"<<alumno->getLastName()<<endl;
    cout << "Carrera:"<<alumno->getMajor()<<endl;
    cout << "Fecha:"<<alumno->getEnrollmentDate()<<endl;
    cout<<"\n";
}

bool Alumno::ConfirmarAlumnoPorNom(const string & nom) {
    for (NodoAlumno* i = cabezaAlum;i!=nullptr;i=i->next) {
        if (i->infoAlum->getFirstName()==nom) {
            return true;

        }
    }
    return false;
}

bool Alumno::alumnoPorNombre(const string& nom) {
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

bool Alumno:: confirmarAlumnoPorID(const string & id) {
    for (NodoAlumno* i = cabezaAlum;i!=nullptr;i=i->next) {
        if (i->infoAlum->getId()==id) {
            return true;
        }

    }
    return false;
}

Alumno* Alumno::obtenerAlumnoPorId(const string & id) {
    for (NodoAlumno* i = cabezaAlum;i!=nullptr;i=i->next) {
        if (i->infoAlum->getId()==id) {
            return i->infoAlum;
        }

    }
    return nullptr;
}

void Alumno::registrarAlumno() {
    cout<<"***Registro de alumnos***"<<endl;
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
    cabezaAlum = new NodoAlumno(nuevo,cabezaAlum);
    cout << "Alumno registrado con exito \n";
    cout<<"\n";
}

void Alumno::buscarAlumno() {
    if (cabezaAlum==nullptr) {
        cout<<"No hay alumnos registrados \n";
        cout<<"\n";
        return;
    }
    int opcion;
    cout << "Buscar por:\n"
            "1) ID \n"
            "2) Nombre \n "
            "Opcion:";
    opcion = leerOp(1,2);
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
            cout<<"\n";
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
            cout<<"\n";
        }
    }

    //no olvidar cambiar el buscar alumno con funciones mas pequeñas para poder reutilizar en otras funciones
    ////y tmb hacer funcion de el lista de nombres repetidos


}

void Alumno::eliminarAlumno() {
    cout<<"***Eliminacion de alumnos***"<<endl;
    if (cabezaAlum==nullptr) {
        cout << "No hay alumnos registrados \n ";
        cout<<"\n";
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
        cout<<"\n";
    }
}







string Alumno::getId() {
    return id;
}
string Alumno::getFirstName()  {
    return nom;
}
string Alumno::getLastName() {
    return apellido;
}
string Alumno::getMajor() {
    return carrera;
}
string Alumno::getEnrollmentDate() {
    return inscripcion;
}
