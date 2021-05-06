#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"

static int state = 0;
static int note = 0;

char toggle_red()		/* always toggle! */
{
  static char state = 0;

  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  

  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}

void red_light_on(){
  red_on = 1;
  green_on = 0;
  led_update();
}

void green_light_on(){
  green_on = 1;
  red_on = 0;
  led_update();
}

void myTestMethod(){
  buzzer_set_period(1000);
}

void reset(){
  buzzer_set_period(0);
  red_on = 0;
  green_on = 0;
  led_changed = 1;
  led_update();
}
/*
void assembly_stuff(){
  switch(state){
  case 0:
    assembly_method(0);
    state++;
    break;
  case 1:
    assembly_method(1);
    state++;
    break;
  case 2:
    assembly_method(2);
    state++;
    break;
  case 3:
    assembly_method(3);
    state++;
    break;
  default:
    state = 0;
    break;
  }
}

*/
void play_buzzer(short note){
  buzzer_set_period(2000000/note);
}
