/**
 * @file map.h
 * @author Erik Bergsten
 * @date Fri 01 Sep 2017
 * @brief The definition of a hashmap. Initial size is always 8 and the map
 *        is never downsized!
 */
#ifndef __crisp_list_h__
#define __crisp_list_h__

#include <crisp/list.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief The type of a hashing function. A hashing function must be
 *        provided when creating a map.
 */
typedef uint32_t (*cr_hash)(void*);
/**
 * @brief The type of a comparing function. It should return 0 if the
 *        two values are equal. A comparing function must be provided
 *        when creating a map.
 */
typedef int (*cr_cmp)(void*,void*);
/**
 * @brief The type of an update function. Update functions can be used to
 *        modify the value at a certain key. For example to increment a number
 *        or just to have some fun.
 */
typedef void * (*cr_update)(void*);


/**
 * @brief Hashing function for integers
 */
uint32_t cr_int_hash(int value);
/**
 * @brief Comparing function for integers
 */
int cr_int_cmp(int v1, int v2);

/**
 * @brief Hashing function for strings
 */
uint32_t cr_str_hash(char * str);

/**
 * @brief Struct representing a key-value pair in the map.
 */
typedef struct {
  void *key, *value;
} cr_entry;

/**
 * @brief Struct representing a hashmap.
 */
typedef struct {
  cr_hash hash;
  cr_cmp cmp;
  int entries;
  int capacity;
  cr_list ** buckets;
} cr_map;

/**
 * @brief Creates a new map with the given hashing and comparing functions.
 */
cr_map * cr_map_new(cr_hash hash, cr_cmp cmp);

/**
 * @brief Macro for creating new maps that casts the functions automatically
 *        to supress warnings.
 */
#define cr_map_newS(hash, cmp) cr_map_new((cr_hash) hash, (cr_cmp) cmp)

/**
 * @brief Macro for creating maps with ints as keys
 */
#define cr_intmap_new() cr_map_new((cr_hash) cr_int_hash, (cr_cmp) cr_int_cmp)
/**
 * @brief Macro for cerating maps with strings as keys
 */
#define cr_strmap_new()\
  cr_map_new((cr_hash) cr_str_hash, (cr_cmp) strcmp)

/**
 * @brief Destroys and frees the map
 */
void cr_map_destroy(cr_map * map);

/**
 * @brief Binds key to value in map, if the key was already bound
 *        the old value is returned so it can be finalized.
 */
void * cr_map_set(cr_map * map, void * key, void * value);

/**
 * @brief Macro that casts key and value to voidptrs to suppress warnings
 */
#define cr_map_setS(map, key, value)\
  cr_map_set(map, (void *) key, (void *) value)

/**
 * @brief Returns the value bound to key, returns NULL if key is not in the map.
 */
void * cr_map_get(cr_map * map, void * key);
/**
 * @brief Macro that automatically casts the key to a voidptr to suppress warnings.
 */
#define cr_map_getS(map, key) cr_map_get(map, (void *) key)


/**
 * @brief Unbinds the key and returns the value for finalization.
 */
void * cr_map_unset(cr_map * map, void * key);
/**
 * @brief Macro that automatically casts the key to a voidptr to suppress warnings.
 */
#define cr_map_unsetS(map, key) cr_map_unset(map, (void *) key)

/**
 * @brief Applies the @p update function to the value referred to by @p key.
 */
void * cr_map_update(cr_map * map, void * key, cr_update update);

/**
 * @brief Macro that automatically casts the key to a voidptr and
 *        update to cr_update to suppress warnings.
 */
#define cr_map_updateS(map, key, update)\
  cr_map_update(map, (void *) key, (cr_update) update)

#endif /* __crisp_list_h__ */
