# Xinu executable environment with qemu-system-i386

## How to use

```
# This fixed all the errors :)
$ git clone https://github.com/hasibul-hasib29/xinu-os.git
# you can add this as build_and_run.sh
cd ~/xinu-os/compile
make clean

# Build the Xinu kernel
make

# Run QEMU with the generated xinu.elf file
qemu-system-i386 -m 16 -kernel xinu.elf -nographic -append "console=ttyS0"
```

## Example

./build_and_run.sh in the compile directory.. [ make sure you make executable file : chmod u+x <name>.sh]
