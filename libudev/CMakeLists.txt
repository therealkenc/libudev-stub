set(DEST_DIR "${CMAKE_INSTALL_PREFIX}")
set(PRIVATE_LIBS -ludev)
CONFIGURE_FILE("template_pc.in" "libudev.pc" @ONLY)
file(GLOB udev_src "*.cpp")
add_library(udev SHARED ${udev_src} "libudev.pc")
set_property(TARGET udev PROPERTY SOVERSION "${LIBUDEV_SOVERSION_MAJOR}")
set_property(TARGET udev PROPERTY VERSION "${LIBUDEV_SOVERSION}")
set_target_properties(udev PROPERTIES PUBLIC_HEADER libudev.h)
install(TARGETS udev
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)
install(FILES "${CMAKE_BINARY_DIR}/libudev.pc" DESTINATION lib/pkgconfig COMPONENT config)
