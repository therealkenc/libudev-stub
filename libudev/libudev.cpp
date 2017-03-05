/***
  This file used to be part of systemd. Based code with the following copyright:

  Copyright 2008-2014 Kay Sievers <kay@vrfy.org>

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#include <stdlib.h>
#include "config.h"
#include "macro.h"
#include "logging.h"
#include "libudev.h"
#include "libudev-internal.h"
#include "libudev1.h"

using namespace libudev_stub;

class StubEntry {
public:
  StubEntry() {
    LOG() << "Using libudev-stub " << STR(LIBUDEV_STUB_VERSION);
  }
};
static StubEntry entry;

extern "C" {

_public_ void* udev_get_userdata(struct udev* udev) {
  LOG() << "udev_get_userdata()";
  if (udev == NULL) {
    return NULL;
  }
  if (udev->loader) {
    LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
    void* data = loader->udev_get_userdata(udev->loader_udev);
    if (data != udev->userdata) {
      LOG() << "userdata mismatch";
    }
  }
  return udev->userdata;
}

_public_ void udev_set_userdata(struct udev* udev, void* userdata) {
  LOG() << "udev_set_userdata()";
  if (udev == NULL) {
    return;
  }
  if (udev->loader) {
    LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
    loader->udev_set_userdata(udev->loader_udev, userdata);
  }
  udev->userdata = userdata;
}

_public_ struct udev* udev_new(void) {
  LOG() << "udev_new()";
  struct udev* new_udev = new udev;
  new_udev->loader = NULL;
  new_udev->loader_udev = NULL;
  char* library = secure_getenv("LIBUDEV_STUB_PASSTHROUGH");
  if (library) {
    LOG() << "found LIBUDEV_STUB_PASSTHROUGH = " << library;
    LibUdev1Loader* loader = new LibUdev1Loader();
    if (loader->load("/lib/x86_64-linux-gnu/libudev.so.1")) {
      LOG() << "udev passthrough load success. proxying instead of stubbing.";
      new_udev->loader = reinterpret_cast<void*>(loader);
      new_udev->loader_udev = loader->udev_new();
    } else {
      LOG() << "udev passthrough load failed";
      delete loader;
    }
  } else {
    LOG() << "stubbing udev...";
  }
  new_udev->userdata = NULL;
  new_udev->refcount = 1;
  return new_udev;
}

_public_ struct udev* udev_ref(struct udev* udev) {
  if (udev == NULL) {
    return NULL;
  }
  if (udev->loader) {
    LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
    loader->udev_ref(udev->loader_udev);
  }
  udev->refcount++;
  return udev;
}

_public_ struct udev* udev_unref(struct udev* udev) {
  LOG() << "udev_unref()";
  if (udev == NULL) {
    return NULL;
  }
  if (udev->loader) {
    LibUdev1Loader* loader = reinterpret_cast<LibUdev1Loader*>(udev->loader);
    loader->udev_unref(udev->loader_udev);
  }
  udev->refcount--;
  if (udev->refcount > 0) {
    return udev;
  }
  delete udev;
  return NULL;
}

_public_ void udev_set_log_fn(struct udev* udev,
                              void (*log_fn)(struct udev* udev,
                                             int priority,
                                             const char* file,
                                             int line,
                                             const char* fn,
                                             const char* format,
                                             va_list args)) {
  LOG() << "udev_set_log_fn()";
}

_public_ int udev_get_log_priority(struct udev* udev) {
  LOG() << "udev_get_log_priority";
  return 0;
}

_public_ void udev_set_log_priority(struct udev* udev, int priority) {
  LOG() << "udev_set_log_priority";
}

}  // extern "C"