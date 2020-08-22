# DevicePathView

all: ../../Build/hdd/EFI/BOOT/BOOTX64.EFI ../../Build/hdd/test.efi

efi.o: efi.c
	clang -target x86_64-pc-win32-coff -Wincompatible-library-redeclaration -fno-stack-protector -fshort-wchar \
	-Wno-incompatible-library-redeclaration \
	-mno-red-zone -nostdlibinc -Wall -Wpedantic -c -o $@ $+

common.o: common.c
	clang -target x86_64-pc-win32-coff -Wincompatible-library-redeclaration -fno-stack-protector -fshort-wchar \
	-Wno-incompatible-library-redeclaration \
	-mno-red-zone -nostdlibinc -Wall -Wpedantic -c -o $@ $+

main.o: main.c
	clang -target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar \
	-Wno-incompatible-library-redeclaration \
	-mno-red-zone -nostdlibinc -Wall -Wpedantic -c -o $@ $+

graphics.o: graphics.c
	clang -target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar \
	-Wno-incompatible-library-redeclaration \
	-mno-red-zone -nostdlibinc -Wall -Wpedantic -c -o $@ $+

../../Build/hdd/EFI/BOOT/BOOTX64.EFI: efi.o common.o main.o graphics.o
	mkdir -p ../../Build/hdd/EFI/BOOT
	lld-link  -subsystem:efi_application -nodefaultlib -dll -entry:efi_main $+ -out:$@

# 以下ロードするUEFIアプリケーションのコンパイルと配置
test.o: HelloUefi/HelloUefimain.c
	clang -target x86_64-pc-win32-coff -fno-stack-protector -fshort-wchar \
	-Wno-incompatible-library-redeclaration \
	-mno-red-zone -nostdlibinc -Wall -Wpedantic -c -o $@ $+
# lldだと-subsystem:efi_applicationの時点でリロケータブルなバイナリだそうです。教えてくれた方ほんとにありがとう
../../Build/hdd/test.efi: test.o
	lld-link  -subsystem:efi_application -nodefaultlib -dll -entry:efi_main $+ -out:$@

# ここの依存関係に書いてないとコンパイルされない
run: ../../Build/hdd/EFI/BOOT/BOOTX64.EFI ../../Build/hdd/test.efi
	qemu-system-x86_64 -m 512 -bios /usr/share/edk2-ovmf/x64/OVMF.fd -hda fat:rw:../../Build/hdd

clean:
	rm -rf *.o
