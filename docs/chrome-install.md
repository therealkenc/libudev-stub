# Full installation of Chrome on WSL from virgin install 
#### This assumes you have [VcXsrv](https://sourceforge.net/projects/vcxsrv/) on Windows set up. Choose multiple windows, display 0, start no client, _disable_ native opengl (sic). [Do this even if you think you know different.]

From `CMD`:
```
lxrun /uninstall
lxrun /install
```

From WSL `bash`:
```
sudo update && sudo apt upgrade
sudo apt install ubuntu-desktop
sudo add-apt-repository ppa:therealkenc/wsl-pulseaudio
sudo add-apt-repository ppa:paulo-miguel-dias/mesa
sudo apt update && sudo apt dist-upgrade  # yes dist-upgrade. You'll be on 16.04.03 as of Aug 2017
sudo apt install wget mesa-utils
# Download the stable or development Chrome .deb package - dev if you want headless functionality
wget https://dl.google.com/linux/direct/google-chrome-unstable_current_amd64.deb
sudo dpkg -i google-chrome-unstable_current_amd64.deb
sudo apt -f install                       # probably
wget https://github.com/therealkenc/libudev-stub/releases/download/v0.9.0/libudev-stub-0.9.0-WSL.deb
sudo dpkg -i libudev-stub-0.9.0-WSL.deb   # doing this **last** is important

# setting up session environment
export DISPLAY=localhost:0
export NO_AT_BRIDGE=1
exec dbus-run-session -- bash
sudo service dbus start

# Try firefox. If firefox doesn't launch all hope is lost for chrome
firefox
# Finally:
google-chrome-unstable --no-sandbox
```
