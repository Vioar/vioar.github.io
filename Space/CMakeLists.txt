cmake_minimum_required(VERSION 3.25.1)

project(
	"Space"
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(RAYLIB_DIR ${CMAKE_SOURCE_DIR}/external/raylib)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(${RAYLIB_DIR} raylib_binary_dir)
set(LIBRARIES ${LIBRARIES}
	raylib
)

include(cmake/Includes.cmake)
include(cmake/sources.cmake)

add_executable(${PROJECT_NAME}
	${SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBRARIES})
