#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fila_prioridade.h"

#define ALEATORIO  0
#define CONTROLADO 1

#define INSERIR        0
#define INSERIRREMOVER 1

#define CRESCENTE   0
#define DECRESCENTE 1

int aletatorio(){
    
  // Inserindo numeros aleatorios
  srand(time(NULL));
  int n = 100;
  int i, elemento;
    
  FilaPrioridade* f = filaP_criar();
    
  for (i=0; i < n; i++){
    filaP_inserir(f, rand() % (n*10));        
  }

  // Removendo e imprimindo todos os elementos
  while(!filaP_vazia(f)){
    filaP_remover(f, &elemento);
    printf("%d ", elemento);
  }
  filaP_destruir(&f);
  printf("\n");
  return 0; 
}

int controlado(){
  int elemento;
  char str[100];

  FilaPrioridade* f = filaP_criar();
  filaP_inserir(f, 15);
  filaP_inserir(f, 10);
  filaP_inserir(f, 4);
  filaP_inserir(f, 7);
  filaP_inserir(f, 13);
  filaP_inserir(f, 3);
  filaP_inserir(f, 2);
  filaP_inserir(f, 6);
  filaP_inserir(f, 1);
  filaP_inserir(f, 5);
  filaP_toString(f, str);
  printf("%s\n", str );

  filaP_remover(f, &elemento);
  filaP_toString(f, str);
  printf("%s\n", str );

  filaP_remover(f, &elemento);
  filaP_toString(f, str);
  printf("%s\n", str );
    
  filaP_remover(f, &elemento);
  filaP_toString(f, str);
  printf("%s\n", str );

  filaP_remover(f, &elemento);
  filaP_toString(f, str);
  printf("%s\n", str );

  filaP_remover(f, &elemento);
  filaP_toString(f, str);
  printf("%s\n", str );

  filaP_remover(f, &elemento);
  filaP_toString(f, str);
  printf("%s\n", str );

  filaP_remover(f, &elemento);
  filaP_toString(f, str);
  printf("%s\n", str );

  filaP_remover(f, &elemento);
  filaP_toString(f, str);
  printf("%s\n", str );

  filaP_remover(f, &elemento);
  filaP_toString(f, str);
  printf("%s\n", str );


  filaP_remover(f, &elemento);
  filaP_toString(f, str);
  printf("%s\n", str );

  filaP_destruir(&f);
  return 0; 
}

int main(int argc, char **argv) {
  int i;
  int N;
  
  int modo1; // Aleatório ou Controlado
  int modo2; // Adicionar ou Adicionar e Remover
  int modo3; // Crescente ou decrescente

  int buffer;
  FilaPrioridade *PQ;

  if ( argc != 4 ) {
    printf("Usage: %s A|CC|CD A|R N\n", argv[0]);
    printf("Arguments:\n");
    printf("A|C Aleatório | Controlado Crescente | Controlado Decrescente\n");
    printf("I|R Inserir   | Inserir e Remover\n");
    printf("N   Quantidade de entradas\n");
    return -1;
  }

  if ( argv[1][0] == 'A' ) {
    modo1 = ALEATORIO;
  }
  else {
    modo1 = CONTROLADO;

    if ( argv[1][1] == 'C' ) {
      modo3 = CRESCENTE;
    }
    else {
      modo3 = DECRESCENTE;
    }
  }

  if ( argv[2][0] == 'I' ) {
    modo2 = INSERIR;
  }
  else {
    modo2 = INSERIRREMOVER;
  }

  N = atoi(argv[3]);

  printf("Running [%d, %d, %d]\n", modo1, modo2, N);

  srand(time(NULL));

  if ( modo1 == ALEATORIO ) {
    if ( modo2 == INSERIR ) {
      // ALEATORIO
      // INSERIR
      PQ = filaP_criar();
      for ( i = 0; i < N; i++ ) {
	filaP_inserir(PQ, rand() % (N));
      }

      filaP_destruir(&PQ);
    }
    else {
      // ALEATORIO
      // INSERIR E REMOVER
      PQ = filaP_criar();
      for ( i = 0; i < N; i++ ) {
	filaP_inserir(PQ, rand() % (N));
      }

      for ( i = 0; i < N; i++ ) {
	filaP_remover(PQ, &buffer);
      }

      filaP_destruir(&PQ);
    }
  }
  else {
    if ( modo2 == INSERIR ) {
      if ( modo3 == CRESCENTE ) {
	// CONTROLADO
	// INSERIR
	// CRESCENTE
	PQ = filaP_criar();
	for ( i = 0; i < N; i++ ) {
	  filaP_inserir(PQ, i);
	}

	filaP_destruir(&PQ);
      }
      else {
	// CONTROLADO
	// INSERIR
	// DECRESCENTE
	PQ = filaP_criar();
	for ( i = N; i >= 0; i-- ) {
	  filaP_inserir(PQ, i);
	}

	filaP_destruir(&PQ);
      }      
    }
    else {
      if ( modo3 == CRESCENTE ) {
	// CONTROLADO
	// INSERIR E REMOVER
	// CRESCENTE
	PQ = filaP_criar();
	for ( i = 0; i < N; i++ ) {
	  filaP_inserir(PQ, i);
	}

	for ( i = 0; i < N; i++ ) {
	  filaP_remover(PQ, &buffer);
	}

	filaP_destruir(&PQ);
      }
      else {
	// CONTROLADO
	// INSERIR E REMOVER
	// DECRESCENTE
	PQ = filaP_criar();
	for ( i = N; i >= 0; i-- ) {
	  filaP_inserir(PQ, i);
	}

	for ( i = N; i >=0; i-- ) {
	  filaP_remover(PQ, &buffer);
	}
	
	filaP_destruir(&PQ);
      }
    }
  }

  return 0;
}
