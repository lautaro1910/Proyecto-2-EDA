#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "persona.h"

typedef struct Nodo{
    Persona vipd;
    struct Nodo *ps;
}Nodo;

typedef struct Lista{
    Nodo *acc;
    Nodo *cur;
    Nodo *curaux;
}Lista;

void inicializarL (Lista *l)
{
    l->acc = NULL;
    l->cur = NULL;
    l->curaux = NULL;
}

void resetL(Lista *l)
{
    l->cur = l->acc;
    l->curaux = l->acc;
}

int insertL (Lista *l, Persona p)
{
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    if(aux!=NULL){
        if((l->cur)==(l->acc))
        {
            l->acc = aux;
            aux->ps = l->cur;
            l->cur = l->acc;
            l->curaux = l->acc;
        }
        else
        {
            (l->curaux)->ps = aux;
            (*aux).ps = l->cur;
            l->cur = aux;
        }
        (l->cur)->vipd = p;
        return 1;
    }
    else {
        return 0;
    }
}

void supressL(Lista *l)
{
    if ((l->cur)==(l->acc))
    {
        (*l).acc =((*l).cur)->ps;
        free((*l).cur);
        (*l).cur = (*l).acc;
        (*l).curaux = (*l).acc;
    }
    else
    {
        (l->curaux)->ps = (l->cur)->ps;
        free((*l).cur);
        (*l).cur = (l->curaux)->ps;
    }
}

void forwardL(Lista *l)
{
    l->curaux = l->cur;
    l->cur = (l->cur)->ps;
}

Persona copyL (Lista l)
{
    return (l.cur)->vipd;
}

int emptyL(Lista l)
{
    if (l.acc==NULL)  return 1;
    else          return 0;
}

int fullL()
{
    Nodo *aux=(Nodo*)malloc(sizeof(Nodo));

    if(aux!=NULL)
    {
        free(aux);
        return 0;
    }
    else
    {
        return 1;
    }
}

int oosL(Lista l)
{
    if (l.cur==NULL) return 1;
    else    return 0;
}
