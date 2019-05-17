cmake_minimum_required (VERSION 3.10.2)
project (Pathfinder VERSION 1.0.0 DESCRIPTION "Example Pathfinder for the DroNeS app")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(JSON_BuildTests OFF CACHE INTERNAL "")
set_target_properties(Pathfinder PROPERTIES VERSION ${PROJECT_VERSION})

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

ExternalProject_Add(json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(external/json)

add_library(Pathfinder STATIC
	src/Obstacle.cpp
	src/Pathfinder.cpp
	src/RayPath.cpp
	src/Vector3.cpp
)

include_directories(include)

option(Pathfinder_TESTING "Enable testing" ON)

if(Pathfinder_TESTING)
    add_executable(Pathfinder "main.cpp")
endif()

target_link_libraries(Pathfinder PRIVATE nlohmann_json::nlohmann_json)

install(TARGETS Pathfinder
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})