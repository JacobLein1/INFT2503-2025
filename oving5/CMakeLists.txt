cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0167 NEW)

project(oving5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost 1.89 REQUIRED COMPONENTS headers)
find_package(Threads REQUIRED)

# 1) Program: oving5 (din oppgave med main.cpp)
add_executable(oving5
        main.cpp
        ChessBoard.cpp
        ChessBoardPrint.cpp
)
target_link_libraries(oving5 PRIVATE Boost::headers Threads::Threads)

# 2) Program: echoserver (har egen main i EchoServer.cpp)
add_executable(echoserver
        EchoServer.cpp
)
target_link_libraries(echoserver PRIVATE Boost::headers Threads::Threads)
