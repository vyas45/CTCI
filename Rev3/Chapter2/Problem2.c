/*
 *  kth from last
 */
struct node* kfromLast(struct node* head, int k) {
  int i = 0;
  struct node* slow = head;
  struct node* fast = head;
  for(i=0; i<k; i++) {
    if(fast==NULL) return NULL;
    fast = fast->next;
  }
  while(fast!=NULL) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}
