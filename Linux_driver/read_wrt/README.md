# Character Device with Read and Write Operations

This project demonstrates implementing read and write operations in a Linux character device driver.

---

## Files

- `read_wrt.c`: Source code implementing read and write operations.
- `Makefile`: Build script for compiling the module.

---

## Features

- Registers a character device with dynamic major number allocation.
- Implements `read` and `write` file operations to exchange data between user space and kernel space.

---

## Build and Load the Module

```bash
make
sudo insmod read_wrt.ko
dmesg | tail
```

---

## Create Device Node

Replace `<major_number>` with the number assigned to your device (check `dmesg` output):

```bash
sudo mknod /dev/read_wrt c <major_number> 0
sudo chmod 666 /dev/read_wrt
```

---

## Write to the Device

```bash
echo "Hello Kernel" > /dev/read_wrt
```

---

## Read from the Device

```bash
cat /dev/read_wrt
```

---

## Remove the Module

```bash
sudo rmmod read_wrt
```

---

## Notes

This example helps in understanding data exchange between user space and kernel space.

> **Tip**: Ensure kernel headers are installed on Raspberry Pi OS:
>
> ```bash
> sudo apt install raspberrypi-kernel-headers
> ```
