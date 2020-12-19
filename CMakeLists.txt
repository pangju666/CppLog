cmake_minimum_required(VERSION 3.15)
project(CppLog VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX d)

# check and introduce CppCommonUtil library
set(CPP_COMMON_UTIL_INCLUDE_DIR "CPP_COMMON_UTIL_INCLUDE_DIR-NOTFOUND" CACHE PATH "cpp_common_util include directory")
set(CPP_COMMON_UTIL_LIBRARY "CPP_COMMON_UTIL_LIBRARY-NOTFOUND" CACHE FILEPATH "cpp_common_util library")

add_library(cpp_common_util_lib STATIC IMPORTED)
set_target_properties(cpp_common_util_lib
        PROPERTIES IMPORTED_LOCATION $CACHE{CPP_COMMON_UTIL_LIBRARY}
        )
target_include_directories(cpp_common_util_lib
        INTERFACE $CACHE{CPP_COMMON_UTIL_INCLUDE_DIR}
        )

file(GLOB headers *.h)
file(GLOB sources *.cpp)
add_library(CppLog ${headers} ${sources})
target_link_libraries(CppLog PRIVATE cpp_common_util_lib)

install(TARGETS CppLog
        DESTINATION lib)
install(FILES ${headers}
        DESTINATION include)
