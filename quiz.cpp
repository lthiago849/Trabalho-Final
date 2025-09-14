#include "quiz.hpp"
#include <limits> // Necessário para numeric_limits

// Códigos de cores para exibição de erro ou acerto
const string VERDE = "\033[32m";
const string VERMELHO = "\033[31m";
const string RESET = "\033[0m";

QuizEstruturaDados::QuizEstruturaDados() {
    inicializarPerguntas();
    totalJogadores = 0;
}

void QuizEstruturaDados::inicializarPerguntas() {
    totalPerguntas = 0;
    
    // Pergunta 1
    string alt1[] = {"Acesso mais rapido aos elementos", "Tamanho dinamico", "Menor uso de memoria", "Ordenacao automatica"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual a principal vantagem das listas encadeadas sobre arrays?", alt1, 1, "TAD - Listas", 10, 1);
    
    // Pergunta 2
    string alt2[] = {"Apenas ponteiro para o proximo", "Ponteiros para anterior e proximo", "Apenas dados", "Array de ponteiros"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Em uma lista duplamente encadeada, cada no possui:", alt2, 1, "TAD - Listas", 15, 2);
    
    // Pergunta 3
    string alt3[] = {"O primeiro inserido (FIFO)", "O ultimo inserido (LIFO)", "O do meio", "Qualquer um"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Em uma pilha, qual elemento e removido primeiro?", alt3, 1, "TAD - Pilhas", 10, 1);
    
    // Pergunta 4
    string alt4[] = {"Push (empilhar)", "Pop (desempilhar)", "Top (topo)", "Search (buscar no meio)"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual operacao NAO e tipica de uma pilha?", alt4, 3, "TAD - Pilhas", 15, 2);
    
    // Pergunta 5
    string alt5[] = {"LIFO (Last In, First Out)", "FIFO (First In, First Out)", "Random Access", "FILO (First In, Last Out)"};
    bancoPerguntas[totalPerguntas++] = Pergunta("O principio de funcionamento de uma fila e:", alt5, 1, "TAD - Filas", 10, 1);
    
    // Pergunta 6
    string alt6[] = {"Rear aponta para Front", "(Rear + 1) % size == Front", "Rear > Front", "Front == 0"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Em uma fila circular, quando ela esta cheia:", alt6, 1, "TAD - Filas", 20, 3);
    
    // Pergunta 7
    string alt7[] = {"O(n)", "O(log n)", "O(n^2)", "O(1)"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual a complexidade de busca em uma arvore binaria balanceada?", alt7, 1, "TAD - Arvores", 15, 2);
    
    // Pergunta 8
    string alt8[] = {"Em ordem crescente", "Em ordem decrescente", "Aleatoriamente", "Por nivel"};
    bancoPerguntas[totalPerguntas++] = Pergunta("No percurso in-ordem de uma BST, os elementos sao visitados:", alt8, 0, "TAD - Arvores", 20, 3);
    
    // Pergunta 9
    string alt9[] = {"2^h", "2^h - 1", "2^(h+1) - 1", "h^2"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Uma arvore binaria completa com altura h tem quantos nos?", alt9, 2, "TAD - Arvores", 25, 3);
    
    // Pergunta 10
    string alt10[] = {"Bubble Sort", "Selection Sort", "Merge Sort", "Insertion Sort"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual algoritmo de ordenacao tem complexidade O(n log n) no melhor caso?", alt10, 2, "Ordenacao", 15, 2);
    
    // Pergunta 11
    string alt11[] = {"O(n^2) no melhor e pior caso", "O(n) no melhor caso", "O(n log n) em todos os casos", "O(1) no melhor caso"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual e a complexidade de tempo do algoritmo Selection Sort?", alt11, 0, "Ordenação", 15, 2);

    // Pergunta 12
    string alt12[] = {"O endereco de memoria da variavel", "O valor armazenado no endereco apontado", "O tipo de dado da variavel", "O tamanho em bytes do ponteiro"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Em C++, o que o operador de desreferencia (*) retorna quando aplicado a um ponteiro?", alt12, 1, "Ponteiros", 10, 1);

    // Pergunta 13
    string alt13[] = {"Quando o vetor de base esta quase ordenado", "Quando o vetor esta em ordem inversa", "Quando o vetor e muito grande", "A complexidade e sempre a mesma"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Em que cenario o Insertion Sort apresenta sua melhor performance, com complexidade O(n)?", alt13, 0, "Ordenacao", 20, 3);
    
    // Pergunta 14
    string alt14[] = {"Alocacao de memoria contigua e tamanho fixo", "Alocacao de memoria nao contigua e tamanho variavel", "Acesso a elementos em tempo O(n)", "Necessidade de ponteiros duplos"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual a principal caracteristica de uma Lista Estatica (baseada em array)?", alt14, 0, "TAD - Lista", 10, 1);

    // Pergunta 15
    string alt15[] = {"Dividir para conquistar", "Heuristica gulosa", "Backtracking", "Programacao dinamica"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Quicksort e Mergesort sao exemplos de qual paradigma de algoritmo?", alt15, 0, "Ordenacao", 15, 2);

    // Pergunta 16
    string alt16[] = {"Stack Underflow", "Stack Overflow", "Null Pointer Exception", "Segmentation Fault"};
    bancoPerguntas[totalPerguntas++] = Pergunta("O que ocorre ao tentar inserir (push) um elemento em uma Pilha Estatica cheia?", alt16, 1, "TAD - Pilha", 15, 2);

    // Pergunta 17
    string alt17[] = {"Ele e mais rapido que o Insertion Sort para dados aleatorios", "Ele e um algoritmo de ordenacao estavel", "Ele utiliza saltos (gaps) para mover elementos distantes", "Sua complexidade de pior caso e O(n log n)"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual afirmacao descreve corretamente o Shellsort?", alt17, 2, "Ordenação", 25, 3);

    // Pergunta 18
    string alt18[] = {"Para indicar um erro", "Para liberar a memoria alocada com 'new'", "Para alocar memoria para um objeto", "Para criar uma referencia a uma variavel"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual a finalidade do operador 'delete' em C++ quando usado com ponteiros?", alt18, 1, "Ponteiros", 15, 2);

    // Pergunta 19
    string alt19[] = {"A insercao e remocao sao sempre O(1)", "O acesso a um elemento qualquer e O(1)", "Utiliza mais memoria que uma lista estatica para os mesmos dados", "Nao pode ficar cheia"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual e uma caracteristica de uma Lista Dinamica (encadeada)?", alt19, 2, "TAD - Lista", 20, 3);

    // Pergunta 20
    string alt20[] = {"O(n^2)", "O(n log n)", "O(n)", "O(1)"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual a complexidade de tempo de pior caso do Quicksort (com uma ma escolha de pivo)?", alt20, 0, "Ordenacao", 20, 3);

    // Pergunta 21
    string alt21[] = {"O topo e o fim sao o mesmo ponteiro", "O ponteiro 'topo' aponta para nullptr", "O contador de elementos e zero", "O ponteiro 'base' e igual ao 'topo'"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Como se identifica que uma Pilha Dinamica (encadeada) esta vazia?", alt21, 1, "TAD - Pilha", 10, 1);
    
    // Pergunta 22
    string alt22[] = {"Requer espaco de memoria adicional O(n)", "Nao e um algoritmo estavel", "E ineficiente para vetores grandes", "Seu pior caso e O(n^2)"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual e a principal desvantagem do Mergesort em comparacao com o Quicksort?", alt22, 0, "Ordenacao", 20, 3);

    // Pergunta 23
    string alt23[] = {"O ponteiro 'inicio' e igual ao 'fim'", "O ponteiro 'fim' aponta para nullptr", "O ponteiro 'inicio' aponta para nullptr", "O contador de elementos e -1"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Em uma Fila Dinamica (encadeada), qual e a condicao para ela estar vazia?", alt23, 2, "TAD - Fila", 10, 1);
    
    // Pergunta 24
    string alt24[] = {"Para indicar o final de uma lista", "Para apontar para o endereco de memoria 0", "Para inicializar ponteiros que nao apontam para um objeto valido", "Para otimizar o acesso a memoria"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual e o proposito da palavra-chave 'nullptr' em C++ moderno?", alt24, 2, "Ponteiros", 15, 2);

    // Pergunta 25
    string alt25[] = {"O no a ser inserido e menor que a raiz", "O no a ser inserido tem valor igual a raiz", "A sub-arvore direita da raiz esta vazia", "A sub-arvore esquerda da raiz esta vazia"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Em uma Arvore Binaria de Busca, um novo elemento e inserido na sub-arvore esquerda da raiz se:", alt25, 0, "TAD - Árvore", 10, 1);
    
    // Pergunta 26
    string alt26[] = {"Para evitar que o indice de 'fim' ultrapasse o limite do array", "Para facilitar a verificacao de fila cheia", "Para reutilizar espacos vazios no inicio do array", "Para acelerar a remocao de elementos"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Por que uma Fila Estatica e frequentemente implementada como um vetor circular?", alt26, 2, "TAD - Fila", 25, 3);
    
    // Pergunta 27
    string alt27[] = {"O TAD define 'o que' uma estrutura faz (operacoes), a implementacao define 'como' ela faz", "TAD e a versao dinamica, implementacao e a estatica", "Nao ha diferenca, sao sinonimos", "TAD e um conceito teorico, implementacao e o codigo em C"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual a principal diferenca entre um TAD (Tipo Abstrato de Dados) e sua implementacao?", alt27, 0, "TAD - Conceitos", 15, 2);
    
    // Pergunta 28
    string alt28[] = {"Trocar o primeiro com o ultimo", "Encontrar o menor elemento restante e troca-lo para a posicao correta", "Comparar elementos adjacentes e troca-los se estiverem fora de ordem", "Inserir cada elemento em sua posicao correta em uma sub-lista ordenada"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual e o passo fundamental do algoritmo Selection Sort a cada iteracao?", alt28, 1, "Ordenacao", 15, 2);
    
    // Pergunta 29
    string alt29[] = {"O(n)", "O(log n)", "O(1)", "O(n^2)"};
    bancoPerguntas[totalPerguntas++] = Pergunta("Qual a complexidade media de insercao e remocao em uma Pilha Dinamica?", alt29, 2, "TAD - Pilha", 10, 1);
    
    // Pergunta 30
    string alt30[] = {"A altura da arvore", "O numero de nos na arvore", "O fator de balanceamento", "Se a arvore esta cheia ou nao"};
    bancoPerguntas[totalPerguntas++] = Pergunta("A complexidade O(log n) para busca em uma Arvore Binaria de Busca depende diretamente de qual fator?", alt30, 0, "TAD - Árvore", 25, 3);
    
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

// ALGORITMO SELECTION SORT - O(n²)
void QuizEstruturaDados::selectionSort(Jogador arr[], int tamanho) {
    cout << "\n=== INICIANDO SELECTION SORT ===" << endl;
    cout << "Complexidade: O(n^2)" << endl;
    cout << "Algoritmo: Encontra o maior elemento e coloca na posicao correta" << endl;
    
    for(int i = 0; i < tamanho - 1; i++) {
        int indiceMaior = i; // assume que o primeiro é o maior
        
        cout << "\nPasso " << (i+1) << ": Procurando o maior elemento de [" << i << ".." << (tamanho-1) << "]" << endl;
        cout << "Elemento atual na posicao " << i << ": " << arr[i].nome << "(" << arr[i].pontuacao << ")" << endl;
        
        // Procura o maior elemento no resto do array
        for(int j = i + 1; j < tamanho; j++) {
            if(arr[j].pontuacao > arr[indiceMaior].pontuacao) {
                cout << "  Novo maior encontrado: " << arr[j].nome << "(" << arr[j].pontuacao << ") na posicao " << j << endl;
                indiceMaior = j;
            }
        }
        
        // Se encontrou um elemento maior, faz a troca
        if(indiceMaior != i) {
            cout << "  Trocando " << arr[i].nome << "(" << arr[i].pontuacao << ")" 
                 << " com " << arr[indiceMaior].nome << "(" << arr[indiceMaior].pontuacao << ")" << endl;
            
            Jogador temp = arr[i];
            arr[i] = arr[indiceMaior];
            arr[indiceMaior] = temp;
        } else {
            cout << "  Nenhuma troca necessaria - elemento ja esta na posicao correta" << endl;
        }
        
        // Mostra o estado atual do array
        cout << "  Estado atual: ";
        for(int k = 0; k < tamanho; k++) {
            if(k <= i) cout << "[" << arr[k].nome << "(" << arr[k].pontuacao << ")] "; // já ordenado
            else cout << arr[k].nome << "(" << arr[k].pontuacao << ") "; // ainda não ordenado
        }
        cout << endl;
    }
    
    cout << "\n=== SELECTION SORT CONCLUIDO ===" << endl;
}

void QuizEstruturaDados::adicionarJogadorRanking(Jogador novoJogador) {
    if(totalJogadores < MAX_JOGADORES) {
        rankingJogadores[totalJogadores] = novoJogador;
        totalJogadores++;
    }
}

void QuizEstruturaDados::exibirMenu() {
    cout << endl;
    cout << R"(   ____        _                   __________ ___
  / __ \__  __(_)___              / ____/ __ <  /
 / / / / / / / /_  /    ______   / __/ / / / / / 
/ /_/ / /_/ / / / /_   /_____/  / /___/ /_/ / /  
\___\_\__,_/_/ /___/           /_____/_____/_/   
                                                 )" << endl;
    cout << " UFPA - Sistemas de Informação (2025)   " << endl;
    cout << "=====================================" << endl;
    cout << "  1. Jogar Quiz                    " << endl;
    cout << "  2. Ver Ranking                   " << endl;
    cout << "  3. Demonstrar Funcionamento Fila " << endl;
    cout << "  4. Sobre o Jogo                  " << endl;
    cout << "  5. Sair                          " << endl;
    cout << "=====================================" << endl;
    cout << "Escolha uma opcao (1-5): ";
}

void QuizEstruturaDados::jogarQuiz() {
    // Códigos de cores para exibição de erro ou acerto

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
        
        // executando o comando 'clear' (para Linux/macOS) ou 'cls' (para Windows)
        system("clear || cls"); 

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
            cout << VERDE << "CORRETO! +" << perguntaAtual.pontos << " pontos" << RESET << endl;
            jogador.pontuacao += perguntaAtual.pontos;
            acertos++;
        } else {
            cout << VERMELHO << "ERRADO! A resposta correta era: " 
                 << (char)('A' + perguntaAtual.respostaCorreta) << ") "
                 << perguntaAtual.alternativas[perguntaAtual.respostaCorreta] << RESET << endl;
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
    
    system("clear || cls"); 
    cout << "\nDEMONSTRACAO DO SELECTION SORT - ORDENACAO DO RANKING" << endl;
    cout << string(60, '-') << endl;
    
    cout << "Estado inicial (desordenado):" << endl;
    for(int i = 0; i < tamanho; i++) {
        cout << jogadores[i].nome << "(" << jogadores[i].pontuacao << ") ";
    }
    cout << endl;
    
    selectionSort(jogadores, tamanho);
    
    cout << "\nEstado final (ordem decrescente de pontuacao):" << endl;
    for(int i = 0; i < tamanho; i++) {
        cout << jogadores[i].nome << "(" << jogadores[i].pontuacao << ") ";
    }
    cout << endl;
}

void QuizEstruturaDados::exibirRanking() {
    system("clear || cls"); 
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
        selectionSort(ranking, totalJogadores);
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
    system("clear || cls"); 
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
    system("clear || cls"); 
    
    cout << "\nSOBRE O QUIZ - ESTRUTURAS DE DADOS" << endl;
    cout << string(50, '=') << endl;
    cout << "Objetivo: Aprender e testar conhecimentos sobre estruturas de dados" << endl;
    cout << "Disciplina: Estruturas de Dados I - UFPA" << endl;
    cout << "Desenvolvedores: João Paulo, Thayo Felipe e Thiago Leonardo" << endl;
    cout << "\nESTRUTURAS DE DADOS UTILIZADAS:" << endl;
    cout << "• Fila (Array Circular): Gerencia sequencia de perguntas do quiz" << endl;
    cout << "• Arrays: Armazenamento do banco de perguntas e ranking" << endl;
    cout << "\nALGORITMOS IMPLEMENTADOS:" << endl;
    cout << "• Selection Sort: Ordenacao do ranking (complexidade O(n^2))" << endl;
    cout << "• Embaralhamento Fisher-Yates: Randomizacao das perguntas" << endl;
    cout << "\nFUNCIONALIDADES:" << endl;
    cout << "• Quiz interativo com perguntas de multipla escolha" << endl;
    cout << "• Sistema de pontuacao baseado na dificuldade" << endl;
    cout << "• Demonstracao visual do funcionamento da fila" << endl;
    cout << "• Visualizacao detalhada do processo de ordenacao Selection Sort" << endl;
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
        bool on = true;
        // --- INÍCIO DO BLOCO DE VALIDAÇÃO ---
        
        // Usamos um loop infinito que só será quebrado (break) quando a entrada for válida.
        while (on) {
            cin >> opcao;   

            // CASO 1: A entrada NÃO é um número (ex: 'a', 'texto')
            if (cin.fail()) {
                system("clear || cls");
                exibirMenu(); // Mostra o menu novamente
                cout << VERMELHO << "(Erro) Por favor, digite apenas um NUMERO." << RESET << endl;
                cin.clear(); // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer      
            // CASO 2: A entrada é um número, MAS está fora do intervalo válido (1 a 5)
            } else if (opcao < 1 || opcao > 5) {
                system("clear || cls");
                exibirMenu(); // Mostra o menu novamente

                cout << VERMELHO <<"(Erro) Opcao invalida! Por favor, digite um numero entre 1 e 5."<< RESET << endl;

            // CASO 3: A entrada é um número E está no intervalo correto
            } else {
                on = false; // A entrada é válida, sai do loop de validação.
            }
        }
        // --- FIM DO BLOCO DE VALIDAÇÃO ---
        
        // Limpa o buffer DEPOIS de uma leitura bem-sucedida, preparando para futuras entradas.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        // Temos certeza que a opcao eh um inteiro, portanto o switch será executado.     
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