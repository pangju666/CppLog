cmake_minimum_required(VERSION 3.15)
project(CppLog VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX d)

# check and introduce OES library
set(CPP_COMMON_UTIL_DIR "CPP_COMMON_UTIL-NOTFOUND"
        CACHE PATH "CppCommonUtil root directory"
        )
set(CPP_COMMON_UTIL_DIR $CACHE{CPP_COMMON_UTIL_DIR})
if ($<CONFIG:Debug>)
    set(CPP_COMMON_UTIL_LIBRARY $CACHE{CPP_COMMON_UTIL_DIR}/lib/libConfigd.a)
else ()
    set(CPP_COMMON_UTIL_LIBRARY $CACHE{CPP_COMMON_UTIL_DIR}/lib/libConfig.a)
endif ()

if (NOT IS_DIRECTORY ${CPP_COMMON_UTIL_DIR})
    message(FATAL_ERROR "MUST SET CPP_COMMON_UTIL DIRECTORY")
endif ()

add_library(CppCommonUtil STATIC IMPORTED)
set_target_properties(CppCommonUtil PROPERTIES
        IMPORTED_LOCATION ${CPP_COMMON_UTIL_LIBRARY}
        )
target_include_directories(CppCommonUtil
        INTERFACE "${CPP_COMMON_UTIL_DIR}/include"
        )

file(GLOB headers *.h)
file(GLOB sources *.cpp)
add_library(CppLog ${headers} ${sources})
target_link_libraries(CppLog PRIVATE CppCommonUtil)

install(TARGETS CppLog
        DESTINATION lib)
install(FILES ${headers}
        DESTINATION include)
