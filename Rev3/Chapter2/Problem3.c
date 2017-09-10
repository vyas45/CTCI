/*
 * Delete middle node
 */
void DeleteMid(struct node* curr) {
  if(curr->next == NULL) {
    printf("Cannot...");
    return;
  }
  curr->data = curr->next->data;
  curr->next = curr->next->next;
}
