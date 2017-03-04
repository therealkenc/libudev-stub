#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include "macro.h"
#include "logging.h"
#include "libudev.h"
#include "libudev-internal.h"
#include "libudev1.h"

using namespace libudev_stub;

extern "C" {

struct udev_monitor {
  struct udev* udev;
  int refcount;
  int sock_pair[2];
  struct udev_monitor* proxy;
};

_public_ struct udev_monitor* udev_monitor_ref(struct udev_monitor* udev_monitor) {
  LOG() << "udev_monitor_ref()";
  if (udev_monitor) {
    struct udev* udev = udev_monitor->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      loader->udev_monitor_ref(udev_monitor->proxy);
    }
    udev_monitor->refcount++;
  }
  return udev_monitor;
}

_public_ struct udev_monitor* udev_monitor_unref(struct udev_monitor* udev_monitor) {
  LOG() << "udev_monitor_unref()";
  if (udev_monitor) {
    struct udev* udev = udev_monitor->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      loader->udev_monitor_unref(udev_monitor->proxy);
    }
    udev_monitor->refcount--;
    if (udev_monitor->refcount == 0) {
      if (udev_monitor->sock_pair[0] > 0) {
        close(udev_monitor->sock_pair[0]);
      }
      if (udev_monitor->sock_pair[1] > 0) {
        close(udev_monitor->sock_pair[1]);
      }
      delete udev_monitor;
      udev_monitor = NULL;
    }
  }
  return udev_monitor;
}

_public_ struct udev* udev_monitor_get_udev(struct udev_monitor* udev_monitor) {
  LOG() << "udev_monitor_get_udev()";
  return (udev_monitor) ? udev_monitor->udev : NULL;
}

_public_ struct udev_monitor* udev_monitor_new_from_netlink(struct udev* udev, const char* name) {
  LOG() << "udev_monitor_new_from_netlink() name: " << name;
  struct udev_monitor* new_monitor = NULL;
  if (udev) {
    new_monitor = new udev_monitor;
    new_monitor->udev = udev;
    new_monitor->refcount = 1;
    new_monitor->proxy = NULL;
    new_monitor->sock_pair[0] = -1;
    new_monitor->sock_pair[1] = -1;
    if (udev->loader) {
      LOG() << "here!";
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      new_monitor->proxy = loader->udev_monitor_new_from_netlink(udev->loader_udev, name);
    }
  }
  return new_monitor;
}

_public_ int udev_monitor_enable_receiving(struct udev_monitor* udev_monitor) {
  LOG() << "udev_monitor_enable_receiving()";
  int ret = -1;
  if (udev_monitor) {
    struct udev* udev = udev_monitor->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_monitor_enable_receiving(udev_monitor->proxy);
      if (ret != 0) {
        LOG() << "udev_monitor_enable_receiving() return != 0";
      }
    } else {
      ret = socketpair(AF_UNIX, SOCK_DGRAM, 0, udev_monitor->sock_pair);
    }
  }
  return ret;
}

_public_ int udev_monitor_set_receive_buffer_size(struct udev_monitor* udev_monitor, int size) {
  LOG() << "udev_monitor_set_receive_buffer_size()";
  int ret = -1;
  if (udev_monitor) {
    struct udev* udev = udev_monitor->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_monitor_set_receive_buffer_size(udev_monitor->proxy, size);
      if (ret != 0) {
        LOG() << "udev_monitor_set_receive_buffer_size() return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_monitor_get_fd(struct udev_monitor* udev_monitor) {
  LOG() << "udev_monitor_get_fd()";
  int ret = -1;
  if (udev_monitor) {
    struct udev* udev = udev_monitor->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_monitor_get_fd(udev_monitor->proxy);
    } else {
      ret = udev_monitor->sock_pair[0];
    }
  }
  return ret;
}

_public_ struct udev_device* udev_monitor_receive_device(struct udev_monitor* udev_monitor) {
  LOG() << "udev_monitor_receive_device()";
  struct udev_device* device = NULL;
  if (udev_monitor) {
    struct udev* udev = udev_monitor->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      device = loader->udev_monitor_receive_device(udev_monitor->proxy);
    }
  }
  return device;
}

_public_ int udev_monitor_filter_add_match_subsystem_devtype(struct udev_monitor* udev_monitor,
                                                             const char* subsystem,
                                                             const char* devtype) {
  LOG() << "udev_monitor_filter_add_match_subsystem_devtype() subsystem: " << subsystem
        << " devtype: " << ((devtype) ? devtype : "(null)");
  int ret = -1;
  if (udev_monitor) {
    struct udev* udev = udev_monitor->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_monitor_filter_add_match_subsystem_devtype(udev_monitor->proxy, subsystem,
                                                                    devtype);
    } else {
      // lie like a rug and accept any subsystem/devtype given.
      ret = 0;
    }
  }
  return ret;
}

_public_ int udev_monitor_filter_add_match_tag(struct udev_monitor* udev_monitor, const char* tag) {
  LOG() << "udev_monitor_filter_add_match_tag() tag: " << tag;
  int ret = -1;
  if (udev_monitor) {
    struct udev* udev = udev_monitor->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_monitor_filter_add_match_tag(udev_monitor->proxy, tag);
    }
  }
  return ret;
}

_public_ int udev_monitor_filter_update(struct udev_monitor* udev_monitor) {
  LOG() << "udev_monitor_filter_update()";
  int ret = -1;
  if (udev_monitor) {
    struct udev* udev = udev_monitor->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_monitor_filter_update(udev_monitor->proxy);
    }
  }
  return ret;
}

_public_ int udev_monitor_filter_remove(struct udev_monitor* udev_monitor) {
  LOG() << "udev_monitor_filter_remove()";
  int ret = -1;
  if (udev_monitor) {
    struct udev* udev = udev_monitor->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_monitor_filter_remove(udev_monitor->proxy);
    }
  }
}

}  // extern "C"
