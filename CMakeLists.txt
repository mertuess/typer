# Minimum required version of cmake set
cmake_minimum_required(VERSION 3.10)
project(typer) # Project name

# Set C++ 17 standart
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Import includes from ./include directory
include_directories(include)

# Import source files from ./src directory
file(GLOB SRC_FILES "src/*.cpp")
list(APPEND SRC_FILES "main.cpp") # Add main.cpp file

# Find the ncurses library
find_package(Curses REQUIRED)

# Add ncurses to the project and make executable
if (CURSES_FOUND)
		include_directories(${CURSES_INCLUDE_DIRS}) # Include ncurses
		add_executable(typer ${SRC_FILES}) # Make executable
		target_link_libraries(typer ${CURSES_LIBRARIES}) # Link ncurses
		set(CONFIG_DIR "$ENV{HOME}/.config/Typer") # Set path to config directory
		# Create config directory if it not exist
		add_custom_command(
    TARGET typer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CONFIG_DIR}
				COMMENT "Creating config directory: ${CONFIG_DIR}"
		)
		# Copy words file to config directory
		configure_file(
						${CMAKE_SOURCE_DIR}/res/words.txt
						${CONFIG_DIR}/words.txt
						@ONLY
		)
		install(TARGETS typer DESTINATION bin)
else()
		# Error message if ncurses not found
		message(FATAL_ERROR "ncurses library not found!")
endif()
