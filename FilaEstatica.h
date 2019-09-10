#ifndef FILAESTATICA_H
#define FILAESTATICA_H
#include <stdio.h>
#include <stdbool.h>
#define MAXN 10

typedef struct {
    int chave;
} ObjetoEstatico;

typedef struct {
    int inicio;
    int fim;
    ObjetoEstatico array[MAXN];
    int contador;
} FilaEstatica;

bool estaVaziaEstatica(FilaEstatica *fila) {
    if (fila->contador == 0) {
        return true;
    } else {
        return false;
    }
    //return (fila->contador == 0);
}

bool estaCheiaEstatica(FilaEstatica *fila) {
    if (fila->contador == MAXN) {
        return true;
    } else {
        return false;
    }
    //return (fila->contador == N);
}

void iniciaFilaEstatica(FilaEstatica *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->contador = 0;
}

int incrementaIndiceEstatica(int i) { //BUFFER CIRCULAR
    i++;
    if (i == MAXN) {
        i = 0;
    }
    return (i);
}

void enfileiraEstatica(ObjetoEstatico x, FilaEstatica *fila) {
    if (estaCheiaEstatica(fila) == 0) {
        fila->fim = incrementaIndiceEstatica(fila->fim);
        fila->array[fila->fim] = x;
        fila->contador++;
    }


}

ObjetoEstatico desenfileiraEstatica(FilaEstatica *fila) {
    ObjetoEstatico aux;
    if (estaVaziaEstatica(fila) == 0) {
        aux = fila->array[fila->inicio];
        fila->inicio = incrementaIndiceEstatica(fila->inicio);
        fila->contador -= 1;
        return (aux);
    }
}

void imprimeFilaEstatica(FilaEstatica *fila) {
    /*    printf("[ ");
        for(int i =0; i < fila->contador; i++){
                printf("%i ", fila->array[i].chave);
        
        }
        printf(" ]\n");
     */

    int iterador = fila->inicio;

    if (fila->contador == 0) {
        printf("Fila = [ ]\n");
    } else {
        printf("Fila = [ ");
        while (iterador != fila->fim) {
            printf("%d ", fila->array[iterador].chave);
            if (iterador == (MAXN - 1)) {
                iterador = 0;
            } else {
                iterador++;
            }
        }
        printf("%d ]\n", fila->array[fila->fim].chave);
    }
}

int tamanhoFilaEstatica(FilaEstatica *fila) {

    return (fila->contador);
}

ObjetoEstatico primeiroEstatica(FilaEstatica *fila) {
    ObjetoEstatico aux;
    aux = fila->array[fila->inicio];
    return (aux);
}

ObjetoEstatico ultimoEstatica(FilaEstatica *fila) {
    ObjetoEstatico aux;
    aux = fila->array[fila->fim];
    return (aux);
}


#endif /* FILADINAMICA_H */

