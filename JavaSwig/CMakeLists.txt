project(fact)

add_library( ${PROJECT_NAME} SHARED fact.h fact.cpp)
target_link_libraries( ${PROJECT_NAME} )

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

FIND_PACKAGE(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_SWIG_FLAGS "")

SET_SOURCE_FILES_PROPERTIES(fact.i PROPERTIES CPLUSPLUS ON)
SWIG_ADD_MODULE(lib${PROJECT_NAME}_java java fact.i)
swig_link_libraries(lib${PROJECT_NAME}_java ${JNI_LIBRARIES} fact)


