#include <stdlib.h>
#include <stdio.h>
#include "List.h"

static int compare_int(void* obj1,void* obj2) {
  int oggetto1 = *(int*)obj1;
  int oggetto2 = *(int*)obj2;
  if( oggetto1 == oggetto2){
    return 0;
  }
  if(oggetto1 < oggetto2) {
    return -1;
  }
  return 1;
}

List *mergeSort(List *a,List *b,int (*compare)(void*,void*)){

	List* Sort = create_list();
	Iterator* iteratoreA = create_iterator(a);
	Iterator* iteratoreB = create_iterator(b);
  void* oggettoA;
  void* oggettoB;
  int result_comp;
  int esc = 0;
  while( !esc ){
      oggettoA = iterator_get(iteratoreA);
      oggettoB = iterator_get(iteratoreB);
      result_comp = compare(oggettoA,oggettoB);
      if(result_comp <= 0){
        add_queue_element(Sort,oggettoA);
        if( iterator_has_next(iteratoreA) ){
          iterator_increases(iteratoreA);
        }else{
          esc = 1;
        }
      }else{
        add_queue_element(Sort,oggettoB);
        if( iterator_has_next(iteratoreB) ){
          iterator_increases(iteratoreB);
        }else{
          esc = 2;
        }
      }
  }
  if(esc == 1){
    while( iterator_has_next(iteratoreB) ){
      oggettoB = iterator_get(iteratoreB);
      add_queue_element(Sort,oggettoB);
      iterator_increases(iteratoreB);
    }
    oggettoB = iterator_get(iteratoreB);
    add_queue_element(Sort,oggettoB);
  }else{
    while( iterator_has_next(iteratoreA) ){
      oggettoA = iterator_get(iteratoreA);
      add_queue_element(Sort,oggettoA);
      iterator_increases(iteratoreA);
    }
    oggettoA = iterator_get(iteratoreA);
    add_queue_element(Sort,oggettoA);
  }
	return(Sort);
}