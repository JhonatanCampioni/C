#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

int tam = 0;

typedef struct no{
	int valor;
	struct no *prox;
	struct no *ant;	
}no;

no *inicio = NULL;

void add(int val){
	no *novo = (no*) malloc(sizeof(no));
	novo->valor = val;
	
	if(inicio == NULL){
		novo->prox = NULL;
		novo->ant = NULL;
		inicio = novo;
	}else{
		no *temp = inicio;
		while(temp->valor < novo->valor){
			if(temp->prox == NULL){
				break;
			}else{
				temp = temp->prox;
			}
		}
		if(temp->valor < novo->valor){
			novo->prox = NULL;
			novo->ant = temp;
			temp->prox = novo;
		}else{
			if(temp->ant == NULL){
				novo->ant = NULL;
				novo->prox = temp;
				temp->ant = novo;
				inicio = novo;
			}else{
				no *aux = temp->ant;
				novo->prox = temp;
				novo->ant = aux;
				temp->ant = novo;
				aux->prox = novo;
			}
		}
	}
	tam++;
}

void mostrar(){
	system("cls");
	int cont = 0;
	if(inicio!=NULL){
		no *temp = inicio;
		do{
			cont ++;
			printf("==================\n");
			printf("valor: %i          %i°\n", temp->valor, cont);
			printf("==================\n\n");
			temp = temp->prox;
		}while(temp!=NULL);
	}else{
		printf("NADA FOI ADICIONADO AINDA!!\n\n");
	}
	system("pause");	
}

void apagar(int posi){
	system("cls");
	no *temp = inicio;
	if(posi!=1){
		int i = 1;
		while(i < posi-1){
			temp = temp->prox;
			i++;
		}
		no *aux = temp->prox;
		if(aux->prox!=NULL){
			temp->prox = aux->prox;
			temp = aux->prox;
			temp->ant = aux->ant;
			printf("  FOI APAGADO\n");
			printf("==================\n");
			printf("valor: %i\n", aux->valor);
			printf("==================\n\n");
			free(aux);
		}else{
			temp->prox = NULL;
			printf("  FOI APAGADO\n");
			printf("==================\n");
			printf("valor: %i\n", aux->valor);
			printf("==================\n\n");
			free(aux);		
		}
	}else{
		if(temp->prox!=NULL){
			inicio = inicio->prox;
			inicio->ant = NULL;
			printf("  FOI APAGADO\n");
			printf("==================\n");
			printf("valor: %i\n", temp->valor);
			printf("==================\n\n");
			free(temp);	
		}else{
			printf("  FOI APAGADO\n");
			printf("==================\n");
			printf("valor: %i\n", temp->valor);
			printf("==================\n\n");
			inicio = NULL;
			free(temp);
		}
	}
	tam--;
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int val, cont, posi;
	char op;
	int x=0;
	
	do{
		system("cls");
		printf("1 - adicionar valor\n");
		printf("2 - mostrar valores\n");
		printf("3 - apagar\n");
		printf("4 - sair\n");
		scanf("%s", &op);
		
		switch(op){
			case '1':{
				printf("quantos valores deseja adicionar?\n");
				scanf("%i", &cont);
				printf("\nCARREGANDO... \n");
				for(x; x<cont; x++){
					if(cont/5 == x){
						printf("20%%");
					}
					if(cont/2 == x){
						printf("\r");
						printf("50%%");
					}
					if(cont/1.25 == x){
						printf("\r");
						printf("80%%");
					}
					val = rand ();
					add(val);
				}
				system("cls");
				printf("ADICIONADO!!\n\n");
				system("pause");
				break;
			}
			case '2':{
				mostrar();
				break;
			}
			case '3':{
				printf("qual posição deseja apagar: \n");
				scanf("%i", &posi);
				if(inicio!=NULL){
					if(posi > tam || posi == 0){
						system("cls");
						printf("POSIÇÃO INVALIDA!!\n\n");
					}else{
						apagar(posi);	
					}
				}else{
					system("cls");
					printf("NADA FOI ADICIONADO AINDA!!\n\n");
				}
				system("pause");
				break;
			}
			default:{
				system("cls");
				if(op == '4'){
					printf("SAINDO...\n\n");
				}else{
					printf("OPÇÃO ERRADA!!\n\n");
					system("pause");
				}
				break;
			}
		}
	}while(op!='4');
	
	return 0;
}
