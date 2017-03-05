# libudev-stub

[TL;DR It lets you run chrome on WSL. Get the release build [here](https://github.com/therealkenc/libudev-stub/releases).]

[Libudev-stub](https://github.com/therealkenc/libudev-stub) is a shim library for `libudev`, created primarily for the Windows Subsystem for Linux [WSL](https://msdn.microsoft.com/en-us/commandline/wsl/about). Theoretically it could be useful for other Linux-ish systems that lack udev support. [Udev](https://www.freedesktop.org/software/systemd/man/udev.html) is part of [systemd](https://www.freedesktop.org/wiki/Software/systemd/). It provides a well-known interface for device events (such as hot plugging of usb dongles and cameras) for many Linux distributions like [Ubuntu](https://www.ubuntu.com/). Unfortunately, WSL currently lacks much of the functionality required to support `udev`; at least as of [Windows Insider](https://insider.windows.com/) build 15046.

To work around this, `libudev-stub` implements a subset of the `libudev` interface and does not actually communicate with the kernel. The theory of operation is pretty straightforward. When an application uses `libudev` to ask for a list of devices, the stub library says there aren't any devices worth mentioning. When an application asks to monitor for device events, the library obliges, and then never raises any event notifications. The code is structured in a way that a static device list could be faked, but it does not do so as of right now.

All of which is just enough to make Google's [chromium](https://www.chromium.org/Home) happy, as well as by extension [libchromiumcontent](https://github.com/electron/libchromiumcontent) and [electron](https://electron.atom.io/). With `libudev-stub` installed, the out-of-the box version of [Chrome](https://www.google.com/chrome/) will run with the `--no-sandbox` command line option.

Note however that graphical applications are [**not supported**](https://wpdev.uservoice.com/forums/266908-command-prompt-console-bash-on-ubuntu-on-windo/suggestions/13250499-support-for-x-server-running-in-windows-on-the-sam?tracking_code=6be7122042c59b213451b9198f208f27) by Microsoft. You are _on your own_ here until MSFT has cleared their development backlog of commandline development use case scenarios. See the WSL [FAQ](https://msdn.microsoft.com/en-us/commandline/wsl/faq) for more.

## Release installation
The installer leaves the stock `libudev1` debian package in place, but changes the system `libudev.so.1` symlink to the `libudev-stub` version. This is harmless on WSL (since stock libudev doesn't work anyway), but you should not do this on a Real Ubuntu machine unless that is _really_ what you want.

```
wget https://github.com/therealkenc/libudev-stub/releases/download/v0.9.0/libudev-stub-0.9.0-WSL.deb
sudo dpkg -i libudev-stub-0.9.0-WSL.deb
```

## Source builds
Builds require a C++11 compiler, so `install-deps.sh` will install g++-6 from [ppa:ubuntu-toolchain-r/test](https://launchpad.net/~ubuntu-toolchain-r/+archive/ubuntu/test). This will **not** change your system's default compiler.
```
git clone https://github.com/therealkenc/libudev-stub.git
./scripts/install-deps.sh
./scripts/build-all.sh
```
This creates the `.deb` package in `build/out/deb`. The library file and symlinks live in `build/out/lib`. If you would rather not change your system `libudev.so.1`, you can manually set the `LD_LIBRARY_PATH` environment variable. For example:
```
export LD_LIBRARY_PATH=./build/out/lib
```

## Hacking

There is also an environment variable to turn the stub library into a passthrough proxy for the real `libudev.so.1`. It is useful to see where applications fail when using the `libudev` interface. Enable it with:
```
export LIBUDEV_STUB_PASSTHROUGH=/lib/x86_64-linux-gnu/libudev.so.1.6.4
```

## ob-screenshot
<img src="https://raw.githubusercontent.com/therealkenc/libudev-stub/master/docs/chrome-screencap.png" width="640">
