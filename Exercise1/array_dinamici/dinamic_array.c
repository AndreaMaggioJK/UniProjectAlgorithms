#include <stdlib.h>
#include <stdio.h>
#include "List.h"

#define INITIAL_CAPACITY 2


struct _List{
  void** array;
  unsigned long el_num;
  unsigned long array_capacity;
};

struct _Iterator{
	long unsigned current_index;
	List *dinamic_array;
};


int list_is_empty(List *dinamic_array){
  if(dinamic_array == NULL){
    fprintf(stderr,"list_is_empty: dinamic_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(dinamic_array->el_num == 0)
    return(1);
  return(0);
}
List *create_list(){

  List *dinamic_array = (List *)malloc(sizeof(List));
  if(dinamic_array == NULL){
    fprintf(stderr, "create_list: unable to allocate memory for the list");
    exit(EXIT_FAILURE);
  }
  dinamic_array->array = (void**)malloc(INITIAL_CAPACITY*sizeof(void*));
  if(dinamic_array->array == NULL){
    fprintf(stderr, "create_list: unable to allocate memory for the internal array");
    exit(EXIT_FAILURE);
  }
  dinamic_array->el_num = 0;
  dinamic_array->array_capacity =INITIAL_CAPACITY;
  
  return(dinamic_array);
}

unsigned long list_size(List *dinamic_array){
  if(dinamic_array == NULL){
    fprintf(stderr,"list_size: dinamic_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  return(dinamic_array->el_num);
}

void increse_memory(List *dinamic_array){
	dinamic_array->array = (void**)realloc(dinamic_array->array,2*(dinamic_array->array_capacity)*sizeof(void*));
    if(dinamic_array->array == NULL){
      fprintf(stderr,"increse_memory: unable to reallocate memory");
      exit(EXIT_FAILURE);
    }
    dinamic_array->array_capacity = 2*dinamic_array->array_capacity;
}

void decrese_memory_unused(List *dinamic_array){
	dinamic_array->array = (void**)realloc(dinamic_array->array,(dinamic_array->array_capacity)*sizeof(void*)/2);
	if(dinamic_array->array == NULL){
      fprintf(stderr,"decrese_memory_unused: unable to reallocate memory");
      exit(EXIT_FAILURE);
    }
    dinamic_array->array_capacity = dinamic_array->array_capacity/2;
}


void add_queue_element(List *dinamic_array,void* elem){

  if(dinamic_array == NULL){
    fprintf(stderr,"add_queue_element: dinamic_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(elem == NULL){
    fprintf(stderr,"add_queue_element: element parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(dinamic_array->el_num >= dinamic_array->array_capacity){
    increse_memory(dinamic_array);
  }
  
  long unsigned index = dinamic_array->el_num;
	(dinamic_array->el_num)++;
	(dinamic_array->array)[index] = elem;


}

void delete_queue_element(List *dinamic_array){

	if( list_is_empty(dinamic_array) ){
		fprintf(stderr,"delete_queue_element: array cannot be empty");
    	exit(EXIT_FAILURE);
	}
	if(dinamic_array == NULL){
    fprintf(stderr,"delete_queue_element: dinamic_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  	}
		(dinamic_array->array)[dinamic_array->el_num] = NULL;
		(dinamic_array->el_num)--;
	if((dinamic_array->el_num) <= (dinamic_array->array_capacity)/4){
  		decrese_memory_unused(dinamic_array);
  	}
}

void delete_element(List *dinamic_array,long unsigned index){

	if( list_is_empty(dinamic_array) ){
	}
	if(dinamic_array == NULL){
    fprintf(stderr,"insert_element: dinamic_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  	}
  	(dinamic_array->array)[index] = NULL;
  	for (int i = index; i < dinamic_array->el_num; ++i){
  		(dinamic_array->array)[i] = (dinamic_array->array)[i+1];
  	}
  	(dinamic_array->el_num)--;
  	if((dinamic_array->el_num) <= (dinamic_array->array_capacity)/4){
  		decrese_memory_unused(dinamic_array);
  	}

}

void list_free_memory(List *dinamic_array){
  if(dinamic_array == NULL){
    fprintf(stderr,"list_free_memory: dinamic_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  free(dinamic_array->array);
  free(dinamic_array);
}

void add_element(List *dinamic_array,void* elem,long unsigned index){
  if(dinamic_array == NULL){
    fprintf(stderr,"add_element: dinamic_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(elem == NULL){
    fprintf(stderr,"add_element: element parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(dinamic_array->el_num >= dinamic_array->array_capacity){
    increse_memory(dinamic_array);
  }
	(dinamic_array->el_num)++;
	unsigned long i = dinamic_array->el_num;
  	for(;i>index;i--){
    (dinamic_array->array)[i] = (dinamic_array->array)[i-1];
  	}
  	(dinamic_array->array)[i] = elem;
}

void* list_get(List *dinamic_array, unsigned long i){
  if(dinamic_array == NULL){
    fprintf(stderr,"list_get: dinamic_array parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(i>=dinamic_array->el_num){
    fprintf(stderr,"list_get: Index %lu is out of the array bounds",i);
    exit(EXIT_FAILURE);
  }
  return(dinamic_array->array)[i];
}

void print_List(List *lista){
  unsigned long el_num =  list_size(lista);

  for(unsigned long i=0;i<el_num;i++){
    printf("<%ld,%d>\n",i,*((int*)list_get(lista, i))); 
  }
  printf("///////////////////////////////////\n");
}

Iterator *create_iterator(List *dinamic_array){

	Iterator *iteratore = (Iterator *)malloc(sizeof(Iterator));
	if(iteratore == NULL){
    	fprintf(stderr, "create_iterator: unable to allocate memory for the Iterator");
    	exit(EXIT_FAILURE);
  }
  	iteratore->dinamic_array = dinamic_array;
  	iteratore->current_index = 0;
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
  	return iteratore->dinamic_array->array[ iteratore->current_index ];
}

void iterator_set_initial(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_set_initial : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  iteratore->current_index = 0;
}

void iterator_set_end(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_set_end : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  iteratore->current_index = (iteratore->dinamic_array->el_num)-1;
}

void iterator_increases(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_set_initial : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(iteratore->current_index >= iteratore->dinamic_array->el_num){
    fprintf(stderr,"array_get: Index %lu is out of the array bounds",iteratore->current_index);
    exit(EXIT_FAILURE);
  }
  (iteratore->current_index)++;
}

void iterator_decreases(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_set_initial : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(iteratore->current_index == 0){
    fprintf(stderr,"array_get: Index %lu is out of the array bounds",iteratore->current_index);
    exit(EXIT_FAILURE);
  }
  (iteratore->current_index)--;
}


int iterator_has_next(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_has_next : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(iteratore->current_index == (iteratore->dinamic_array->el_num)-1 )
    return(0);
  return(1);
}

int iterator_has_prev(Iterator *iteratore){
  if(iteratore == NULL){
    fprintf(stderr,"iterator_has_prev : iteratore parameter cannot be NULL");
    exit(EXIT_FAILURE);
  }
  if(iteratore->current_index == 0 )
    return(0);
  return(1);
}