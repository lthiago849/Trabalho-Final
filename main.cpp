#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "Arvore.hpp"

using namespace std;

// Estrutura da Pergunta
struct Pergunta {
    string enunciado;
    vector<string> alternativas;
    int respostaCorreta;
    string categoria;
    int pontos;
    int dificuldade; // 1=fácil, 2=médio, 3=difícil
};

// Classe principal do Quiz
class QuizEstruturaDados {
private:
    vector<Pergunta> bancoPerguntas;
    ArvoreBST* arvoreRanking;
    stack<Pergunta> historicoPerguntas; // pilha para histórico
    
    void inicializarPerguntas();
    void embaralharPerguntas(vector<Pergunta>& perguntas);
    
public:
    QuizEstruturaDados();
    ~QuizEstruturaDados();
    
    void exibirMenu();
    void jogarQuiz();
    void exibirRanking();
    void demonstrarOrdenacao(vector<Jogador>& jogadores);
    void sobreOJogo();
    void executar();
};

// Construtor
QuizEstruturaDados::QuizEstruturaDados() {
    arvoreRanking = new ArvoreBST();
    inicializarPerguntas();
    srand(time(0)); // semente para números aleatórios
}

// Destrutor
QuizEstruturaDados::~QuizEstruturaDados() {
    delete arvoreRanking;
}

// Inicializar banco de perguntas
void QuizEstruturaDados::inicializarPerguntas() {
    bancoPerguntas.clear();
    
    // Perguntas sobre Listas
    bancoPerguntas.push_back({
        "Qual a principal vantagem das listas ligadas sobre arrays?",
        {"Acesso mais rapido aos elementos", "Tamanho dinamico", "Menor uso de memoria", "Ordenacao automatica"},
        1, "Listas", 10, 1
    });
    
    bancoPerguntas.push_back({
        "Em uma lista duplamente ligada, cada no possui:",
        {"Apenas ponteiro para o proximo", "Ponteiros para anterior e proximo", "Apenas dados", "Array de ponteiros"},
        1, "Listas", 15, 2
    });
    
    // Perguntas sobre Pilhas
    bancoPerguntas.push_back({
        "Em uma pilha, qual elemento e removido primeiro?",
        {"O primeiro inserido (FIFO)", "O ultimo inserido (LIFO)", "O do meio", "Qualquer um"},
        1, "Pilhas", 10, 1
    });
    
    bancoPerguntas.push_back({
        "Qual operacao NAO e tipica de uma pilha?",
        {"Push (empilhar)", "Pop (desempilhar)", "Top (topo)", "Search (buscar no meio)"},
        3, "Pilhas", 15, 2
    });
    
    // Perguntas sobre Filas
    bancoPerguntas.push_back({
        "O principio de funcionamento de uma fila e:",
        {"LIFO (Last In, First Out)", "FIFO (First In, First Out)", "Random Access", "FILO (First In, Last Out)"},
        1, "Filas", 10, 1
    });
    
    bancoPerguntas.push_back({
        "Em uma fila circular, quando ela esta cheia:",
        {"Rear aponta para Front", "(Rear + 1) % size == Front", "Rear > Front", "Front == 0"},
        1, "Filas", 20, 3
    });
    
    // Perguntas sobre Árvores
    bancoPerguntas.push_back({
        "Qual a complexidade de busca em uma arvore binaria balanceada?",
        {"O(n)", "O(log n)", "O(n^2)", "O(1)"},
        1, "Arvores", 15, 2
    });
    
    bancoPerguntas.push_back({
        "No percurso in-ordem de uma BST, os elementos sao visitados:",
        {"Em ordem crescente", "Em ordem decrescente", "Aleatoriamente", "Por nivel"},
        0, "Arvores", 20, 3
    });
    
    bancoPerguntas.push_back({
        "Uma arvore binaria completa com altura h tem quantos nos?",
        {"2^h", "2^h - 1", "2^(h+1) - 1", "h^2"},
        2, "Arvores", 25, 3
    });
    
    // Perguntas sobre Algoritmos
    bancoPerguntas.push_back({
        "Qual algoritmo de ordenacao tem complexidade O(n log n) no melhor caso?",
        {"Bubble Sort", "Selection Sort", "Merge Sort", "Insertion Sort"},
        2, "Algoritmos", 15, 2
    });
    
    bancoPerguntas.push_back({
        "O Quick Sort tem complexidade de pior caso:",
        {"O(n log n)", "O(n^2)", "O(log n)", "O(n)"},
        1, "Algoritmos", 20, 3
    });
    
    bancoPerguntas.push_back({
        "Qual estrutura de dados e mais eficiente para implementar uma fila de prioridades?",
        {"Array", "Lista ligada", "Heap", "Stack"},
        2, "Algoritmos", 25, 3
    });
    
    cout << "Banco de perguntas inicializado com " << bancoPerguntas.size() << " perguntas!" << endl;
}

