#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>
#include <string>
#include "pergunta.hpp"
using namespace std;

// Implementação de uma fila usando array (ESTRUTURA DE DADOS PRINCIPAL)
class FilaPerguntas {
private:
    static const int MAX_SIZE = 20;
    Pergunta dados[MAX_SIZE];
    int frente;
    int tras;
    int tamanho;
    
public:
    FilaPerguntas();
    
    bool vazia();
    bool cheia();
    void enfileirar(Pergunta p);
    Pergunta desenfileirar();
    int getTamanho();
    void exibirStatusFila();
};

#endif