#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Edge;
struct Node{  
    int data;
    struct Node* left;
    struct Node* right;
protected:
    string id;
    string state;
    string team;
public: 
    Node();
    Node(string i, string s, string t){
        id = i;
        state=s;
        team=t; 
    }
    friend Edge;
    friend ostream& operator<<(ostream& os, Node *other){
        return os <<other->id<< " [label="<<other->state<<" color="<<other->team<<"]";
    }
};

class BinaryTree{
    private:
        void destroy_tree(Node *leaf);
        void insert(int dat, Node *leaf);
        Node *search(int dat, Node *leaf);
         
        Node *root;
    public:
        BinaryTree();
        ~BinaryTree();
 
        void insert(int dat);
        Node *search(int dat);
        void destroy_tree();
};

BinaryTree::BinaryTree(){
    root=NULL;
}

BinaryTree::~BinaryTree(){
    destroy_tree();
}

void BinaryTree::destroy_tree(Node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void BinaryTree::insert(int dat, Node *leaf)
{
  if(dat< leaf->data)
  {
    if(leaf->left!=NULL)
     insert(dat, leaf->left);
    else
    {
      leaf->left=new Node;
      leaf->left->data=dat;
      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
  else if(dat>=leaf->data)
  {
    if(leaf->right!=NULL)
      insert(dat, leaf->right);
    else
    {
      leaf->right=new Node;
      leaf->right->data=dat;
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
    }
  }
}

Node *BinaryTree::search(int dat, Node *leaf)
{
  if(leaf!=NULL)
  {
    if(dat==leaf->data)
      return leaf;
    if(dat<leaf->data)
      return search(dat, leaf->left);
    else
      return search(dat, leaf->right);
  }
  else return NULL;
}

struct Edge{
    map<string,string> attributes;
    
    Node* start;
    Node* end;
    string arrowhead;
    Edge(Node* s,Node* e){
        start = s;
        end = e;
    }
    void setArrowhead(string s){
        arrowhead = s;
    }
    friend ostream& operator<<(ostream& os,const Edge& other){
        os << other.start->id<<"->"<<other.end->id;
        os << "[ arrowhead="<<other.arrowhead<<"]";
        return os;
    }
};

struct Graphviz{

    void Print(){
        cout<<"digraph G {\nstart -> a0;\nstart -> b0;\na1 -> b3;\n}";
    }
};

int main() {
  Graphviz G;
  Node* N1 = new Node("001","dallas","red");
  Node* N2 = new Node("002","amarillo","blue");
  Edge E1(N1,N2);
  E1.setArrowhead("diamond");
  cout<<N1<<endl;
  cout<<N2<<endl;
  cout<<E1<<endl;
  return 0;
}