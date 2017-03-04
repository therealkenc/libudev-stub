#include <iostream>
#include <sstream>

namespace libudev_stub {

#define LOG() LogMessage().get()

class LogMessage {
public:
  LogMessage() {}
  virtual ~LogMessage() {
    std::cout << "UDEV STUB: " << msg_.str().c_str() << std::endl;
  }

  std::ostringstream& get(void) {
    return msg_;
  }

private:
  std::ostringstream msg_;
};

}
