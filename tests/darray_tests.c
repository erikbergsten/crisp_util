#include <minunit.h>
#include <stdio.h>
#include <crisp/darray.h>
#include <string.h>


int tests_run = 0;

cr_darray * names;

char * name1 = "Isle of Eternal Despair",
     * name2 = "Wykydtron",
     * name3 = "Lord of the Storm",
     * name4 = "Forest King",
     * name5 = "Axes of Evil",
     * name6 = "Destroy the Orcs",
     * name7 = "The Phantom of the Crimson Cloak";

static char * test_new(){
  names = cr_darray_new();
  mu_assert("Expected array to be non-NULL", names != NULL);
  mu_assert("Expected initial size to be 0", cr_darray_length(names) == 0);
  mu_assert("Expected initial capacity to be 6",
              names->capacity == CR_DARRAY_INIT_CAPACITY);
  return NULL;
}
static char * test_push(){
  cr_darray_push(names, name1);
  mu_assert("Expected array length to be 1", cr_darray_length(names) == 1);
  mu_assert("Expected initial capacity to be 6",
              names->capacity == CR_DARRAY_INIT_CAPACITY);
  cr_darray_push(names, name2);
  mu_assert("Expected array length to be 2", cr_darray_length(names) == 2);
  mu_assert("Expected initial capacity to be 6",
              names->capacity == CR_DARRAY_INIT_CAPACITY);
  cr_darray_push(names, name3);
  mu_assert("Expected array length to be 3", cr_darray_length(names) == 3);
  mu_assert("Expected initial capacity to be 6",
              names->capacity == CR_DARRAY_INIT_CAPACITY);
  cr_darray_push(names, name4);
  cr_darray_push(names, name5);
  cr_darray_push(names, name6);
  mu_assert("Expected array length to be 6", cr_darray_length(names) == 6);
  mu_assert("Expected initial capacity to be 6",
              names->capacity == CR_DARRAY_INIT_CAPACITY);
  cr_darray_push(names, name7);
  mu_assert("Expected array length to be 7", cr_darray_length(names) == 7);
  mu_assert("Expected initial capacity to be 12",
              names->capacity == 12);


  return NULL;
}
static char * test_pop(){
  char * ret;
  ret = (char *) cr_darray_pop(names);
  mu_assert("Expected popped string to be name7", strcmp(ret, name7) == 0);
  mu_assert("Expected array length to be 6", cr_darray_length(names) == 6);
  mu_assert("Expected initial capacity to be 12",
              names->capacity == 12);
  ret = (char *) cr_darray_pop(names);
  mu_assert("Expected popped string to be name6", strcmp(ret, name6) == 0);
  mu_assert("Expected array length to be 5", cr_darray_length(names) == 5);
  mu_assert("Expected initial capacity to be 12",
              names->capacity == 12);

  return NULL;
}
static char * test_destroy(){
  cr_darray_destroy(names);
  return NULL;
}
static char * all_tests(){
  mu_run_test(test_new);
  mu_run_test(test_push);
  mu_run_test(test_pop);

  mu_run_test(test_destroy);

  return NULL;
}

int main(){
  char * res = all_tests();
  if(res){
    printf("%s\n", res);
    return -1;
  }else{
    printf("DARRAY TESTS: ALL TESTS PASSED\n");
  }
  printf("%i tests run.\n", tests_run);
  return 0;
}
