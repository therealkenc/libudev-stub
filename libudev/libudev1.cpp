#include <libudev.h>
#include <dlfcn.h>
#include "logging.h"
#include "libudev1.h"

namespace libudev_stub {

LibUdev1Loader::LibUdev1Loader() {}

LibUdev1Loader::~LibUdev1Loader() {}

bool LibUdev1Loader::load(const std::string& library_path) {
  library_ = dlopen(library_path.c_str(), RTLD_LAZY);
  if (!library_)
    return false;
  udev_device_get_action = reinterpret_cast<decltype(this->udev_device_get_action)>(
      dlsym(library_, "udev_device_get_action"));
  udev_device_get_devnode = reinterpret_cast<decltype(this->udev_device_get_devnode)>(
      dlsym(library_, "udev_device_get_devnode"));
  udev_device_get_parent = reinterpret_cast<decltype(this->udev_device_get_parent)>(
      dlsym(library_, "udev_device_get_parent"));
  udev_device_get_parent_with_subsystem_devtype =
      reinterpret_cast<decltype(this->udev_device_get_parent_with_subsystem_devtype)>(
          dlsym(library_, "udev_device_get_parent_with_subsystem_devtype"));
  udev_device_get_property_value = reinterpret_cast<decltype(this->udev_device_get_property_value)>(
      dlsym(library_, "udev_device_get_property_value"));
  udev_device_get_subsystem = reinterpret_cast<decltype(this->udev_device_get_subsystem)>(
      dlsym(library_, "udev_device_get_subsystem"));
  udev_device_get_sysattr_value = reinterpret_cast<decltype(this->udev_device_get_sysattr_value)>(
      dlsym(library_, "udev_device_get_sysattr_value"));
  udev_device_get_sysname = reinterpret_cast<decltype(this->udev_device_get_sysname)>(
      dlsym(library_, "udev_device_get_sysname"));
  udev_device_get_syspath = reinterpret_cast<decltype(this->udev_device_get_syspath)>(
      dlsym(library_, "udev_device_get_syspath"));
  udev_device_new_from_devnum = reinterpret_cast<decltype(this->udev_device_new_from_devnum)>(
      dlsym(library_, "udev_device_new_from_devnum"));
  udev_device_new_from_subsystem_sysname =
      reinterpret_cast<decltype(this->udev_device_new_from_subsystem_sysname)>(
          dlsym(library_, "udev_device_new_from_subsystem_sysname"));
  udev_device_new_from_syspath = reinterpret_cast<decltype(this->udev_device_new_from_syspath)>(
      dlsym(library_, "udev_device_new_from_syspath"));
  udev_device_unref =
      reinterpret_cast<decltype(this->udev_device_unref)>(dlsym(library_, "udev_device_unref"));
  udev_enumerate_add_match_subsystem =
      reinterpret_cast<decltype(this->udev_enumerate_add_match_subsystem)>(
          dlsym(library_, "udev_enumerate_add_match_subsystem"));
  udev_enumerate_get_list_entry = reinterpret_cast<decltype(this->udev_enumerate_get_list_entry)>(
      dlsym(library_, "udev_enumerate_get_list_entry"));
  udev_enumerate_new =
      reinterpret_cast<decltype(this->udev_enumerate_new)>(dlsym(library_, "udev_enumerate_new"));
  udev_enumerate_scan_devices = reinterpret_cast<decltype(this->udev_enumerate_scan_devices)>(
      dlsym(library_, "udev_enumerate_scan_devices"));
  udev_enumerate_unref = reinterpret_cast<decltype(this->udev_enumerate_unref)>(
      dlsym(library_, "udev_enumerate_unref"));
  udev_list_entry_get_next = reinterpret_cast<decltype(this->udev_list_entry_get_next)>(
      dlsym(library_, "udev_list_entry_get_next"));
  udev_list_entry_get_name = reinterpret_cast<decltype(this->udev_list_entry_get_name)>(
      dlsym(library_, "udev_list_entry_get_name"));
  udev_monitor_enable_receiving = reinterpret_cast<decltype(this->udev_monitor_enable_receiving)>(
      dlsym(library_, "udev_monitor_enable_receiving"));
  udev_monitor_filter_add_match_subsystem_devtype =
      reinterpret_cast<decltype(this->udev_monitor_filter_add_match_subsystem_devtype)>(
          dlsym(library_, "udev_monitor_filter_add_match_subsystem_devtype"));
  udev_monitor_get_fd =
      reinterpret_cast<decltype(this->udev_monitor_get_fd)>(dlsym(library_, "udev_monitor_get_fd"));
  udev_monitor_new_from_netlink = reinterpret_cast<decltype(this->udev_monitor_new_from_netlink)>(
      dlsym(library_, "udev_monitor_new_from_netlink"));
  udev_monitor_receive_device = reinterpret_cast<decltype(this->udev_monitor_receive_device)>(
      dlsym(library_, "udev_monitor_receive_device"));
  udev_monitor_ref =
      reinterpret_cast<decltype(this->udev_monitor_ref)>(dlsym(library_, "udev_monitor_ref"));
  udev_monitor_unref =
      reinterpret_cast<decltype(this->udev_monitor_unref)>(dlsym(library_, "udev_monitor_unref"));
  udev_new = reinterpret_cast<decltype(this->udev_new)>(dlsym(library_, "udev_new"));
#if 0
  udev_set_log_fn =
      reinterpret_cast<decltype(this->udev_set_log_fn)>(
          dlsym(library_, "udev_set_log_fn"));
  udev_set_log_priority =
      reinterpret_cast<decltype(this->udev_set_log_priority)>(
          dlsym(library_, "udev_set_log_priority"));
#endif
  udev_ref = reinterpret_cast<decltype(this->udev_ref)>(dlsym(library_, "udev_ref"));
  udev_unref = reinterpret_cast<decltype(this->udev_unref)>(dlsym(library_, "udev_unref"));
  udev_get_userdata =
      reinterpret_cast<decltype(this->udev_get_userdata)>(dlsym(library_, "udev_get_userdata"));
  udev_set_userdata =
      reinterpret_cast<decltype(this->udev_set_userdata)>(dlsym(library_, "udev_set_userdata"));
  udev_monitor_set_receive_buffer_size =
      reinterpret_cast<decltype(this->udev_monitor_set_receive_buffer_size)>(
          dlsym(library_, "udev_monitor_set_receive_buffer_size"));
  udev_monitor_filter_add_match_tag =
      reinterpret_cast<decltype(this->udev_monitor_filter_add_match_tag)>(
          dlsym(library_, "udev_monitor_filter_add_match_tag"));
  udev_monitor_filter_update = reinterpret_cast<decltype(this->udev_monitor_filter_update)>(
      dlsym(library_, "udev_monitor_filter_update"));
  udev_monitor_filter_remove = reinterpret_cast<decltype(this->udev_monitor_filter_remove)>(
      dlsym(library_, "udev_monitor_filter_remove"));
  udev_enumerate_ref =
      reinterpret_cast<decltype(this->udev_enumerate_ref)>(dlsym(library_, "udev_enumerate_ref"));
  udev_enumerate_add_nomatch_subsystem =
      reinterpret_cast<decltype(this->udev_enumerate_add_nomatch_subsystem)>(
          dlsym(library_, "udev_enumerate_add_nomatch_subsystem"));
  udev_enumerate_add_match_sysattr =
      reinterpret_cast<decltype(this->udev_enumerate_add_match_sysattr)>(
          dlsym(library_, "udev_enumerate_add_match_sysattr"));
  udev_enumerate_add_nomatch_sysattr =
      reinterpret_cast<decltype(this->udev_enumerate_add_nomatch_sysattr)>(
          dlsym(library_, "udev_enumerate_add_nomatch_sysattr"));
  return true;
}
}
