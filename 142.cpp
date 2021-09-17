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
    ListNode *detectCycle(ListNode *head) {
        //if(head == NULL || head -> next == NULL) return NULL;
        
        ListNode *slow = head, *fast = head;
        
        while(fast != NULL){
            slow = slow -> next;
            if(fast -> next != NULL){
                fast = fast -> next -> next;
                if(slow == fast){
                    ListNode *tmp = head;
                    while(tmp != slow){
                        tmp = tmp -> next;
                        slow = slow -> next;
                    }
                    return tmp;
                }
            }else {
                return NULL;
            }
                
        }
        
        return NULL;
    }
};