/**
  This class is basically the same as the generated loader class from chrome with
  more interface manually added.
    .../gen/library_loaders/libudev1.h
 **/

#include <string>

namespace libudev_stub {

class LibUdev1Loader {
 public:
  LibUdev1Loader();
  ~LibUdev1Loader();
  bool load(const std::string& library_path);

  decltype(&::udev_device_get_action) udev_device_get_action;
  decltype(&::udev_device_get_devnode) udev_device_get_devnode;
  decltype(&::udev_device_get_parent) udev_device_get_parent;
  decltype(&::udev_device_get_parent_with_subsystem_devtype)
      udev_device_get_parent_with_subsystem_devtype;
  decltype(&::udev_device_get_property_value) udev_device_get_property_value;
  decltype(&::udev_device_get_subsystem) udev_device_get_subsystem;
  decltype(&::udev_device_get_sysattr_value) udev_device_get_sysattr_value;
  decltype(&::udev_device_get_sysname) udev_device_get_sysname;
  decltype(&::udev_device_get_syspath) udev_device_get_syspath;
  decltype(&::udev_device_new_from_devnum) udev_device_new_from_devnum;
  decltype(&::udev_device_new_from_subsystem_sysname) udev_device_new_from_subsystem_sysname;
  decltype(&::udev_device_new_from_syspath) udev_device_new_from_syspath;
  decltype(&::udev_device_unref) udev_device_unref;
  decltype(&::udev_enumerate_add_match_subsystem) udev_enumerate_add_match_subsystem;
  decltype(&::udev_enumerate_get_list_entry) udev_enumerate_get_list_entry;
  decltype(&::udev_enumerate_new) udev_enumerate_new;
  decltype(&::udev_enumerate_scan_devices) udev_enumerate_scan_devices;
  decltype(&::udev_enumerate_unref) udev_enumerate_unref;
  decltype(&::udev_list_entry_get_next) udev_list_entry_get_next;
  decltype(&::udev_list_entry_get_name) udev_list_entry_get_name;
  decltype(&::udev_monitor_enable_receiving) udev_monitor_enable_receiving;
  decltype(&::udev_monitor_filter_add_match_subsystem_devtype)
      udev_monitor_filter_add_match_subsystem_devtype;
  decltype(&::udev_monitor_get_fd) udev_monitor_get_fd;
  decltype(&::udev_monitor_new_from_netlink) udev_monitor_new_from_netlink;
  decltype(&::udev_monitor_receive_device) udev_monitor_receive_device;
  decltype(&::udev_monitor_ref) udev_monitor_ref;
  decltype(&::udev_monitor_unref) udev_monitor_unref;
  decltype(&::udev_new) udev_new;
#if 0
  decltype(&::udev_set_log_fn) udev_set_log_fn;
  decltype(&::udev_set_log_priority) udev_set_log_priority;
#endif
  decltype(&::udev_ref) udev_ref;
  decltype(&::udev_unref) udev_unref;
  decltype(&::udev_get_userdata) udev_get_userdata;
  decltype(&::udev_set_userdata) udev_set_userdata;
  decltype(&::udev_monitor_set_receive_buffer_size) udev_monitor_set_receive_buffer_size;
  decltype(&::udev_monitor_filter_add_match_tag) udev_monitor_filter_add_match_tag;
  decltype(&::udev_monitor_filter_update) udev_monitor_filter_update;
  decltype(&::udev_monitor_filter_remove) udev_monitor_filter_remove;
  decltype(&::udev_enumerate_ref) udev_enumerate_ref;
  decltype(&::udev_enumerate_add_nomatch_subsystem) udev_enumerate_add_nomatch_subsystem;
  decltype(&::udev_enumerate_add_match_sysattr) udev_enumerate_add_match_sysattr;
  decltype(&::udev_enumerate_add_nomatch_sysattr) udev_enumerate_add_nomatch_sysattr;

  decltype(&::udev_enumerate_add_match_property) udev_enumerate_add_match_property;
  decltype(&::udev_enumerate_add_match_sysname) udev_enumerate_add_match_sysname;
  decltype(&::udev_enumerate_add_match_tag) udev_enumerate_add_match_tag;
  decltype(&::udev_enumerate_add_match_parent) udev_enumerate_add_match_parent;

  decltype(&::udev_enumerate_add_match_is_initialized) udev_enumerate_add_match_is_initialized;
  decltype(&::udev_enumerate_add_syspath) udev_enumerate_add_syspath;
  decltype(&::udev_enumerate_scan_subsystems) udev_enumerate_scan_subsystems;
  

 private:
  void* library_;
};
}
