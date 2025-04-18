# Hello World Kernel Module

This is a simple "Hello, World!" Linux kernel module for Raspberry Pi OS. It demonstrates the basic structure of a kernel module and how to load and unload it.

## Files

- `hello.c`: Source code for the kernel module.
- `Makefile`: Build script for compiling the module.

## Usage

```bash
make
sudo insmod hello.ko
dmesg | tail
sudo rmmod hello
