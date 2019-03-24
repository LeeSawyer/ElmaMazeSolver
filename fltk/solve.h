#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <iostream>

//#include "maze.h"
//#include "state_process_event.h"

int stateWeAreIn = 0;
int currentLocation[2] = {1, 1};//{i, j}, {upDown, rigthLeft}
enum direction {north, south , east, west};
enum state { searching_for_end , backtracking_to_last_unknown}; 
int breadCrumbCount = 0;
int directionWeAreGoingTo = 666;// arbitary value to let us know things are going wrong

struct memoryBlock{
  bool northWall;
  bool southWall;
  bool eastWall;
  bool westWall;
  bool unexploredPath;// does the block have a direction that is unexplored
  int distanceToEnd;
  int breadCrumb;
};

memoryBlock memory[6][6];

void initMemory(){
  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 6; j++){
         memory[i][j].northWall = 0;
        memory[i][j].southWall = 0;
        memory[i][j].eastWall = 0;
        memory[i][j].westWall = 0;
        memory[i][j].unexploredPath = 0;
//        std::cout << " " << (memory[i][j].distanceToEnd = 10 -(i + j));
        memory[i][j].distanceToEnd = 10 -(i + j);
        memory[i][j].breadCrumb = 40;// arbitrary high number more than number of blocks in maze

      }
//              std::cout << std::endl;
  }
};

void updateCurrentLocationBlock(){
    maze[2*currentLocation[0] - 1][2*currentLocation[1] - 1]->label("M");
    maze[2*currentLocation[0] - 1][2*currentLocation[1] - 1]->labelfont(FL_BOLD);
    maze[2*currentLocation[0] - 1][2*currentLocation[1] - 1]->labelsize(40);
};

void checkWalls(){

    // std::cout << "maze i : " << (2*currentLocation[0] - 2) << std::endl;
    // std::cout << "maze j : " << (2*currentLocation[1] - 1) << std::endl;
  if(maze[2*currentLocation[0] - 2][2*currentLocation[1] - 1]->color() == FL_RED){// north wall
    memory[currentLocation[0]-1][currentLocation[1]-1].northWall = 1;
    //      std::cout << "what" << std::endl;
  }
  if(maze[2*currentLocation[0]    ][2*currentLocation[1] - 1]->color() == FL_RED)// south wall
    memory[currentLocation[0]-1][currentLocation[1]-1].southWall = 1;
  if(maze[2*currentLocation[0] - 1][2*currentLocation[1]    ]->color() == FL_RED)// east wall
    memory[currentLocation[0]-1][currentLocation[1]-1].eastWall = 1;
  if(maze[2*currentLocation[0] - 1][2*currentLocation[1] - 2]->color() == FL_RED)// west wall
    memory[currentLocation[0]-1][currentLocation[1]-1].westWall = 1;

  // std::cout << std::endl << "north: "<< memory[currentLocation[0] - 1][currentLocation[1] - 1].northWall << std::endl;
  // std::cout << "south: "<< memory[currentLocation[0] - 1][currentLocation[1] - 1].southWall << std::endl;
  // std::cout << " east: "<< memory[currentLocation[0] - 1][currentLocation[1] - 1].eastWall << std::endl;
  // std::cout << " west: "<< memory[currentLocation[0] - 1][currentLocation[1] - 1].westWall << std::endl ;

};



void backtrackingToLastUnknownPathState(){
    //////////////////////////////switch to backtracking_to_last_unknown state
  if(memory[currentLocation[0] - 1][currentLocation[1] - 1].northWall == 0){// first check if there was a wall there
    if(memory[currentLocation[0] - 2][currentLocation[1] - 1].breadCrumb < memory[currentLocation[0] - 1][currentLocation[1] - 1].breadCrumb)// second check if we have been in the next block in that direction
      {directionWeAreGoingTo = north;
      }
  }
  if(memory[currentLocation[0] - 1][currentLocation[1] - 1].southWall == 0){// first check if there was a wall there
    if(memory[currentLocation[0]    ][currentLocation[1] - 1].breadCrumb < memory[currentLocation[0] - 1][currentLocation[1] - 1].breadCrumb)// second check if we have been in the next block in that direction
      {directionWeAreGoingTo = south;
      }
  }
  if(memory[currentLocation[0] - 1][currentLocation[1] - 1].eastWall == 0){// first check if there was a wall there
    if(memory[currentLocation[0] - 1][currentLocation[1]    ].breadCrumb < memory[currentLocation[0] - 1][currentLocation[1] - 1].breadCrumb)// second check if we have been in the next block in that direction
      {directionWeAreGoingTo = east;
      }
  }
  if(memory[currentLocation[0] - 1][currentLocation[1] - 1].westWall == 0){// first check if there was a wall there
    if(memory[currentLocation[0] - 1][currentLocation[1] - 2].breadCrumb < memory[currentLocation[0] - 1][currentLocation[1] - 1].breadCrumb)// second check if we have been in the next block in that direction
      {directionWeAreGoingTo = west;
      }     
  }   
  // std::cout << "north   breadcrumb: "<< memory[currentLocation[0] - 2][currentLocation[1] - 1].breadCrumb << std::endl;
  // std::cout << "south   breadcrumb: "<< memory[currentLocation[0]    ][currentLocation[1] - 1].breadCrumb << std::endl;
  // std::cout << "east    breadcrumb: "<< memory[currentLocation[0] - 1][currentLocation[1]    ].breadCrumb << std::endl;
  // std::cout << "west    breadcrumb: "<< memory[currentLocation[0] - 1][currentLocation[1] - 2].breadCrumb << std::endl;  
  // std::cout << "current breadcrumb: "<< memory[currentLocation[0] -1][currentLocation[1] -1].breadCrumb << std::endl;
  // std::cout << "directWAGT: "<< directionWeAreGoingTo << std::endl;
}

