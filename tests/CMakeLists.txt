cmake_minimum_required(VERSION 3.0)
add_custom_target(tests)


macro(test name)
  add_executable("${name}_tests" "${name}_tests.c")
  add_dependencies(tests "${name}_tests")
  target_link_libraries("${name}_tests" crisp_util)
  target_link_libraries("${name}_tests" m)

endmacro(test)

test(list)
test(map)
test(gc)
test(darray)