// Embaralhar perguntas
void QuizEstruturaDados::embaralharPerguntas(vector<Pergunta>& perguntas) {
    random_shuffle(perguntas.begin(), perguntas.end());
}

// Exibir menu principal
void QuizEstruturaDados::exibirMenu() {
    cout << "\n╔══════════════════════════════════════╗" << endl;
    cout << "║     QUIZ - ESTRUTURAS DE DADOS       ║" << endl;
    cout << "║          UFPA - 2024                 ║" << endl;
    cout << "╠══════════════════════════════════════╣" << endl;
    cout << "║  1. 🎮 Jogar Quiz                    ║" << endl;
    cout << "║  2. 🏆 Ver Ranking                   ║" << endl;
    cout << "║  3. 🌳 Visualizar Arvore             ║" << endl;
    cout << "║  4. ℹ️  Sobre o Jogo                  ║" << endl;
    cout << "║  5. 🚪 Sair                          ║" << endl;
    cout << "╚══════════════════════════════════════╝" << endl;
    cout << "Escolha uma opcao (1-5): ";
}

// Função principal para jogar
void QuizEstruturaDados::jogarQuiz() {
    cout << "\n=== INICIANDO QUIZ ===" << endl;
    
    string nomeJogador;
    cout << "Digite seu nome: ";
    cin.ignore();
    getline(cin, nomeJogador);
    
    // Selecionar perguntas aleatórias
    vector<Pergunta> perguntasJogo = bancoPerguntas;
    embaralharPerguntas(perguntasJogo);
    
    // Limitar a 8 perguntas para não ficar muito longo
    if (perguntasJogo.size() > 8) {
        perguntasJogo.resize(8);
    }
    
    // Usar fila para sequência de perguntas
    queue<Pergunta> filaPerguntas;
    for (const auto& p : perguntasJogo) {
        filaPerguntas.push(p);
    }
    
    Jogador jogador(nomeJogador, 0);
    int numeroPergunta = 1;
    int acertos = 0;
    
    cout << "\n🎯 Voce tera " << filaPerguntas.size() << " perguntas para responder!" << endl;
    cout << "Pressione ENTER para comecar...";
    cin.get();
    
    while (!filaPerguntas.empty()) {
        system("clear || cls"); // Limpar tela (funciona no Linux/Mac e Windows)
        
        Pergunta perguntaAtual = filaPerguntas.front();
        filaPerguntas.pop();
        historicoPerguntas.push(perguntaAtual); // Adicionar ao histórico
        
        cout << "\n" << string(50, '=') << endl;
        cout << "PERGUNTA " << numeroPergunta << "/" << perguntasJogo.size() << endl;
        cout << "Categoria: " << perguntaAtual.categoria << " | ";
        cout << "Dificuldade: " << string(perguntaAtual.dificuldade, '⭐') << endl;
        cout << "Pontos: " << perguntaAtual.pontos << endl;
        cout << string(50, '=') << endl;
        
        cout << "\n📝 " << perguntaAtual.enunciado << endl << endl;
        
        for (int i = 0; i < perguntaAtual.alternativas.size(); i++) {
            cout << "  " << (char)('A' + i) << ") " << perguntaAtual.alternativas[i] << endl;
        }
        
        cout << "\nSua resposta (A/B/C/D): ";
        char resposta;
        cin >> resposta;
        resposta = toupper(resposta);
        int indiceResposta = resposta - 'A';
        
        cout << "\n" << string(30, '-') << endl;
        
        if (indiceResposta == perguntaAtual.respostaCorreta) {
            cout << "✅ CORRETO! +" << perguntaAtual.pontos << " pontos" << endl;
            jogador.pontuacao += perguntaAtual.pontos;
            acertos++;
        } else {
            cout << "❌ ERRADO! A resposta correta era: " 
                 << (char)('A' + perguntaAtual.respostaCorreta) << ") "
                 << perguntaAtual.alternativas[perguntaAtual.respostaCorreta] << endl;
        }
        
        cout << "Pontuacao atual: " << jogador.pontuacao << " pontos" << endl;
        
        numeroPergunta++;
        
        if (!filaPerguntas.empty()) {
            cout << "\nPressione ENTER para a proxima pergunta...";
            cin.ignore();
            cin.get();
        }
    }
    
    // Resultados finais
    cout << "\n" << string(60, '=') << endl;
    cout << "🎊 QUIZ FINALIZADO! 🎊" << endl;
    cout << string(60, '=') << endl;
    cout << "Jogador: " << jogador.nome << endl;
    cout << "Acertos: " << acertos << "/" << perguntasJogo.size() << endl;
    cout << "Pontuacao Final: " << jogador.pontuacao << " pontos" << endl;
    
    double percentual = (double)acertos / perguntasJogo.size() * 100;
    cout << "Aproveitamento: " << fixed << setprecision(1) << percentual << "%" << endl;
    
    // Classificação
    if (percentual >= 80) cout << "🏆 Excelente!" << endl;
    else if (percentual >= 60) cout << "👍 Bom trabalho!" << endl;
    else if (percentual >= 40) cout << "📚 Continue estudando!" << endl;
    else cout << "💪 Nao desista, pratique mais!" << endl;
    
    // Inserir na árvore de ranking
    cout << "\n🌳 Inserindo no ranking..." << endl;
    arvoreRanking->inserir(jogador);
    
    cout << "\nPressione ENTER para voltar ao menu...";
    cin.ignore();
    cin.get();
}

