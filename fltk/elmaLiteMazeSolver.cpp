
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <iostream>
#include "maze.h"
#include "solve.h"
#include "state_process_event.h"


static void cb(void *) {
  Fl::repeat_timeout(1.0 , cb);
  
  solve();
}

int main(int argc, char ** argv) {
  Fl_Window *window = new Fl_Window(1000,650);
  
  makeMaze();
  initMemory();
  
  window->end();
  window->show(argc, argv);

  Fl::add_timeout(1.0 , cb);

  return Fl::run();
} 