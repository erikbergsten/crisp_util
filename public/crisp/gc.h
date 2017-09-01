/**
 * @file gc.h
 * @author Erik Bergsten
 * @date Fri 01 Sep 2017
 * @brief Ref counting gc functions. Extra space is allocated for the refcount.
 */
#ifndef __crisp_gc_h__
#define __crisp_gc_h__

#include <stdlib.h>
/**
 * @brief Type of a destructor
 */
typedef void (*cr_destroy)(void*);

/**
 * @brief Allocates @p size sets its refcount to 0 and destructor to @p detsroy.
 */
void * cr_malloc(size_t size, cr_destroy destroy);
/**
 * @brief Macro that casts destroy to cr_destroy to suppress warnings.
 */
#define cr_mallocS(size, destroy) cr_malloc(size, (cr_destroy) destroy)

/**
 * @brief Increases the refcount of a pointer and returns it. When creating a
 *        new reference use this. Instead of just an assignment.
 */
void * cr_ref(void * ptr);

/**
 * @brief Macro that casts to a voidptr to suppress warnings.
 */
#define cr_refS(ptr) cr_ref((void *) ptr)
/**
 * @brief Reduces the refcount of a pointer. If the refcount is 0 or less it
 *        calls the destructor and then frees the pointer.
 */
void cr_free(void * ptr);

/**
 * @brief Macro that casts to a voidptr to suppress warnings.
 */
#define cr_freeS(ptr) cr_free((void *) ptr)

/**
 * @brief Returns the address of the meta information, i.e. the refcount and
 *        destructor. This meta info and the pointer is in one contiguous block
 *        allocated by one system malloc call.
 */
void * cr_ref_meta_addr(void * ptr);
/**
 * @brief Free the pointer regardless of the refcount
 */
void cr_force_free(void * ptr);
/**
 * @brief Get the refcount of a certain pointer
 */
int cr_ref_count(void * ptr);

/**
 * @brief Macro that casts to a voidptr to suppress warnings.
 */
#define cr_ref_countS(ptr) cr_ref_count((void *) ptr)

#endif /* __crisp_gc_h__ */
