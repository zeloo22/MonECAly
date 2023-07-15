#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para representar cada jogador
typedef struct {
    char nome[50];
    float saldo;
    int propriedades;
    int posicao;
} Jogador;

// Estrutura para representar cada materia
typedef struct {
    char nome[50];
    float preco;
    float aluguel;
    int dono;
    int lote;
} Propriedade;

// Função para criar um jogador
Jogador* criarJogador(const char* nome) {
    Jogador* jogador = (Jogador*) malloc(sizeof(Jogador));
    strcpy(jogador->nome, nome);
    jogador->saldo = 30;
    jogador->propriedades = 0;
    jogador->posicao = 0;
    return jogador;
}

// Função para criar uma materia
Propriedade* criarPropriedade(const char* nome, float preco, int lote) {
    Propriedade* propriedade = (Propriedade*) malloc(sizeof(Propriedade));
    strcpy(propriedade->nome, nome);
    propriedade->preco = preco;
    propriedade->aluguel = preco*0.1;
    propriedade->dono = -1;// Nenhum dono inicialmente
    propriedade->lote = lote;
    return propriedade;
}

// Função para imprimir o estado de um jogador
void imprimirJogador(const Jogador* jogador) {
    printf("Jogador: %s\n", jogador->nome);
    printf("Saldo: %.2f Creditos\n", jogador->saldo);
    printf("Materias: %i\n", jogador->propriedades);
    printf("------------------------------\n");
}

// Função para imprimir o estado de uma materia
void imprimirPropriedade(const Propriedade* propriedade) {
    printf("Materia: %s\n", propriedade->nome);
    printf("Preço: %.2f Creditos\n", propriedade->preco);
    printf("Tarefas: %.2f Creditos\n", propriedade->aluguel);
    if (propriedade->dono == -1) {
        printf("Disponível para cursar\n");
    } else {
        printf("Dono: Jogador %d\n", propriedade->dono);
    }
    printf("------------------------------\n");
}

int rollDice() {
    srand(time(NULL));
    int y = (rand() % 12) + 1;

    return (y);
}

void initgame(){
    int w;
    printf("inicializando o jogo\n");
    for(w=0; w<3; w++){
        sleep(1);
        printf(". ");
    }
    printf("\n");
    for(w=0; w<3; w++){
        sleep(1);
        printf(". ");
    }
    printf("\n");
    for(w=0; w<3; w++){
        sleep(1);
        printf(". ");
    }
    printf("\n");
    sleep(1);
    system("cls");
    printf("=========================================================================\n");
    printf("                   bem vindo ao MonECAly em C\n                sao permitidos ate quatro jogadores\n");
    printf("=========================================================================\n\n\n");
}

