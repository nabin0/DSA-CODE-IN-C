#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void dataTraversel(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element is : " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Insertion in Linked list

struct Node *insertAtBegin(struct Node *head, int data)
{
    struct Node *ptr = new struct Node;
    ptr->data = data;
    ptr->next = head;

    return ptr;
}

// Insert in Between or AT index
struct Node *insertInBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = new struct Node;
    ptr->data = data;

    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Insert in at the end
struct Node *insertAtTheEnd(struct Node *head, int data)
{
    struct Node *ptr = new struct Node;
    ptr->data = data;

    struct Node *p = head;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    ptr->next = NULL;
    p->next = ptr;

    return head;
}

// Insert after Given Node
int insertAfterGivenNode(struct Node *givenNode, int data)
{
    struct Node *ptr = new struct Node;
    ptr->data = data;

    ptr->next = givenNode->next;
    givenNode->next = ptr;

    return 1;
}

// Insert Before Given Node
int insertBeforeGivenNode(struct Node *head, struct Node *givenNode, int data)
{
    struct Node *ptr = new struct Node;
    ptr->data = data;

    struct Node *p, *n = head;

    for (p, n; n != givenNode; p = n, n = n->next)
        ;

    ptr->next = givenNode;
    p->next = ptr;

    return 1;
}

// ------Deletion --------

struct Node *deletionAtStart(struct Node *head)
{
    struct Node *a = head;
    head = head->next;
    delete a;

    return head;
}
struct Node *deletionAtIndex(struct Node *head, int index)
{
    struct Node *a = head;
    struct Node *b = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        a = a->next;
        b = b->next;
    }
    a->next = b->next;
    delete b;
    return head;
}
struct Node *deletionAtEnd(struct Node *head)
{
    struct Node *a = head;
    struct Node *b = head->next;
    while (b->next != NULL)
    {
        a = a->next;
        b = b->next;
    }
    a->next =NULL;
    delete b;
    return head;
}

struct Node *deletionOfGiven(struct Node *head, int elem)
{
    // NOTE: No condition speciedfied for 1st and last element(Node) so it will not work for those elements.
    struct Node *a = head;
    struct Node *b = head->next;
    while (b->data != elem && b->next != NULL)
    {
        a = a->next;
        b = b->next;
    }
    if (b->data == elem)
    {
        a->next = b->next;
        delete b;
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    head = new struct Node;
    second = new struct Node;
    third = new struct Node;

    // Head of linked list
    head->data = 121;
    head->next = second;

    // Linking Head Node with second node
    second->data = 321;
    second->next = third;

    // Last Node in the list pointed to NULL
    third->data = 413;
    third->next = NULL;

    // Linked List Displaying
    cout << "Displaying linked list: " << endl;
    dataTraversel(head);

    // Insertion
    cout << "Displaying linked list after insertion: " << endl;
    head = insertAtBegin(head, 2);
    insertInBetween(head, 11, 1);
    insertAtTheEnd(head,121);
    insertAfterGivenNode(second, 981);
    insertBeforeGivenNode(head, third, 1009);
    dataTraversel(head);

    // Insertion
    cout << "Displaying linked list after Deletion: " << endl;
    head = deletionAtStart(head);
    head = deletionAtIndex(head, 1);
    head = deletionAtEnd(head);
    head = deletionOfGiven(head, 321);
    dataTraversel(head);
    return 0;
}