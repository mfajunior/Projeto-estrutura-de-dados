#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct estacionamento{
  int id;
	int vaga;                
  char cor[10];    
  char placa[8];   
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
    
	printf("\n--- Cadastro da Vaga Ocupada ---\n");
    printf("ID: ");
    scanf("%i", &novo->carro.id);
    
    printf("Qual a cor do carro?: ");
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


no* busca(no* database, int id_procurado) {
    no* aux;
    for (aux = database; aux != NULL; aux = aux->next) {
        if (aux->carro.id == id_procurado) return aux;
    }
    return NULL;
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
    	printf ("Banco de dados vazio! \n");
		return;
		}
		
    printf("\n--- database do estacionamento ---\n");
    for (aux = database; aux != NULL; aux = aux->next) {
        printf("Dados dos veiculos: \n %i - %s - %s - %s - %d",
               aux->carro.id, 
               aux->carro.placa, 
               aux->carro.cor, 
               aux->carro.nome, 
               aux->carro.tipo);
    }
    printf("-----------------------\n");
}

void libera(no* database) {
    no* aux = database;
    while (aux != NULL) {
        no* temp = aux->next;
        free(aux);
        aux = temp;
    }
}

int main (){
	int opcao=0;
	int operador=0;
	no* base = cria();
  
    while (opcao != 6) {
        printf("\n1. Mostrar todos os dados \n2. Incluir dado \n3. Apagar dado \n4. Alterar dado \n5. Apagar tudo \n6. Sair\n Digite a opçao desejada: ");
        scanf("%d", &opcao)
        switch (opcao) {
            case 1:
                imprime(base);
                break;
            case 2:
                base = insere(base);
                break;
            case 3:
                system ("cls");
                imprime(base);
                printf("Digite o ID para apagar: ");
                scanf("%d", &operador);
                base = retira(base, operador);
                break;
            case 4:
                system ("cls");
                imprime(base);
                printf("Digite o ID para alterar: ");
                scanf("%d", &operador);
                altera(base, operador);
                break;
            case 5:
                libera(base);
                printf("Todos os dados foram apagados!\n");
                break;
            case 6:
                libera(base);
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }

    printf("Fim do programa.\n");
    return 0;
}
