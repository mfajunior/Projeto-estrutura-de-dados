#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

typedef struct estacionamento{
	int id;
	int vaga;                
	char cor[15];    
	char placa[9];   
	char nome[20];
	bool tipo;               
} estacionamento;


typedef struct no{
    estacionamento carro;
    struct no *next;
} no;


no* cria() {
    return NULL;
}

no* insere(no* database) {
    no* novo = (no*)malloc(sizeof(no));
    system("cls");
    
	printf("\n--- Cadastro da Vaga Ocupada ---\n");
    printf("ID: ");
    scanf("%i", &novo->carro.id);
    
    printf("Qual a cor do veiculo?: ");
    scanf("%s",&novo->carro.cor);
    
    printf("Qual a placa do veiculo? Digite no formato ""AAA-AAAA"": ");
    scanf("%s",&novo->carro.placa);
    
    printf("Qual o numero da vaga?: ");
    scanf("%i", &novo->carro.vaga);

    printf("Nome do aluno/funcionario que esta ocupando a vaga: ");
    scanf("%s", &novo->carro.nome);

    printf("Digite 1 - Moto / 2 - Carro: ");
    scanf("%d", &novo->carro.tipo);
    
    novo->next = database;
    system ("cls");
	return novo;
}


no* altera(no* database, int id_procurado) {
    no* aux = database;
    
    for (aux = database; aux != NULL; aux = aux->next) {
        if (aux->carro.id == id_procurado){
        	printf("\n--- Alterar informacoes da vaga ocupada ---\n");
		    printf("ID a ser alterado: %i\n", aux->carro.id );
		    
		    printf("Qual a cor do veiculo?: ");
		    scanf("%s",&aux->carro.cor);
		    
		    printf("Qual a placa do veiculo? Digite no formato ""AAA-AAAA"": ");
		    scanf("%s",&aux->carro.placa);
		    
		    printf("Qual o numero da vaga?: ");
		    scanf("%i", &aux->carro.vaga);
		
		    printf("Nome do aluno/funcionario que esta ocupando a vaga: ");
		    scanf("%s", &aux->carro.nome);
		
		    printf("Digite 1 - Moto / 2 - Carro: ");
		    scanf("%i", &aux->carro.tipo);
		    
		    system ("cls");
			return aux;
        	
		};
    }
    printf("ID %i nao encontrado! \n", id_procurado);
}


no* retira(no *database, int id_remover){
	no* ant = NULL;
	no* aux = database;
	while (aux != NULL && aux->carro.id != id_remover){
	ant = aux;
	aux = aux->next;
	}
	if (ant == NULL) database= aux->next;
    else ant->next = aux->next;
    free(aux);
    system ("cls");
    return database;
}

void imprime(no* database) {
    no* aux;
    
    if (database == NULL) {
        printf("\nEstacionamento vazio!\n");
        return;
    }

    printf("\n--- Veiculos no estacionamento ---\n");
    // O sinal de menos (-) alinha a esquerda. O numero define o tamanho da coluna.
    printf("%-4s | %-10s | %-8s | %-12s | %-4s | %-5s\n", "ID", "Placa", "Cor", "Nome", "Vaga", "Tipo");
    printf("------------------------------------------------------------\n");

    for (aux = database; aux != NULL; aux = aux->next) {
        printf("%-4i | %-10s | %-8s | %-12s | %-4i | %-5i\n",
               aux->carro.id, 
               aux->carro.placa, 
               aux->carro.cor, 
               aux->carro.nome,
			   aux->carro.vaga, 
               aux->carro.id); // Usei id_tipo aqui como exemplo do 1 ou 2
    }
    printf("------------------------------------------------------------\n");
}

void* libera(no* database) {
    no* aux = database;
    while (aux != NULL) {
        no* temp = aux->next;
        free(aux);
        aux = temp;
    }
    return NULL;
}

int main (){
	no* base = cria();
	int opcao=0;
  
    while (opcao != 6) {
        printf("\n1. Mostrar todos os dados \n2. Incluir dado \n3. Apagar dado \n4. Alterar dado \n5. Apagar tudo \n6. Sair\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        int retorno=0;
		int operador=0;
		
        switch (opcao) {
            case 1: // Ok
                system("cls");	
                imprime(base);
                printf("Digite 1 para voltar ao menu principal:");
                while(retorno!=1) scanf("%i", &retorno); 
                system("cls");
                break;
            case 2: // Ok
                base = insere(base);
                break;
            case 3: // OK
                system ("cls");
                imprime(base);
                printf("Digite o ID para apagar: ");
                scanf("%d", &operador);
                base = retira(base, operador);
                break;
            case 4: // OK
                system ("cls");
                imprime(base);
                printf("Digite o ID para alterar: ");
                scanf("%d", &operador);
                base = altera(base, operador);
                break;
            case 5: // OK
                base = libera(base);
                printf("Todos os dados foram apagados!\n");
                sleep(1);
                system ("cls");
                break;
            case 6:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    printf("Fim do programa.\n");
    return 0;
}
