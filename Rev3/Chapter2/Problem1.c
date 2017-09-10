/* Remove duplicate nodes from linked list */
struct node {
  int data;
  struct node* next;
};

void removeDups(struct node* head) {
  struct node* slow = head;
  struct node* fast = NULL;

  while(slow->next!=NULL) {
    fast = slow;
    while(fast->next != NULL) {
      if(fast->data == fast->next->data)
        fast->next = fast->next->next;
      else
        fast = fast->next;
    }
    slow = slow->next;
  }
}
