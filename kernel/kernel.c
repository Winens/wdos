#include "kernel.h"
#include "../obj/utils.h"
#include "../drivers/keyboard.h"
#include "../drivers/vga.h"
#include "../obj/char.h"

int nowWriting = 0;


int writX = 0, writY = 0;
int gui3_enable = 0;

/*static void sleep(uint32 timer_count)
{
  wait_for_io(timer_count);
}*/

static void sleep(int timer_count)
{
  wait_for_io(timer_count);
}

int harf = 0;
char exp[20];
static void input()
{
  nowWriting = 1;
  char ch = 0;  char bc = 0;
  char keycode = 0;
  int a = 0;
  do{
    keycode = get_input_keycode();
    if(keycode == KEY_ENTER){
      nowWriting = 0;
      harf = 0;
      sleep(70000000); 
      break;
    } else if(keycode == KEY_TAB || keycode == KEY_ESC || keycode == KEY_UP || keycode == KEY_RIGHT || keycode == KEY_DOWN || keycode == KEY_LEFT){
      
    } else {
      ch = utf8(keycode);
      exp[harf] = ch;
      harf++;
      print_char(ch);
    }
    sleep(50000000);
  }while(ch > 0);
}

static void clear_screen(int w){
  int i = 0;
  int s = 0;
  for(i = 0; w >= 0; w--){
    if(w <= 0){
      break;
    } else {
      gotoxy(0, i);
      s = VGA_MAX_WIDTH;
      for(int q = 0; s >= 1; s--){
        print_string(" ");
      }
      i++;
    }
  }
  writX = 0;
  gui3_enable = 0;
}

static void first_problem_control(){

  gotoxy(0, 0);
  print_color_string("[OK]", GREEN, BLACK);
  print_string(" VGA driver booted"); print_new_line(); sleep(90000000);

  if(input){
  print_color_string("[OK]", GREEN, BLACK);
  print_string(" Keyboard driver booted"); print_new_line(); sleep(90000000);
  } else {
  print_color_string("[ERROR]", RED, BLACK);
  print_string(" KEYBOARD DRIVER CANNOT BOOTED!"); print_new_line(); sleep(990000000);
  }

  print_color_string("[OK]", GREEN, BLACK);
  print_string(" System running"); print_new_line(); sleep(90000000);

  clear_screen(10);
}

void gui1(){
  clear_screen(1);
  draw_box(BOX_SINGLELINE, 0, 0, (VGA_MAX_WIDTH - 2), (VGA_MAX_HEIGHT - 2), GREY, DARK_GREY);
  writX = 1; gui3_enable = 0;
}
void gui2(){
  clear_screen(1);
  draw_box(BOX_SINGLELINE, 0, 0, (VGA_MAX_WIDTH - 2), (VGA_MAX_HEIGHT - 2), GREY, WHITE);
  writX = 1; gui3_enable = 0;
}

void gui3(){
  clear_screen(1);
  draw_box(BOX_SINGLELINE, 0, 0, (VGA_MAX_WIDTH - 2), (VGA_MAX_HEIGHT - 2), WHITE, WHITE);
  gotoxy((VGA_MAX_WIDTH / 2) - 6,0);
  print_color_string("Welcome W-DOS",DARK_GREY,WHITE);
  gotoxy((VGA_MAX_WIDTH - 4), 0);
  print_color_string(" X ", WHITE, RED);
  gotoxy((VGA_MAX_WIDTH - 8), 0);
  print_color_string(" [] ", WHITE, BLUE);
  gotoxy((VGA_MAX_WIDTH - 11), 0);
  print_color_string(" _ ", WHITE, GREY);
  writX = 1;
  gui3_enable = 1;
}

