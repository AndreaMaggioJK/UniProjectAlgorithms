#include <stdlib.h>
#include <assert.h>
#include "unity.h"
#include "List.h"

static void test_create_list(){
	List* lista = create_list();

	TEST_ASSERT_NOT_NULL(lista);
  	TEST_ASSERT_EQUAL_INT( list_is_empty(lista), 1);
  	list_free_memory(lista);
}

static void test_add_queue_element(){
	List* lista = create_list();

	int x = 72;
	char* y = "Stringa" ;
	add_queue_element(lista , &x);
	TEST_ASSERT_EQUAL_INT( 72 , *(int *)list_get(lista,0) );
	add_queue_element(lista , &y);
	TEST_ASSERT_EQUAL_STRING( "Stringa" , *( (char **)(list_get(lista,1)) ) );
	list_free_memory(lista);
}

static void test_delete_queue_element(){
	List* lista = create_list();

	int x = 72;
	int y = 44;
	int z = 3;
	add_queue_element(lista , &x);
	add_queue_element(lista , &y);
	add_queue_element(lista , &z);
	delete_queue_element(lista);
	TEST_ASSERT_EQUAL_INT( 44 , *(int *)list_get(lista,1) );
	TEST_ASSERT_EQUAL_INT( 72 , *(int *)list_get(lista,0) );
	list_free_memory(lista);
}

static void test_list_size(){
	List* lista = create_list();
	int x = 72;
	int y = 44;
	int z = 3;
	TEST_ASSERT_EQUAL_INT(0 , list_size(lista) );
	add_queue_element(lista , &x);
	TEST_ASSERT_EQUAL_INT(1 , list_size(lista) );
	add_queue_element(lista , &y);
	TEST_ASSERT_EQUAL_INT(2 , list_size(lista) );
	delete_queue_element(lista);
	TEST_ASSERT_EQUAL_INT(1 , list_size(lista) );
	list_free_memory(lista);
}

static void test_add_element(){
	List* lista = create_list();

	int x = 72;
	int y = 44;
	int z = 3;
	add_element(lista,&z,0);
	add_element(lista,&x,0);
	add_element(lista,&y,1);
	TEST_ASSERT_EQUAL_INT( 72 , *(int *)list_get(lista,0) );
	TEST_ASSERT_EQUAL_INT( 44 , *(int *)list_get(lista,1) );
	TEST_ASSERT_EQUAL_INT( 3 , *(int *)list_get(lista,2) );
	list_free_memory(lista);
}

static void test_delete_element(){
	List* lista = create_list();

	int x = 72;
	int y = 44;
	int z = 3;
	add_queue_element(lista , &x);
	add_queue_element(lista , &y);
	add_queue_element(lista , &z);
	delete_element(lista,0);
	TEST_ASSERT_EQUAL_INT( 44 , *(int *)list_get(lista,0) );
	TEST_ASSERT_EQUAL_INT( 3 , *(int *)list_get(lista,1) );
	add_element(lista,&x,0);
	delete_element(lista,1);
	TEST_ASSERT_EQUAL_INT( 72 , *(int *)list_get(lista,0) );
	TEST_ASSERT_EQUAL_INT( 3 , *(int *)list_get(lista,1) );
	add_element(lista,&y,1);
	delete_element(lista,2);
	TEST_ASSERT_EQUAL_INT( 72 , *(int *)list_get(lista,0) );
	TEST_ASSERT_EQUAL_INT( 44 , *(int *)list_get(lista,1) );
	list_free_memory(lista);
} 

static void test_create_iterator(){
	List* lista = create_list();
	int x = 888;
	add_queue_element(lista,&x);

	Iterator* iteratore = create_iterator(lista);
	TEST_ASSERT_NOT_NULL(iteratore);
  	TEST_ASSERT_EQUAL_INT( *(int *)list_get(lista,0) , *(int *)iterator_get(iteratore));
  	list_free_memory(lista);
  	iterator_free_memory(iteratore);
}

static void test_iterator_increases(){
	List* lista = create_list();	int x = 72;
	int y = 44;
	add_queue_element(lista , &x);
	add_queue_element(lista , &y);

	Iterator* iteratore = create_iterator(lista);

	TEST_ASSERT_EQUAL_INT( *(int *)list_get(lista,0) , *(int *)iterator_get(iteratore));
	iterator_increases(iteratore);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(lista,1) , *(int *)iterator_get(iteratore));
  	list_free_memory(lista);
  	iterator_free_memory(iteratore);
}

static void test_iterator_set_initial(){
	List* lista = create_list();
	int x = 72;
	int y = 44;
	add_queue_element(lista , &x);
	add_queue_element(lista , &y);

	Iterator* iteratore = create_iterator(lista);

	iterator_increases(iteratore);
	iterator_set_initial(iteratore);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(lista,0) , *(int *)iterator_get(iteratore));
  	list_free_memory(lista);
  	iterator_free_memory(iteratore);
}

static void test_iterator_set_end(){
	List* lista = create_list();
	int x = 72;
	int y = 44;
	add_queue_element(lista , &x);
	add_queue_element(lista , &y);

	Iterator* iteratore = create_iterator(lista);

	iterator_set_end(iteratore);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(lista,1) , *(int *)iterator_get(iteratore));
  	list_free_memory(lista);
  	iterator_free_memory(iteratore);
}

static void test_iterator_decreases(){
	List* lista = create_list();
	int x = 72;
	int y = 44;
	int z = 3;
	add_queue_element(lista , &x);
	add_queue_element(lista , &y);
	add_queue_element(lista , &z);

	Iterator* iteratore = create_iterator(lista);

	iterator_set_end(iteratore);
	iterator_decreases(iteratore);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(lista,1) , *(int *)iterator_get(iteratore));
	iterator_decreases(iteratore);
	TEST_ASSERT_EQUAL_INT( *(int *)list_get(lista,0) , *(int *)iterator_get(iteratore));
  	list_free_memory(lista);
  	iterator_free_memory(iteratore);
}

static void test_iterator_has_next(){
	List* lista = create_list();
	int x = 72;
	int y = 44;
	add_queue_element(lista , &x);
	add_queue_element(lista , &y);

	Iterator* iteratore = create_iterator(lista);

	TEST_ASSERT_EQUAL_INT( 1 , iterator_has_next(iteratore) );
	iterator_set_end(iteratore);
	TEST_ASSERT_EQUAL_INT( 0 , iterator_has_next(iteratore) );
	list_free_memory(lista);
  	iterator_free_memory(iteratore);
}

static void test_iterator_has_prev(){
	List* lista = create_list();
	int x = 72;
	int y = 44;
	add_queue_element(lista , &x);
	add_queue_element(lista , &y);
	
	Iterator* iteratore = create_iterator(lista);

	TEST_ASSERT_EQUAL_INT( 0 , iterator_has_prev(iteratore) );
	iterator_increases(iteratore);
	TEST_ASSERT_EQUAL_INT( 1 , iterator_has_prev(iteratore) );
	list_free_memory(lista);
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