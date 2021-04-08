//maze.h

#pragma once

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };

class Maze {
    // Prints current maze
    friend ostream& operator<<(ostream& out, const Maze& maze);

  public:
    // Maze constructor
    explicit Maze(const string& fileName);

    // Checks to see if location is clear 
    bool isClear(int row, int col) const;

    //Marks the location with an *
    void markAsPath(int row, int col);

    //Marks the location with a + if not in exit path
    void markAsVisited(int row, int col);

    //Gets the row the exit location is in
    int getExitRow() const;

    //Gets the column the exit location is in
    int getExitColumn() const;

    // Function to check if creature is at the exit
    // bool atExit(int row, int col) const;

  private:
    static const int MAX_SIZE = 100;

    char field[MAX_SIZE][MAX_SIZE];
    int width;
    int height;
    int exitRow;
    int exitColumn;
};
