//Haz un programa que lea una pila dinamica de enteros
//La pila tiene funciones para crear la pila, insertar, extraer, mostrar, vaciar y saber si esta vacia
//El programa tiene un menu con las opciones de insertar, extraer, mostrar, vaciar y salir

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    int dato;
    struct nodo *sig;
}nodo;

typedef struct Pila{
    nodo *tope;
}pila;

void crear(pila *p);
int estaVacia(pila *p);
void insertar(pila *p, int dato);
int extraer(pila *p);
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
                insertar(&p, dato);
                break;
            case 2:
                dato=extraer(&p);
                if(dato!=-1){
                    printf("Dato extraido: %d\n", dato);
                }
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
    p->tope=NULL;
}

int estaVacia(pila *p){
    return p->tope == NULL ? 1 : 0;
} 

void insertar(pila *p, int dato){
    nodo *nuevo=(nodo*)malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->sig=p->tope;
    p->tope=nuevo;
}

int extraer(pila *p){
    if(estaVacia(p)){
        printf("Pila vacia\n");
        return -1;
    }
    int dato=p->tope->dato;
    nodo *aux=p->tope;
    p->tope=p->tope->sig;
    free(aux);
    return dato;
    
}

void mostrar(pila *p){
    if(estaVacia(p)){
        printf("Pila vacia\n");
        return;
    }
    nodo *aux=p->tope;
    while(aux!=NULL){
        printf("%d\n", aux->dato);
        aux=aux->sig;
    }
}

void vaciar(pila *p){
    nodo *aux=p->tope;
    while(aux!=NULL){
        p->tope=p->tope->sig;
        free(aux);
        aux=p->tope;
    }
}