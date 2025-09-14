#include "Arvore.hpp"

// Construtor
ArvoreBST::ArvoreBST() : raiz(nullptr) {}

// Destrutor
ArvoreBST::~ArvoreBST() {
    destruirArvore(raiz);
}

// Destruir árvore recursivamente
void ArvoreBST::destruirArvore(NoArvore* no) {
    if (no != nullptr) {
        destruirArvore(no->esquerda);
        destruirArvore(no->direita);
        delete no;
    }
}

// Inserir jogador na árvore
void ArvoreBST::inserir(Jogador jogador) {
    cout << "Inserindo jogador " << jogador.nome << " com " << jogador.pontuacao << " pontos na arvore..." << endl;
    raiz = inserirRecursivo(raiz, jogador);
}

// Inserção recursiva
NoArvore* ArvoreBST::inserirRecursivo(NoArvore* no, Jogador jogador) {
    // Caso base: posição vazia encontrada
    if (no == nullptr) {
        return new NoArvore(jogador);
    }
    
    // Inserir à esquerda se pontuação for menor
    if (jogador.pontuacao < no->jogador.pontuacao) {
        no->esquerda = inserirRecursivo(no->esquerda, jogador);
    }
    // Inserir à direita se pontuação for maior ou igual
    else {
        no->direita = inserirRecursivo(no->direita, jogador);
    }
    
    return no;
}

// Obter ranking em ordem crescente (percurso in-ordem)
int ArvoreBST::obterRankingCrescente(Jogador lista[], int maxSize) {
    int indice = 0;
    percorrerInOrdemRecursivo(raiz, lista, indice, maxSize);
    return indice;
}

// Obter ranking em ordem decrescente 
int ArvoreBST::obterRankingDecrescente(Jogador lista[], int maxSize) {
    int tamanho = obterRankingCrescente(lista, maxSize);
    
    // Inverter a ordem manualmente (sem usar algorithm)
    for(int i = 0; i < tamanho / 2; i++) {
        Jogador temp = lista[i];
        lista[i] = lista[tamanho - 1 - i];
        lista[tamanho - 1 - i] = temp;
    }
    
    return tamanho;
}

// Percorrimento in-ordem recursivo
void ArvoreBST::percorrerInOrdemRecursivo(NoArvore* no, Jogador lista[], int& indice, int maxSize) {
    if (no != nullptr && indice < maxSize) {
        percorrerInOrdemRecursivo(no->esquerda, lista, indice, maxSize);
        if(indice < maxSize) {
            lista[indice++] = no->jogador;
        }
        percorrerInOrdemRecursivo(no->direita, lista, indice, maxSize);
    }
}

// Verificar se árvore está vazia
bool ArvoreBST::vazia() {
    return raiz == nullptr;
}

// Contar número de nós
int ArvoreBST::tamanho() {
    return contarNos(raiz);
}

int ArvoreBST::contarNos(NoArvore* no) {
    if (no == nullptr) {
        return 0;
    }
    return 1 + contarNos(no->esquerda) + contarNos(no->direita);
}

// Exibir estrutura da árvore
void ArvoreBST::exibirArvore() {
    if (vazia()) {
        cout << "Arvore vazia!" << endl;
        return;
    }
    
    cout << "\n=== ESTRUTURA DA ARVORE BST ===" << endl;
    cout << "Legenda: (Nome - Pontos)" << endl;
    exibirArvoreRecursivo(raiz, 0, "");
}

void ArvoreBST::exibirArvoreRecursivo(NoArvore* no, int nivel, string prefixo) {
    if (no != nullptr) {
        // Exibir nó direito primeiro (maior pontuação)
        exibirArvoreRecursivo(no->direita, nivel + 1, prefixo + "    ");
        
        // Exibir nó atual
        cout << prefixo;
        for (int i = 0; i < nivel; i++) {
            cout << "    ";
        }
        cout << "(" << no->jogador.nome << " - " << no->jogador.pontuacao << ")" << endl;
        
        // Exibir nó esquerdo (menor pontuação)
        exibirArvoreRecursivo(no->esquerda, nivel + 1, prefixo + "    ");
    }
}

// Exibir estatísticas da árvore
void ArvoreBST::exibirEstatisticas() {
    cout << "\n=== ESTATISTICAS DA ARVORE ===" << endl;
    cout << "Total de jogadores: " << tamanho() << endl;
    
    if (!vazia()) {
        const int MAX_JOGADORES = 100;
        Jogador ranking[MAX_JOGADORES];
        int tam = obterRankingDecrescente(ranking, MAX_JOGADORES);
        
        cout << "Maior pontuacao: " << ranking[0].pontuacao << " (" << ranking[0].nome << ")" << endl;
        cout << "Menor pontuacao: " << ranking[tam-1].pontuacao 
             << " (" << ranking[tam-1].nome << ")" << endl;
    }
}