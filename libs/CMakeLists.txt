set(LIB_SOURCES
    game.cpp
    gameobject.cpp)

set(LIB_HEADERS
    game.hpp
    gameobject.hpp)

add_library(my_lib STATIC ${LIB_SOURCES} ${LIB_HEADERS})
target_link_libraries(my_lib sfml-graphics)
