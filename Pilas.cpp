#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo* siguiente;
} TipoNodo;

typedef TipoNodo* pNodo;
typedef TipoNodo* Pila;

void Push(Pila* pila, int n);
int Pop(Pila* pila);
void PrintPila(Pila pila);

int main() {
    Pila pila = NULL;
    Push(&pila, 10);
    Push(&pila, 30);
    Push(&pila, 20);
    Push(&pila, 50);
    Push(&pila, 40);
    PrintPila(pila);
    
    return 0;
}

void Push(Pila* pila, int v) {
    pNodo nuevo = (pNodo)malloc(sizeof(TipoNodo));
    nuevo->valor = v;
    nuevo->siguiente = *pila;
    *pila = nuevo;
}

int Pop(Pila* pila) {
    pNodo nodo = *pila;
    int v;
    if (!nodo) {
        return 0;
    }
    *pila = nodo->siguiente;
    v = nodo->valor;
    free(nodo);
    return v;
}

void PrintPila(Pila pila) {
    printf("Contenido de la pila: ");
    while (pila != NULL) {
        printf("%d ", Pop(&pila));
    }
    printf("\n");
}

