/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        
        //edge case: if linked list is empty or have just one element
        if(head == nullptr || head -> next == nullptr){
            return false;
        }

        //initialising pointers
        ListNode* slow = head;
        ListNode* fast = head;

        //looping through the linked list to see if the slow and the fast pointer clash declaring the presence of a cycle
        while (fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;

            //to check for the cycle
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};