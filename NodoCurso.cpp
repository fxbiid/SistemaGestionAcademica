
#include "NodoCurso.h"
#include "Curso.h"

NodoCurso::NodoCurso(Curso *curso, NodoCurso *sig)
    :infoCurso(curso),next(sig){}


NodoCurso::~NodoCurso() {
    delete infoCurso;
}