void incrementBreadCrumbVar(){
      memory[currentLocation[0] - 1][currentLocation[1] - 1 ].breadCrumb = breadCrumbCount;
      breadCrumbCount++;
}

void chooseDirection(){// also marks if block has an unexplored path
  directionWeAreGoingTo = 666;
  int numberOfUnexploredPaths = 0;  
  if(memory[currentLocation[0] - 1][currentLocation[1] - 1].northWall == 0){// first check if there was a wall there
    if(memory[currentLocation[0] - 2][currentLocation[1] - 1].breadCrumb == 40)// second check if we have been in the next block in that direction
      {directionWeAreGoingTo = north;
      numberOfUnexploredPaths++;
      }
  }
  if(memory[currentLocation[0] - 1][currentLocation[1] - 1].southWall == 0){// first check if there was a wall there
    if(memory[currentLocation[0]    ][currentLocation[1] - 1].breadCrumb == 40)// second check if we have been in the next block in that direction
      {directionWeAreGoingTo = south;
      numberOfUnexploredPaths++;
      }
  }
  if(memory[currentLocation[0] - 1][currentLocation[1] - 1].eastWall == 0){// first check if there was a wall there
    if(memory[currentLocation[0] - 1][currentLocation[1]    ].breadCrumb == 40)// second check if we have been in the next block in that direction
      {directionWeAreGoingTo = east;
      numberOfUnexploredPaths++;      
      }
  }
  if(memory[currentLocation[0] - 1][currentLocation[1] - 1].westWall == 0){// first check if there was a wall there
    if(memory[currentLocation[0] - 1][currentLocation[1] - 2].breadCrumb == 40)// second check if we have been in the next block in that direction
      {directionWeAreGoingTo = west;
      numberOfUnexploredPaths++;      
      }
  }
  if(numberOfUnexploredPaths > 1)//if a exit (path) out of a block is not explored, mark it
    memory[currentLocation[0] - 1][currentLocation[1] - 1].unexploredPath = 1;
  else
    memory[currentLocation[0] - 1][currentLocation[1] - 1].unexploredPath = 0;

  if(directionWeAreGoingTo == 666){
    stateWeAreIn = backtracking_to_last_unknown;
    incrementBreadCrumbVar();
  }
  // std::cout << "north   breadcrumb: "<< memory[currentLocation[0] - 2][currentLocation[1] - 1].breadCrumb << std::endl;
  // std::cout << "south   breadcrumb: "<< memory[currentLocation[0]    ][currentLocation[1] - 1].breadCrumb << std::endl;
  // std::cout << "east    breadcrumb: "<< memory[currentLocation[0] - 1][currentLocation[1]    ].breadCrumb << std::endl;
  // std::cout << "west    breadcrumb: "<< memory[currentLocation[0] - 1][currentLocation[1] - 2].breadCrumb << std::endl;  
  // std::cout << "current breadcrumb: "<< memory[currentLocation[0] -1][currentLocation[1] -1].breadCrumb << std::endl;
  // std::cout << "directWAGT: "<< directionWeAreGoingTo << std::endl;
}



void updateBlockBeforeMoving(){
    if(memory[currentLocation[0] - 1][currentLocation[1] - 1 ].breadCrumb == 40){
        incrementBreadCrumbVar();
    }
    maze[2*currentLocation[0] - 1][2*currentLocation[1] - 1]->label("");
};


void moveOneBlock(){
//  std::cout << "currentLocation: i:"<< currentLocation[0]  << " ;j: " << currentLocation[1] << std::endl;

if(directionWeAreGoingTo == north){
  currentLocation[0] = (currentLocation[0] -1);
}
if(directionWeAreGoingTo == south){
  currentLocation[0] = (currentLocation[0] +1);
}
if(directionWeAreGoingTo == east){
  currentLocation[1] = (currentLocation[1] +1);
}
if(directionWeAreGoingTo == west){
  currentLocation[1] = (currentLocation[1] -1);
}
//  std::cout << "currentLocation: i:"<< currentLocation[0]  << " ;j: " << currentLocation[1] << std::endl;

}

void searchingForEnd(){//searching_for_end state
    // stateBox->label("searching_for_end");
    // stateBox->labelfont(FL_BOLD);
    // stateBox->labelsize(12);
    checkWalls();
    chooseDirection();
    updateBlockBeforeMoving();
    moveOneBlock();
    updateCurrentLocationBlock();
}

void backtrackingToLastUnknown(){// backtracking_to_last_unknown state
    // Fl_Box *stateBox = new Fl_Box(700,100,250,50,"backtracking_to_last_unknown");
    // stateBox->box(FL_DOWN_BOX);
    // stateBox->labelfont(FL_BOLD);
    //stateBox->labelsize(12);
    backtrackingToLastUnknownPathState();
    updateBlockBeforeMoving();
    moveOneBlock();
    updateCurrentLocationBlock();
    if(memory[currentLocation[0] - 1][currentLocation[1] - 1].unexploredPath == 1){
      stateWeAreIn = searching_for_end;
    }
}

void solve(){
    
  //  std::cout << "currentstate:"<< stateWeAreIn << std::endl;

  switch ( stateWeAreIn ) {
  case searching_for_end:
    searchingForEnd();
    break;
  case backtracking_to_last_unknown:
    backtrackingToLastUnknown();
    break;
  default:
      // Code
    break;
  } 

}