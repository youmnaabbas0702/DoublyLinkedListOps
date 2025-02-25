#include <iostream>
#include "clsDblLinkedList.h"


int main()
{
    clsDblLinkedList<int> MydblLinkedList;

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(6);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(4);

    cout << "Linked List Content:\n";
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::Node* N1 = MydblLinkedList.Find(2);
    if (N1 != NULL)
    {
        cout << "Node with value 2 was found\n";
    }
    else
    {
        cout << "Node was not found\n";
    }
    
    MydblLinkedList.InsertAfter(N1, 500);
    cout << "After inserting 500 after 2:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAtEnd(700);
    cout << "After inserting 700 at the end:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.DeleteNode(N1);
    cout << "After deleting Node with value 2:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.DeleteFirstNode();
    cout << "After deleting first Node:\n";
    MydblLinkedList.PrintList();
    
    MydblLinkedList.DeleteLastNode();
    cout << "After deleting last Node:\n";
    MydblLinkedList.PrintList();
}