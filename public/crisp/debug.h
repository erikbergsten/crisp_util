/**
 * @file debug.h
 * @author Erik Bergsten
 * @date Fri 01 Sep 2017
 * @brief Debug logging functions that are only enabled if CR_DEBUG is defined.
 */
#ifndef __cr_debug_h__
#define __cr_debug_h__

#include <stdio.h>
#include <stdarg.h>

/**
 * @brief enumeration of the debug info levels
 */
typedef enum{
  cr_level_fatal,
  cr_level_warning,
  cr_level_info
} cr_debug_lvl;

/**
 * @brief initialize the debugger with one output for each level, can be the same
 *        for multiple levels or NULL if not interested. For example you can use
 *        stdout for fatal errors, a log file for warnings and NULL for info.
 */
void cr_debug_init(FILE * info, FILE * warning, FILE * fatal);

/**
 * @brief Terminate the debugger and close the files.
 */
void cr_debug_finish();
/**
 * @brief Macro for initializing the debugger to use stdout for all 3 levels
 */
#define cr_debug_init_std() cr_debug_init(stdout, stdout, stdout)
void cr_debug_log_(cr_debug_lvl lvl, char * format, ...);

#ifdef CR_DEBUG
/**
 * @brief Log with specified lvl
 */
  #define cr_debug_log(lvl, format, ...) cr_debug_log_(lvl, format, ##__VA_ARGS__)
/**
 * @brief Log with level set to info
 */
  #define cr_debug_info(format, ...) cr_debug_log_(cr_level_info, format, ##__VA_ARGS__)
/**
 * @brief Log with level set to warning
 */
  #define cr_debug_warn(format, ...) cr_debug_log_(cr_level_warning, format, ##__VA_ARGS__)
/**
 * @brief Log ith level set to fail
 */
  #define cr_debug_fail(format, ...) cr_debug_log_(cr_level_fatal, format, ##__VA_ARGS__)
#else
  #define cr_debug_log(lvl, format, ...)
  #define cr_debug_info(format, ...)
  #define cr_debug_warn(format, ...)
  #define cr_debug_fail(format, ...)
#endif

#endif /* __cr_debug_h__ */
