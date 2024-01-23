#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int key;
  Node *prev;
  Node *next;
};
void createNode(Node **head, int key)
{
  Node *newNode = new Node();
  newNode->key = key;
  newNode->prev = NULL;
  newNode->next = NULL;

  if (*head == NULL)
  {
    *head = newNode;
  }
  else
  {
    Node *last = *head;
    while (last->next != NULL)
    {
      last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
  }
}
void deleteNode(Node **head, int key)
{
  if (*head == NULL)
  {
    printf("Lista jest pusta. Nie mozna usunac elementu.\n");
    return;
  }

  Node *current = *head;
  while (current != NULL)
  {
    if (current->key == key)
    {
      if (current->prev != NULL)
      {
        current->prev->next = current->next;
      }
      else
      {
        *head = current->next;
      }

      if (current->next != NULL)
      {
        current->next->prev = current->prev;
      }

      delete current;
      printf("Usunieto element o wartosci %d z listy.\n", key);
      return;
    }

    current = current->next;
  }

  printf("element o wartości %d nie zostal znaleziony w liscie.\n", key);
}
void printList(Node *head)
{
  while (head != NULL)
  {
    printf("%d -> ", head->key);
    head = head->next;
  }
  printf("NULL\n");
}
int main()
{
  Node *head = NULL;

  // Dodawanie węzłów do listy
  createNode(&head, 1);
  createNode(&head, 2);
  createNode(&head, 3);

  // Wyświetlanie listy od przodu
  printf("Lista od przodu przed usunieciem: ");
  printList(head);

  // Usuwanie węzła o wartości 2
  deleteNode(&head, 2);

  // Wyświetlanie listy od przodu po usunięciu
  printf("Lista od przodu po usunieciu: ");
  printList(head);

  return 0;
}