// Demonstrar algoritmo de ordenação
void QuizEstruturaDados::demonstrarOrdenacao(vector<Jogador>& jogadores) {
    if (jogadores.size() <= 1) return;
    
    cout << "\n🔄 DEMONSTRACAO DO MERGE SORT - ORDENACAO DO RANKING" << endl;
    cout << string(60, '-') << endl;
    
    cout << "Estado inicial:" << endl;
    for (int i = 0; i < jogadores.size(); i++) {
        cout << jogadores[i].nome << "(" << jogadores[i].pontuacao << ") ";
    }
    cout << endl << endl;
    
    // Implementação simplificada do Merge Sort com visualização
    function<void(vector<Jogador>&, int, int)> mergeSort = [&](vector<Jogador>& arr, int inicio, int fim) {
        if (inicio < fim) {
            int meio = inicio + (fim - inicio) / 2;
            
            cout << "Dividindo: [" << inicio << ".." << meio << "] e [" << (meio+1) << ".." << fim << "]" << endl;
            
            mergeSort(arr, inicio, meio);
            mergeSort(arr, meio + 1, fim);
            
            // Merge
            vector<Jogador> temp(fim - inicio + 1);
            int i = inicio, j = meio + 1, k = 0;
            
            while (i <= meio && j <= fim) {
                if (arr[i].pontuacao >= arr[j].pontuacao) {
                    temp[k++] = arr[i++];
                } else {
                    temp[k++] = arr[j++];
                }
            }
            
            while (i <= meio) temp[k++] = arr[i++];
            while (j <= fim) temp[k++] = arr[j++];
            
            for (i = inicio, k = 0; i <= fim; i++, k++) {
                arr[i] = temp[k];
            }
            
            cout << "Merged [" << inicio << ".." << fim << "]: ";
            for (int x = inicio; x <= fim; x++) {
                cout << arr[x].nome << "(" << arr[x].pontuacao << ") ";
            }
            cout << endl;
        }
    };
    
    mergeSort(jogadores, 0, jogadores.size() - 1);
    
    cout << "\n✅ Ordenacao concluida!" << endl;
    cout << "Estado final (ordem decrescente de pontuacao):" << endl;
    for (const auto& j : jogadores) {
        cout << j.nome << "(" << j.pontuacao << ") ";
    }
    cout << endl;
}

