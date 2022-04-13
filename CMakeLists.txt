cmake_minimum_required(VERSION 3.21)
project(lab_78)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_78 main.cpp Domain/ApartamentExpens.cpp Domain/ApartamentExpens.h Domain/Vector.h Repository/Repository.h Service/ServiceApartamen.cpp Service/ServiceApartamen.h Tests/Tests.h UI/UI.cpp UI/UI.h)
