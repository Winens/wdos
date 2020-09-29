#gcc -m32 -c obj/char.c -o TEMP/char.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
#gcc -m32 -c kernel/kernel.c -o TEMP/kernel.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
#as --32 bootloader/boot.s -o TEMP/boot.o
#ld -m elf_i386 -T obj/linker.ld TEMP/kernel.o TEMP/utils.o TEMP/boot.o -o TEMP/MyOS.bin -nostdlib
#grub-file --is-x86-multiboot TEMP/MyOS.bin
#qemu-system-i386 MyOS.iso
#mkdir -p isodir/boot/grub
#cp TEMP/MyOS.bin isodir/boot/MyOS.bin
#cp grub.cfg isodir/boot/grub/grub.cfg
#grub-mkrescue -o MyOS.iso isodir

as --32 bootloader/boot.s -o TEMP/boot.o
gcc -m32 -c obj/utils.c -o TEMP/utils.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
#gcc -m32 -c obj/char.c -o TEMP/char.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
gcc -m32 -c kernel/kernel.c -o TEMP/kernel.o -std=gnu99 -ffreestanding -O1 -Wall -Wextra
ld -m elf_i386 -T obj/linker.ld TEMP/kernel.o TEMP/utils.o TEMP/boot.o -o TEMP/kernel.bin -nostdlib
grub-file --is-x86-multiboot TEMP/kernel.bin


mkdir -p isodir/boot/grub
cp TEMP/kernel.bin isodir/boot/kernel.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o MyOS.iso isodir

qemu-system-i386 MyOS.iso