//creature.h
// Created by Brent Barrese on 1/25/2020.

#pragma once

#include "maze.h"
#include <ostream>

class Creature {
  public:
    // Prints coordinates of where creature is (row, col)
    friend ostream& operator<<(ostream& out, const Creature& creature);

  public:
    // Initialize creature
    Creature(int row, int col);

    // Solve function that begins solving maze and returns string of path
    string solve(Maze& maze);

    // Boolean value to check if creature is at the exit to the maze
    bool atExit(const Maze& maze);

    // Moves creature North by 1 and -1 row
    string goNorth(Maze& maze);

    // Moves creature South by 1 and +1 row
    string goSouth(Maze& maze);

    // Moves creature East by 1 and +1 column
    string goEast(Maze& maze);

    // Moves creature West by 1 and -1 column
    string goWest(Maze& maze);

  private:
    int row;
    int col;
    bool didReachExit = false;
};
