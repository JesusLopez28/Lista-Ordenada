#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef Node *pNode;
typedef Node *Lista;

void insertAsc(Lista *head, int data);
void insertDesc(Lista *head, int data);
void printList(Lista head);

int main()
{
    Lista head = NULL;
    int numeros[] = {5, 2, 8, 3, 1, 7, 4, 6};

    for (int i = 0; i < sizeof(numeros) / sizeof(numeros[0]); i++)
    {
        insertAsc(&head, numeros[i]);
    }

    printf("Lista en orden ascendente: ");
    printList(head);

    return 0;
}

void insertAsc(Lista *head, int data)
{
    pNode new_node = (pNode)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL || data < (*head)->data)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        pNode current = *head;
        while (current->next != NULL && data > current->next->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void insertDesc(Lista *head, int data)
{
    pNode new_node = (pNode)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL || data > (*head)->data)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        pNode current = *head;
        while (current->next != NULL && data < current->next->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printList(Lista head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

