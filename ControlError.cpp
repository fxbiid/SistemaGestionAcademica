#include "ControlError.h"


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