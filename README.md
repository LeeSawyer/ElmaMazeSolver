# ElmaMazeSolver

Create a graphic maze, search and solve it using Elma template. Preferable this would be made with a Visual Studeo C++ Form or QT GUI for easy of graphics. Or use graphics liberaries such as Cairomm or Nux as permitted.

Goals would include better appreciation for advanced C++ programming methods/techniques such as classes, inheritance, and State-Machines.





Progress week 8 homework: Making progress with a GUI libreary (https://www.fltk.org/). Not compiling yet, still linking libereary files.

Progress week 9: after adding the included libraries to the g++ compilation, "helloworld" GUI works. But does not work when inside of a docker container.  

ElmaMazeSolver
===

ElmaMazeSolver is a micromouse maze solving simulator using fltk, Fast Light Toolkit for a front end graphic user interface. On exicution the "mouse" in the top left of the maze will navigate to the "end" in the lower right of the maze. The algorythm will switch between a "searching_for_end" state and a "backtracking_to_last_unknown" state. Each state follows shared and state specific processes to deal with events while in the state. 


Installation
===

The source code for ElmaMazeSolver [is on Github](https://github.com/LeeSawyer/ElmaMazeSolver).

Manual Installation
---

To get started, you will need a C++ build environment. 

    git clone https://github.com/LeeSawyer/ElmaMazeSolver.git
    cd fltk

Installation on Unix systems
---

First install of required packages may be needed through apt-get

RUN apt-get update && \
    apt-get install -y libx11-dev && \
    apt-get install -y libxfixes-dev && \
    apt-get install -y libxext-dev && \
    apt-get install -y libxrender-dev && \
    apt-get install -y libxcursor-dev && \
    apt-get install -y libxft-dev && \
    apt-get install -y libxinerama-dev

also fltk version 1.3.5 is include in the ElmaMazeSolver.git. But if needed to install

WORKDIR /tmp
RUN git clone https://github.com/fltk/fltk.git
RUN mkdir /usr/local/include/fltk
RUN mv /tmp/fltk/FL/Fl.H /usr/local/include/fltk
RUN rm -r /tmp/fltk


Issues
===

GUIs do not easily run in docker containers and I was unsuccessful in figuring them out. So manual compiling in using g++ is required. My system is Ubuntu linux and suspect it will run on other unix machines. 

I attempted to compile and run it on a Windows PC and was unsuccessful.


Usage
===

Compile and exicute with: 

    g++ elmaLiteMazeSolver.cpp -Ifltk-1.3.5 -Lfltk-1.3.5/lib -lfltk -lX11 -lXfixes -lXext -ldl -lXrender -lXcursor -lfontconfig -lXft -lXinerama -o elmaLiteMazeSolver
    ./elmaLiteMazeSolver




License
===

This software is open source and uses the MIT license. 
