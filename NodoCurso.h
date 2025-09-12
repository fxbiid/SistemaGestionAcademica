#pragma once
class Curso;


class NodoCurso {
    public:
    Curso* infoCurso;
    NodoCurso* next;


    NodoCurso(Curso*curso,NodoCurso*sig=nullptr);
    ~NodoCurso();
};


