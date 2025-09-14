#include "quiz.hpp"

QuizEstruturaDados::QuizEstruturaDados() {
    inicializarPerguntas();
    totalJogadores = 0;
}

void QuizEstruturaDados::inicializarPerguntas() {
    totalPerguntas = 0;
    
    // Pergunta 1
    string alt1[] = {"Acesso mais rapido aos elementos", "Tamanho dinamico", "Menor uso de memoria", "Ordenacao automatica"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual a principal vantagem das listas ligadas sobre arrays?", alt1, 1, "Listas", 10, 1);
    
    // Pergunta 2
    string alt2[] = {"Apenas ponteiro para o proximo", "Ponteiros para anterior e proximo", "Apenas dados", "Array de ponteiros"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Em uma lista duplamente ligada, cada no possui:", alt2, 1, "Listas", 15, 2);
    
    // Pergunta 3
    string alt3[] = {"O primeiro inserido (FIFO)", "O ultimo inserido (LIFO)", "O do meio", "Qualquer um"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Em uma pilha, qual elemento e removido primeiro?", alt3, 1, "Pilhas", 10, 1);
    
    // Pergunta 4
    string alt4[] = {"Push (empilhar)", "Pop (desempilhar)", "Top (topo)", "Search (buscar no meio)"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual operacao NAO e tipica de uma pilha?", alt4, 3, "Pilhas", 15, 2);
    
    // Pergunta 5
    string alt5[] = {"LIFO (Last In, First Out)", "FIFO (First In, First Out)", "Random Access", "FILO (First In, Last Out)"};
    bancoPerguntas[totalPerguntas++] = Pergunta("O principio de funcionamento de uma fila e:", alt5, 1, "Filas", 10, 1);
    
    // Pergunta 6
    string alt6[] = {"Rear aponta para Front", "(Rear + 1) % size == Front", "Rear > Front", "Front == 0"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Em uma fila circular, quando ela esta cheia:", alt6, 1, "Filas", 20, 3);
    
    // Pergunta 7
    string alt7[] = {"O(n)", "O(log n)", "O(n^2)", "O(1)"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual a complexidade de busca em uma arvore binaria balanceada?", alt7, 1, "Arvores", 15, 2);
    
    // Pergunta 8
    string alt8[] = {"Em ordem crescente", "Em ordem decrescente", "Aleatoriamente", "Por nivel"};
    bancoPerguntas[totalPerguntas++] = Pergunta("No percurso in-ordem de uma BST, os elementos sao visitados:", alt8, 0, "Arvores", 20, 3);
    
    // Pergunta 9
    string alt9[] = {"2^h", "2^h - 1", "2^(h+1) - 1", "h^2"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Uma arvore binaria completa com altura h tem quantos nos?", alt9, 2, "Arvores", 25, 3);
    
    // Pergunta 10
    string alt10[] = {"Bubble Sort", "Selection Sort", "Merge Sort", "Insertion Sort"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual algoritmo de ordenacao tem complexidade O(n log n) no melhor caso?", alt10, 2, "Algoritmos", 15, 2);
    
    cout << "Banco de perguntas inicializado com " << totalPerguntas << " perguntas!" << endl;
}

void QuizEstruturaDados::embaralharPerguntas() {
    for(int i = 0; i < totalPerguntas; i++) {
        int j = i + (rand() % (totalPerguntas - i));
        Pergunta temp = bancoPerguntas[i];
        bancoPerguntas[i] = bancoPerguntas[j];
        bancoPerguntas[j] = temp;
    }
}

void QuizEstruturaDados::mergeSort(Jogador arr[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        cout << "Dividindo: [" << inicio << ".." << meio << "] e [" << (meio+1) << ".." << fim << "]" << endl;
        
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);
        
        merge(arr, inicio, meio, fim);
    }
}

void QuizEstruturaDados::merge(Jogador arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    
    Jogador* esquerda = new Jogador[n1];
    Jogador* direita = new Jogador[n2];
    
    for(int i = 0; i < n1; i++)
        esquerda[i] = arr[inicio + i];
    for(int j = 0; j < n2; j++)
        direita[j] = arr[meio + 1 + j];
    
    int i = 0, j = 0, k = inicio;
    
    while(i < n1 && j < n2) {
        if(esquerda[i].pontuacao >= direita[j].pontuacao) {
            arr[k] = esquerda[i];
            i++;
        } else {
            arr[k] = direita[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        arr[k] = esquerda[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        arr[k] = direita[j];
        j++;
        k++;
    }
    
    cout << "Merged [" << inicio << ".." << fim << "]: ";
    for(int x = inicio; x <= fim; x++) {
        cout << arr[x].nome << "(" << arr[x].pontuacao << ") ";
    }
    cout << endl;
    
    delete[] esquerda;
    delete[] direita;
}

void QuizEstruturaDados::adicionarJogadorRanking(Jogador novoJogador) {
    if(totalJogadores < MAX_JOGADORES) {
        rankingJogadores[totalJogadores] = novoJogador;
        totalJogadores++;
    }
}

void QuizEstruturaDados::exibirMenu() {
    cout << "\n=======================================" << endl;
    cout << "     QUIZ - ESTRUTURAS DE DADOS       " << endl;
    cout << "          UFPA - 2024                 " << endl;
    cout << "=======================================" << endl;
    cout << "  1. Jogar Quiz                    " << endl;
    cout << "  2. Ver Ranking                   " << endl;
    cout << "  3. Demonstrar Funcionamento Fila " << endl;
    cout << "  4. Sobre o Jogo                  " << endl;
    cout << "  5. Sair                          " << endl;
    cout << "=======================================" << endl;
    cout << "Escolha uma opcao (1-5): ";
}

void QuizEstruturaDados::jogarQuiz() {
    cout << "\n=== INICIANDO QUIZ ===" << endl;
    
    string nomeJogador;
    cout << "Digite seu nome: ";
    cin.ignore();
    getline(cin, nomeJogador);
    
    embaralharPerguntas();
    
    FilaPerguntas filaPerguntas;
    int numPerguntasJogo = (totalPerguntas > 8) ? 8 : totalPerguntas;
    
    cout << "\n--- DEMONSTRACAO DA FILA ---" << endl;
    cout << "Enfileirando " << numPerguntasJogo << " perguntas..." << endl;
    
    for(int i = 0; i < numPerguntasJogo; i++) {
        filaPerguntas.enfileirar(bancoPerguntas[i]);
        cout << "Pergunta " << (i+1) << " enfileirada: " << bancoPerguntas[i].categoria << endl;
    }
    
    filaPerguntas.exibirStatusFila();
    
    Jogador jogador(nomeJogador, 0);
    int numeroPergunta = 1;
    int acertos = 0;
    
    cout << "\nVoce tera " << filaPerguntas.getTamanho() << " perguntas para responder!" << endl;
    cout << "Pressione ENTER para comecar...";
    cin.get();
    
    while(!filaPerguntas.vazia()) {
        cout << "\n--- DESENFILEIRANDO PERGUNTA ---" << endl;
        Pergunta perguntaAtual = filaPerguntas.desenfileirar();
        
        cout << "Perguntas restantes na fila: " << filaPerguntas.getTamanho() << endl;
        
        cout << "\n" << string(50, '=') << endl;
        cout << "PERGUNTA " << numeroPergunta << "/" << numPerguntasJogo << endl;
        cout << "Categoria: " << perguntaAtual.categoria << " | ";
        cout << "Dificuldade: " << string(perguntaAtual.dificuldade, '*') << endl;
        cout << "Pontos: " << perguntaAtual.pontos << endl;
        cout << string(50, '=') << endl;
        
        cout << "\n" << perguntaAtual.enunciado << endl << endl;
        
        for(int i = 0; i < 4; i++) {
            cout << "  " << (char)('A' + i) << ") " << perguntaAtual.alternativas[i] << endl;
        }
        
        cout << "\nSua resposta (A/B/C/D): ";
        char resposta;
        cin >> resposta;
        resposta = (resposta >= 'a' && resposta <= 'z') ? resposta - 32 : resposta;
        int indiceResposta = resposta - 'A';
        
        cout << "\n" << string(30, '-') << endl;
        
        if(indiceResposta == perguntaAtual.respostaCorreta) {
            cout << "CORRETO! +" << perguntaAtual.pontos << " pontos" << endl;
            jogador.pontuacao += perguntaAtual.pontos;
            acertos++;
        } else {
            cout << "ERRADO! A resposta correta era: " 
                 << (char)('A' + perguntaAtual.respostaCorreta) << ") "
                 << perguntaAtual.alternativas[perguntaAtual.respostaCorreta] << endl;
        }
        
        cout << "Pontuacao atual: " << jogador.pontuacao << " pontos" << endl;
        
        numeroPergunta++;
        
        if(!filaPerguntas.vazia()) {
            cout << "\nPressione ENTER para a proxima pergunta...";
            cin.ignore();
            cin.get();
        }
    }
    
    cout << "\n--- FILA VAZIA! ---" << endl;
    filaPerguntas.exibirStatusFila();
    
    cout << "\n" << string(60, '=') << endl;
    cout << "QUIZ FINALIZADO!" << endl;
    cout << string(60, '=') << endl;
    cout << "Jogador: " << jogador.nome << endl;
    cout << "Acertos: " << acertos << "/" << numPerguntasJogo << endl;
    cout << "Pontuacao Final: " << jogador.pontuacao << " pontos" << endl;
    
    double percentual = (double)acertos / numPerguntasJogo * 100;
    cout << "Aproveitamento: " << percentual << "%" << endl;
    
    if(percentual >= 80) cout << "Excelente!" << endl;
    else if(percentual >= 60) cout << "Bom trabalho!" << endl;
    else if(percentual >= 40) cout << "Continue estudando!" << endl;
    else cout << "Nao desista, pratique mais!" << endl;
    
    cout << "\nAdicionando ao ranking..." << endl;
    adicionarJogadorRanking(jogador);
    
    cout << "\nPressione ENTER para voltar ao menu...";
    cin.ignore();
    cin.get();
}

void QuizEstruturaDados::demonstrarOrdenacao(Jogador jogadores[], int tamanho) {
    if(tamanho <= 1) return;
    
    cout << "\nDEMONSTRACAO DO MERGE SORT - ORDENACAO DO RANKING" << endl;
    cout << string(60, '-') << endl;
    
    cout << "Estado inicial:" << endl;
    for(int i = 0; i < tamanho; i++) {
        cout << jogadores[i].nome << "(" << jogadores[i].pontuacao << ") ";
    }
    cout << endl << endl;
    
    mergeSort(jogadores, 0, tamanho - 1);
    
    cout << "\nOrdenacao concluida!" << endl;
    cout << "Estado final (ordem decrescente de pontuacao):" << endl;
    for(int i = 0; i < tamanho; i++) {
        cout << jogadores[i].nome << "(" << jogadores[i].pontuacao << ") ";
    }
    cout << endl;
}

void QuizEstruturaDados::exibirRanking() {
    cout << "\nRANKING DOS JOGADORES" << endl;
    
    if(totalJogadores == 0) {
        cout << "Nenhum jogador no ranking ainda. Jogue para aparecer aqui!" << endl;
        return;
    }
    
    Jogador ranking[MAX_JOGADORES];
    for(int i = 0; i < totalJogadores; i++) {
        ranking[i] = rankingJogadores[i];
    }
    
    cout << "\nDeseja ver a demonstracao do algoritmo de ordenacao? (s/n): ";
    char opcao;
    cin >> opcao;
    if(opcao == 's' || opcao == 'S') {
        for(int i = 0; i < totalJogadores; i++) {
            int j = i + (rand() % (totalJogadores - i));
            Jogador temp = ranking[i];
            ranking[i] = ranking[j];
            ranking[j] = temp;
        }
        
        demonstrarOrdenacao(ranking, totalJogadores);
    } else {
        mergeSort(ranking, 0, totalJogadores - 1);
    }
    
    cout << "\n" << string(50, '=') << endl;
    cout << "RANKING FINAL" << endl;
    cout << string(50, '=') << endl;
    
    for(int i = 0; i < totalJogadores; i++) {
        string medalha = "";
        if(i == 0) medalha = "[1]";
        else if(i == 1) medalha = "[2]";
        else if(i == 2) medalha = "[3]";
        else medalha = "   ";
        
        cout << medalha << " " << (i + 1) << "o lugar: " 
             << ranking[i].nome << " - " << ranking[i].pontuacao << " pontos" << endl;
    }
    
    cout << "\nTotal de jogadores: " << totalJogadores << endl;
}

void QuizEstruturaDados::demonstrarFila() {
    cout << "\nDEMONSTRACAO DO FUNCIONAMENTO DA FILA" << endl;
    cout << string(50, '=') << endl;
    
    FilaPerguntas filaDemo;
    
    cout << "1. Criando fila vazia:" << endl;
    filaDemo.exibirStatusFila();
    
    cout << "\n2. Enfileirando algumas perguntas de exemplo:" << endl;
    
    for(int i = 0; i < 5 && i < totalPerguntas; i++) {
        filaDemo.enfileirar(bancoPerguntas[i]);
        cout << "Enfileirou: " << bancoPerguntas[i].categoria << endl;
    }
    
    filaDemo.exibirStatusFila();
    
    cout << "\n3. Desenfileirando perguntas (FIFO - First In, First Out):" << endl;
    
    while(!filaDemo.vazia()) {
        Pergunta p = filaDemo.desenfileirar();
        cout << "Desenfileirou: " << p.categoria << " (restam " << filaDemo.getTamanho() << " na fila)" << endl;
    }
    
    cout << "\n4. Fila apos desenfileirar tudo:" << endl;
    filaDemo.exibirStatusFila();
}

void QuizEstruturaDados::sobreOJogo() {
    cout << "\nSOBRE O QUIZ - ESTRUTURAS DE DADOS" << endl;
    cout << string(50, '=') << endl;
    cout << "Objetivo: Aprender e testar conhecimentos sobre estruturas de dados" << endl;
    cout << "Disciplina: Estruturas de Dados I - UFPA" << endl;
    cout << "\nESTRUTURAS DE DADOS UTILIZADAS:" << endl;
    cout << "• Fila (Array Circular): Gerencia sequencia de perguntas do quiz" << endl;
    cout << "• Arrays: Armazenamento do banco de perguntas e ranking" << endl;
    cout << "\nALGORITMOS IMPLEMENTADOS:" << endl;
    cout << "• Merge Sort: Ordenacao do ranking (complexidade O(n log n))" << endl;
    cout << "• Embaralhamento Fisher-Yates: Randomizacao das perguntas" << endl;
    cout << "\nFUNCIONALIDADES:" << endl;
    cout << "• Quiz interativo com perguntas de multipla escolha" << endl;
    cout << "• Sistema de pontuacao baseado na dificuldade" << endl;
    cout << "• Demonstracao visual do funcionamento da fila" << endl;
    cout << "• Visualizacao do processo de ordenacao Merge Sort" << endl;
    cout << "• Interface amigavel no terminal" << endl;
    cout << "\nPRINCIPIO FIFO DA FILA:" << endl;
    cout << "As perguntas sao organizadas em fila e apresentadas" << endl;
    cout << "na ordem que foram enfileiradas (First In, First Out)" << endl;
}

void QuizEstruturaDados::executar() {
    int opcao;
    
    cout << "Inicializando Quiz de Estruturas de Dados..." << endl;
    
    do {
        exibirMenu();
        cin >> opcao;
        
        switch(opcao) {
            case 1:
                jogarQuiz();
                break;
            case 2:
                exibirRanking();
                break;
            case 3:
                demonstrarFila();
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
                cout << "\nObrigado por jogar! Continue estudando estruturas de dados!" << endl;
                break;
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
        }
        
    } while(opcao != 5);
}