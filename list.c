#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node 
{
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) 
{
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
  List* nuevo = (List*)malloc(sizeof(List*));
  return nuevo;
}


//La primera retorna el dato del primer nodo de la lista (head) y actualiza el current para que apunte a ese nodo.
void * firstList(List * list) 
{
  if(list->head == NULL) 
  {
    list->current = NULL;
    return NULL;
  }
  
  list->current = list->head;
  return list->head->data;
}

//La segunda función retorna el dato del nodo a continuación del current y actualiza el current para que apunte a ese nodo.
void * nextList(List * list) 
{
  if(list->current == NULL || list->current->next == NULL) 
  {
    list->current = NULL;
    return NULL;
  }

  list->current = list->current->next;
  return list->current->data; 
}

//La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente.
void * lastList(List * list) 
{
  Node* aux = list->head;

  if(list->head == NULL)
  {
    list->current = NULL;
    return NULL;
  }
  
  aux = list->tail;
  list->current = aux;
  return aux->data;
}

/* opcion 2 (sin el tail)
void * lastList(List * list) 
{
  Node* aux = list->head;

  if(list->head == NULL)
  {
    list->current = NULL;
    return NULL;
  }

  while(aux->next != NULL)
  {
    aux = aux->next;
  }

  list->current = aux;
  return aux->data;
}
*/


//La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.
void * prevList(List * list) 
{
  if(list->current == NULL || list->current->prev == NULL)
  {
    list->current = NULL;    
    return NULL;
  }
  
  list->current = list->current->prev;  
  return list->current->data;
}


//Programe la función void pushFront(List * list, void * data), la cual agrega un dato al comienzo de la lista.

void pushFront(List * list, void * data) 
{
  Node* nuevo = createNode();
  nuevo->data = data;
  
  if(list->head == NULL)
  {
    list->head = nuevo;
    return;
  }

  
  list->head->prev = nuevo;
  nuevo->next = list->head;
  nuevo->prev = NULL;
  
  list->head = nuevo;
  
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}