//https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1/
class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
       // Your code here
       if(del == NULL) {
           return;
       }
       del->data = del->next->data;
       del->next = del->next->next;
    }

};

