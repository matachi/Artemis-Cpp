cmake_minimum_required(VERSION 2.6)
FILE(GLOB ALL_CPP_SRCS *.cpp)
add_library(Artemis ${ALL_CPP_SRCS})
install(TARGETS Artemis
        ARCHIVE DESTINATION lib)
FILE(GLOB ALL_H_ *.h)
install(FILES ${ALL_H_}
        DESTINATION include/Artemis-Cpp)
