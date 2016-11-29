cmake_minimum_required(VERSION 2.6)
project(ConnectFour)

# Include cmake directory for various SDL2 modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ConnectFour_SOURCE_DIR}/cmake")
# Set an output binary directory
set(BIN_DIR ${ConnectFour_SOURCE_DIR}/bin)

# Bump up warning levels appropriately for clang, gcc & msvc
# Also set debug/optimization flags depending on the build type
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
		string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
	endif()
endif()

# Look up SDL2 and its modules, and add their directories to include path
find_package(SDL2 REQUIRED)
include_directories(include ${SDL2_INCLUDE_DIR})
file(GLOB SOURCES "src/*.cc")
add_executable(main ${SOURCES})
target_link_libraries(main ${SDL2_LIBRARY})
install(TARGETS main RUNTIME DESTINATION ${BIN_DIR})
