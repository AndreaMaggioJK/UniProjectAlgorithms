#include <stdio.h>
#include <stdlib.h>
#include "List.h"

typedef struct node{
	void* value;
	struct node *next;
	struct node *prev;
} nodo;


typedef nodo * link;

struct _List{
	link front;
	link rear;
	unsigned long size;
};

struct _Iterator{
	List *lista;
	link current_node;
};


List *create_list(){
  List *lista = (List *)malloc(sizeof(List));
  if(lista == NULL){
    fprintf(stderr, "create_list: unable to allocate memory for the list");
    exit(EXIT_FAILURE);
  }
  lista->front = NULL;
  lista->rear = NULL;
  lista->size = 0;

  return(lista);
}

int list_is_empty(List *lista){
	if(lista == NULL){
    	fprintf(stderr,"list_is_empty: lista parameter cannot be NULL");
    	exit(EXIT_FAILURE);
  	}
	if(lista->front == NULL)
		return(1);
	return(0);
}

void list_free_memory(List *lista){
  if(lista == NULL){
    fprintf(stderr,"list_free_memory: lista parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  for (;lista->front != lista->rear;){
  	(lista->front) = (lista->front)->next;
  	free((lista->front)->prev);

  }
  free(lista->front);
  free(lista);
}

unsigned long list_size(List *lista){
  if(lista == NULL){
    fprintf(stderr,"list_size: lista parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  return(lista->size);
}

link allocate_node(void* value){

	link return_value = malloc(sizeof(nodo));
	return_value->value = value;
	return_value->next = NULL;
	return_value->prev = NULL;
	return return_value;
}

void add_queue_element(List *lista,void* elem){
	if(lista == NULL){
    	fprintf(stderr,"add_queue_element: lista parameter cannot be NULL");
    	exit(EXIT_FAILURE);
  	}
  	if(elem == NULL){
    	fprintf(stderr,"add_queue_element: element parameter cannot be NULL");
    	exit(EXIT_FAILURE);
  	}
	link new_node = allocate_node(elem);
	if ( !(list_is_empty(lista)) ){
		new_node->prev = lista->rear;
		(lista->rear)->next = new_node;
	}else{
		lista->front = new_node;
	}
	(lista->size)++;
	lista->rear = new_node;

}

void* list_get(List *lista, unsigned long i){
  if(lista == NULL){
    fprintf(stderr,"list_get: lista parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(i >= lista->size || i < 0){
    fprintf(stderr,"list_get: Index %lu is out of the list bounds",i);
    exit(EXIT_FAILURE);
  }
	link check_node = lista->front;
	for (int count = 0 ; count < i; count++ ){
		check_node = check_node->next;
	}
	return(check_node->value);
}

void delete_queue_element(List *lista){
	if( list_is_empty(lista) ){
		fprintf(stderr,"delete_queue_element: array cannot be empty");
    	exit(EXIT_FAILURE);
	}
	if(lista == NULL){
    	fprintf(stderr,"delete_queue_element: lista parameter cannot be NULL");
    	exit(EXIT_FAILURE);
  	}
  	(lista->size)--;
  	(lista->rear) = (lista->rear)->prev;
  	free((lista->rear)->next);
  	lista->rear->next = NULL;
}

void add_element(List *lista,void* elem,long unsigned index){
	if(lista == NULL){
    	fprintf(stderr,"add_element: lista parameter cannot be NULL");
    	exit(EXIT_FAILURE);
  	}
  	if(elem == NULL){
    	fprintf(stderr,"add_element: element parameter cannot be NULL");
    	exit(EXIT_FAILURE);
  	}
  	if(index > lista->size || index<0){
  		fprintf(stderr,"add_element: Index %lu is out of the list bounds",index);
    	exit(EXIT_FAILURE);
  	}
  	link new_node = allocate_node(elem);
  	link check_node = lista->front;
	int count = 0;
	for ( ; count < index && check_node->next != NULL; count++ ){
		check_node = check_node->next;
	}
	if( list_is_empty(lista) ){
		lista->rear = new_node;
		lista->front = new_node;
	}
	else if(index == 0){
		lista->front = new_node;
		new_node->next = check_node;
		check_node->prev = new_node; 
	}else if(index == lista->size){
		check_node->next = new_node;
		new_node->prev = check_node;
		lista->rear = new_node;
	}else{
		new_node->next = check_node;
		new_node->prev = check_node->prev;
		check_node->prev = new_node;
		(new_node->prev)->next = new_node;

	}
	(lista->size)++;

}

void delete_element(List *lista,unsigned long index){
	if( list_is_empty(lista) ){
		fprintf(stderr,"delete_element: array cannot be empty");
    	exit(EXIT_FAILURE);
	}
	if(lista == NULL){
    	fprintf(stderr,"delete_element: lista parameter cannot be NULL");
    	exit(EXIT_FAILURE);
  	}
  	if(index >= lista->size || index<0){
  		fprintf(stderr,"delete_element: Index %lu is out of the list bounds",index);
    	exit(EXIT_FAILURE);
  	}
  	link check_node = lista->front;
	int count = 0;
	for ( ; count < index; count++ ){
		check_node = check_node->next;
	}
	if (lista->size == 1){
		free(lista->front);
		lista->front = NULL;
		lista->rear = NULL;
	}
	else if(index == 0){
		check_node = check_node->next;
		free(lista->front);
		lista->front = check_node;
		check_node->prev = NULL;
	}
	else if(index == lista->size-1){
		check_node = check_node->prev;
		check_node->next = NULL;
		free(lista->rear);
		lista->rear = check_node;
	}
	else{
		(check_node->next)->prev = check_node->prev;
		(check_node->prev)->next = check_node->next;
		free(check_node);
	}
  	(lista->size)--;
}

void print_List(List *lista){
	printf("front ->  %d\n",*((int*)list_get(lista,0)));
	int i = 1;
	for (; i < (lista->size)-1; ++i){
		printf("          %d\n",*((int*)list_get(lista,i)));
	}
	printf("rear ->   %d\n",*((int*)list_get(lista,i)));
}

Iterator *create_iterator(List *lista){

	Iterator *iteratore = (Iterator *)malloc(sizeof(Iterator));
	if(iteratore == NULL){
    	fprintf(stderr, "create_iterator: unable to allocate memory for the Iterator");
    	exit(EXIT_FAILURE);
  	}
  	iteratore->lista = lista;
  	iteratore->current_node = lista->front;
}


void iterator_free_memory(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iteratore_free_memory: iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  free(iteratore);
}

void* iterator_get(Iterator *iteratore){
	if(iteratore == NULL){
    	fprintf(stderr, "iterator_get: iteratore parameter cannot be NULL");
    	exit(EXIT_FAILURE);
  	}
  	return(iteratore->current_node->value);
}

void iterator_set_initial(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_set_initial : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  iteratore->current_node = iteratore->lista->front;
}

void iterator_set_end(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_set_end : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  iteratore->current_node = iteratore->lista->rear;
}

void iterator_increases(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_increases : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(iteratore->current_node == iteratore->lista->rear ){
    fprintf(stderr,"iterator_increases : node is out of the list bounds");
    exit(EXIT_FAILURE);
  }
  iteratore->current_node = iteratore->current_node->next;
}

void iterator_decreases(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_increases : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(iteratore->current_node == iteratore->lista->front ){
    fprintf(stderr,"iterator_increases : node is out of the list bounds");
    exit(EXIT_FAILURE);
  }
  iteratore->current_node = iteratore->current_node->prev;
}

int iterator_has_next(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_has_next : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(iteratore->current_node == iteratore->lista->rear )
    return(0);
  return(1);
}

int iterator_has_prev(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_has_prev : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(iteratore->current_node == iteratore->lista->front )
    return(0);
  return(1);
}
/*
void main(){
	List* a = create_list();
	printf("%s \n",(list_is_empty(a)? "vuoto" : "non vuoto"));
	printf("size = %ld\n", list_size(a));
	int x = 3;
	int y = 5;
	int z= 6;
	int f= 9;
	add_queue_element(a,&x);
	add_queue_element(a,&y);
	add_queue_element(a,&z);
	add_element(a,&f,3);
	printf("%s \n",(list_is_empty(a)? "vuoto" : "non vuoto"));
	printf("size = %ld\n", list_size(a));

	//printf("<%d>\n",*((int*)list_get(a,0)));
	print_List(a);

	//delete_queue_element(a);
	
	//delete_element(a,3);
  //delete_element(a,1);


	printf("size =%ld\n", a->size);
	print_List(a);


	Iterator* iteratore = create_iterator(a);
	printf("Has prev %s \n",( iterator_has_prev(iteratore)? "Vero" : "Falso"));
	printf("elemento corrente%d\n",   *(int*)( iterator_get(iteratore) )) ;
  iterator_increases(iteratore);
	//delete_queue_element(a);

	print_List(a);
	printf("elemento corrente %d\n",   *(int*)( iterator_get(iteratore) )) ;
	
	//Fine//
	list_free_memory(a);
}
*/