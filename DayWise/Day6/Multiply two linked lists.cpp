//https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1/

/* Linked list node structure
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/

/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/
long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
long long N = 1000000007;
  long long fn = 0, sn = 0;
  
  while(l1 || l2) {
      if(l1) {
          fn = (fn*10)%N + l1->data;
          l1 = l1->next;
      }
      if(l2) {
          sn = (sn*10)%N + l2->data;
          l2 = l2->next;
      }
  }
  return (fn*sn)%N;
}
