project(shared_ptr)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
add_executable( shared_from_this shared_from_this.cpp )
