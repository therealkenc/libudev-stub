file(GLOB udev_src "*.cpp")
add_library(udev-stub SHARED ${udev_src})
set_property(TARGET udev-stub PROPERTY SOVERSION "${LIBUDEV_SOVERSION_MAJOR}")
set_property(TARGET udev-stub PROPERTY VERSION "${LIBUDEV_SOVERSION}")
add_custom_command(TARGET udev-stub
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E create_symlink
  "${CMAKE_BINARY_DIR}/out/lib/libudev-stub.so.${LIBUDEV_SOVERSION}"
  "${CMAKE_BINARY_DIR}/out/lib/libudev.so.${LIBUDEV_SOVERSION_MAJOR}"
)
install(TARGETS udev-stub DESTINATION .)
