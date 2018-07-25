cmake_minimum_required(VERSION 3.6)
project(AdvancedCplusplus)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Person.cpp Resource.cpp Holder.cpp Account.cpp Account1.cpp AccountImpl.cpp)
add_executable(AdvancedCplusplus ${SOURCE_FILES})