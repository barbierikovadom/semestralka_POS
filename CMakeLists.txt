cmake_minimum_required(VERSION 3.7)
project(semestralka)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(semestralka logika_hadik.cpp Hadik.cpp Hadik.h Hrac.cpp Hrac.h Pravidla.cpp Pravidla.h ZbieraneObjekty.h main.cpp Client.cpp Client.h Server.cpp Server.h)