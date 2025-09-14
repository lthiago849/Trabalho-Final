#ifndef PERGUNTA_HPP
#define PERGUNTA_HPP

#include <string>
using namespace std;

// Estrutura da Pergunta
struct Pergunta {
    string enunciado;
    string alternativas[4]; // Array fixo de 4 alternativas
    int respostaCorreta;
    string categoria;
    int pontos;
    int dificuldade; // 1=fácil, 2=médio, 3=difícil
    
    // Construtor padrão
    Pergunta() : enunciado(""), respostaCorreta(0), categoria(""), pontos(0), dificuldade(1) {
        for(int i = 0; i < 4; i++) {
            alternativas[i] = "";
        }
    }
    
    // Construtor com parâmetros
    Pergunta(string e, string alt[4], int resp, string cat, int pts, int dif) 
        : enunciado(e), respostaCorreta(resp), categoria(cat), pontos(pts), dificuldade(dif) {
        for(int i = 0; i < 4; i++) {
            alternativas[i] = alt[i];
        }
    }
};

#endif