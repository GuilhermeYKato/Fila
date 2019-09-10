#ifndef FILADINAMICA_H
#define FILADINAMICA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} ObjetoDinamico;

typedef struct NoFila *PtrNoFila;

typedef struct NoFila {
    ObjetoDinamico obj;
    PtrNoFila proximo;

} NoFila;

typedef struct {
    PtrNoFila inicio;
    PtrNoFila fim;
    int contador;
} FilaDinamica;

void iniciaFilaDinamica(FilaDinamica *fila) {
    fila->contador = 0;
    fila->fim = NULL;
    fila->inicio = NULL;
}

int estaVaziaDinamica(FilaDinamica *fila) {
    return (fila->contador == 0);
    //pode ser tambem:
    //return (fila->inicio == NULL);
}

void enfileiraDinamica(ObjetoDinamico item, FilaDinamica *fila) {
    PtrNoFila aux;
    aux = (PtrNoFila) malloc(sizeof (NoFila));
    aux->obj = item;
    aux->proximo = NULL;

    if (estaVaziaDinamica(fila)) {

        aux = fila->fim = fila->inicio;

    } else {

        fila->fim->proximo = aux;
        fila->fim = fila->fim->proximo; // fim = aux

    }
    
    fila->contador++;
}

ObjetoDinamico desenfileiraDinamica(FilaDinamica *fila) {


}

void imprimeFilaDinamica(FilaDinamica *fila) {


}


int tamanhoFilaDinamica(FilaDinamica *fila) {
    return (fila->contador);

}

ObjetoDinamico primeiroDinamica(FilaDinamica *fila) {


}

ObjetoDinamico ultimoDinamica(FilaDinamica *fila) {


}

void destroiFilaDinamica(FilaDinamica *fila) {


}

#endif /* FILADINAMICA_H */

