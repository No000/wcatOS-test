all: ../../Build/hdd/EFI/BOOT/BOOTX64.EFI

efi.o: efi.c
	clang -target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar \
	-mno-red-zone -nostdlibinc -Wall -Wpedantic -c -o $@ $+

common.o: common.c
	clang -target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar \
	-mno-red-zone -nostdlibinc -Wall -Wpedantic -c -o $@ $+

main.o: main.c
	clang -target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar \
	-mno-red-zone -nostdlibinc -Wall -Wpedantic -c -o $@ $+

../../Build/hdd/EFI/BOOT/BOOTX64.EFI: efi.o common.o main.o
	mkdir -p ../../Build/hdd/EFI/BOOT
	lld-link  -subsystem:efi_application -nodefaultlib -dll -entry:efi_main $+ -out:$@

run: ../../Build/hdd/EFI/BOOT/BOOTX64.EFI
	qemu-system-x86_64 -m 512 -bios /usr/share/edk2-ovmf/x64/OVMF.fd -hda fat:rw:../../Build/hdd

clean:
	rm -rf *.o
