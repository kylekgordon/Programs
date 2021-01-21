///////////////////////////////////////////////////////////////////////////////
// 
// Author:           Kyle Gordon
// Email:            kylekgordon@gmail.com
// Label:            A03
// Title:            Commented Code
// Course:           3013-Algorithms
// Semester:         Spring 2021
//
// Description:
//      This program implements a class that allows a linked list to be used just like 
//      an array.It overloads the "[]" (square brackets) to simulate accessing seperate
//      array elements, but really it traverses the list to find the specified node using
//      an index value. It also overloads the "+" and "-" signs allowing a user to "add"
//      or "push" items onto the end of the list, as well as "pop" items off the end of our
//      array.
//
// Usage:
//      Run the program and it will generate values for L1 and L2 based on the parameters.
//
// Files:     
//      main.cpp    : driver program
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

int A[100];                 // global Array


// linked list node
struct Node {
    int x;
    Node* next;             // Link to next node
    // default constructor
    Node() {
        x = -1;
        next = NULL;
    }
    // overloaded constructor
    Node(int n) {
        x = n;
        next = NULL;
    }
};

/**
 *
 * List
 *
 * Description:
 *      This class creates a tree. 
 *
 * Public Methods:
 *      - void        Push(int val)
 *      - void        Insert(int val)
 *      - void        PrintTail()
 *      - string      Print()
 *
 * Private Methods:
 *      - Node*       Head
 *      - Node*       Tail
 *      - int         Size
 *
 * Usage:
 *
 *      - L1.Push(i)
 *      - L1.PrintTail()
 */

class List {
private:
    Node* Head;
    Node* Tail;
    int Size;

public:
    List() {
        Head = Tail = NULL;
        Size = 0;
    }

    void Push(int val) {
        // allocate new memory and init node
        Node* Temp = new Node(val);

        if (!Head && !Tail) {
            Head = Tail = Temp;
        }
        else {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    void Insert(int val) {
        // allocate new memory and init node
        Node* Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail) {
            Tail = Head;
        }
        Size++;
    }
        // prints the tail
    void PrintTail() {
        cout << Tail->x << endl;
    }

    string Print() {
        // copy head as not to destroy the list
        Node* Temp = Head;
        string list;

        while (Temp != NULL) {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented
    int Pop() {
        Size--;
        return 0;
    }

    List operator+(const List& Rhs) {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node* Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL) {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index) {
        Node* Temp = Head;

        if (index >= Size) {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else {

            for (int i = 0; i < index; i++) {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream& operator<<(ostream& os, List L) {
        os << L.Print();
        return os;
    }
};

int main(int argc, char** argv) {
    List L1;                // declare instance of list L1
    List L2;                // declare instance of list L2

    // standard for loop to loop over 
    // our list/array and insert
    // into the list 0 to  24
    for (int i = 0; i < 27; i++) {
        L1.Push(i);
    }
    // standard for loop to loop over 
    // our list/array and insert
    // into the list 50 to 99
    for (int i = 50; i < 110; i++) {
        L2.Push(i);
    }

    //cout << L1 << endl;
    // Print the list's Tail
    L1.PrintTail();
    L2.PrintTail();

    List L3 = L1 + L2;      // declare instance of list L3
    cout << L3 << endl;     // print the list to screen

    cout << L3[25] << endl;  // Print specific index to screen
    return 0;
}