using namespace libudev_stub;

extern "C" {

struct udev {
  int refcount;
  void (*log_fn)(struct udev* udev,
                 int priority,
                 const char* file,
                 int line,
                 const char* fn,
                 const char* format,
                 va_list args);
  void* userdata;
  void* loader;
  struct udev* loader_udev;
};

/*  Unlike the other opague structures in udev, udev_list_entry (which is
    returned by udev_enumerate_get_list_entry) does not have a public method
    to get back to the udev root. Rather than depend on internals and expose
    such an interface, treat ours like a cursor to the real one and hold a 
    back pointer to udev. This will break horribly if two threads try to
    iterate on the list at the same time, but I doubt that's allowed or
    happens in practice anyway.
 */
struct udev_list_entry {
  struct udev* udev;
  struct udev_list_entry* proxy;
};

}  // extern "C"