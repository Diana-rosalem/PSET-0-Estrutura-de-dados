#include "prototipos.h"

struct no{
	int info;
	NO *proximo, *anterior;
};

NO *inserirInicio(NO *lista, int v){			
	
	NO *novo;
	novo = (NO*) malloc(sizeof(NO));
	novo->info = v;

	if( lista==NULL){
		novo->proximo = NULL;
		novo->anterior = NULL;
	}else{
		novo->proximo = lista;
		
		lista->anterior = novo;
	}
	return novo;
}

NO *inserirFinal(NO *lista, int v){				
	NO *novo;
	novo = (NO*) malloc(sizeof(NO));
	novo->info = v;

	if( lista == NULL){
		novo->proximo = lista;
		return novo;
	}else{
		NO *aux;	
		for(aux = lista; aux->proximo != NULL; aux = aux->proximo);
		aux->proximo = novo;
		return lista;
	}
}

NO *inserirOrdenado(NO *lista, int v){			
	NO *novo;
	novo = (NO*) malloc(sizeof(NO));
	novo->info = v;
	if( lista == NULL){
		novo->proximo  = lista;
		return novo;
	}else{
		//INICIO
		if( lista->info > novo->info){
			novo->proximo = lista;
			return novo;
		}
		
		NO *aux;
		for(aux=lista; aux->proximo != NULL; aux= aux->proximo){
			//MEIO	
			if( aux->proximo->info > novo->info){
				novo->proximo = aux->proximo;
				aux->proximo = novo;
				return lista;
			}
		}
		aux->proximo = novo;
		return lista;
	}
}

NO *criarLista(){								
	return NULL;
	//linhavazia
}

void mostrarLista(NO *lista){					
	if( lista == NULL){
		printf("Lista Vazia.\n");
	}else{
		printf("LISTA: ");
		for(NO *aux=lista; aux != NULL; aux = aux->proximo){
			printf("|| %d || <-> ",aux->info);
		}
		printf("\n");
	}
}

void mostrarInverso(NO *lista){		

	if(lista == NULL){
		printf("Lista Vazia.\n");
	}else{
		if(lista->proximo == NULL){
      printf("LISTA INVERTIDA: "); 
			printf(" || %d ||<-> ", lista->info);
			return ;
		}
    
    mostrarInverso(lista->proximo);
	  printf(" || %d ||<-> ", lista->info);
	}
}

NO *buscar(NO *lista, int v){					
	if( lista == NULL){
		printf("Lista Vazia.\n");
		return criarLista();
	}else{
		for(NO *aux=lista; aux != NULL; aux= aux->proximo){
			if( aux->info == v){
				printf("Valor encontrado.\n");
				return aux;
			}
		}
		printf("Valor não encontrado.\n");
		return criarLista();
	}
}

int qtdElementos(NO *lista){					
	int qtd = 0;
	for(NO *aux=lista; aux != NULL; aux= aux->proximo){
		qtd++;
	}
	return qtd;
}

NO* removerElemento(NO *lista, int valor){		
	if( lista == NULL){
		printf("Lista Vazia.\n");
		return lista;
	}else{

		NO *aux;
		//INICIO
		if(lista->info == valor){	
			printf("Valor %d encontrado.\n", valor);
			return lista->proximo;
		}
		for(aux=lista; aux->proximo != NULL; aux= aux->proximo){
			if( (aux->proximo)->info == valor){
				NO *local;
				local = (aux->proximo)->proximo;
				aux->proximo = local;
				printf("Valor %d encontrado.\n", valor);
				return lista;
			}
		}
		printf("Valor %d não encontrado.\n", valor);
		return lista;
	}
}

void liberar(NO *lista){						
	if( lista->proximo != NULL){
		liberar(lista->proximo);
	}
	printf("Limpando elemento: %d\n", lista->info);
	free(lista);
}