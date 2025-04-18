# GPIO LED Control Kernel Module

This kernel module demonstrates controlling an LED connected to a GPIO pin on Raspberry Pi using a character device interface.

---

## Files

- `led.c`: Source code for the kernel module.
- `Makefile`: Build script for compiling the module.

---

## Features

- Configures a specified GPIO pin as output.
- Provides a character device interface to turn the LED on or off.

---

## Build and Load the Module

```bash
make
sudo insmod led.ko
sudo dmesg -W
```

---

## Create Device Node

Replace `<major_number>` with the actual major number assigned to your device (check `dmesg` output):

```bash
sudo mknod /dev/led_device c <major_number> 0
sudo chmod 666 /dev/led_device
```

---

## Control the LED

```bash
echo 1 > /dev/led_device  # Turn LED on
echo 0 > /dev/led_device  # Turn LED off
```

---

## Remove the Module

```bash
sudo rmmod led
```

## Notes

- Ensure the GPIO pin number in the source code matches your hardware setup.
- Tested on Raspberry Pi OS with appropriate kernel headers installed.
