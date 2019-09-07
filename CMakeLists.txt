cmake_minimum_required(VERSION 3.14)
project(CPHP)

set(PHP_FUNCTIONS array_sum
                  array_merge
                  range
                  implode # / join (alias)
                  str_repeat)

set(GENERIC_FUNCTIONS array_for_each
                      array_print)

set(COMMON ansi.h
           assertions.h
           tests.h
           tests.c
           main.c)

  foreach(PHP_FUNCTION ${PHP_FUNCTIONS})
    list(APPEND GENERATED_C_CODE_RUN_TEST "\n\ttest_${PHP_FUNCTION}()")
  endforeach()

  set(GENERATED_C_CODE_RUN_TEST "${GENERATED_C_CODE_RUN_TEST};")

set(CONFIG configuration)
configure_file(${CONFIG}.in.c ${CONFIG}.c)
set(CONFIG_SRC ${CMAKE_CURRENT_BINARY_DIR}/${CONFIG}.c)

function(PREPEND_APPEND out in pre post)
  set(${out} ${${in}})
  list(TRANSFORM ${out} PREPEND ${pre})
  list(TRANSFORM ${out} APPEND  ${post})
  set(${out} ${${out}} PARENT_SCOPE)
endfunction(PREPEND_APPEND)


PREPEND_APPEND(PHP_SRC     PHP_FUNCTIONS     cphp/    .c)
PREPEND_APPEND(PHP_TESTS   PHP_FUNCTIONS     tests/   .c)
PREPEND_APPEND(GENERICS_SRC GENERIC_FUNCTIONS generic/ .c)
list(APPEND PHP_SRC              cphp/prototypes.h)
list(APPEND GENERICS_SRC         generic/prototypes.h)

set(ALL_SRCS ${PHP_SRC}
             ${PHP_TESTS}
             ${COMMON}
             ${GENERICS_SRC}
             ${CONFIG_SRC})

include_directories(${CMAKE_SOURCE_DIR})
add_executable(${PROJECT_NAME} ${ALL_SRCS})
