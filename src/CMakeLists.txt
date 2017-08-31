cmake_minimum_required (VERSION 3.0)

set(SRC "debug.c"
        "list.c"
        "map.c"
        "gc.c")

add_library(crisp_util SHARED ${SRC})
