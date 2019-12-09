/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: link
 *
 * Created on 30 de mayo de 2018, 19:57
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * 
 */
typedef struct nodo{
    int n;
    struct nodo *izq;
    struct nodo *der;
} NODO;

void escribirFichero(){
    FILE *f = fopen ("lista.txt", "w");
    if(f!=NULL){
        int i=0;
        for(i=0; i<10;i++){
            fprintf(f, "%d\n",i);
        }
    }
    fclose(f);
}

void leerFichero(){
    FILE *f = fopen ("Lista.txt", "r");
    int num;
    if(f!=NULL){
        do{
            fscanf(f,"%d",&num);
            printf("%d\n", num);
        }while(!feof(f));
    }
    fclose(f);
}

void insertar (NODO** a, int valor){
    NODO *nodo = *a;
    if(nodo==NULL){ // esta vacío
        nodo = (NODO*) malloc (sizeof(NODO));
        nodo->n = valor;
        nodo->der=NULL;
        nodo->izq = NULL;
        *a = nodo;
    }else{
        if(valor< nodo->n){
            insertar(&(nodo->izq), valor);
        }else{
            insertar(&(nodo->der), valor);
        }
    }
}

void inOrden(NODO* a){
    if(a!=NULL){
        inOrden(a->izq);
        printf("%d\n", a->n);
        inOrden(a->der);
    }
}

void preOrden(NODO* a){
    if(a!=NULL){
        printf("%d\n", a->n);
        preOrden(a->izq);
        preOrden(a->der);
    }
}

void preOrdenFichero(NODO* a, FILE *f){
    if(a!=NULL){
        fprintf(f,"%d\n", a->n);
        preOrdenFichero(a->izq, f);
        preOrdenFichero(a->der, f);
    }
}


int escribe(NODO *a, char *fic){
    FILE *f=fopen(fic, "w");
    if(f!=NULL)
        preOrdenFichero(a,f);
    fclose(f);
    return 0;
}

int lee(NODO **a, char *fic){
    FILE *f=fopen(fic, "r");
    int num;
        if(f!=NULL){
            
        do{
            fscanf(f,"%d",&num);
            insertar(a,num);
        }while(!feof(f));
    }
    fclose(f);
    return 0;
}

int main(int argc, char** argv) {
    NODO *arbol = NULL;
    
 
    //escribirFichero();
    //leerFichero();
    printf("insertamos nodos\n\n");
    insertar (&arbol, 5);
    insertar (&arbol, 4);
    insertar (&arbol, 1);
    insertar (&arbol, 6);
    insertar (&arbol, 2); 
    insertar (&arbol, 8);
    
    printf("\nRecorrido en pre-orden\n");
    preOrden(arbol);
    //inOrden(arbol);
   
    printf("\nEscribimos el fichero\n");
    escribe(arbol, "arbol.txt");
    
    printf("\nLeemos el fichero el fichero\n");
    
    NODO *arbol2 = NULL;
    lee(&arbol2, "arbol.txt");
    
    printf("\nRecorrido en pre-orden\n");
    preOrden(arbol);
    

    
    
}

