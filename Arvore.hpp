#ifndef ARVORE_HPP
#define ARVORE_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Estrutura do Jogador (mesmo do main.cpp)
struct Jogador {
    string nome;
    int pontuacao;
    
    Jogador(string n = "", int p = 0) : nome(n), pontuacao(p) {}
    
    // Operadores para comparação
    bool operator>(const Jogador& outro) const {
        return pontuacao > outro.pontuacao;
    }
    
    bool operator<(const Jogador& outro) const {
        return pontuacao < outro.pontuacao;
    }
    
    bool operator==(const Jogador& outro) const {
        return pontuacao == outro.pontuacao;
    }
};

// Nó da Árvore BST
struct NoArvore {
    Jogador jogador;
    NoArvore* esquerda;
    NoArvore* direita;
    
    NoArvore(Jogador j) : jogador(j), esquerda(nullptr), direita(nullptr) {}
};

// TAD Árvore BST para Ranking
class ArvoreBST {
private:
    NoArvore* raiz;
    
    // Métodos auxiliares privados
    NoArvore* inserirRecursivo(NoArvore* no, Jogador jogador);
    void percorrerInOrdemRecursivo(NoArvore* no, vector<Jogador>& lista);
    void destruirArvore(NoArvore* no);
    void exibirArvoreRecursivo(NoArvore* no, int nivel, string prefixo);
    int contarNos(NoArvore* no);
    
public:
    // Construtor e Destrutor
    ArvoreBST();
    ~ArvoreBST();
    
    // Operações principais
    void inserir(Jogador jogador);
    vector<Jogador> obterRankingDecrescente();
    vector<Jogador> obterRankingCrescente();
    void exibirArvore();
    bool vazia();
    int tamanho();
    
    // Métodos para demonstrar funcionamento da árvore
    void exibirEstatisticas();
};

#endif