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
    bool isPalindrome(ListNode* head) {
        

        //edge case: if the LL is empty or only contains one element
        if(head == nullptr || head -> next == nullptr){
            return true;
        }

        //initialising variables to keep track of the nodes
        ListNode* slow = head;
        ListNode* fast = head;

        //part 1: parsing through the LL to find the middle of the LL
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            if(fast -> next != nullptr){
                fast = fast -> next -> next;
            }
        }

        //part 2: reversing the second half of the list
        //initialising nodes for successful reversal
        ListNode* next_node = nullptr;
        ListNode* prev = nullptr;
        ListNode* current = slow;

        //parsing the LL for the reversal
        while(current != nullptr){
            //reverse the pointers of the second half of the LL to point to the middle as well
            next_node = current -> next;
            current -> next = prev;
            prev = current;
            current = next_node;
        }


        //part 3 comparing the nodes
        //initialising nodes for the comparision
        ListNode* first_half = head;
        ListNode* second_half = prev;

        //checking for the similarity
        while(second_half != nullptr){
            if(first_half -> val != second_half -> val){
                return false;
            }
            else{
                first_half = first_half -> next;
                second_half = second_half -> next;
            }
        }
        return true;
    }
};

