#include <iostream>
#include "Alumno.h"
#include "Curso.h"
#include <string>
using namespace std;

void cosasGestionAlum();
     cout<<"Registrar alumno"<<endl;
     cout<<"Buscar alumno"<<endl;
     cout<<"Eliminar alumno"<<endl;


void cosasGestionCurso();

void inscribir();

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

                    break;
                case 5:
                    break;
                case 6:
                    opcion = -1;
                    break;
            }
        }

    return 0;
}