project(apps)
find_package(Qt4)

include_directories(${QT_INCLUDES})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} QtCore ${QT_QTGUI_LIBRARY})

