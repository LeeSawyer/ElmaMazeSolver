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
void noVerticalWalls(int i, int j){
  maze[i][j] = new Fl_Box(((((j-1)/2)*100) + 110),((((i-1)/2)*100) + 20),10,90,"");
  maze[i][j]->box(FL_FLAT_BOX);
  maze[i][j]->color(FL_WHITE);
  //std::cout << "what " ;//((j%2) == 0) << " ";
}
void noHorizontalWalls(int i, int j){
  maze[i][j] = new Fl_Box(((((j-1)/2)*100) + 20),((((i-1)/2)*100) + 110),90,10,"");
  maze[i][j]->box(FL_FLAT_BOX);
  maze[i][j]->color(FL_WHITE);
}

void makeMaze() {
  for (int i = 0; i < 13; i++){
    for (int j = 0; j < 13; j++){
        if(((i%2)==1) && ((j%2) == 0))//placing No vertical walls
          noVerticalWalls(i,j);
        if(((i%2)==0) && ((j%2) == 1))//placing No vertical walls
          noHorizontalWalls(i,j);
    }
  }
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
        if(((i%2)==1) && ((j%2)==1)){//placing each block
          maze[i][j] = new Fl_Box(((((j-1)/2)*100) + 20),((((i-1)/2)*100) + 20),90,90,"");
          maze[i][j]->box(FL_FLAT_BOX);
          maze[i][j]->color(FL_WHITE);
        }
    }

  }
  maze[11][11]->label("END");

  Fl_Box *stateBoxLabel = new Fl_Box(800,50,30,50,"State");
  stateBoxLabel->box(FL_NO_BOX);
  stateBoxLabel->labelfont(FL_BOLD);
  stateBoxLabel->labelsize(12);
  Fl_Box *stateBox = new Fl_Box(700,100,250,50,"");
  stateBox->box(FL_DOWN_BOX);
  stateBox->labelfont(FL_BOLD);
  stateBox->labelsize(12);

  Fl_Box *processBoxLabel = new Fl_Box(800,250,30,50,"Process");
  processBoxLabel->box(FL_NO_BOX);
  processBoxLabel->labelfont(FL_BOLD);
  processBoxLabel->labelsize(12);
  Fl_Box *processBox = new Fl_Box(700,300,250,50,"");
  processBox->box(FL_DOWN_BOX);
  processBox->labelfont(FL_BOLD);
  processBox->labelsize(12);

  Fl_Box *eventBoxLabel = new Fl_Box(800,450,30,50,"Event");
  eventBoxLabel->box(FL_NO_BOX);
  eventBoxLabel->labelfont(FL_BOLD);
  eventBoxLabel->labelsize(12);
  Fl_Box *eventBox = new Fl_Box(700,500,250,50,"");
  eventBox->box(FL_DOWN_BOX);
  eventBox->labelfont(FL_BOLD);
  eventBox->labelsize(12);

}

int main(int argc, char ** argv) {
  
  
  Fl_Window *window = new Fl_Window(1000,630);
  
  makeMaze();


  window->end();
  window->show(argc, argv);
  return Fl::run();
}