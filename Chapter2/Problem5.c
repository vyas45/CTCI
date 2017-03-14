/*
 * Sum of Two Linked Lists
 * We have 2 linked lists that represent 2 numbers. The digits are in 
 * reverse order, i.e the first node is the units digit
 *
 * Input: (7->1->6) + (4->2->8->3) = 617 + 4283
 * Output: (0->0->9->4) = 4900
 */
#include<stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* next;
};

/* Allocate an new node with the data */
struct node* createNode(int item) {
  struct node* newNode = NULL;
  newNode = malloc(sizeof(struct node));
  newNode->data = item;
  newNode->next = NULL;
  return newNode;
}

/* Insert a newNode at the end of the list */
void InsertEnd(struct node** head, int item) {
  struct node* curr = *head;

  /* Create the new Node with the data passed in */
  struct node* newNode =  createNode(item);

  /* If it is an empty list to start with */
  if(*head == NULL) {
    *head = newNode; 
    return;
  }

  /* Iterate till the end of the list and append the newNode */
  while(curr->next!=NULL) {
    curr = curr->next;
  }
  curr->next = newNode;
}

/* Insert at the front of the array */
void InsertFront(struct node** head, int item) {
  struct node* newNode =  createNode(item);

  if(*head == NULL){
    *head = newNode;
    return;
  }
  /* Otherwise make it the head of the existing list */
  newNode->next = *head;
  *head  = newNode;
}

/* Sum the 2 linked lists and produce another list */
void SumLists(struct node* head1, struct node* head2, struct node** result) {
  struct node* curr1 = NULL;
  struct node* curr2 = NULL;
  int carry = 0;
  int sum = 0;//Holding the sum

  /* Get the runners ready */
  curr1 = head1;
  curr2 = head2;
    while(curr1 && curr2) {
    sum = curr1->data + curr2->data + carry; 
    carry = sum/10;
    sum = sum%10;

    printf("Sum and carry are %d and %d\n", sum, carry);
    InsertEnd(result, sum);

    //Update the runners
    curr1 = curr1->next;
    curr2 = curr2->next;
  }

  //If curr1 is still going on
  while(curr1!=NULL) {
    sum = curr1->data + carry;
    carry = sum/10;
    sum = sum%10;

    InsertEnd(result, sum);
    curr1 = curr1->next;
  }

  //If curr1 is still going on
  while(curr2!=NULL) {
    sum = curr2->data + carry;
    carry = sum/10;
    sum = sum%10;

    InsertEnd(result, sum);
    curr2 = curr2->next;
  }
}

/* Recursive Sum of the Linked Lists */
void SumRec(struct node* head1, struct node* head2, struct node** result) {
  if(head1==NULL || head2==NULL) return;
  else {
     int sum = 0;
     int carry = 0;
     SumRec((head1->next), (head2->next), result);
     printf("Adding %d and %d\n", head1->data, head2->data);
     sum = (head1->data) + (head2->data) + carry;
     carry = sum/10;
     carry = sum % 10;
     InsertEnd(result, sum);
  }
}

/* Print the linked list */
void printer(struct node* head) {
  struct node* curr = head;

  while(curr!=NULL) {
    printf("%d -->", curr->data);
    curr = curr->next;
  }
  printf("NULL\n");
}

int main() {
  struct node* head1 = NULL; //First number
  struct node* head2 = NULL; //Second number
  struct node* result  = NULL; //Result Linked List
  struct node* result_rec  = NULL; //Recursive Result Linked List


  // Number 1 =  (7->1->6)
  InsertEnd(&head1, 7);
  InsertEnd(&head1, 1);
  InsertEnd(&head1, 6);
  InsertEnd(&head1, 4);

  printer(head1);

  // Number 2 = (4->2->8->3)
  InsertFront(&head2, 1);
  InsertFront(&head2, 1);
  InsertFront(&head2, 1);
  //InsertFront(&head2, 1);

  printer(head2);

  SumLists(head1, head2, &result);

  /* print the result linked list */
  printer(result);
  
  /* Sum the numnbers the other way
   * The number are aligned straight
   * (7->1->6->4) == 7164
   * (1->1->1->1) == 1111 ...duh...
   */
  SumRec(head1, head2, &result_rec);
  printf("Recursive Result is \n");
  printer(result);
  return 0;
}
