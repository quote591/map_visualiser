cmake_minimum_required(VERSION 3.21.0)

project(map_visualiser VERSION 1.0 DESCRIPTION "Simple OpenGL program to \
visualise 3d map data")

set(EXECUTABLE_NAME "map_vis")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)
add_subdirectory(renderer)
add_subdirectory(3rdParty/glad/src)

message(STATUS "Here are the cxx sources: ${cxx_sources}")
message(STATUS "Here are the c sources: ${c_sources}")

include_directories(${CMAKE_SOURCE_DIR}/3rdParty/glad/include)
include_directories(${CMAKE_SOURCE_DIR}/3rdParty/GLFW/include)
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/renderer)

add_executable(${EXECUTABLE_NAME}
	${cxx_sources}
	${c_sources}
)

IF (WIN32)
	message(STATUS "Building for Win32 target")

	## env var for this? No, fingers crossed you have this
	link_directories("C:/msys64/mingw64/lib/")

	target_link_libraries(${EXECUTABLE_NAME} PRIVATE
		${CMAKE_SOURCE_DIR}/3rdParty/GLFW/win_libs/libglfw3.a
		libz.dll.a
	)
ELSE ()
	message (STATUS "Building for UNIX-Like target")
	target_link_libraries(${EXECUTABLE_NAME} PRIVATE
		libglfw3.a
		X11
	)
ENDIF()

