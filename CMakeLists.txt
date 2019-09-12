cmake_minimum_required (VERSION 3.5)
project(libudev_stub)

set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 4)
set(LIBUDEV_STUB_VERSION "${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set(LIBUDEV_SOVERSION_MAJOR "1")
set(LIBUDEV_SOVERSION "1.6.4")
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/out/bin")
include_directories("${PROJECT_BINARY_DIR}")
add_subdirectory(libudev)
add_executable(libudev_test udev-test.cpp)
target_include_directories(libudev_test PUBLIC "${PROJECT_SOURCE_DIR}/libudev")
target_link_libraries(libudev_test dl udev)

set(CPACK_GENERATOR "DEB")
set(CPACK_SYSTEM_NAME "WSL")
set(CPACK_PACKAGE_DIRECTORY "${CMAKE_BINARY_DIR}/out/deb")
set(CPACK_PACKAGING_INSTALL_PREFIX "/lib/x86_64-linux-gnu")
set(CPACK_PACKAGE_NAME libudev-stub)
set(CPACK_PACKAGE_VENDOR "community project")
set(CPACK_PACKAGE_CONTACT "https://github.com/therealkenc/libudev-stub")
set(CPACK_CMAKE_GENERATOR Ninja)
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "libudev stub library for WSL (${LIBUDEV_STUB_VERSION})")
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_SOURCE_DIR}/scripts/postinst")
include(CPack)

