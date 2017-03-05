#!/bin/bash
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install build-essential git cmake ninja-build libudev-dev gcc-6 g++-6
