#include "macro.h"
#include "logging.h"
#include "libudev.h"
#include "libudev1.h"

using namespace libudev_stub;

extern "C" {

struct udev_hwdb 
{
  int _reserved;
};

_public_ struct udev_hwdb* udev_hwdb_ref(struct udev_hwdb* hwdb) {
  LOG() << "udev_hwdb_ref()";
  return NULL;
}

_public_ struct udev_hwdb* udev_hwdb_unref(struct udev_hwdb* hwdb) {
  LOG() << "udev_hwdb_unref()";
  return NULL;
}

_public_ struct udev_list_entry* udev_hwdb_get_properties_list_entry(struct udev_hwdb* hwdb,
                                                                     const char* modalias,
                                                                     unsigned int flags) {
  LOG() << "udev_hwdb_get_properties_list_entry()";
  return NULL;
}

_public_ struct udev_hwdb* udev_hwdb_new(struct udev* udev) {
  LOG() << "udev_hwdb_new()";
  return NULL;
}

}  // extern "C"