// Função principal do jogo
int main() {
    // Criando jogadores
    int x;
    int i;
    int z;
    initgame();
    printf("Quantas pessoas irao jogar?\n");
    scanf("%d", &x);

    // nao permite que o jogo comece enquanto tiverem mais jogadores do que o limite
    while (x > 4 || x == 1){
        if (x==1){
            printf("Voce realmente vai jogar sozinho??? Chama teus amigos!");
        }
        else{
            printf("Voce adicionou mais jogadores do que suportado.");
        }
        sleep(1);
        printf("\nInforme novamente o numeno de jogadores novamente: ");
        scanf("%d", &x);
    }

    Jogador* jogadores[x];
    for(z=0; z<x; z++){
        char name[50];
        printf("Digite o nome do jogador %d: ", z + 1);
        scanf("%s", name);
        jogadores[z] = criarJogador(name);
    }



    // Criando propriedades
    Propriedade* propriedades[40]; 
    propriedades[0] = criarPropriedade("Logica Matematica", 5, 0); 
    propriedades[1] = criarPropriedade("IntroEca", 2, 1); 
    propriedades[2] = criarPropriedade("Quimica EE", 4, 2); 
    propriedades[3] = criarPropriedade("Fisexp", 1, 3); 
    propriedades[4] = criarPropriedade("Algoritmos e Programacao", 5, 4); 
    propriedades[5] = criarPropriedade("Fisica I", 4, 5); 
    propriedades[6] = criarPropriedade("Calculo I", 6, 6); 
    propriedades[7] = criarPropriedade("Desenho Tecnico", 4, 7); 
    propriedades[8] = criarPropriedade("Liguagens de programacao", 5, 8); 
    propriedades[9] = criarPropriedade("Circuitos logicos", 5, 9); 
    propriedades[10] = criarPropriedade("Calculo II", 4, 10);
    propriedades[11] = criarPropriedade("Fisexp II", 1, 11);
    propriedades[12] = criarPropriedade("Algebra linear", 2.1, 12); 
    propriedades[13] = criarPropriedade("Fisica II", 4, 13); 
    propriedades[14] = criarPropriedade("Calculo III", 7, 14); 
    propriedades[15] = criarPropriedade("Mecanica I", 3, 15);
    propriedades[16] = criarPropriedade("Fisica III", 5, 16);
    propriedades[17] = criarPropriedade("Metodos matematicos", 4, 17); 
    propriedades[18] = criarPropriedade("Fisexp III", 1, 18); 
    propriedades[19] = criarPropriedade("Sinais e sistemas", 5, 19); 
    propriedades[20] = criarPropriedade("Redes", 4, 20); 
    propriedades[21] = criarPropriedade("Remo", 3.2, 21); 
    propriedades[22] = criarPropriedade("Fisica IV", 4, 22); 
    propriedades[23] = criarPropriedade("Matematica computacional", 5, 23); 
    propriedades[24] = criarPropriedade("Controle Realimentado", 4, 24);
    propriedades[25] = criarPropriedade("Estatistica", 3, 25); 
    propriedades[26] = criarPropriedade("Eletronica I", 4, 26); 
    propriedades[27] = criarPropriedade("Engenharia e meio ambiente", 2, 27); 
    propriedades[28] = criarPropriedade("Sensores e atuadores I", 4, 28); 
    propriedades[29] = criarPropriedade("Danca de salao", 2.3, 29); 
    propriedades[30] = criarPropriedade("Economia", 2, 30);
    propriedades[31] = criarPropriedade("Laboratorio de eletronica", 1, 31);
    propriedades[32] = criarPropriedade("Banco de dados", 4, 32); 
    propriedades[33] = criarPropriedade("Libras", 3.2, 33);
    propriedades[34] = criarPropriedade("Eletronica II", 4, 34); 
    propriedades[35] = criarPropriedade("Organizacao das industrias", 3, 35);
    propriedades[36] = criarPropriedade("Automacao industrial", 4, 36);
    propriedades[37] = criarPropriedade("Procesamento de sinais", 5, 37);
    propriedades[38] = criarPropriedade("Arquitetura de computadores", 5, 38);
    propriedades[39] = criarPropriedade("Etica do setor publico", 3, 39);



    int jogadorAtual = 0;
    int jogadoresFalidos = 0;
    getchar();
    while (jogadoresFalidos < x - 1) {
        if(jogadores[jogadorAtual]->saldo > 0){
        int dice = rollDice();
        system("cls");
        // Imprimir estado do jogador atual
        imprimirJogador(jogadores[jogadorAtual]);
        printf("Aperte enter e jogue os dados\n");
        getchar();
        // Simulação do turno do jogador atual
        
        printf("Jogador %s, voce tirou %d no dado.\n", jogadores[jogadorAtual]->nome, dice);
        printf("Andando");
        for(int w=0; w<3; w++){
        sleep(1);
        printf(".");
        }
        jogadores[jogadorAtual]->posicao = (jogadores[jogadorAtual]->posicao + dice) % 40;
        Propriedade* propriedadeAtual = propriedades[jogadores[jogadorAtual]->posicao];
        printf("\nJogador %s, voce chegou na casa %d na materia %s.\n", jogadores[jogadorAtual]->nome, propriedadeAtual->lote, propriedadeAtual->nome);
        sleep(1);

        if (propriedadeAtual->dono == -1) {
            // Materia disponível para compra
            printf("Deseja cursar a materia %s por %.2f Creditos? Ela retornara %.2f Creditos por aluguel (S/N): ", propriedadeAtual->nome, propriedadeAtual->preco, propriedadeAtual->aluguel);
            char resposta; //olhar com c
            scanf(" %c", &resposta);
            
            if (resposta == 'S' || resposta == 's') {
                if (jogadores[jogadorAtual]->saldo >= propriedadeAtual->preco) {
                    jogadores[jogadorAtual]->saldo -= propriedadeAtual->preco;
                    jogadores[jogadorAtual]->propriedades++;
                    propriedadeAtual->dono = jogadorAtual;
                    printf("Parabens! Agora voce esta cursando a materia %s.\n", propriedadeAtual->nome);
                    getchar();
                }
                else{
                printf("Voce nao tem Creditos suficientes para cursar essa materia");
                getchar();
                }
            }
            else {
                printf("Voce nao esta cursando a materia %s.\n", propriedadeAtual->nome);
                getchar();
            }

            


        } else if (propriedadeAtual->dono != jogadorAtual) {
            // a materia pertence a outro jogador
            float aluguel = propriedadeAtual->aluguel; //olha aqui
            printf("Putssss voce tera que fazer a tarefa de %s do %s.\ne isso ira lhe custar %.2f Creditos",
            propriedadeAtual->nome, jogadores[propriedadeAtual->dono]->nome, aluguel);
            jogadores[jogadorAtual]->saldo -= aluguel;
            jogadores[propriedadeAtual->dono]->saldo += aluguel;

        } 

        else{
            printf("Voce ja esta cursando essa materia.");
        }

        // Verificar se o jogador foi reprovado
        if (jogadores[jogadorAtual]->saldo < 0) {
            printf("\nO jogador %s reprovou!! \nPor isso esta fora do jogo.\n", jogadores[jogadorAtual]->nome);
            jogadoresFalidos++;
        }

        // Próximo jogador
        jogadorAtual = (jogadorAtual + 1) % x;
        printf("\n");
        getchar();
    }
    else{
       printf("\nO jogador %s reprovou!! \nPor isso esta fora do jogo.\n", jogadores[jogadorAtual]->nome); 
        jogadorAtual = (jogadorAtual + 1) % x;
        
    }
    }

    // Encontrar o vencedor
    int vencedor = 0;
    for (i = 0; i < x; i++) {
        if (jogadores[i]->saldo >= 0) {
            vencedor = i;
            break;
        }
    }

    printf("O jogador %s venceu o jogo!\n", jogadores[vencedor]->nome);
        // Liberar memória
    for (i = 0; i < x; i++) {
        free(jogadores[i]);
    }
    for (i = 0; i < 40; i++) {

        free(propriedades[i]);
    }
    return 0;
}