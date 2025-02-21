#!/bin/bash

# Clean previous builds
cd ~/learning-xinu/compile
make clean

# Build the Xinu kernel
make

# Run QEMU with the generated xinu.elf file
qemu-system-i386 -m 16 -kernel xinu.elf -nographic -append "console=ttyS0"