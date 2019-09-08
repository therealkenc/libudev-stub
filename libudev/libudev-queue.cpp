#include "macro.h"
#include "logging.h"
#include "libudev.h"
#include "libudev1.h"

using namespace libudev_stub;

extern "C" {

struct udev_queue 
{
  int _reserved;
};

_public_ struct udev_queue* udev_queue_ref(struct udev_queue* udev_queue) {
  LOG() << "udev_queue_ref()";
  return NULL;
}

_public_ struct udev_queue* udev_queue_unref(struct udev_queue* udev_queue) {
  LOG() << "udev_queue_unref()";
  return NULL;
}

_public_ struct udev* udev_queue_get_udev(struct udev_queue* udev_queue) {
  LOG() << "udev_queue_get_udev()";
  return NULL;
}

_public_ struct udev_queue* udev_queue_new(struct udev* udev) {
  LOG() << "udev_queue_new()";
  return NULL;
}

_public_ unsigned long long int udev_queue_get_kernel_seqnum(struct udev_queue* udev_queue) {
  LOG() << "udev_queue_get_kernel_seqnum()";
  return 0;
}

_public_ unsigned long long int udev_queue_get_udev_seqnum(struct udev_queue* udev_queue) {
  LOG() << "udev_queue_get_udev_seqnum()";
  return 0;
}

_public_ int udev_queue_get_udev_is_active(struct udev_queue* udev_queue) {
  LOG() << "udev_queue_get_udev_is_active()";
  return 0;
}

_public_ int udev_queue_get_queue_is_empty(struct udev_queue* udev_queue) {
  LOG() << "udev_queue_get_queue_is_empty()";
  return 0;
}

_public_ int udev_queue_get_seqnum_is_finished(struct udev_queue* udev_queue,
                                               unsigned long long int seqnum) {
  LOG() << "udev_queue_get_seqnum_is_finished()";
  return 0;
}

_public_ int udev_queue_get_seqnum_sequence_is_finished(struct udev_queue* udev_queue,
                                                        unsigned long long int start,
                                                        unsigned long long int end) {
  LOG() << "udev_queue_get_seqnum_sequence_is_finished()";
  return 0;
}

_public_ int udev_queue_get_fd(struct udev_queue* udev_queue) {
  LOG() << "udev_queue_get_fd()";
  return 0;
}

_public_ int udev_queue_flush(struct udev_queue* udev_queue) {
  LOG() << "udev_queue_flush()";
  return 0;
}

_public_ struct udev_list_entry* udev_queue_get_queued_list_entry(struct udev_queue* udev_queue) {
  LOG() << "udev_queue_get_queued_list_entry()";
  return NULL;
}

}  // extern "C"
