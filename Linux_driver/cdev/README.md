Notes
Ensure that kernel headers are installed on your Raspberry Pi:

sudo apt install raspberrypi-kernel-headers


# Character Device Driver Example

This project demonstrates how to create a basic character device driver in Linux.

## Files

- `cdev.c`: Source code implementing the character device.
- `Makefile`: Build script for compiling the module.

## Features

- Registers a character device with dynamic major number allocation.
- Implements basic file operations: open, read, write, and release.

## Usage

```bash
make
sudo insmod cdev.ko
sudo dmesg -W
sudo rmmod cdev
