/* 
**  Name:               Fowzy Alsaud & Paxton Proctor
**  Assignments:        P02 - Graphviz class
**  Date:               March, 24th, 2021
**  Course:             OOP - CMPS 2143
**  Professor:          Dr. Griffin
**  About the program:  
**      - Program to make Graphviz code to build you a diagram :D [NFL Fandom for 2014]
**  How it works:    
        0. Compile and run the program
        1. Program will create a node
        2. Pragram will create a edge
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Node.h"
#include "Edge.h"

using namespace std;

// Prototype Function(s)
void runApp(); // run the program

// Main Function
int main()
{
    runApp(); // run the program
    return 0;
}

void runApp()
{
    Node NodeObject; // creating an objecto for Node class
    Edge EdgeObject; // creating an object for Edge class
    // Two var. to store the name of the filenames
    string inputName;
    string outputName;
    cout << "Enter the input file: ";
    cin >> inputName;                           // user input the file name
    // cout << "Enter the output file name: ";
    // cin >> outputName;                       // user input the file name

    // Start ifstream, ofstream
    ifstream inputFile(inputName);
    ofstream outputFile(outputName);
    // calling create Vectors function from the node class so it will read input file and print out the result
    NodeObject.createVN(inputFile);
    // calling create Vectors function from the edge class so it will read input file and print out the result
    EdgeObject.createVN(inputFile);

    // Close ifstream and ofstream
    inputFile.close();
    outputFile.close();
}