
#include "NodoCurso.h"
#include "curso.h"

NodoCurso::NodoCurso(Curso *curso, NodoCurso *sig)
    :infoCurso(curso),next(sig){}


NodoCurso::~NodoCurso() {
    delete infoCurso;
}
