#ifndef JOGADOR_HPP
#define JOGADOR_HPP

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

#endif