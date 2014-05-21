INTRODUCTION

This document describes the plan for testing the 2048 text mode game. 
The 2048 text mode game is a single player sliding puzzle game based on the 2048 online version (http://gabrielecirulli.github.io/2048/).
By providing a text mode variant, we want to widen the targeted users to also included those who prefere to use console and text mode instead of GUI

The 2048 text mode game supports the following features:

1) Display a 4 x 4 board
2) Display score
3) Accept user inputs
   a) Left
   b) Right
   c) Up
   d) Down
   
4) Tilt board left
5) Tilt board right
6) Tilt board up
7) Tilt board down


RESPONSIBILITIES

The software developer will be in charge for testing the application

SCOPE
All the mentioned features must be tested

1) During development
   a) Create unit tests
   b) Implement functionality intil unit tests pass

2) After each requirement:
   a) Create a manual test with all necessary steps
   b) Review it (or send it for review) 
   c) Run the test case and provide a report with test results 
   d) If issues are found: write unit tests that reproduce it possible, fix the issues and rerun the test case

REQUIREMENTS FOR TEST

1) User Interface Testing
   a) Verify ease of input for the game moves and other commands
   b) Verify that the console output matches the current state of the game (output up to date)
   c) Verify tat console output is understandable by a normal user

2) Performance Testing
   a) Verify response time after a move
b) Verify overall system load while game is running

3) Installation / deployment Testing  
   a) Make sure that the program can be installed a run on the following platforms: Linux/UNIX, Win32 provided that they have C runtime libraries

APPROACH
 
1) Function testing:
   Testing of the application should focus on any target requirements that can be traced directly to use cases or business functions (like tilt left)
   The main goal of such test will be to verify that all the functions are working as specified
2) Test Automation: 
   a) As part of the development process we use automated unit tests, in fact we are using Test Driven Development 
   b) We also plan to automate the user interaction with the program by writing scripts that forward standard input to a stream of predefined inputs

3) Completion Criteria	
    a) All tests have been executed.
    b) All identified issues have been addressed.

ENVIRONMENT

- Os: Unix/Linux, Win32
- Software: C runtime libraries
- Hardware: Keybpoard input and console output are required in order to use the program

MILESTONES AND DELIVERABLES

1) Schedule
   a) Tilt the board (left, right, up, down)
      - Start: 1 day 
      - Finish:2 day 
      - Effort: 2d

   b) Display score:
      - Start: 0 day 
      - Finish:0 day 
      - Effort: 3 h

   c) Accept user inputs
      - Start: 0 day 
      - Finish: 0 day 
      - Effort: 3 h

   d) Display a 4 x 4 board
      - Start: 0 day 
      - Finish: 0 day 
      - Effort: 2h

   

2) Deliverables 
   a) Test plan: Project owner
   b) Test results: Project owner, Developer
   c) Metrics: ALL
