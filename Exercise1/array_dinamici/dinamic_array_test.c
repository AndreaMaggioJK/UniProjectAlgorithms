#include <stdlib.h>
#include <assert.h>
#include "unity.h"
#include "List.h"

static void test_create_list(){
	List* array = create_list();

	TEST_ASSERT_NOT_NULL(array);
  	TEST_ASSERT_EQUAL_INT( list_is_empty(array), 1);
  	list_free_memory(array);
}

static void test_add_queue_element(){
	List* array = create_list();

	int x = 72;
	char* y = "Stringa" ;
	add_queue_element(array , &x);
	TEST_ASSERT_EQUAL_INT( 72 , *(int *)list_get(array,0) );
	add_queue_element(array , &y);
	TEST_ASSERT_EQUAL_STRING( "Stringa" , *( (char **)(list_get(array,1)) ) );
	list_free_memory(array);
}

static void test_delete_queue_element(){
	List* array = create_list();

	int x = 72;
	int y = 44;
	int z = 3;
	add_queue_element(array , &x);
	add_queue_element(array , &y);
	add_queue_element(array , &z);
	delete_queue_element(array);
	TEST_ASSERT_EQUAL_INT( 44 , *(int *)list_get(array,1) );
	TEST_ASSERT_EQUAL_INT( 72 , *(int *)list_get(array,0) );
	list_free_memory(array);
}

static void test_list_size(){
	List* array = create_list();
	int x = 72;
	int y = 44;
	int z = 3;
	TEST_ASSERT_EQUAL_INT(0 , list_size(array) );
	add_queue_element(array , &x);
	TEST_ASSERT_EQUAL_INT(1 , list_size(array) );
	add_queue_element(array , &y);
	TEST_ASSERT_EQUAL_INT(2 , list_size(array) );
	delete_queue_element(array);
	TEST_ASSERT_EQUAL_INT(1 , list_size(array) );
	list_free_memory(array);
}

static void test_add_element(){
	List* array = create_list();

	int x = 72;
	int y = 44;
	int z = 3;
	add_element(array,&z,0);
	add_element(array,&x,0);
	add_element(array,&y,1);
	TEST_ASSERT_EQUAL_INT( 72 , *(int *)list_get(array,0) );
	TEST_ASSERT_EQUAL_INT( 44 , *(int *)list_get(array,1) );
	TEST_ASSERT_EQUAL_INT( 3 , *(int *)list_get(array,2) );
	list_free_memory(array);
}

static void test_delete_element(){
	List* array = create_list();

	int x = 72;
	int y = 44;
	int z = 3;
	add_queue_element(array , &x);
	add_queue_element(array , &y);
	add_queue_element(array , &z);
	delete_element(array,0);
	TEST_ASSERT_EQUAL_INT( 44 , *(int *)list_get(array,0) );
	TEST_ASSERT_EQUAL_INT( 3 , *(int *)list_get(array,1) );
	add_element(array,&x,0);
	delete_element(array,1);
	TEST_ASSERT_EQUAL_INT( 72 , *(int *)list_get(array,0) );
	TEST_ASSERT_EQUAL_INT( 3 , *(int *)list_get(array,1) );
	add_element(array,&y,1);
	delete_element(array,2);
	TEST_ASSERT_EQUAL_INT( 72 , *(int *)list_get(array,0) );
	TEST_ASSERT_EQUAL_INT( 44 , *(int *)list_get(array,1) );
	list_free_memory(array);
} 

static void test_create_iterator(){
	List* array = create_list();
	Iterator* iteratore = create_iterator(array);
	int x = 888;
	add_queue_element(array,&x);

	TEST_ASSERT_NOT_NULL(iteratore);
  	TEST_ASSERT_EQUAL_INT( *(int *)list_get(array,0) , *(int *)iterator_get(iteratore));
  	list_free_memory(array);
  	iterator_free_memory(iteratore);
}

static void test_iterator_increases(){
	List* array = create_list();
	Iterator* iteratore = create_iterator(array);
	int x = 72;
	int y = 44;
	add_queue_element(array , &x);
	add_queue_element(array , &y);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(array,0) , *(int *)iterator_get(iteratore));
	iterator_increases(iteratore);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(array,1) , *(int *)iterator_get(iteratore));
  	list_free_memory(array);
  	iterator_free_memory(iteratore);
}

static void test_iterator_set_initial(){
	List* array = create_list();
	Iterator* iteratore = create_iterator(array);
	int x = 72;
	int y = 44;
	add_queue_element(array , &x);
	add_queue_element(array , &y);
	iterator_increases(iteratore);
	iterator_set_initial(iteratore);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(array,0) , *(int *)iterator_get(iteratore));
  	list_free_memory(array);
  	iterator_free_memory(iteratore);
}

static void test_iterator_set_end(){
	List* array = create_list();
	Iterator* iteratore = create_iterator(array);
	int x = 72;
	int y = 44;
	add_queue_element(array , &x);
	add_queue_element(array , &y);
	iterator_set_end(iteratore);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(array,1) , *(int *)iterator_get(iteratore));
  	list_free_memory(array);
  	iterator_free_memory(iteratore);
}

static void test_iterator_decreases(){
	List* array = create_list();
	Iterator* iteratore = create_iterator(array);
	int x = 72;
	int y = 44;
	int z = 3;
	add_queue_element(array , &x);
	add_queue_element(array , &y);
	add_queue_element(array , &z);
	iterator_set_end(iteratore);
	iterator_decreases(iteratore);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(array,1) , *(int *)iterator_get(iteratore));
	iterator_decreases(iteratore);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(array,0) , *(int *)iterator_get(iteratore));
  	list_free_memory(array);
  	iterator_free_memory(iteratore);
}

static void test_iterator_has_next(){
	List* array = create_list();
	Iterator* iteratore = create_iterator(array);
	int x = 72;
	int y = 44;
	add_queue_element(array , &x);
	add_queue_element(array , &y);
	TEST_ASSERT_EQUAL_INT( 1 , iterator_has_next(iteratore) );
	iterator_set_end(iteratore);
	TEST_ASSERT_EQUAL_INT( 0 , iterator_has_next(iteratore) );
	list_free_memory(array);
  	iterator_free_memory(iteratore);
}

static void test_iterator_has_prev(){
	List* array = create_list();
	Iterator* iteratore = create_iterator(array);
	int x = 72;
	int y = 44;
	add_queue_element(array , &x);
	add_queue_element(array , &y);
	TEST_ASSERT_EQUAL_INT( 0 , iterator_has_prev(iteratore) );
	iterator_increases(iteratore);
	TEST_ASSERT_EQUAL_INT( 1 , iterator_has_prev(iteratore) );
	list_free_memory(array);
  	iterator_free_memory(iteratore);
}

void main(){
	UNITY_BEGIN();

	RUN_TEST(test_create_list);
	RUN_TEST(test_add_queue_element);
	RUN_TEST(test_delete_queue_element);
	RUN_TEST(test_list_size);
	RUN_TEST(test_add_element);
	RUN_TEST(test_delete_element);
	RUN_TEST(test_create_iterator);
	RUN_TEST(test_iterator_increases);
	RUN_TEST(test_iterator_set_initial);
	RUN_TEST(test_iterator_set_end);
	RUN_TEST(test_iterator_decreases);
	RUN_TEST(test_iterator_has_next);
	RUN_TEST(test_iterator_has_prev);
}