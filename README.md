# libudev-stub
**Libudev-stub** is a shim library for `libudev`, created primarily for the Windows Subsystem for Linux [WSL](https://msdn.microsoft.com/en-us/commandline/wsl/about). Theoretically it could be useful for other Linux-ish systems that lack udev support. [Udev](https://www.freedesktop.org/software/systemd/man/udev.html) is part of [systemd](https://www.freedesktop.org/wiki/Software/systemd/). It provides a well-known interface for device events (such as hot plugging of usb dongles and cameras) for many Linux distributions like [Ubuntu](https://www.ubuntu.com/). Unfortunately, WSL currently lacks much of the functionality required to support `udev`; at least as of [Windows Insider](https://insider.windows.com/) build 15046.

To work around this, `libudev-stub` implements a subset of the `libudev` interface that does not actually talk to the kernel. The theory of operation is pretty straightforward. When an application that uses `libudev` asks for a list of devices, the stub library says the list of devices is empty. When an application asks to monitor for device events, the library obliges, and then never raises any notifications. The code is structured in a way that devices could be faked, but it does not do so as of this initial relase.

That is just enough to make Google's [chromium](https://www.chromium.org/Home) happy, as well as by extension [libchromiumcontent](https://github.com/electron/libchromiumcontent) and [electron](https://electron.atom.io/). With `libudev-stub` installed, the out-of-the box version of [Chrome](https://www.google.com/chrome/) will run with the `--no-sandbox` command line option.

Note however that graphical applications are [**not supported**](https://wpdev.uservoice.com/forums/266908-command-prompt-console-bash-on-ubuntu-on-windo/suggestions/13250499-support-for-x-server-running-in-windows-on-the-sam?tracking_code=6be7122042c59b213451b9198f208f27) by Microsoft. You are on your own here until MSFT has cleared their development backlog of commandline development use case scenarios.

There is no fancy installer yet, but building is pretty painless. It requires a C++11 compiler.
```
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install build-essential git cmake ninja-build libudev-dev gcc-6 g++-6
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-6 200
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 200
mkdir somewhere && cd somewhere
git clone https://github.com/therealkenc/libudev-stub.git
cd libudev-stub/build
cmake -G Ninja ..
ninja
export LD_LIBRARY_PATH=$PWD/lib
```

There is also an environment variable to turn the stub library into a passthrough proxy for the real `libudev.so.1`. It is useful to see where applications break when using the interface. Enable it with:
```
export LIBUDEV_STUB_PASSTHROUGH=/lib/x86_64-linux-gnu/libudev.so.1
```
<br><br><br>
<img src="https://raw.githubusercontent.com/therealkenc/libudev-stub/master/docs/chrome-screencap.png" width="640">
