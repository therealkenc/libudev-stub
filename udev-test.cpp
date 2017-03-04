#include <libudev.h>
#include <dlfcn.h>
#include <stdio.h>

int main(int argc, const char* argv[]) {
  void* library = dlopen("libudev.so.1", RTLD_LAZY);
  printf("library: %p\n", library);
  struct udev* udev = udev_new();
  printf("udev: %p\n", udev);
  struct udev_monitor* mon = udev_monitor_new_from_netlink(udev, "udev");
  printf("mon: %p\n", mon);
  udev_monitor_filter_add_match_subsystem_devtype(mon, "hidraw", NULL);
	udev_monitor_enable_receiving(mon);
	int fd = udev_monitor_get_fd(mon);  
  printf("fd: %d\n", fd);
  struct udev_enumerate* enumerate = udev_enumerate_new(udev);
  printf("enumerate: %p\n", enumerate);
	udev_enumerate_add_match_subsystem(enumerate, "hidraw");
	udev_enumerate_scan_devices(enumerate);
  struct udev_list_entry* devices = udev_enumerate_get_list_entry(enumerate);
  printf("devices: %p\n", devices);
  struct udev_list_entry* entry;
  udev_list_entry_foreach(entry, devices) {
    const char* path = udev_list_entry_get_name(entry);
    struct udev_device* dev = udev_device_new_from_syspath(udev, path);
    printf("path: %s node: %s\n", path, udev_device_get_devnode(dev));
  }
  return 0;
}
