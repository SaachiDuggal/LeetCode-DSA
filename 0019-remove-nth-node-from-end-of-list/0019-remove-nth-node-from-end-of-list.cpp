/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //edge case: if LL empty
        if(head == nullptr){
            return head;
        }

        //declaring a safeguard node to handle the edge case of head being deleted 2 pointers to keep track of the nth node while we traverse through the list
        ListNode* dummy = new ListNode(0, head);
        ListNode* left = dummy;
        ListNode* right = dummy;

        //traversing the LL till we attain nth gap between the nodes
        for(int i = 0; i < n; i++){
            right = right -> next;
        }

        while(right -> next != nullptr){

            //traversing to reach the nth element
            right = right -> next;
            left = left -> next;
        }

        //removing the node
        left -> next = left -> next -> next;

        //returning the head
        return dummy -> next;
    }
};