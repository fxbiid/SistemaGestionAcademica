#include "ControlError.h"
#include<algorithm>
#include<cctype>
#include<string>


static bool esEspacio(char c) {
    return c== ' '||c=='\n';
}
bool validarId(const string &palabra) {
    if (palabra.empty()) {
        return false;
    }
    for (char c : palabra) {
        if (c==' ') {
            return false;
        }
        bool correcto = (isalnum(static_cast<unsigned char>(c))||c=='_'||c=='-');
        if (!correcto) {
            return false;
        }
    }
    return true;
}

string leerId(const string& palabra) {
    string id;
    do {
        cout<<palabra;
        getline(cin, id);
        if (!validarId(id)) {
            cout<<"El ID debe ser con guion puede incluir ( _ o -) y sin espacios \n";
            id.clear();
        }
    }while (id.empty());
    return id;
}
static string vaciosExtremos(const string &x) {
    if(x.empty()) return x;
    size_t i= 0, j= x.size();
    while (i<j&&esEspacio(x[i])) i++;
    while (j>i&&esEspacio(x[j-1])) j--;
    return x.substr(i,j-i);
}
static string espaciosMedios(const string &x) {
    string d;
    bool espacio = false;
    for (char c : x) {
        if (c== ' '||c=='\n') {
            if (!(espacio)) {
                d.push_back(' ');
                espacio = true;
            }
        }else {
            d.push_back(c);
            espacio = false;
        }
    }
    return d;
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
string cambiarAminus(const string &palabra) {
    string cambia = palabra;
    transform(cambia.begin(),cambia.end(),cambia.begin(),::tolower);
    return cambia;
}

string arreglarPalabra(const string &palabra) {
    string i = espaciosMedios(palabra);
    transform(i.begin(),i.end(),i.begin(),::tolower);

    bool ini=true;
    for (size_t k = 0; k < i.size(); ++k) {
        if (ini && isalpha((unsigned char)i[k])) {
            i[k] = (char)toupper((unsigned char)i[k]);
            ini=false;
        }

        else if (i[k]==' '||i[k]=='\n') {
            ini=true;
        }else {
            ini=false;
        }


    }
    return i;
}

string leerVacio(const string &palabra) {
    string vacio;
    do {
        cout<<palabra;
        getline(cin, vacio);
        vacio=vaciosExtremos(vacio);


    }while (vacio.empty());
    return vacio;
}

bool validarSoloEspaciosyLetras(const string &palabra) {
    if (palabra.empty()) return false;
    for (char c: palabra) {
        if (c==' ') {
            continue;
        }
        if (!isalpha((unsigned char)c)) { // isalpha para las tildes y ñ
            return false;
        }
    }
    return true;
}

string leerFecha(const string& palabra) {
while (true) {
    string fecha = leerVacio(palabra);
    if (!validarFecha(fecha)) {
        cout<<"Fecha invalida ingresa una fecha valida en day/month/year y con numeros reales \n";
        continue;
    }
    return fecha;
}
}

string leerNombre(const string& palabra) {
    while (true) {
        string nombre = leerVacio(palabra);
        if (!validarSoloEspaciosyLetras(nombre)) {
            cout<<"El nombre solo puede tener espacios y letras";
            continue;
        }
        return arreglarPalabra(nombre);
    }

}

string leerApellido(const string& palabra) {
while (true) {
    string apellido = leerVacio(palabra);
    if (!validarSoloEspaciosyLetras(apellido)) {
        cout<<"El apellido solo puede tener espacios y letras \n";
        continue;
    }
    return arreglarPalabra(apellido);
}
}
string leerCarrera(const string& palabra) {
    while (true) {
        string carre = leerVacio(palabra);
        if (!validarSoloEspaciosyLetras(carre)) {
            cout<<"La carrera solo puede tener espacios y letras";
            continue;
        }
        return arreglarPalabra(carre);
    }

}

static bool verificarBisiesto(int ye) {
    if (ye%400==0) {
        return true;
    }
    if (ye%100==0) {
        return false;
    }
    return ye%4==0;
}

bool validarFecha(const string &palabra) {
    int separador =0;
    for (char c: palabra) {
        if (c=='/') {
            separador++;
        }
        if (separador!=2) {
            return false;
        }

        size_t parte1 = palabra.find('/');
        size_t parte2 = palabra.find('/',parte1);
        if (parte1==string::npos||parte2==string::npos) {
            return false;
        }
        string dia = palabra.substr(0,parte1);
        string mes = palabra.substr(parte1+1,parte2-(parte1+1));
        string year = palabra.substr(parte2+1);
        if (dia.empty()||mes.empty()||year.empty()) {
            return false;
        }
        auto digitos = [](const string & x) {
          for (char c: x) {
              if (!isdigit((unsigned char)c)) return false;
              return true;
          }
        };
        if (!digitos(dia)||!digitos(mes)||!digitos(year)) {
            return false;
        }
        int di = stoi(dia);
        int me = stoi(mes);
        int ye = stoi(year);

        if (ye<1900||ye>2100) {
            return false;
        }
        if (me<1||me>12) {
            return false;
        }
        int diasMes;
        if (me==1||me==3||me==5||me==7||me==8||me==10||me==12) {
            diasMes = 31;
        }else if (me==4||me==6||me==9||me==11) {
            diasMes = 30;
        }else {
            diasMes = verificarBisiesto(ye) ? 29 : 28;

        }

        if (di<1||di>diasMes) {
            return false;
        }
        return true;
    }
}


