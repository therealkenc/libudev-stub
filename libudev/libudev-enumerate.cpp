#include "macro.h"
#include "logging.h"
#include "libudev.h"
#include "libudev-internal.h"
#include "libudev1.h"

using namespace libudev_stub;

extern "C" {

struct udev_enumerate {
  struct udev* udev;
  int refcount;
  struct udev_enumerate* proxy;
  struct udev_list_entry devices_list;
};

_public_ struct udev_enumerate* udev_enumerate_ref(struct udev_enumerate* udev_enumerate) {
  LOG() << "udev_enumerate_ref()";
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      loader->udev_enumerate_ref(udev_enumerate->proxy);
    }
    udev_enumerate->refcount++;
  }
  return udev_enumerate;
}

_public_ struct udev_enumerate* udev_enumerate_unref(struct udev_enumerate* udev_enumerate) {
  LOG() << "udev_enumerate_unref()";
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      loader->udev_enumerate_unref(udev_enumerate->proxy);
    }
    udev_enumerate->refcount--;
    if (udev_enumerate->refcount == 0) {
      delete udev_enumerate;
      udev_enumerate = NULL;
    }
  }
  return udev_enumerate;
}

_public_ struct udev* udev_enumerate_get_udev(struct udev_enumerate* udev_enumerate) {
  LOG() << "udev_enumerate_get_udev()";
  return (udev_enumerate) ? udev_enumerate->udev : NULL;
}

_public_ struct udev_enumerate* udev_enumerate_new(struct udev* udev) {
  LOG() << "udev_enumerate_new()";
  struct udev_enumerate* new_enumerate = NULL;
  if (udev) {
    new_enumerate = new udev_enumerate;
    new_enumerate->udev = udev;
    new_enumerate->devices_list.udev = udev;
    new_enumerate->refcount = 1;
    new_enumerate->proxy = NULL;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      new_enumerate->proxy = loader->udev_enumerate_new(udev->loader_udev);
    }
  }
  return new_enumerate;
}

_public_ int udev_enumerate_add_match_subsystem(struct udev_enumerate* udev_enumerate,
                                                const char* subsystem) {
  LOG() << "udev_enumerate_add_match_subsystem() subsystem: " << subsystem;
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_add_match_subsystem(udev_enumerate->proxy, subsystem);
      if (ret != 0) {
        LOG() << "udev_enumerate_add_match_subsystem return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_add_nomatch_subsystem(struct udev_enumerate* udev_enumerate,
                                                  const char* subsystem) {
  LOG() << "udev_enumerate_add_nomatch_subsystem() subsystem: " << subsystem;
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_add_nomatch_subsystem(udev_enumerate->proxy, subsystem);
      if (ret != 0) {
        LOG() << "udev_enumerate_add_nomatch_subsystem return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_add_match_sysattr(struct udev_enumerate* udev_enumerate,
                                              const char* sysattr,
                                              const char* value) {
  LOG() << "udev_enumerate_add_match_sysattr() sysattr: " << sysattr << "value: " << value;
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_add_match_sysattr(udev_enumerate->proxy, sysattr, value);
      if (ret != 0) {
        LOG() << "dev_enumerate_add_match_sysattr return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_add_nomatch_sysattr(struct udev_enumerate* udev_enumerate,
                                                const char* sysattr,
                                                const char* value) {
  LOG() << "udev_enumerate_add_nomatch_sysattr() sysattr: " << sysattr << "value: " << value;
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_add_nomatch_sysattr(udev_enumerate->proxy, sysattr, value);
      if (ret != 0) {
        LOG() << "udev_enumerate_add_nomatch_sysattr return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_add_match_property(struct udev_enumerate* udev_enumerate,
                                               const char* property,
                                               const char* value) {
  LOG() << "udev_enumerate_add_match_property() property: " << property << "value: " << value;
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_add_match_property(udev_enumerate->proxy, property, value);
      if (ret != 0) {
        LOG() << "udev_enumerate_add_match_property return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_add_match_sysname(struct udev_enumerate* udev_enumerate,
                                              const char* sysname) {
  LOG() << "udev_enumerate_add_match_sysname() sysname: " << sysname;

  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_add_match_sysname(udev_enumerate->proxy, sysname);
      if (ret != 0) {
        LOG() << "udev_enumerate_add_match_sysname return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_add_match_tag(struct udev_enumerate* udev_enumerate, const char* tag) {
  LOG() << "udev_enumerate_add_match_tag() tag: " << tag;
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_add_match_tag(udev_enumerate->proxy, tag);
      if (ret != 0) {
        LOG() << "udev_enumerate_add_match_tag return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_add_match_parent(struct udev_enumerate* udev_enumerate,
                                             struct udev_device* parent) {
  LOG() << "udev_enumerate_add_match_parent() parent: " << parent;
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_add_match_parent(udev_enumerate->proxy, parent);
      if (ret != 0) {
        LOG() << "udev_enumerate_add_match_parent return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_add_match_is_initialized(struct udev_enumerate* udev_enumerate) {
  LOG() << "udev_enumerate_add_match_is_initialized()";
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_add_match_is_initialized(udev_enumerate->proxy);
      if (ret != 0) {
        LOG() << "udev_enumerate_add_match_is_initialized return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_add_syspath(struct udev_enumerate* udev_enumerate,
                                        const char* syspath) {
  LOG() << "udev_enumerate_add_syspath() syspath: " << syspath;
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_add_syspath(udev_enumerate->proxy, syspath);
      if (ret != 0) {
        LOG() << "udev_enumerate_add_syspath return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_scan_devices(struct udev_enumerate* udev_enumerate) {
  LOG() << "udev_enumerate_scan_devices()";
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_scan_devices(udev_enumerate->proxy);
      if (ret != 0) {
        LOG() << "udev_enumerate_scan_devices return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ int udev_enumerate_scan_subsystems(struct udev_enumerate* udev_enumerate) {
  LOG() << "udev_enumerate_scan_subsystems()";
  int ret = -1;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      ret = loader->udev_enumerate_scan_subsystems(udev_enumerate->proxy);
      if (ret != 0) {
        LOG() << "udev_enumerate_scan_devices return != 0";
      }
    }
    ret = 0;
  }
  return ret;
}

_public_ struct udev_list_entry* udev_enumerate_get_list_entry(
    struct udev_enumerate* udev_enumerate) {
  LOG() << "udev_enumerate_get_list_entry()";
  struct udev_list_entry* entry = NULL;
  if (udev_enumerate) {
    struct udev* udev = udev_enumerate->udev;
    if (udev->loader) {
      LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
      entry = &udev_enumerate->devices_list;
      entry->proxy = loader->udev_enumerate_get_list_entry(udev_enumerate->proxy);
    } else {
      LOG() << "udev stubbing: returning empty device list.";
    }
  } 
  return entry;
}

}  // extern "C"
