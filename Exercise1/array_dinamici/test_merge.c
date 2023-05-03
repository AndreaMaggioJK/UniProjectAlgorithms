#include <stdlib.h>
#include <assert.h>
#include "unity.h"
#include "merge.c"


static void test_mergeSort(){

  List* a = create_list();
  List* b = create_list();

  int x = 0;
  int y = 2;
  int z = 5;
  add_queue_element(a,&x);
  add_queue_element(a,&y);
  add_queue_element(a,&z);

  int f = 3;
  int g = 6;
  int h = 7;
  int h1 = 12;
  add_queue_element(b,&f);
  add_queue_element(b,&g);
  add_queue_element(b,&h);
  add_queue_element(b,&h1);
  List* Sort = mergeSort(a,b,compare_int);
  TEST_ASSERT_EQUAL_INT( 0 , *(int *)list_get(Sort,0));
  TEST_ASSERT_EQUAL_INT( 2 , *(int *)list_get(Sort,1));
  TEST_ASSERT_EQUAL_INT( 3 , *(int *)list_get(Sort,2));
  TEST_ASSERT_EQUAL_INT( 5 , *(int *)list_get(Sort,3));
  TEST_ASSERT_EQUAL_INT( 6 , *(int *)list_get(Sort,4));
  TEST_ASSERT_EQUAL_INT( 7 , *(int *)list_get(Sort,5));
  TEST_ASSERT_EQUAL_INT( 12 , *(int *)list_get(Sort,6));
  list_free_memory(a);
  list_free_memory(b);

  List* a1 = create_list();
  List* b1 = create_list();

  int x1 = 0;
  add_queue_element(a1,&x1);

  int f1 = 0;
  add_queue_element(b1,&f1);
  List* Sort1 = mergeSort(a1,b1,compare_int);
  TEST_ASSERT_EQUAL_INT( 0 , *(int *)list_get(Sort1,0));
  TEST_ASSERT_EQUAL_INT( 0 , *(int *)list_get(Sort1,1));
  list_free_memory(a1);
  list_free_memory(b1);

}



void main(){
	
	UNITY_BEGIN();

	RUN_TEST(test_mergeSort);
}