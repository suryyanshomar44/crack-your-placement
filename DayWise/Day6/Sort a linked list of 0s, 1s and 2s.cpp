//https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1


class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int arr[3] = {0,0,0};
        Node* temp = head;
        while(temp!=NULL) {
            arr[temp->data]++;
            temp = temp->next;
        }
        int i = 0;
        temp = head;
        while(temp!=NULL) {
            if(arr[i]==0) {
                i++;
            }
            else {
                temp->data = i;
                arr[i]--;
                temp = temp->next;
            }
        }
        return head;
    }
};
