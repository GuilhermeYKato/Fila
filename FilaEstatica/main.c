#include <stdio.h>
#include <stdbool.h>
#define N 10

typedef struct {
    int chave;
}Objeto;

typedef struct {
    int inicio;
    int fim;
    Objeto array[N];
    int contador;
}FilaEstatica;

bool estaVazia(FilaEstatica *fila){
    if(fila->contador == 0){
        return true;
    } else {
        return false;
    }
    //return (fila->contador == 0);
}
bool estaCheia(FilaEstatica *fila){
    if(fila->contador == N){
        return true;
    } else {
        return false;
    }
    //return (fila->contador == N);
}

void iniciaFila(FilaEstatica *fila){
    fila->inicio = 0;
    fila->fim = -1;
    fila->contador = 0;
}

int incrementaIndice(int i){ //BUFFER CIRCULAR
    i++;
    if( i == N ){
        i = 0;
    }
    return (i);
}

void enfileira(Objeto x, FilaEstatica *fila){
    if(estaCheia(fila) == 0){
        fila->fim = incrementaIndice(fila->fim);
        fila->array[fila->fim] = x;
        fila->contador++;
    }


}

Objeto desenfileira(FilaEstatica *fila){
    Objeto aux;
    if(estaVazia(fila)==0){
        aux = fila->array[fila->inicio];
        fila->inicio = incrementaIndice(fila->inicio);
        fila->contador -= 1;
        return (aux);
    }
}

void imprimeFila(FilaEstatica *fila){
/*    printf("[ ");
    for(int i =0; i < fila->contador; i++){
            printf("%i ", fila->array[i].chave);
        
    }
    printf(" ]\n");
*/

    int iterador = fila->inicio;

    if(fila->contador == 0){
        printf("Fila = [ ]\n");
    } else {
      printf("Fila = [ ");
      while(iterador != fila->fim){
          printf ("%d ", fila->array[iterador].chave);
          if(iterador == (N-1)) {
              iterador = 0;
          } else {
              iterador++;
          }
      }
      printf("%d ]\n", fila->array[fila->fim].chave);
    }
 }

int tamanhoFila(FilaEstatica *fila){

    return (fila->contador);
}

Objeto primeiro(FilaEstatica *fila){
    Objeto aux;
    aux = fila->array[fila->inicio];
    return (aux);
}

Objeto ultimo(FilaEstatica *fila){
    Objeto aux;
    aux = fila->array[fila->fim];
    return (aux);
}

int main() {
    FilaEstatica fila;
    Objeto obj;
    int x;
    iniciaFila(&fila);

    obj.chave = 4;
    enfileira(obj, &fila);

    obj.chave = 1;
    enfileira(obj, &fila);

    obj.chave = 3;
    enfileira(obj, &fila);

    desenfileira(&fila);

    obj.chave = 8;
    enfileira(obj, &fila);

    desenfileira(&fila);

    imprimeFila(&fila);

    printf("Primeiro: %d\n", primeiro(&fila));
    printf("Ultimo: %d\n", ultimo(&fila));
    printf("Ultimo: %d\n", tamanhoFila(&fila));


    return 0;
}
