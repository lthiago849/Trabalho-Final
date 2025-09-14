#ifndef QUIZ_HPP
#define QUIZ_HPP

#include <iostream>
#include <string>
#include "jogador.hpp"
#include "pergunta.hpp"
#include "fila.hpp"

using namespace std;

// Classe principal do Quiz
class QuizEstruturaDados {
private:
    static const int MAX_PERGUNTAS = 15;
    static const int MAX_JOGADORES = 50;
    Pergunta bancoPerguntas[MAX_PERGUNTAS];
    int totalPerguntas;
    Jogador rankingJogadores[MAX_JOGADORES];
    int totalJogadores;
    
    void inicializarPerguntas();
    void embaralharPerguntas();
    void mergeSort(Jogador arr[], int inicio, int fim);
    void merge(Jogador arr[], int inicio, int meio, int fim);
    void adicionarJogadorRanking(Jogador novoJogador);
    void demonstrarOrdenacao(Jogador jogadores[], int tamanho);
    
public:
    QuizEstruturaDados();
    void executar();
    void exibirMenu();
    void jogarQuiz();
    void exibirRanking();
    void demonstrarFila();
    void sobreOJogo();
};

#endif