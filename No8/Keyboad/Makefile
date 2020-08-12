all: hdd1/EFI/BOOT/BOOTX64.EFI

hdd1/EFI/BOOT/BOOTX64.EFI: efi.c common.c main.c
	mkdir -p hdd1/EFI/BOOT
	x86_64-w64-mingw32-gcc -Wall -Wextra -e efi_main -nostdinc -nostdlib \
 	-fno-builtin -Wl,--subsystem,10 -o $@ $+

run: hdd1/EFI/BOOT/BOOTX64.EFI
	qemu-system-x86_64 -m 512 -bios /home/toto/Work/SelfMadeOS/UEFI/BM/firmware/OVMF.fd -hda fat:rw:hdd1
