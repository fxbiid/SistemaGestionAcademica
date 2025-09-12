#pragma once
#include <string>
using namespace std;
class Curso {
    private:
    string id;
    string name;
    int cantMaxStudents;
    string carrera;
    string profe;
    public:
    Curso(string id,string name,int cantMaxStudents,string carrera,string profe);
    static void crearCurso();
    static bool cursoPorNombre(const string & nom);
    static void buscarCurso();
    static void printCursoEliminar(Curso * curso);
    static void eliminarMatriculaDeCurso(Curso * cursoElim);
    static bool borrarCursoDelistaPorId(const string & id);
    static void eliminarCurso();
    static bool confirmarCursoPorId(const string & id);
    static Curso* obtenerCursoPorId(const string & id);
    string getId();
    string getName();
    int getCantMaxStudents();
    string getCarrera();
    string getProfe();

};
