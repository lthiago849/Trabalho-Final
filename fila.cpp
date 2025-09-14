#include "fila.hpp"

// Construtor
FilaPerguntas::FilaPerguntas() : frente(0), tras(0), tamanho(0) {}

bool FilaPerguntas::vazia() { 
    return tamanho == 0; 
}

bool FilaPerguntas::cheia() { 
    return tamanho == MAX_SIZE; 
}

void FilaPerguntas::enfileirar(Pergunta p) {
    if(!cheia()) {
        dados[tras] = p;
        tras = (tras + 1) % MAX_SIZE;
        tamanho++;
    }
}

Pergunta FilaPerguntas::desenfileirar() {
    if(!vazia()) {
        Pergunta p = dados[frente];
        frente = (frente + 1) % MAX_SIZE;
        tamanho--;
        return p;
    }
    return Pergunta(); // retorna pergunta vazia se fila vazia
}

int FilaPerguntas::getTamanho() { 
    return tamanho; 
}

void FilaPerguntas::exibirStatusFila() {
    cout << "\n=== STATUS DA FILA ===" << endl;
    cout << "Tamanho atual: " << tamanho << endl;
    cout << "Posicao frente: " << frente << endl;
    cout << "Posicao tras: " << tras << endl;
    cout << "Fila vazia? " << (vazia() ? "Sim" : "Nao") << endl;
    cout << "Fila cheia? " << (cheia() ? "Sim" : "Nao") << endl;
}