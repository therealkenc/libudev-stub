#include "macro.h"
#include "logging.h"
#include "libudev.h"
#include "libudev1.h"

using namespace libudev_stub;

extern "C" {

_public_ int udev_util_encode_string(const char* str, char* str_enc, size_t len) {
  LOG() << "udev_util_encode_string()";
  return 0;
}

}  // extern "C"
