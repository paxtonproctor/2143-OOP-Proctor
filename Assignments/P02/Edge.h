/*
**  Member Functions:
        - Public Functions: 
            - getedges - get edges function
            - setedges  - sets edges function
            - createsVN  - creates a vector of nodes
            - showVN  - displays the vector of nodes
** Member Variable:
        - firstedge -    The First Node
        - secondedge -  The second node
        - label - Edge label
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Edge
{
private:
    string firstEdge;
    string secondEdge;
    string label;

public:
    //Default Constructor
    Edge()
    {
        firstEdge = "NULL";
        secondEdge = "NULL";
        label = "NULL";
    }
    //Overloaded Constructor
    Edge(string _firstEdge, string _secondEdge, string _label)
    {
        firstEdge = _firstEdge;
        secondEdge = _secondEdge;
        label = _label;
    }
    void getEdges();                        // getEdges
    void setEdges(string, string, string);  // setEdges
    void createVN(ifstream &);              // create vectors nodes
    void showVN(vector<Edge> &);            // show vectors nodes
};

// Member functions definitions
void Edge::getEdges()                                           // get Edges
{
    cout << firstEdge << " -> " << secondEdge << " [label=" << label << "]" << endl;
}
void Edge::setEdges(string frst, string scnd, string lbl)       // setEdge
{
    firstEdge = frst;
    secondEdge = scnd;
    label = lbl;
}

void Edge::createVN(ifstream &openFile)                         // show vectors nodes
{
    string element;
    vector<Edge> vecEdges;
    while (openFile >> element)
    {
        if (element == "50")
        {
            string firstElement, seconElement, label;
            while (openFile >> firstElement >> seconElement >> label)
            {
                if (firstElement != "74")
                {
                    Edge newNode(firstElement, seconElement, label);
                    // Then push data into vectors
                    vecEdges.push_back(newNode);
                }
                else
                    break;
            }
            showVN(vecEdges);
        }
    }
}

void Edge::showVN(vector<Edge> &vecEdges)                       // create vectors nodes
{
    // for loop to read Edge class
    for (int i = 0; i <= vecEdges.size(); i++)
    {
        vecEdges[i].getEdges();
    }
}