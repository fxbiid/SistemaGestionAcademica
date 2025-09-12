#include "Curso.h"
#include "Lista.h"
#include "NodoMatricula.h"

Curso::Curso(string id, string name, int cantMaxStudents, string carrera, string profe) {
    this->id = id;
    this->name = name;
    this->cantMaxStudents = cantMaxStudents;
    this->carrera = carrera;
    this->profe = profe;
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

Curso* Curso::obtenerCursoPorId(const string & id) {
    for (NodoCurso* i = cabezaCurso;i!=nullptr;i=i->next) {
        if (i->infoCurso->getId()==id) {
            return i->infoCurso;
        }
    }
    return nullptr;
}

bool Curso::confirmarCursoPorId(const string & id) {
    for (NodoCurso*i = cabezaCurso;i!=nullptr;i=i->next) {
        if (i->infoCurso->getId()==id) {
            return true;
        }
    }
    return false;
}
void Curso::crearCurso() {
    cout<<"***Creacion de cursos***"<<endl;
    cin.ignore(1000,'\n');
    string id,nom,carrera,profe;
    int cantMaxEstu;
    cout << "Ingrese el codigo del curso: ";
    getline(cin,id);
    //preguntamos si existe ya ese codigo
    if (confirmarCursoPorId(id)) {
        cout << "El ID ya existe en un curso";
    }

    cout << "Ingrese el nombre del curso: ";
    getline(cin,nom);
    cout << "Ingrese el cupo maximo de estudiantes: ";
    while (!(cin>>cantMaxEstu)||cantMaxEstu<=0) {
        cout<<"Ingrese un cupo mayor a 0";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    cin.ignore(1000,'\n');
    cout << "Ingrese el carrera del curso: ";
    getline(cin,carrera);
    cout << "Ingrese el profe: ";
    getline(cin,profe);

    Curso* nuevo = new Curso(id,nom,cantMaxEstu,carrera,profe);
    cabezaCurso = new NodoCurso(nuevo,cabezaCurso);
    cout << "El curso se creo exitosamente \n";
    cout<<"\n";
}


bool Curso:: cursoPorNombre(const string & nom) {
    bool encontrado = false;
    for (NodoCurso*i = cabezaCurso;i!=nullptr;i=i->next) {
        if (i->infoCurso->getName()==nom) {
            cout<<"ID:"<<i->infoCurso->getId()<<endl;
            cout<<"Nombre:"<<i->infoCurso->getName()<<endl;
            cout<<"Cupo:"<<i->infoCurso->getCantMaxStudents()<<endl;
            cout<<"Carrera:"<<i->infoCurso->getCarrera()<<endl;
            cout<<"Profesor:"<<i->infoCurso->getProfe()<<endl;
            cout<<"\n";
            encontrado = true;
        }
    }
    return encontrado;
}

void Curso:: buscarCurso() {
    if (cabezaCurso==nullptr) {
        cout << "No hay cursos registrados";
        cout<<"\n";
        return;
    }

    int opcion;
    cout<<"Buscar curso: \n"
          "1) ID \n"
          "2) Nombre \n"
          "Opcion: ";
    opcion = leerOp(1,2);
    if (opcion==1) {
        string id;
        do {
            cout<<"ingrese el id: ";
            getline(cin,id);
            if (id.empty()) {
                cout << "El ID no puede ser vacio";
                cin.clear();
                cin.ignore(1000,'\n');
            }
        }while (id.empty());

        Curso* encon = obtenerCursoPorId(id);
        if (encon!=nullptr) {
            cout << "Curso encontrado con exito \n ";
            cout<<"ID:"<<encon->getId()<<endl;
            cout<<"Nombre:"<<encon->getName()<<endl;
            cout<<"Cupo:"<<encon->getCantMaxStudents()<<endl;
            cout<<"Carrera:"<<encon->getCarrera()<<endl;
            cout<<"Profesor:"<<encon->getProfe()<<endl;
            cout<<"\n";
        }else {
            cout<<"No se encontro ningun curso con ese ID \n ";
            cout<<"\n";
        }
    }else if(opcion==2) {
        string nom;
        do {
            cout << "Ingrese el nombre: ";
            getline(cin, nom);
            if (nom.empty()) {
                cout << "El nombre no puede ser vacio \n ";
                cin.clear();
                cin.ignore(1000,'\n');
            }
        }while (nom.empty());

        if (!cursoPorNombre(nom)) {
            cout << "No se encontro ningun curso con ese nombre \n ";
            cout<<"\n";
        }
    }
}

void Curso::printCursoEliminar(Curso * curso) {
    cout << "Curso a eliminar: \n ";
    cout <<"ID:"<<curso->getId() << endl;
    cout <<"Nombre:"<<curso->getName() << endl;
    cout<<"Cupo:"<<curso->getCantMaxStudents() << endl;
    cout<<"Carrera:"<<curso->getCarrera() << endl;
    cout<<"Profesor:"<<curso->getProfe() << endl;
    cout<<"\n";
}

void Curso::eliminarMatriculaDeCurso(Curso * cursoElim) {
    NodoMatricula* actual = cabezaMatri;
    NodoMatricula* anterior = nullptr;

    while (actual!=nullptr) {
        if (actual->curso==cursoElim) {
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
bool Curso::borrarCursoDelistaPorId(const string & id) {
    NodoCurso* actual = cabezaCurso;
    NodoCurso* anterior = nullptr;
    while (actual!=nullptr) {
        if (actual->infoCurso->getId()==id) {
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
        cabezaCurso=actual->next; //el else pasara si es q el que queremos borrar es la cabeza entonces movemos la cabeza
    }
    delete actual;
    return true;

}

void Curso::eliminarCurso() {
    if (cabezaCurso==nullptr) {
        cout << "No hay cursos registrados";
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

    Curso * cursito = obtenerCursoPorId(id);
    if (cursito!=nullptr) {

        printCursoEliminar(cursito);
        eliminarMatriculaDeCurso(cursito);


        if (borrarCursoDelistaPorId(id)) {
            cout << "Informacion del curso eliminada \n";
            cout << "\n ";
        }

    }else {
        cout << "No se encontro el curso a eliminar \n";
        cout<<"\n";
    }
}
string Curso::getId() {
    return id;
}
string Curso::getName() {
    return name;
}
int Curso::getCantMaxStudents() {
    return cantMaxStudents;
}
string Curso::getCarrera() {
    return carrera;
}
string Curso::getProfe() {
    return profe;
}

