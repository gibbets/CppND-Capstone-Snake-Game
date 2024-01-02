# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg


## New features added

### Function and control structures

Additional function and control structures added to various files. New classes 
and functions added for the power up system. This is related to all files.

### User Input

When the snake dies, the game pauses to show the results in the console. A future
release could also show this in the game window, but it is too much effort to
add a text engine to SDL. The user can then hit Escape to leave the screen.

The user can hit anytime Escape to leave the game.

Files:
* controller.cpp
* game.cpp

### Classes added to the project

For the power up system addtional interfaces and classes have been added.

Files:
* doublepoints.cpp
* doublespeed.cpp
* powerup.cpp

### Initializer lists

Where applicable for the power up system, intializer lists in the constructors have been used.

Files:
* doublepoints.cpp
* doublespeed.cpp
* powerup.cpp

### Class abstract implementation

For the power up system all methods are documented with comments

Files:
* doublepoints.cpp
* doublespeed.cpp
* powerup.cpp

### Class inheritance

The power up system is using class inheritance. The classes doublepoints and doublespeed
are both derived from the same abstract base clase.

Files:
* doublepoints.cpp
* doublespeed.cpp
* powerup.cpp

### References in function parameters

The power up system is using refernces to the speed and points multiplicator
to modify in the applyEffects class.

Files:
* doublepoints.cpp
* doublespeed.cpp
* powerup.cpp

### Resource acquisition is initialization

The project uses the RAII pattern for the locks created in the power up system.

Files:
* powerup.cpp

### Smart Pointers

The project uses smart pointers for the power up system.

Files:
* powerup.cpp

### Multiple Threads

The power up system is spawning a thread to spawn and despwan power up items.

Files:
* powerup.cpp

### Locks

The power up system is using locks to synchronize access to data objects.

Files:
* powerup.cpp

### 


