
#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void ft_print_linked(struct Node *head)
{
    struct Node *current = head;
    while (current)
    {
        printf("%d \n", current->data);
        current = current->next;
    }
}
void insertNode(struct Node *n,int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
   while(n->next)
   {
         n = n->next;
   }
    n->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
}

struct Node *insertinFront(struct Node *head,int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node *deleteNode(struct Node *head,int data)
{
    struct Node *current = head;
    struct Node *previous = NULL;
    struct Node *newHead = head;
    while (current)
    {
        if (current->data == data)
        {
            if (previous == NULL)
            {
                newHead = current->next;
                free(current);
                return newHead;
            }
            previous->next = current->next;
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
    return newHead;
}

int check_args(char **av)
{
    int i = 1;
    while (av[i])
    {
        int j = 0;
        while (av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

struct Node *ra(struct Node *head)
{
    int data = head->data;
    struct Node *current = head;

    while (current->next)
    {
        current = current->next;
    }
    head->data = current->data;
    current->data = data;
    printf("ra\n");
    return head;
}

struct Node *sa(struct Node *head)
{
    int data = head->data;
    head->data = head->next->data;
    head->next->data = data;
    printf("sa\n");
    return head;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        printf("Error: Wrong number of arguments\n");
        return 1;
    }
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));

    

    if (check_args(av))
    {
        printf("Error: Arguments must be numbers\n");
        return 1;
    }

    head->data = atoi(av[1]);
    head->next = NULL;
    while (av[2])
    {
        insertNode(head,atoi(av[2]));
        av++;
    }

    // ft_print_linked(head);
    // printf("------------------------\n");
    head = sa(head);
    // ft_print_linked(head);
    // printf("------------------------\n");
    head = ra(head);
    head = ra(head);
    // ft_print_linked(head);
    
 
   
    return 0;
}
