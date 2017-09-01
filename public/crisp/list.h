/**
 * @file list.h
 * @author Erik Bergsten
 * @date Fri 01 Sep 2017
 * @brief The definition of a doubly linked list. Storing NULL pointers in
 *        the list is unsafe since NULL is returned by pop/shift/head/end if
 *        the list is empty.
 */

#ifndef __cr_list_h__
#define __cr_list_h__

#include <stddef.h>

/**
 * @brief Represents a node in the list
 */

typedef struct _cr_node {
  struct _cr_node *next, /**< Next node in the list */
                  *prev; /**< Previous node in the list */
  void * value;  /**< The value of the node */
} cr_node;

/**
 * @brief Struct representing a list
 */
typedef struct {
  cr_node *head, /**< The first node in the list */
          *end; /**< The last node in the list */
  size_t elem_size; /**< the size of values in the list */
} cr_list;

/**
 * @brief Creates a new list with elements of size size_elem
 */
cr_list * cr_list_new(size_t elem_size);
/**
 * @brief Destroys list and frees all nodes but NOT the values in the list
 */
void cr_list_destroy(cr_list * list);

/**
 * @brief Macro for creating lists of pointers (i.e. most lists)
 */
#define cr_list_newP() cr_list_new(sizeof(void *))

/**
 * @brief Gets the length of a list in O(n)
 */
int cr_list_length(cr_list * list);

/**
 * @brief Removes a node in O(1). Takes a node not a value as argument
 *        removing values still taken O(n)
 */
void cr_list_remove(cr_list * list, cr_node * node);

/**
 * @brief Appends a value in O(1)
 */
void cr_list_append(cr_list * list, void * elem);
/**
 * @brief Macro that casts the appended value to a voidptr to suppress warnings.
 */
#define cr_list_appendS(list, elem) cr_list_append(list, (void *) elem)

/**
 * @brief Prepends a value in O(1)
 */
void cr_list_prepend(cr_list * list, void * elem);
/**
 * @brief Macro that casts the prepended value to a voidptr to suppress warnings.
 */
#define cr_list_prependS(list, elem) cr_list_prepend(list, (void *) elem)

/**
 * @brief Pops a value from the end of the list in O(1), returns
 * NULL if list is empty
 */
void * cr_list_pop(cr_list * list);
/**
 * @brief Shifts a value from the front of the list in O(1), returns NULL
 *        if the list is empty
 */
void * cr_list_shift(cr_list * list);

/**
 * @brief Macro that returns the first value of the list or NULL if the list
 *        is empty.
 */
#define cr_list_head(list) (list->head ? list->head->value : NULL)
/**
 * @brief Macro that returns the last value of the list or NULL if the list is
 *        empty.
 */
#define cr_list_end(list) (list->end ? list->end->value : NULL)


#endif /* __cr_list_h__ */
