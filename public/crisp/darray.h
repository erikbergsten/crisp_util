#ifndef __crisp_darray_h__
#define __crisp_darray_h__

#define CR_DARRAY_INIT_CAPACITY 6
#define CR_DARRAY_GROWTH_FACTOR 2
#define CR_DARRAY_SHRINK_LIMIT (0.33)
#define CR_DARRAY_SHRINK_MINIMUM 12

typedef struct {
  int length, capacity;
  void ** data;
} cr_darray;

cr_darray * cr_darray_new();
void cr_darray_destroy(cr_darray * array);

void cr_darray_push(cr_darray * array, void * value);
void * cr_darray_pop(cr_darray * array);

#define cr_darray_at(array, i) (array->data[i])
#define cr_darray_length(array) (array->length)



#endif /* __crisp_darray_h__ */
