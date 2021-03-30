/*
**  Member Functions:
        - Public Functions: 
            - getnode - get nodes function
            - setnode  - sets node function
            - createsVN  - creates a vector of nodes
            - showVN  - displays the vector of nodes
** Member Variable:
        - nid -    Node ID
        - label -  Node label
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class Node
{
private:
    string nid; // ID for every Node we create
    string label; // var. to store label
public:
    //Default Constructor
    Node()
    {
        nid = "NULL";
        label = "NULL";
    }
    //Overloaded Constructor
    Node(string _nid, string _label)
    {
       nid = _nid;
       label = _label;
    }
    void getNode();                 // get nodes function  
    void setNode(string, string);   // set nodes 
    void createVN(ifstream&);       // create vectors nodes 
    void showVN(vector<Node> &);    // show vectors nodes
};

// Member functions definitions
void Node::getNode()                        // get nodes function
{
    cout << nid << "[label=\"" << label << "\"]\n";
}

void Node::setNode(string id, string nlab)  // set nodes
{
    nid = id;
    label = nlab;
}

void Node::createVN(ifstream& openFile)                       // create vectors nodes
{
    string element;
    vector<Node> vecNodes;
    // While loop to read our data file
    while (openFile >> element)
    {
        if (element == "74")
        {
            string nid, node;
            while (openFile >> nid >> node)
            {
                if (nid != "50")
                {
                    Node newNode(nid, node);
                    // Then push data into vectors
                    vecNodes.push_back(newNode);
                }
                else
                    break;
            }
        showVN(vecNodes);
        }
    }
}


void Node::showVN(vector<Node> &vecNodes)                          // show vectors nodes
{
    // for loop to read Node class
    for (int i = 0; i <= vecNodes.size(); i++)
    {
        vecNodes[i].getNode();
    }
}