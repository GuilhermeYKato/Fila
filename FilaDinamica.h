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

        fila->fim = fila->inicio = aux;

    } else {

        fila->fim->proximo = aux;
        fila->fim = fila->fim->proximo; // fim = aux

    }
    
    fila->contador++;
}

ObjetoDinamico desenfileiraDinamica(FilaDinamica *fila) {
    PtrNoFila aux;
    ObjetoDinamico obj;

    if (!estaVaziaDinamica(fila)) {
        
        aux = fila->inicio;
        obj = aux->obj;
        fila->inicio = fila->inicio->proximo;
        free(aux);
        fila->contador--;
        
    } else {
        printf("\n\tERRO PILHA VAZIA\n\n");
        obj.chave = -1;
    }
    return (obj);
}

void imprimeFilaDinamica(FilaDinamica *fila) {
    printf("\n\t[ ");
    PtrNoFila ptr;
    for (ptr = fila->inicio; ptr != NULL; ptr = ptr->proximo) {
        printf("%d ", ptr->obj.chave);
    }
    printf(" ]\n");
}


int tamanhoFilaDinamica(FilaDinamica *fila) {
    return (fila->contador);

}

ObjetoDinamico primeiroDinamica(FilaDinamica *fila) {
    ObjetoDinamico ret;
    if (estaVaziaDinamica(fila)) {
        printf("Pilha Vazia Troxa\n");
        ret.chave = -1;
    } else {
        ret = fila->inicio->obj;

    }
    return (ret);


}

ObjetoDinamico ultimoDinamica(FilaDinamica *fila) {
    ObjetoDinamico ret;
    if (estaVaziaDinamica(fila)) {
        printf("Pilha Vazia Troxa\n");
        ret.chave = -1;
    } else {
        ret = fila->fim->obj;


    }
    return (ret);

}

void destroiFilaDinamica(FilaDinamica *fila) {


}

#endif /* FILADINAMICA_H */

