#ifndef PERGUNTA_HPP
#define PERGUNTA_HPP

#include <iostream>
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
    int numAlternativas;
    
    // Construtor
    Pergunta();
    Pergunta(string e, string alt[], int resp, string cat, int pts, int dif);
    
    // Métodos para gerenciar alternativas
    void adicionarAlternativa(string alt);
    string obterAlternativa(int indice) const;
    int numeroAlternativas() const;
};

// Classe para gerenciar o banco de perguntas
class BancoPerguntas {
private:
    static const int MAX_PERGUNTAS = 20;
    Pergunta perguntas[MAX_PERGUNTAS];
    int totalPerguntas;
    
public:
    BancoPerguntas();
    void inicializarPerguntas();
    void embaralharPerguntas();
    Pergunta obterPergunta(int indice) const;
    int numeroPerguntas() const;
    void obterPerguntasAleatorias(Pergunta* resultado, int quantidade);
};

#endif