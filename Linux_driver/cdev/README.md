# Character Device Driver Example

This project demonstrates how to create a basic character device driver in Linux on a Raspberry Pi.

---

## Prerequisites

Ensure that kernel headers are installed on your Raspberry Pi:

```bash
sudo apt install raspberrypi-kernel-headers
```

---

## Files

- `cdev.c`: Source code implementing the character device.
- `Makefile`: Build script for compiling the module.

---

## Features

- Registers a character device with dynamic major number allocation.
- Implements basic file operations: `open`, `read`, `write`, and `release`.

---

## Build and Insert Module

```bash
make
sudo insmod cdev.ko
```

Check the kernel log for the assigned major number:

```bash
sudo dmesg -W
```

---

## Create Device Node

Replace `<major_number>` with the actual number shown in the `dmesg` output:

```bash
sudo mknod /dev/cdev_example c <major_number> 0
sudo chmod 666 /dev/cdev_example
```

---

## Interact with the Device

```bash
echo "Test" > /dev/cdev_example
cat /dev/cdev_example
```

---

## Remove the Module

```bash
sudo rmmod cdev
```

## Notes
This example is tested on Raspberry Pi OS. Ensure kernel headers are installed.
