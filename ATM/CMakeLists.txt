cmake_minimum_required(VERSION 3.8)
project(ATM)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Account.cpp
        Account.h
        AccountHolder.cpp
        AccountHolder.h
        ATM.cpp
        ATM.h
        BankDB.cpp
        BankDB.h
        main.cpp
        Pipe.cpp
        Pipe.h)

add_executable(ATM ${SOURCE_FILES})