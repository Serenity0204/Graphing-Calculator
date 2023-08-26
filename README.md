
# Graphing Calculator in C++ SFML

A graphing calculator built with C++ SFML that supports graphing various functions, 
operations including + - * / ^, along with single variable x.

- Press enter to select input box, so the user can enter
- Press esc to unselct input box
- Press UP to graph 
- Press DOWN to clear
- Press RIGHT to zoom in the screen
- Press Left to zoom out the screen
- Use the mouse to click the sidebar to re-visit past input history

The functions supported are listed below:

[![functions.png](https://i.postimg.cc/C5Hnm0cL/functions.png)](https://postimg.cc/sGx2gkFt)

## Tutorial
* part 1: https://medium.com/@eduboost0204/build-a-graphing-calculator-in-c-sfml-part-1-setup-and-introduction-3cb469a43ca3
## Demo

[![demo1.png](https://i.postimg.cc/CxJt9fRb/demo1.png)](https://postimg.cc/BjLMKbcv)

[![demo2.png](https://i.postimg.cc/x1jpGT68/demo2.png)](https://postimg.cc/SJ5GkqFb)

[![demo3.png](https://i.postimg.cc/XNwsTyhX/demo3.png)](https://postimg.cc/SjxL9jmp)

## How To Run
```
## Include This CMakeLists.txt File 
## Open VS Code
## Make Sure You Have The CMake Tools Extension Installed
## Run The Main Using The Tool Bar

cmake_minimum_required(VERSION 3.14 FATAL_ERROR) #FetchContent_MakeAvailable
project(Graphing-Calculator-Usage)

if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

## Fetch the content
include(FetchContent)
FetchContent_Declare(
  Graphing-Calculator
  GIT_REPOSITORY https://github.com/Serenity0204/Graphing-Calculator
)
FetchContent_MakeAvailable(Graphing-Calculator)

```


## Design
Can be found in 
https://github.com/Serenity0204/Graphing_Calculator_SFML/blob/master/design.txt





## Features

- Capability of graphing various functions
- Past history sidebar that combines with LRU cache
- Zoom in/zoom out
- Decimal value input such as 0.5 and 3.14
- Error handling for invalid input
- Unary operator for number such as -3.14 and -5
- User input string parsed into tokens, used Shunting Yard and RPN algorithms to evaluate into points
- Random Color generator to generate different colors for graph


## System Setup

To run this project, please follow the system requirements below, this project has only been tested on windows.


`Windows: `
  - compiler: g++ 13.1.0
  - cmake: 3.20.0

`SFML setup: `
  - windows: https://docs.google.com/document/d/13Tn2sq9-CtAMuUenALlj1l4f8xL-BzeI8-DKRjhdPu0/edit?usp=sharing
  - mac: https://docs.google.com/document/d/1ujZWMMvwwIH_dAd-X4JvcVdtn7B71-joOjbOo-vVXLY/edit?usp=sharing

