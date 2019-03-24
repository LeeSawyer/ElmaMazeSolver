
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <iostream>
#include "maze.h"





int main(int argc, char ** argv) {
  
  
  Fl_Window *window = new Fl_Window(1000,630);
  
  makeMaze();


  window->end();
  window->show(argc, argv);
  return Fl::run();
} 