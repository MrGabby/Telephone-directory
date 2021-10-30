#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
struct Node *head;

   //structure
struct Node
{
  char *data;
  char *num;
  struct Node *next;
};

       // DISPLAY FUNC.
void display(struct Node *ptr)
{
  while (ptr != NULL)
  {
    printf("Element: \t%s\n Contact no: %s\n \n", ptr->data, ptr->num);
    ptr = ptr->next;
  }


}

       // INSERT FUNC.

void insert(struct Node *head)
{
  struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
  ptr->data = (char *)malloc(20 * sizeof(char));
  ptr->num = (char *)malloc(11 * sizeof(char));

  printf("\tENTER NAME\n");
  scanf("%s", ptr->data);

  printf("\tENTER PHONE NUMBER\n");
label:
  scanf("%s", ptr->num);
  if (strlen(ptr->num) == 10)
  {
    struct Node *p = head;
    while (p->next != NULL)
    {
      p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
  }
  else
  {
    printf("\tINVALID NUMBER\n\tPLEASE ENTER PHONE NUMBER AGAIN\n");
    goto label;
  }
}

  //SEARCH FUNCTION

void search(struct Node *ptr)
{ int i;
again:
 printf("\tYOU WANT TO SEARCH BY NUMBER OR NAME\n\t* ENTER 1 TO SEARCH BY NAME \n\t* ENTER 2 TO SEARCH BY NUMBER\n");

scanf("%d",&i);
switch(i)
{
 case 1:
  {
    printf("ENTER NAME YOU WANT TO SEARCH\n");
    char a[20];
    int b;
    scanf("%s", &a);
  up:
    b = strcmp(a, ptr->data);
    if (b == 0)
    {
      printf("\tMATCH FOUND\n");
      printf("NAME is: %s\nCONTACT is: %s\n", ptr->data, ptr->num);
      return;
    }
    else if (ptr->next == NULL)
    {
      printf("NO MATCH FOUND\n\tINVALID NAME\n");

    }
    else
    {
      ptr = ptr->next;
      goto up;
    } break;}

  case 2:
 {
    printf("ENTER NUMBER YOU WANT TO SEARCH\n");
    char a[20];
    int b;
    scanf("%s", &a);
  uup:
    b = strcmp(a, ptr->num);
    if (b == 0)
    {
      printf("\tMATCH FOUND\n");
      printf("NAME is: %s\nCONTACT is: %s\n", ptr->data, ptr->num);
      return;
    }
    else if (ptr->next == NULL)
    {
      printf("NO MATCH FOUND\n\tINVALID NUMBER\n");

    }
    else
    {
      ptr = ptr->next;
      goto uup;
    }}
  default:
    printf("\tINVALID INPUT \n");
    goto again;}
}

                        //DELETE FUNCTION

struct Node * delete(struct Node *ptr)
{
    struct Node *q=ptr->next;
    struct Node *temp = ptr;
    printf("ENTER NAME YOU WANT TO DELETE\n");
    char a[20];
    int b,d;
    scanf("%s", &a);
    d=strcmp(a,head->data);

        if (d==0) // Algo for node if node is head node.
        {
        //head=head->next;
        free(head);
        printf("\n\tSUCCESSFULLY DELETED\n\n");
        return q;
        }


    while(q != NULL)  // Algo for nodes which is not an head node
    {
        d=strcmp(a,q->data);
        if (d==0)
        {
            //head=head->next;
        head->next = q->next;
        free(q);
        printf("\n\tSUCCESSFULLY DELETED\n\n");
        return temp;
        }
        else
        {
            head = head->next;
            q = q->next;
        }

    }
    printf("\n NO Match found, Invalid Entry");
}

       //ALLOCATE FUNCTION

void allocate()
{

  // Allocate memory for nodes in the linked list in Heap
  struct Node *second;
  struct Node *third;
  struct Node *fourth;

  head = (struct Node *)malloc(sizeof(struct Node));
  head->data = (char *)malloc(20 * sizeof(char));
  head->num = (char *)malloc(11 * sizeof(char));

  second = (struct Node *)malloc(sizeof(struct Node));
  second->data = (char *)malloc(20 * sizeof(char));
  second->num = (char *)malloc(11 * sizeof(char));

  third = (struct Node *)malloc(sizeof(struct Node));
  third->data = (char *)malloc(20 * sizeof(char));
  third->num = (char *)malloc(11 * sizeof(char));

  fourth = (struct Node *)malloc(sizeof(struct Node));
  fourth->data = (char *)malloc(20 * sizeof(char));
  fourth->num = (char *)malloc(11 * sizeof(char));

  // Link first and second nodes

  head->data = "aman1";
  head->num = "9999999999";
  head->next = second;

  // Link second and third nodes
  second->data = "aman2";
  second->num = "8888888888";
  second->next = third;

  // Link third and fourth nodes
  third->data = "aman3";
  third->num = "7777777777";
  third->next = fourth;

  // Terminate the list at the third node
  fourth->data = "aman4";
  fourth->num = "6666666666";
  fourth->next = NULL;
}
int main()
{reset:
  allocate();
start:
  printf("\t**  ENTER 1 TO INSERT NAME AND PHONE NUMBER       * \t\n");
  printf("\t**  ENTER 2 TO DISPLAY ALL NAMES AND PHONE NUMBER * \t\n");
  printf("\t**  ENTER 3 TO SEARCH                             *\t\n");
  printf("\t**  ENTER 4 TO DELETE                             *\t\n");
  printf("\t**  ENTER 5 TO EXIT                               *\t\n");

  int a;
  scanf("%d", &a);

  switch (a)
  {
  case 1:
  {
    insert(head);
    printf("\n\tSUCCESSFULLY SAVED\n\n");
    goto start;

    break;
  }
  case 2:
  {
    display(head);
    goto start;
    break;
  }
  case 3:
  {
    search(head);
    goto start;
    break;
  }
  case 4:
  { head= delete(head);
goto start;
  return 0;}


  case 5:
    {
        return 0;
    }
    printf("\tINVALID INPUT\n");
    goto start;

}
return 0;
}