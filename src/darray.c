#include <crisp/darray.h>
#include <stdlib.h>

void _cr_darray_grow(cr_darray * array){
  array->capacity *= CR_DARRAY_GROWTH_FACTOR;
  array->data = realloc(array->data, sizeof(void*) * array->capacity);
}
void _cr_darray_shrink(cr_darray * array){
  array->capacity /= CR_DARRAY_GROWTH_FACTOR;
  array->data = realloc(array->data, sizeof(void*) * array->capacity);
}

cr_darray * cr_darray_new(){
  cr_darray * array = (cr_darray *) malloc(sizeof(cr_darray));
  array->length = 0;
  array->capacity = CR_DARRAY_INIT_CAPACITY;
  array->data = malloc(sizeof(void*) * array->capacity);
  return array;
}
void cr_darray_destroy(cr_darray * array){
  free(array->data);
  free(array);
}

void cr_darray_push(cr_darray * array, void * value){
  if(++array->length > array->capacity){
    _cr_darray_grow(array);
  }
  array->data[array->length-1] = value;
}
void * cr_darray_pop(cr_darray * array){
  void * ret = array->data[array->length-1];
  array->data[array->length-1] = NULL;
  if(--array->length < CR_DARRAY_SHRINK_MINIMUM &&
       array->length < array->capacity * CR_DARRAY_SHRINK_LIMIT){
    _cr_darray_shrink(array);
  }
  return ret;
}
