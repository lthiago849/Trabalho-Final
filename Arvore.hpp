#ifndef ARVORE_HPP
#define ARVORE_HPP

#include <iostream>
#include <string>
using namespace std;

// Estrutura do Jogador
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
    void percorrerInOrdemRecursivo(NoArvore* no, Jogador lista[], int& indice, int maxSize);
    void destruirArvore(NoArvore* no);
    void exibirArvoreRecursivo(NoArvore* no, int nivel, string prefixo);
    int contarNos(NoArvore* no);
    
public:
    // Construtor e Destrutor
    ArvoreBST();
    ~ArvoreBST();
    
    // Operações principais
    void inserir(Jogador jogador);
    int obterRankingDecrescente(Jogador lista[], int maxSize);
    int obterRankingCrescente(Jogador lista[], int maxSize);
    void exibirArvore();
    bool vazia();
    int tamanho();
    
    // Métodos para demonstrar funcionamento da árvore
    void exibirEstatisticas();
};

#endif