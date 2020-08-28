TARGET = ../../Build/hdd/kernel.bin
CFLAGS = -Wall -Wextra -nostdinc -nostdlib -fno-builtin -fno-common	-Iinclude
LDFLAGS = -Map kernel.map -s -x -T kernel.ld

$(TARGET): main.o fb.o
	ld $(LDFLAGS) -o $@ $+

%.o: %.c
	clang $(CFLAGS) -c -o $@ $<

run: $(TARGET)
	qemu-system-x86_64 -m 4G -bios ../../Data/firmware/OVMF.fd -hda fat:rw:../../Build/hdd

clean:
	rm -rf *.o *.map $(TARGET) include/*~

.PHONY: run clean
