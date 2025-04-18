# Hello World Kernel Module

This is a simple "Hello, World!" Linux kernel module for Raspberry Pi OS. It demonstrates the basic structure of a kernel module and how to load and unload it.

---

## Files

- `hello.c`: Source code for the kernel module.
- `Makefile`: Build script for compiling the module.

---

## Usage

### Build and Load the Module

```bash
make
sudo insmod hello.ko
dmesg | tail
```

### Unload the Module

```bash
sudo rmmod hello
```

---

## Output

- Upon loading, the module prints:  
  **`Hello, World!`**
- Upon removal, it prints:  
  **`Goodbye, World!`**

---

## Notes

Ensure that kernel headers are installed on your Raspberry Pi:

```bash
sudo apt install raspberrypi-kernel-headers
```
