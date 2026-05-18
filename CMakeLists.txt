cmake_minimum_required(VERSION 3.28)
project(Bounce CXX)
  
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "/usr/lib/cmake/SFML")
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System Audio)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS source/*.cpp)
add_executable(Bounce ${SOURCES})

target_include_directories(Bounce PRIVATE include)
target_compile_features(Bounce PRIVATE cxx_std_20)
target_link_libraries(Bounce SFML::Graphics SFML::Window SFML::System SFML::Audio)
