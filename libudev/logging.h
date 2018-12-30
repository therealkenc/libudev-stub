#include <iostream>
#include <sstream>

extern bool g_logging;

namespace libudev_stub {

#define LOG() LogMessage().get()

class LogMessage {
public:
  LogMessage() {}
  virtual ~LogMessage() {
    if (g_logging) {
      std::cout << "UDEV STUB: " << msg_.str().c_str() << std::endl;
    }
  }

  std::ostringstream& get(void) {
    return msg_;
  }

private:
  std::ostringstream msg_;
};

}
