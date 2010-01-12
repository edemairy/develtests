project(SpinningCube)

add_executable(${PROJECT_NAME}
  ${PROJECT_NAME}.cpp
)
target_link_libraries(${PROJECT_NAME} glut)



