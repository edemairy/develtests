project(fact)

add_library( ${PROJECT_NAME} SHARED fact.h fact.cpp)
target_link_libraries( ${PROJECT_NAME} )

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

# Don't forget to setup the environment variable JAVA_HOME properly.
FIND_PACKAGE(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_SWIG_FLAGS "")

SET_SOURCE_FILES_PROPERTIES(fact.i PROPERTIES CPLUSPLUS ON)
SWIG_ADD_MODULE(lib${PROJECT_NAME}_java java fact.i)
swig_link_libraries(lib${PROJECT_NAME}_java ${JNI_LIBRARIES} fact)

add_custom_command(
  OUTPUT  ${PROJECT_NAME}.jar
  COMMAND javac ${CMAKE_CURRENT_BUILD_DIR}/*.java ${PROJECT_NAME}.jar
)

add_custom_target(
  ALL
  COMMAND javac ${CMAKE_CURRENT_BINARY_DIR}/*.java
  COMMAND jar cf ${PROJECT_NAME}.jar ${CMAKE_CURRENT_BINARY_DIR}/*.class
)
