#include "macro.h"
#include "logging.h"
#include "libudev.h"
#include "libudev1.h"

using namespace libudev_stub;

extern "C" {

struct udev_device 
{
  int _reserved;
};

struct udev_device* udev_device_ref(struct udev_device* udev_device) {
  LOG() << "udev_device_ref()";
  return NULL;
}

_public_ struct udev_device* udev_device_unref(struct udev_device* udev_device) {
  LOG() << "udev_device_unref()";
  return NULL;
}

_public_ struct udev* udev_device_get_udev(struct udev_device* udev_device) {
  LOG() << "udev_device_get_udev()";
  return NULL;
}

_public_ struct udev_device* udev_device_new_from_syspath(struct udev* udev, const char* syspath) {
  LOG() << "udev_device_new_from_syspath()";
  return NULL;
}

_public_ struct udev_device* udev_device_new_from_devnum(struct udev* udev,
                                                         char type,
                                                         dev_t devnum) {
  LOG() << "udev_device_new_from_devnum()";
  return NULL;
}

_public_ struct udev_device* udev_device_new_from_subsystem_sysname(struct udev* udev,
                                                                    const char* subsystem,
                                                                    const char* sysname) {
  LOG() << "udev_device_new_from_subsystem_sysname()";
  return NULL;
}

_public_ struct udev_device* udev_device_new_from_device_id(struct udev* udev, const char* id) {
  LOG() << "udev_device_new_from_device_id()";
  return NULL;
}

_public_ struct udev_device* udev_device_new_from_environment(struct udev* udev) {
  LOG() << "udev_device_new_from_environment()";
  return NULL;
}

_public_ struct udev_device* udev_device_get_parent(struct udev_device* udev_device) {
  LOG() << "udev_device_get_parent()";
  return NULL;
}

_public_ struct udev_device* udev_device_get_parent_with_subsystem_devtype(struct udev_device* udev_device,
                                                                  const char* subsystem,
                                                                  const char* devtype) {
  LOG() << "udev_device_get_parent_with_subsystem_devtype()";
  return NULL;
}

_public_ const char* udev_device_get_devpath(struct udev_device* udev_device) {
  LOG() << "udev_device_get_devpath()";
  return NULL;
}

_public_ const char* udev_device_get_subsystem(struct udev_device* udev_device) {
  LOG() << "udev_device_get_subsystem()";
  return NULL;
}

_public_ const char* udev_device_get_devtype(struct udev_device* udev_device) {
  LOG() << "udev_device_get_devtype()";
  return NULL;
}

_public_ const char* udev_device_get_syspath(struct udev_device* udev_device) {
  LOG() << "udev_device_get_syspath()";
  return NULL;
}

_public_ const char* udev_device_get_sysname(struct udev_device* udev_device) {
  LOG() << "udev_device_get_sysname()";
  return NULL;
}

_public_ const char* udev_device_get_sysnum(struct udev_device* udev_device) {
  LOG() << "udev_device_get_sysnum()";
  return NULL;
}

_public_ const char* udev_device_get_devnode(struct udev_device* udev_device) {
  LOG() << "udev_device_get_devnode()";
  return NULL;
}

_public_ int udev_device_get_is_initialized(struct udev_device* udev_device) {
  LOG() << "udev_device_get_is_initialized()";
  return 0;
}

_public_ struct udev_list_entry* udev_device_get_devlinks_list_entry(struct udev_device* udev_device) {
  LOG() << "udev_device_get_devlinks_list_entry()";
  return NULL;
}

_public_ struct udev_list_entry* udev_device_get_properties_list_entry(struct udev_device* udev_device) {
  LOG() << "udev_device_get_properties_list_entry()";
  return NULL;
}

_public_ struct udev_list_entry* udev_device_get_tags_list_entry(struct udev_device* udev_device) {
  LOG() << "udev_device_get_tags_list_entry()";
  return NULL;
}

_public_ struct udev_list_entry* udev_device_get_sysattr_list_entry(struct udev_device* udev_device) {
  LOG() << "udev_device_get_sysattr_list_entry()";
  return NULL;
}

_public_ const char* udev_device_get_property_value(struct udev_device* udev_device, const char* key) {
  LOG() << "udev_device_get_property_value()";
  return "unknown_property_value";
}

_public_ const char* udev_device_get_driver(struct udev_device* udev_device) {
  LOG() << "udev_device_get_driver()";
  return "unknown_device_driver";
}

_public_ dev_t udev_device_get_devnum(struct udev_device* udev_device) {
  LOG() << "udev_device_get_devnum()";
  return 0;
}

_public_ const char* udev_device_get_action(struct udev_device* udev_device) {
  LOG() << "udev_device_get_action()";
  return "unknown_device_action";
}

_public_ unsigned long long int udev_device_get_seqnum(struct udev_device* udev_device) {
  LOG() << "udev_device_get_seqnum()";
  return 0;
}

_public_ unsigned long long int udev_device_get_usec_since_initialized(struct udev_device* udev_device) {
  LOG() << "udev_device_get_usec_since_initialized()";
  return 0;
}

_public_ const char* udev_device_get_sysattr_value(struct udev_device* udev_device, const char* sysattr) {
  LOG() << "udev_device_get_sysattr_value()";
  return "unknown_sysattr_value";
}

_public_ int udev_device_set_sysattr_value(struct udev_device* udev_device,
                                  const char* sysattr,
                                  char* value) {
  LOG() << "udev_device_get_sysattr_value()";
  return 0;
}

_public_ int udev_device_has_tag(struct udev_device* udev_device, const char* tag) {
  LOG() << "udev_device_has_tag()";
  return 0;
}

} // extern "C"
