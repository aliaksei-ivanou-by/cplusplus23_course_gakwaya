cmake_minimum_required(VERSION 3.28)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(Rocket  VERSION 1.0.0 LANGUAGES CXX)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp exercise.cpp)

target_include_directories(
			${PROJECT_NAME}
			PRIVATE
			${CMAKE_CURRENT_SOURCE_DIR}
)