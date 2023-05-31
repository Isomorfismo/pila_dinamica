#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    int dato;
    struct nodo *sig;
}nodo;

typedef struct Pila{
    nodo *top;
}pila;

void crear(pila *p);
int estaVacia(pila *p);
void push(pila *p, int dato);
int pop(pila *p);
void mostrar(pila *p);
void vaciar(pila *p);

int main(){
    pila p;
    crear(&p);
    int dato, opcion;
    do{
        printf("1. Insertar\n");
        printf("2. Extraer\n");
        printf("3. Mostrar\n");
        printf("4. Vaciar\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                printf("Dato: ");
                scanf("%d", &dato);
                push(&p, dato);
                break;
            case 2:
                dato=pop(&p);
                printf("Dato extraido: %d\n", dato);
                break;
            case 3:
                mostrar(&p);
                break;
            case 4:
                vaciar(&p);
                break;
            case 5:
                printf("Adios\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }while(opcion!=5);
    return 0;
}

void crear(pila *p){
    p->top=NULL;
}

int estaVacia(pila *p){
    return p->top == NULL ? 1 : 0;
} 

void push(pila *p, int dato){
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->sig=p->top;
    p->top=nuevo;
}

int pop(pila *p){
    if(estaVacia(p)){
        printf("Pila vacia\n");
        return -1;
    }
    int dato=p->top->dato;
    nodo *aux=p->top;
    p->top=p->top->sig;
    free(aux);
    return dato;
}

void mostrar(pila *p){
    if(estaVacia(p)){
        printf("Pila vacia\n");
        return;
    }
    nodo *aux=p->top;
    while(aux!=NULL){
        printf("%d\n", aux->dato);
        aux=aux->sig;
    }
}

void vaciar(pila *p){
    nodo *aux=p->top;
    while(aux!=NULL){
        p->top=p->top->sig;
        free(aux);
        aux=p->top;
    }
}
