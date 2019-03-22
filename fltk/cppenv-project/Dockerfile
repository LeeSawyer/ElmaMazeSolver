#
# To use this image to compile C and C++ projects, do something like
# docker build -t cppenv .
# docker run -v $PWD/hw_1:/source -it cppenv bash
#

# Get the GCC preinstalled image from Docker Hub
FROM gcc:4.9

MAINTAINER Lee Sawyer "LeeSawyer101@gmail.com"

# Get cmake for googletest, graphviz and doxygen for documentation
RUN apt-get update && \
    apt-get install -y cmake && \
    apt-get install -y cppcheck && \
    apt-get install -y graphviz && \
    apt-get install -y doxygen && \
    apt-get install -y nano && \
    apt-get install -y libx11-dev && \
    apt-get install -y libxfixes-dev && \
    apt-get install -y libxext-dev && \
    apt-get install -y libxrender-dev && \
    apt-get install -y libxcursor-dev && \
    apt-get install -y libxft-dev && \
    apt-get install -y libxinerama-dev

# this might get the display to work
ENV DISPLAY :0


# Build google test
WORKDIR /usr/src
RUN git clone https://github.com/google/googletest.git
WORKDIR /usr/src/googletest/install
RUN cmake ../ && make && make install

# Install FLTK
WORKDIR /tmp
RUN git clone https://github.com/fltk/fltk.git
RUN mkdir /usr/local/include/fltk
RUN mv /tmp/fltk/FL/Fl.H /usr/local/include/fltk
RUN rm -r /tmp/fltk

WORKDIR /source

COPY bashrc /root/.bashrc
