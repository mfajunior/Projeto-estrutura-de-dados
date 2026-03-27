#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int contador_id = 1; // Variavel global para automatizar contador

typedef struct estacionamento{
	int id;
	int vaga;                
	char cor[15];    
	char placa[9];   
	char nome[20];
	char tipo[5];            
} estacionamento;

typedef struct no{
    estacionamento carro;
    struct no *next;
} no;

no* cria() {
    return NULL;
}

void desenhaLogoUSF() {
    printf("\n");
    printf("        ########                                            \n");
    printf("       #######    ######    ############    %%##############\n");
    printf("      ######    ########  ################  ################\n");
    printf("      ######    ########  ######    ######  ######        \n");
    printf("     #######    ######    ######    ######  ######       \n");
    printf("    ########    ######    ########          ######        \n");
    printf("    #######     ######    ##########        ##############  \n");
    printf("    ######      ######      ##########mm    ##############  \n");
    printf("    ######     #######        ##########    ######          \n");
    printf("    ######    ########          ########    ######          \n");
    printf("   #######    ########  ######    ######    ######         \n");
    printf("   #######    ######## #######    ######    ######          \n");
    printf("   #################  ##################    ######          \n");
    printf("    ##############      ############        ######            \n");
    printf("      ##########          ######                            \n");
    printf("\n");
    printf("           SISTEMA DE ESTACIONAMENTO - USF\n");
    printf("    ------------------------------------------------");
}

no* insere(no* database) {
    no* novo = (no*)malloc(sizeof(no));
    if (novo == NULL) return database;

    system("cls");
    printf("\n--- Cadastro da Vaga ---\n");
    
    novo->carro.id = contador_id;
    contador_id = contador_id+1;
    
    printf("Qual a cor do veiculo?: ");
    scanf("%s", novo->carro.cor);
    
    printf("Qual a placa do veiculo? (AAA-AAAA): ");
    scanf("%s", novo->carro.placa);
    
    printf("Qual o numero da vaga?: ");
    scanf("%i", &novo->carro.vaga);

    printf("Nome do proprietario: ");
    scanf(" %[^\n]s", novo->carro.nome);
    
    printf("Qual o tipo do veiculo (Carro/Moto)?: ");
    scanf("%s", &novo->carro.tipo);

    novo->next = database;
    system("cls");
	return novo;
}

no* altera(no* database, int id_procurado) {
    no* aux = database;
    
    for (aux = database; aux != NULL; aux = aux->next) {
        if (aux->carro.id == id_procurado){
        	printf("\n--- Alterar informacoes (ID: %i) ---\n", aux->carro.id);
		    printf("Digite a cor: ");
		    scanf("%s", aux->carro.cor);
		    printf("Digite a placa: ");
		    scanf("%s", aux->carro.placa);
		    printf("Digite a vaga: ");
		    scanf("%i", &aux->carro.vaga);
		    printf("Digite o nome: ");
		    setbuf(stdin, NULL);
		    scanf(" %[^\n]s", aux->carro.nome);
		    printf("Digite o tipo do veiculo (Carro/Moto): ");
		    scanf("%s", aux->carro.tipo);
			return database;
		}
    }
    printf("ID %i nao encontrado!\n", id_procurado);
    return database;
}

void reordenaID(no* database) {
    if (database == NULL) { // Se a databaes estiver vazia, o valor do contador é setado como 1 referente ao primeiro ID
        contador_id = 1;
        return;
    }

    int total = 0;
    no* aux = database;
    while (aux != NULL) { // Conta quantos IDs estão existentes no dabase
        total = total +1;
        aux = aux->next;
    }

    contador_id = total + 1; // Seta a variavel global contador_id para o próximo valor a ser inserido

    aux = database; //aux recebe novamente a database para recomeçar o loop
    while (aux != NULL) { //como a estrutura de dados de uma lista encadeada é uma "pilha" o loop começa do maior valor para o menor
        aux->carro.id = total;
		total = total -1; 
        aux = aux->next;
    }
}

no* retira(no *database, int id_remover){
	no* ant = NULL;
	no* aux = database;
	
	while (aux != NULL && aux->carro.id != id_remover){
	    ant = aux;
	    aux = aux->next;
	}
    
    if (aux == NULL) {
    	system("cls");
		printf("Veiculo nao encontrado! \n");
		Sleep(800);	
		return database;	
	}
		

	if (ant == NULL) database = aux->next;
    else ant->next = aux->next;
    
    free(aux);

    if (id_remover == contador_id - 1) {
        contador_id = contador_id - 1;
    }
    reordenaID(database);

    system("cls");
    return database;
}

void imprime(no* database) {
    no* aux;
    if (database == NULL) {
        printf("\nEstacionamento vazio!\n");
        return;
    }
    printf("\n        --- Veiculos no estacionamento ---\n");
    printf("%-4s | %-10s | %-8s | %-16s | %-4s | %-4s\n", "ID", "Placa", "Cor", "Nome", "Vaga", "Tipo");
    printf("---------------------------------------------------------------\n");
    for (aux = database; aux != NULL; aux = aux->next) {
        printf("%-4i | %-10s | %-8s | %-16s | %-4i | %-4s\n",
               aux->carro.id, aux->carro.placa, aux->carro.cor, 
               aux->carro.nome,aux->carro.vaga,aux->carro.tipo);
    }
    printf("---------------------------------------------------------------\n");
}

no* libera(no* database) {
    no* aux = database;
    while (aux != NULL) {
        no* temp = aux->next;
        free(aux);
        aux = temp;
    }

    contador_id = 1; 
    return NULL;
}

void retornamenu(){
	printf("Retornando ao menu principal");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	system("cls");
}

int main (){
	no* base = cria();
	int opcao = 0;
  
    while (opcao != 6) {
    	desenhaLogoUSF();
    	system("color 1F");
        printf("\n1. Mostrar veiculos no estacionamento \n2. Incluir veiculo \n3. Apagar um veiculo \n4. Alterar dados de um veiculo \n5. Apagar tudo \n6. Sair\nOpcao: ");
        scanf("%d", &opcao);
        int retorno = 0;
		int operador = 0;
		
        switch (opcao) {
            case 1:
                system("cls");	
                imprime(base);
                printf("\nDigite 1 para voltar: ");
                while(retorno != 1) scanf("%i", &retorno); 
                retornamenu();
                break;
            case 2:
                base = insere(base);
                retornamenu();
                break;
            case 3:
                system("cls");
                if (base == NULL) {
			        printf("\nEstacionamento vazio!\n");
			        retornamenu();
			        break;
  					}
                imprime(base);
                printf("Digite o ID para apagar: ");
                scanf("%d", &operador);
                base = retira(base, operador);
                retornamenu();
                break;
            case 4:
                system("cls");
                if (base == NULL) {
			        printf("\nEstacionamento vazio!\n");
			        retornamenu();
			        break;
	  				}
                imprime(base);
                printf("Digite o ID para alterar: ");
                scanf("%d", &operador);
                base = altera(base, operador);
                retornamenu();
                break;
            case 5:
            	system("cls");
            	system("color 4F");
            	printf("Voce tem certeza que quer apagar TODOS os registros? 1 - SIM / 2 - NAO\n");
            	scanf("%i",&operador);
            	system("cls");
            	if (operador == 1){                
					base = libera(base);
	                printf("Todos os dados foram apagados !");
	                Sleep(1000);
	                system("cls");
				}
				else retornamenu();			

                break;
        }
    }
    base = libera(base);
    
    return 0;
}
