//creature.cpp
// Created by Brent Barrese on 1/25/2020.

#include "creature.h"

// Prints current location of creature - EX: C(7,3)
ostream& operator<<(ostream& out, const Creature& creature) 
{
    out << "Creature (" << creature.row << "," << creature.col << ")" << endl;
    return out;
}

// Intialized via initializer list with given row and column
Creature::Creature(int row, int col) : row(row), col(col) {}


//Checks to see if creature is at the exit. If yes, sets didReachExit to true
bool Creature::atExit(const Maze& maze) 
{
    if (row == maze.getExitRow() && col == maze.getExitColumn()) 
    {
        didReachExit = true;
        return true;
    }
    return false;
}

// Starts here at solve - Updates string "path" as you move (N, E, S, W)
string Creature::solve(Maze& maze) 
{
    string path;
    maze.markAsPath(row, col);

    // Check to see if at exit already <-- is this correct syntax?
    if (atExit(maze)) 
    {
        maze.markAsPath(row, col);
        return path;
    }

    // Else continue on
    path += goNorth(maze);
    if (!didReachExit) 
    {
        path += goEast(maze);
        if (!didReachExit) 
        {
            path += goSouth(maze);
            if (!didReachExit) 
            {
                path += goWest(maze);
            }
        }
    }
    return path;
}

// Moves creature North by 1 (-1 row)
string Creature::goNorth(Maze& maze) 
{
    string returnString;

    if (maze.isClear(row - 1, col)) 
    {
        row = row - 1;
        maze.markAsPath(row, col);
        if (atExit(maze)) 
        {
            return "N";
        }
        //Else continue on
        returnString = goNorth(maze);
        // success = didReachExit
        if (!didReachExit) 
        {
            returnString = goEast(maze);
            if (!didReachExit) 
            {
                returnString = goWest(maze);
                if (!didReachExit) 
                {
                    maze.markAsVisited(row, col);
                    // Update row to back down a row if you are unsuccessful
                    row = row + 1;
                }
            }
        }
        return "N" + returnString;
    }
    return returnString;
}

// Moves creature East by 1 (+1 column)
string Creature::goEast(Maze& maze) 
{
    string returnString;
    if (maze.isClear(row, col + 1)) 
    {
        col = col + 1;
        maze.markAsPath(row, col);
        if (atExit(maze)) 
        {
            return "E";
        } 
        //else 
        {
            returnString = goEast(maze);
            if (!didReachExit) 
            {
                returnString = goNorth(maze);
                if (!didReachExit) 
                {
                    returnString = goSouth(maze);
                    if (!didReachExit) 
                    {
                        maze.markAsVisited(row, col);
                        col = col - 1;
                    }
                }
            }
        }
        return "E" + returnString;
    }
    return returnString;
}

// Moves creature South by 1 (+1 row)
string Creature::goSouth(Maze& maze) 
{
    string returnString;
    if (maze.isClear(row + 1, col)) 
    {
        row = row + 1;
        maze.markAsPath(row, col);
        if (atExit(maze)) 
        {
            return "S";
        } 
        //else 
        {
            returnString = goSouth(maze);
            if (!didReachExit) 
            {
                returnString = goWest(maze);
                if (!didReachExit) 
                {
                    returnString = goEast(maze);
                    if (!didReachExit) 
                    {
                        maze.markAsVisited(row, col);
                        // Update row if unsuccessful
                        row = row - 1;
                    }
                }
            }
        }
        return "S" + returnString;
    }
    return returnString;
}

// Moves creature West by 1 (-1 column)
string Creature::goWest(Maze& maze) 
{
    string returnString;
    if (maze.isClear(row, col - 1)) 
    {
        col = col - 1;
        maze.markAsPath(row, col);
        if (atExit(maze)) 
        {
            return "W";            
        } 
        //else 
        {
            returnString = goWest(maze);
            if (!didReachExit)
            {
                returnString = goNorth(maze);
                if (!didReachExit) 
                {
                    returnString = goSouth(maze);
                    if (!didReachExit) 
                    {
                        maze.markAsVisited(row, col);
                        // Update column if unsuccessful
                        col = col + 1;
                    }
                }
            }
        }
        return "W" + returnString;
    }
    return returnString;
}