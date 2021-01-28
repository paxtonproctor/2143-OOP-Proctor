/*  
**  Name:               Paxton Proctor
**  Assignments:        A03 - Commenting Code
**  Date:               Jan, Tuesday 26th, 2020
**  Course:             OOP - CMPS 2143
**  Professor:          Dr. Griffin
**  About the program:  
**      - a simple program will create a small queue with capacity of 5 elemnts.
**  How it works:    
        0. Compile and run the program
        1. Program will create a queue with capacity of 5 elements
        2. Pragram will add 1,2,3 to the queue
        3. then print out the result
**  Member Functions:
        - Private Funcations: 
            - int  - set a default value for Front, Rear, CurrentSize to 0
            - Full - check if the queue is full or not
        - Public Functions: 
            - Push - a function to add an item to the queue
            - Pop  - a function to remove front element from the queue
** Member Variable:
        - *Container   -    array to store queue elements
        - Front        -    front points to front element in the queue
        - Rear         -    rear points to last element in the queue
        - QueSize      -    items in the queue
        - CurrentSize; -    count the current size of the queue
*/

#include <iostream>

using namespace std;


class CircularArrayQue {
private:
    // array to store elements
    int *Container; 
    // front element in the queue
    int Front;
    // rear element in the queue
    int Rear;
    // items in the queue
    int QueSize;
    // count the size of the queue currently
    int CurrentSize;

    // This function sets front, rear, and current to 0
    // and sets queue and size equal to each other
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    // determines whether the queue is full or not
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    // Default constructor
    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    // Overloaded constructor
    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }
    // Function that adds an item to the queue
    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
    // Function that removes front element from queue
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }
    // Overloading the cout operator
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    // prints out the queue
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