void kernel_entry()
{
  init_vga(WHITE, BLACK);
  first_problem_control();
  gotoxy(0,0); next_line_index = 1;


 // print_string("W-DOS $> "); input(); print_new_line();

 /* if(exp[0] == 'h' && exp[1] == 'e' && exp[2] == 'l' && exp[3] == 'p'){
    
  }  */
  
  int pwrRet = 1; writX++;
  while (pwrRet)
  {

    gotoxy(writX, next_line_index - 1);
    print_color_string("W-DOS $> ",RED,BLACK); input(); print_new_line();


    if(exp[0] == 'h' && exp[1] == 'e' && exp[2] == 'l' && exp[3] == 'p'){
    print_new_line();
    gotoxy(writX, next_line_index - 1);
    print_string("help            ~ show commands ");print_new_line();gotoxy(writX, next_line_index - 1);
    print_string("clear           ~ clear text and dos-gui ");print_new_line();gotoxy(writX, next_line_index - 1);
    print_string("set color       ~ change text and backgraund colors ");print_new_line();    gotoxy(writX, next_line_index - 1);
    print_string("gui 1           ~ dos theme 1 ");print_new_line();    gotoxy(writX, next_line_index - 1);
    print_string("gui 2           ~ dos theme 2 ");print_new_line();    gotoxy(writX, next_line_index - 1);
    print_string("gui 3           ~ windows theme (beta) ");print_new_line();    gotoxy(writX, next_line_index - 1);
    print_new_line();
  } else if(exp[0] == 's' && exp[1] == 'e' && exp[2] == 't' && exp[3] == ' ' && exp[4] == 'c' && exp[5] == 'o' && exp[6] == 'l' && exp[7] == 'o' && exp[8] == 'r'){
    gotoxy(writX, next_line_index - 1);
    print_new_line();gotoxy(writX, next_line_index - 1);
    print_string("Select color: "); print_new_line();     gotoxy(writX, next_line_index - 1);
    print_color_string(" ", BLACK, RED); print_string(" Red"); print_new_line();     gotoxy(writX, next_line_index - 1);
    print_color_string(" ", BLACK, GREEN); print_string(" Green"); print_new_line();     gotoxy(writX, next_line_index - 1);
    print_color_string(" ", BLACK, BLUE); print_string(" Blue"); print_new_line();    gotoxy(writX, next_line_index - 1);
    print_color_string(" ", BLACK, BLACK); print_string(" Black"); print_new_line();    gotoxy(writX, next_line_index - 1);
    print_color_string(" ", BLACK, WHITE); print_string(" White");print_new_line();    gotoxy(writX, next_line_index - 1);
    print_color_string(" ", BLACK, MAGENTA); print_string(" Magenta"); print_new_line();    gotoxy(writX, next_line_index - 1);
    print_color_string(" ", BLACK, YELLOW); print_string(" Yellow"); print_new_line();    gotoxy(writX, next_line_index - 1);
    print_new_line();     gotoxy(writX, next_line_index - 1);
    print_string("Example :   W-DOS $>  red "); print_new_line();     gotoxy(writX, next_line_index - 1);

     print_string("COLOR $> "); input(); 

    if(exp[0] == 'r' && exp[1] == 'e' && exp[2] == 'd'){
      init_vga(RED, BLACK);
    } else if(exp[0] == 'g' && exp[1] == 'r' && exp[2] == 'e' && exp[3] == 'e' && exp[4] == 'n'){
      init_vga(GREEN, BLACK);
    } else if(exp[0] == 'b' && exp[1] == 'l' && exp[2] == 'u' && exp[3] == 'e'){
      init_vga(BLUE, BLACK);
    } else if(exp[0] == 'b' && exp[1] == 'l' && exp[2] == 'a' && exp[3] == 'c' && exp[4] == 'k'){
      init_vga(BLACK, BLACK);
    } else if(exp[0] == 'w' && exp[1] == 'h' && exp[2] == 'i' && exp[3] == 't' && exp[4] == 'e'){
      init_vga(WHITE, BLACK);
    } else if(exp[0] == 'm' && exp[1] == 'a' && exp[2] == 'g' && exp[3] == 'e' && exp[4] == 'n' && exp[5] == 't' && exp[6] == 'a'){
      init_vga(MAGENTA, BLACK);
    } else if(exp[0] == 'y' && exp[1] == 'e' && exp[2] == 'l' && exp[3] == 'l' && exp[4] == 'o' && exp[5] == 'w'){
      init_vga(YELLOW, BLACK);
    } else

    print_new_line();

  } else if(exp[0] == 'c' && exp[1] == 'l' && exp[2] == 'e' && exp[3] == 'a' && exp[4] == 'r'){
    clear_screen(50);
    gotoxy(0,0);
    next_line_index = 1;
  } else if(exp[0] == 'g' && exp[1] == 'u' && exp[2] == 'i' && exp[3] == ' '&& exp[4] == '1'){
    gui1();
  } else if(exp[0] == 'g' && exp[1] == 'u' && exp[2] == 'i' && exp[3] == ' '&& exp[4] == '2'){
    gui2();
  } else if(exp[0] == 'g' && exp[1] == 'u' && exp[2] == 'i' && exp[3] == ' '&& exp[4] == '3'){
    gui3();
  } 

   else {
    gotoxy(writX, next_line_index - 1);
    print_string("this is not command!"); print_new_line();
  }
  
  }
  
}