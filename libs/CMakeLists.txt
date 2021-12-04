set(LIB_SOURCES
    game.cpp
    gameobject.cpp
    eventhandler.cpp
    player.cpp
    npc.cpp
    )

set(LIB_HEADERS
    game.hpp
    gameobject.hpp
    eventhandler.hpp
    player.hpp
    npc.hpp
    fixed_queue.hpp
    )

add_library(my_lib STATIC ${LIB_SOURCES} ${LIB_HEADERS})
target_link_libraries(my_lib sfml-graphics)
