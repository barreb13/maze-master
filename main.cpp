//main.cpp
// Created by Brent Barrese on 1/29/20.
//

#include "creature.h"
#include "maze.h"
#include <iostream>

void test() 
{
    //Testing original maze.txt
    cout << "Testing original maze.txt\n";
    Maze m("maze.txt");
    Creature c(4, 4);
    //Testing overloaded << operator
    cout << "Creature starting position: " << c << endl;
    cout << "Path: " << c.solve(m) << endl;
    cout << m << endl;

    // Testing maze1
    cout << "Testing maze1.txt\n";
    Maze m1("maze1.txt");
    Creature c1(6, 6);
    // Testing overloaded << operator
    cout << "Creature starting position: " << c1 << endl;
    cout << "Path: " << c1.solve(m1) << endl;
    cout << m1 << endl;

    // Testing maze2
    cout << "Testing maze2.txt\n";
    Maze m2("maze2.txt");
    Creature c2(7, 22);
    // Testing overloaded << operator
    cout << "Creature starting position: " << c2 << endl;
    cout << "Path: " << c2.solve(m2) << endl;
    cout << m2 << endl;

    // Testing maze3
    cout << "Testing maze3.txt\n";
    Maze m3("maze3.txt");
    Creature c3(13, 3);
    // Testing overloaded << operator
    cout << "Creature starting position: " << c3 << endl;
    cout << "Path: " << c3.solve(m3) << endl;
    cout << m3 << endl;
}

int main() {
    test();
    cout << "Done!" << std::endl;
    return 0;
}
