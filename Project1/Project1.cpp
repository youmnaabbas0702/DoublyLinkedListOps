#include <iostream>
#include "clsDblLinkedList.h"


int main()
{
    clsDblLinkedList<int> MydblLinkedList;

    cout << "is linked list empty?: " << MydblLinkedList.IsEmpty() << endl;
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

    cout << "Size of the linked list: " << MydblLinkedList.Size() << endl;
    cout << "is linked list empty?: " << MydblLinkedList.IsEmpty() << endl;

    /*MydblLinkedList.Clear();
    cout << "After clear, size = " << MydblLinkedList.Size();*/

    MydblLinkedList.Reverse();
    cout << "After reverse: \n";
    MydblLinkedList.PrintList();

    cout << MydblLinkedList.head->Value << endl;

    clsDblLinkedList<int>::Node* N2 = MydblLinkedList.Find(500);

    MydblLinkedList.InsertAfter(N2, 300);
    cout << "After inserting 300 after 500:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.Clear();
    MydblLinkedList.InsertAtBeginning(70);

    clsDblLinkedList<int>::Node* N3 = MydblLinkedList.GetNode(0);
    cout << "Node value: " << N3->Value << endl;

    cout << "Item(3): " << MydblLinkedList.GetItem(3) << endl;

    MydblLinkedList.InsertAtBeginning(60);
    MydblLinkedList.InsertAtBeginning(40);
    MydblLinkedList.InsertAtBeginning(20);

    MydblLinkedList.UpdateItem(3, 10);
    MydblLinkedList.UpdateItem(2, 10);
    MydblLinkedList.UpdateItem(1, 10);
    MydblLinkedList.UpdateItem(0, 10);

    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAfter(2, 40);
    cout << "\n\nAfter insert:\n\n";
    MydblLinkedList.PrintList();
}