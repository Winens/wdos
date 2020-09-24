#ifndef KERNEL_H
#define KERNEL_H

#include "../obj/types.h"
#include "../drivers/keyboard.h"

#define NULL 0

#define VGA_ADDRESS 0xB8000 //0xB8000
#define BUFSIZE 2200 //2200

uint16* vga_buffer;

#define VGA_MAX_WIDTH 80 //80
#define VGA_MAX_HEIGHT 25  //25

#define BOX_MAX_WIDTH 78 //78
#define BOX_MAX_HEIGHT 23 //23

#define BOX_SINGLELINE 1
#define BOX_DOUBLELINE 2

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

uint8 inb(uint16 port)
{
  uint8 ret;
  asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
  return ret;
}

void outb(uint16 port, uint8 data)
{
  asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}

char get_input_keycode()
{
  char ch = 0;
  while((ch = inb(KEYBOARD_PORT)) != 0){
    if(ch > 0)
      return ch;
  }
  return ch;
}

/*void wait_for_io(uint32 timer_count)
{
  while(1){
    asm volatile("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
    }
}*/

void wait_for_io(int timer_count)
{
  while(1){
    asm volatile("nop");
    timer_count--;
    if(timer_count <= 0)
      break;
    }
}


#endif