// Exibir ranking
void QuizEstruturaDados::exibirRanking() {
    cout << "\n🏆 RANKING DOS JOGADORES 🏆" << endl;
    
    if (arvoreRanking->vazia()) {
        cout << "Nenhum jogador no ranking ainda. Jogue para aparecer aqui!" << endl;
        return;
    }
    
    // Obter ranking da árvore
    vector<Jogador> ranking = arvoreRanking->obterRankingDecrescente();
    
    // Demonstrar algoritmo de ordenação
    cout << "\nDeseja ver a demonstracao do algoritmo de ordenacao? (s/n): ";
    char opcao;
    cin >> opcao;
    if (tolower(opcao) == 's') {
        vector<Jogador> copia = ranking;
        // Embaralhar para mostrar a ordenação
        random_shuffle(copia.begin(), copia.end());
        demonstrarOrdenacao(copia);
    }
    
    cout << "\n" << string(50, '=') << endl;
    cout << "RANKING FINAL" << endl;
    cout << string(50, '=') << endl;
    
    for (int i = 0; i < ranking.size(); i++) {
        string medalha = "";
        if (i == 0) medalha = "🥇";
        else if (i == 1) medalha = "🥈";
        else if (i == 2) medalha = "🥉";
        else medalha = "  ";
        
        cout << medalha << " " << setw(2) << (i + 1) << "º lugar: " 
             << setw(15) << left << ranking[i].nome 
             << setw(4) << right << ranking[i].pontuacao << " pontos" << endl;
    }
    
    arvoreRanking->exibirEstatisticas();
}

// Sobre o jogo
void QuizEstruturaDados::sobreOJogo() {
    cout << "\n📖 SOBRE O QUIZ - ESTRUTURAS DE DADOS" << endl;
    cout << string(50, '=') << endl;
    cout << "🎯 Objetivo: Aprender e testar conhecimentos sobre estruturas de dados" << endl;
    cout << "🏫 Disciplina: Estruturas de Dados I - UFPA" << endl;
    cout << "👥 Desenvolvedores: [Seus nomes aqui]" << endl;
    cout << "\n📚 ESTRUTURAS DE DADOS UTILIZADAS:" << endl;
    cout << "• Árvore BST: Armazenamento do ranking de jogadores" << endl;
    cout << "• Fila (Queue): Sequência de perguntas do quiz" << endl;
    cout << "• Pilha (Stack): Histórico de perguntas respondidas" << endl;
    cout << "• Vetor (Vector): Banco de perguntas e alternativas" << endl;
    cout << "\n🔧 ALGORITMOS IMPLEMENTADOS:" << endl;
    cout << "• Merge Sort: Ordenação do ranking (complexidade O(n log n))" << endl;
    cout << "• Busca em BST: Organização eficiente dos jogadores" << endl;
    cout << "• Embaralhamento: Randomização das perguntas" << endl;
    cout << "\n🎮 FUNCIONALIDADES:" << endl;
    cout << "• Quiz interativo com perguntas de múltipla escolha" << endl;
    cout << "• Sistema de pontuação baseado na dificuldade" << endl;
    cout << "• Ranking persistente usando árvore binária" << endl;
    cout << "• Visualização do processo de ordenação" << endl;
    cout << "• Interface amigável no terminal" << endl;
}

// Executar o programa principal
void QuizEstruturaDados::executar() {
    int opcao;
    
    cout << "🚀 Inicializando Quiz de Estruturas de Dados..." << endl;
    
    do {
        exibirMenu();
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                jogarQuiz();
                break;
            case 2:
                exibirRanking();
                break;
            case 3:
                cout << "\n🌳 VISUALIZACAO DA ARVORE BST:" << endl;
                arvoreRanking->exibirArvore();
                arvoreRanking->exibirEstatisticas();
                cout << "\nPressione ENTER para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 4:
                sobreOJogo();
                cout << "\nPressione ENTER para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 5:
                cout << "\n👋 Obrigado por jogar! Continue estudando estruturas de dados!" << endl;
                break;
            default:
                cout << "❌ Opção inválida! Tente novamente." << endl;
        }
        
    } while (opcao != 5);
}

// Função main
int main() {
    QuizEstruturaDados quiz;
    quiz.executar();
    return 0;
}