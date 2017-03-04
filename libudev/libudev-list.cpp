#include "macro.h"
#include "logging.h"
#include "libudev.h"
#include "libudev-internal.h"
#include "libudev1.h"

using namespace libudev_stub;

extern "C" {

_public_ struct udev_list_entry* udev_list_entry_get_next(struct udev_list_entry* list_entry) {
  LOG() << "udev_list_entry_get_next()";
  struct udev_list_entry* next = NULL;
  if (list_entry) {
    struct udev* udev = list_entry->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      next = list_entry->proxy = loader->udev_list_entry_get_next(list_entry->proxy);
    }
  }
  return next;
}

_public_ struct udev_list_entry* udev_list_entry_get_by_name(struct udev_list_entry* list_entry,
                                                             const char* name) {
  LOG() << "udev_list_entry_get_by_name()";
  return NULL;
}

_public_ const char* udev_list_entry_get_name(struct udev_list_entry* list_entry) {
  LOG() << "udev_list_entry_get_name()";
  const char* name = "unknown_name";
  if (list_entry) {
    struct udev* udev = list_entry->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      name = loader->udev_list_entry_get_name(list_entry->proxy);
    }
  }
  return name;
}

_public_ const char* udev_list_entry_get_value(struct udev_list_entry* list_entry) {
  LOG() << "udev_list_entry_get_value()";
  return NULL;
}

} // extern "C"
