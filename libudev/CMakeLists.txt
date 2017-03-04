file(GLOB udev_src "*.cpp")
add_library(udev SHARED ${udev_src})
set_property(TARGET udev PROPERTY SOVERSION 1)
set_property(TARGET udev PROPERTY VERSION 1.6.4)
