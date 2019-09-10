#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"
#include "FilaDinamica.h"

int main(int argc, char** argv) {
    int ESCOLHA = 0;
    printf("1 - Fila Estatica\n2 - Fila Dinamica\n");
    scanf("%i", &ESCOLHA);
    if (ESCOLHA == 1) {

        FilaEstatica filaEstatica;
        ObjetoEstatico obj;
        int x;
        iniciaFilaEstatica(&filaEstatica);

        obj.chave = 4;
        enfileiraEstatica(obj, &filaEstatica);

        obj.chave = 1;
        enfileiraEstatica(obj, &filaEstatica);

        obj.chave = 3;
        enfileiraEstatica(obj, &filaEstatica);

        desenfileiraEstatica(&filaEstatica);

        obj.chave = 8;
        enfileiraEstatica(obj, &filaEstatica);

        desenfileiraEstatica(&filaEstatica);

        imprimeFilaEstatica(&filaEstatica);
        
        printf("Primeiro: %i\n", primeiroEstatica(&filaEstatica).chave);
        printf("Ultimo: %i\n", ultimoEstatica(&filaEstatica).chave);
        printf("Tamanho: %i\n", tamanhoFilaEstatica(&filaEstatica));
    } else if (ESCOLHA == 2) {
        FilaDinamica filaDinamica;
        ObjetoDinamico obj;
        iniciaFilaDinamica(&filaDinamica);
        
        obj.chave = 3;
        enfileiraDinamica(obj, &filaDinamica);
        
        obj.chave = 8;
        enfileiraDinamica(obj, &filaDinamica);
        
        
    } else {
        printf("\tEscolha Invalida\n\n\tERRO ERRO ERRO\n\n");
    }






    return (EXIT_SUCCESS);
}

