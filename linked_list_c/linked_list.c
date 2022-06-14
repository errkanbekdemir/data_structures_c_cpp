#include <stdlib.h>
#include <stdio.h>
#include "stdint.h"

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node_t;

void insert(node_t **head, int x);
void insert_with_position(node_t **head, int x, int position_to_insert);
void delete_with_position(node_t **head, int position_to_delete);
void print(node_t *head);
void reverse_list(node_t **head);
void reverse_print(node_t *p);
void reverse_list_recursive(node_t *p,node_t** pointer_to_head);

int main(void)
{
  node_t *head = NULL;
  insert(&head, 1);
  insert(&head, 2);
  insert(&head, 3);
  insert(&head, 4);
  insert(&head, 5);
  insert(&head, 6);
  insert(&head, 7);
  insert(&head, 8);
  // print(head);
  // reverse_list(&head);
  print(head);
  // reverse_print(head);
  reverse_list_recursive(head,&head);
  print(head);

  return 0;
}

void insert(node_t **head, int x)
{
  node_t *temp = (node_t *)malloc(sizeof(node_t));
  temp->data = x;
  temp->next = *head;
  *head = temp;
}

void print(node_t *head)
{
  printf("List is");

  while (head != NULL)
  {
    printf(" %d", head->data);
    head = head->next;
  }
  printf("\n");
}

void insert_with_position(node_t **head, int x, int position_to_insert)
{
  node_t *temp_1;
  node_t *temp_2;

  // we store head in a temp variable for
  temp_2 = *head;
  // allocate memory for new object
  temp_1 = (node_t *)malloc(sizeof(node_t));
  // Put data you want to insert to new object
  temp_1->data = x;
  if (position_to_insert == 1)
  {
    // Replace existing node as second node
    temp_1->next = *head;
    // Set head to new node
    *head = temp_1;
    return;
  }

  for (int i = 0; i < position_to_insert - 2; i++)
  {

    // Find (n-1)th node
    if (temp_2->next != NULL)
    {
      temp_2 = temp_2->next;
    }
    else
    {
      printf("Invalid position");
      free(temp_1);
      return;
    }
  }
  // Set next of (n-1)th node to new node we want to insert
  temp_1->next = temp_2->next;
  // Set link to (n-1)th node to new node
  temp_2->next = temp_1;
}

void delete_with_position(node_t **head, int position_to_delete)
{
  node_t *temp_1 = *head;
  if (position_to_delete == 1)
  {
    *head = temp_1->next;
    free(temp_1);
    return;
  }

  // Find (n-1th element)
  for (int i = 0; i < position_to_delete - 2; i++)
  {
    temp_1 = temp_1->next;
  }

  node_t *temp_2;
  // Get nth element on the list
  temp_2 = temp_1->next;
  if (temp_2 == NULL)
  {
    printf("Invalid position to delete");
    return;
  }
  // Link the n-1th node to n+1th node
  temp_1->next = temp_2->next;
  // Free memory
  free(temp_2);
}

void reverse_list(node_t **head)
{
  node_t *current;
  node_t *prev;
  node_t *next;
  current = *head;
  prev = NULL;
  while (current != NULL)
  {
    // We store next node in a temp variable
    next = current->next;
    // We break the link with next node and assign new link to previous node
    current->next = prev;
    // Update prev node with curr node
    prev = current;
    // Just move to next node;
    current = next;
  }
  // This is new head
  *head = prev;
}

void reverse_print(node_t *p)
{
  if (p == NULL)
    return;
  reverse_print(p->next);
  printf("%d ", p->data);
}

void reverse_list_recursive(node_t *p,node_t** pointer_to_head)
{
  if (p->next == NULL)
  {
    *pointer_to_head = p;
    return;
  }

  reverse_list_recursive(p->next,pointer_to_head);
  //Store next node in a temp variable
  node_t* q = p->next;
  //Connect next node to first node
  q->next = p;
  //Move NULL to next node
  p->next = NULL;
}