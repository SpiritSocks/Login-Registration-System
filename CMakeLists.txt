cmake_minimum_required(VERSION 3.30)
project(Login___Registration_System)

set(CMAKE_CXX_STANDARD 20)

include_directories(/opt/homebrew/Cellar/libsodium/1.0.20/include)
include_directories(/opt/homebrew/Cellar/openssl@3/3.4.0/include)
link_directories(/opt/homebrew/Cellar/libsodium/1.0.20/lib)
link_directories(/opt/homebrew/Cellar/openssl@3/3.4.0/lib)
find_package(OpenSSL REQUIRED)


add_executable(Login___Registration_System
        main.cpp
        header.h
        Login_Registration.cpp
)

target_link_libraries(Login___Registration_System sodium OpenSSL::Crypto)
