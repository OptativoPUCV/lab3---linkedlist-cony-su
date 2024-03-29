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

//1. Programe la función List* createList(), la cual retorna el puntero del tipo de dato List con sus valores inicializados en NULL.
List * createList() 
{
  List* nuevo = (List*)malloc(sizeof(List*));
  return nuevo;
}


//2. La primera retorna el dato del primer nodo de la lista (head) y actualiza el current para que apunte a ese nodo.
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

//2. La segunda función retorna el dato del nodo a continuación del current y actualiza el current para que apunte a ese nodo.
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

//3. La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente.
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


//3. La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.
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


//4. Programe la función void pushFront(List * list, void * data), la cual agrega un dato al comienzo de la lista.

void pushFront(List * list, void * data) 
{
  Node* nuevo = createNode(data);
  
  if(list->head == NULL)
  {
    list->head = nuevo;
    list->tail = nuevo;
    return;
  }

  nuevo->next = list->head;
  list->head->prev = nuevo;
  nuevo->prev = NULL;  
  list->head = nuevo;
  return;
}

void pushBack(List * list, void * data) 
{
  
  list->current = list->tail;
  pushCurrent(list,data);
  
}

//5. Programe la función void pushCurrent(List * list, void* data), la cual agrega un dato a continuación del nodo apuntado por list->current.
void pushCurrent(List * list, void * data) 
{
  Node* nuevo = createNode(data);
  if(list->current == NULL)
  {
    list->current = nuevo;
    return;
  }
//el siguiente del nuevo es el siguiente del current
  nuevo->next = list->current->next;
//Si el nodo siguiente al nodo actual no es NULL, se actualiza el puntero prev de ese nodo para que apunte al nuevo nodo que se está insertando, estableciendo así la conexión en ambos sentidos entre los nodos.
  if(list->current->next != NULL) list->current->next->prev = nuevo;
  //el prev del nuevo es el current
  nuevo->prev = list->current;
//el siguiente del current es el nuevo
  list->current->next = nuevo;
//si no hay nodo despues de nuevo, tail se actualiza
  if(nuevo->next == NULL) list->tail = nuevo;
  
  return;
}


//NO TOCAR
void * popFront(List * list) 
{
    list->current = list->head;
    return popCurrent(list);
}

//NO TOCAR
void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}


//Programe la función void* popCurrent(List * list), la cual elimina el nodo que está en la posición del current de la lista enlazada, y además retorna el dato del nodo eliminado. El current debe quedar apuntando al nodo siguiente del eliminado.
void * popCurrent(List * list) 
{
  if(list->current == NULL) return NULL;
  
  Node* nodo_eliminado = list->current;
  void* dato_eliminado = list->current->data;

  if(list->current == list->head) //si es el primero, head se actualiza
  {
    list->head = list->current->next;
  }
    
  if(list->current == list->tail)
  {
    list->tail = list->current->prev; 
  }

  if(list->current->prev != NULL)
  {
    list->current->prev->next = list->current->next;
  }

  if(list->current->next != NULL)
  {
    list->current->next->prev = list->current->prev;
  }

  list->current = list->current->next;
  
  /*void * dato_aux = list->current->data; 
  list->current->next->prev = list->current->next;*/
  
  return dato_eliminado;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}