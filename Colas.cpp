#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *siguiente;
} TipoNodo;

typedef TipoNodo *cnodo;

void Add(cnodo *primero, cnodo *ultimo, int v);
int Read(cnodo *primero, cnodo *ultimo);
void Print(cnodo primero);

int main() {
    cnodo primero = NULL, ultimo = NULL;

    Add(&primero, &ultimo, 10);
    Add(&primero, &ultimo, 20);
    Add(&primero, &ultimo, 30);
    Add(&primero, &ultimo, 40);

    printf("1.-Insertar (10)\n");
    printf("2.-Insertar (20)\n");
    printf("3.-Insertar (30)\n");
    printf("4.-Insertar (40)\n");

    Print(primero);

    while (primero != NULL) {
        Read(&primero, &ultimo);
    }

    return 0;
}

void Add(cnodo *primero, cnodo *ultimo, int v) {
    cnodo nuevo = (cnodo)malloc(sizeof(TipoNodo));
    if (!nuevo) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    nuevo->valor = v;
    nuevo->siguiente = NULL;
    if (*ultimo) {
        (*ultimo)->siguiente = nuevo;
    }
    *ultimo = nuevo;
    if (!*primero) {
        *primero = nuevo;
    }
}

int Read(cnodo *primero, cnodo *ultimo) {
    cnodo nodo;
    int v;
    nodo = *primero;
    if (!nodo) {
        return 0;
    }
    *primero = nodo->siguiente;
    v = nodo->valor;
    free(nodo);
    if (*primero == NULL) {
        *ultimo = NULL;
    }
    return v;
}

void Print(cnodo primero) {
    cnodo actual = primero;
    while (actual != NULL) {
        printf("->%d", actual->valor);
        actual = actual->siguiente;
    }
}

