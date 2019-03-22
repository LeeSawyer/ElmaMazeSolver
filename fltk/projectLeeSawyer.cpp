#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <iostream>
Fl_Box *maze[13][13];

void verticalWall(int i, int j){
  maze[i][j] = new Fl_Box(((((j-1)/2)*100) + 110),((((i-1)/2)*100) + 20),10,90,"");
  maze[i][j]->box(FL_UP_BOX);
  maze[i][j]->color(FL_RED);
}
void horizontalWalls(int i, int j){
  maze[i][j] = new Fl_Box(((((j-1)/2)*100) + 20),((((i-1)/2)*100) + 110),90,10,"");
  maze[i][j]->box(FL_UP_BOX);
  maze[i][j]->color(FL_RED);
}
// void noVerticalWall(int i, int j){
//   maze[i][j] = new Fl_Box(((((j-1)/2)*100) + 110),((((i-1)/2)*100) + 20),10,90,"");
//   maze[i][j]->box(FL_FLAT_BOX);
//   maze[i][j]->color(FL_WHITE);
// }
// void horizontalWalls(int i, int j){
//   maze[i][j] = new Fl_Box(((((j-1)/2)*100) + 20),((((i-1)/2)*100) + 110),90,10,"");
//   maze[i][j]->box(FL_FLAT_BOX);
//   maze[i][j]->color(FL_WHITE);
// }

void makeMaze() {
        ///////////vertical walls
        verticalWall(1,2);
        verticalWall(3,2);
        verticalWall(3,4);
        verticalWall(3,10);
        verticalWall(5,6);
        verticalWall(5,8);
        verticalWall(7,2);
        verticalWall(7,6);
        verticalWall(7,10);
        verticalWall(9,2);        
        verticalWall(9,6);
        verticalWall(11,4);
        verticalWall(11,6);
        ////////////////////horizontal walls
        horizontalWalls(2,5);
        horizontalWalls(2,9);
        horizontalWalls(4,5);
        horizontalWalls(4,9);
        horizontalWalls(6,3);
        horizontalWalls(6,9);
        horizontalWalls(8,5);
        horizontalWalls(8,7);
        horizontalWalls(8,11);
        horizontalWalls(10,1);
        horizontalWalls(10,9);
        horizontalWalls(10,11);



  for (int i = 0; i < 13; i++){
    for (int j = 0; j < 13; j++){
        if(((i%2)==0) && ((j%2)==0)){//corner posts
          maze[i][j] = new Fl_Box((((j/2)*100) + 10),(((i/2)*100) + 10),10,10,"");
          maze[i][j]->box(FL_UP_BOX);
          maze[i][j]->color(FL_RED);
          //std::cout << j;
        }
        if(((i%2)==1) && (j == 0)){//right and left walls
          maze[i][0] = new Fl_Box(10,((((i-1)/2)*100) + 20),10,90,"");
          maze[i][0]->box(FL_UP_BOX);
          maze[i][0]->color(FL_RED);
          maze[i][12] = new Fl_Box(610,((((i-1)/2)*100) + 20),10,90,"");
          maze[i][12]->box(FL_UP_BOX);
          maze[i][12]->color(FL_RED);
          //std::cout << i;
        }
        if((i==0) && ((j%2)==1)){//top and bottom walls
          maze[0][j] = new Fl_Box(((((j-1)/2)*100) + 20),10,90,10,"");
          maze[0][j]->box(FL_UP_BOX);
          maze[0][j]->color(FL_RED);
          maze[12][j] = new Fl_Box(((((j-1)/2)*100) + 20),610,90,10,"");
          maze[12][j]->box(FL_UP_BOX);
          maze[12][j]->color(FL_RED);
          //std::cout << i;
        }
        // if(((i%2)==1) && ((j%2)==1)){//placing No vertical walls
        //   if(maze[i][j]->color() != FL_RED)
        //     noVerticalWall(i,j);
        // }
    }

  }




}

int main(int argc, char ** argv) {//helloworld.cpp:18:16: error: ‘argc’ was not declared in this sco
  
  
  Fl_Window *window = new Fl_Window(1000,630);
  
  makeMaze();


  window->end();
  window->show(argc, argv);
  return Fl::run();
}