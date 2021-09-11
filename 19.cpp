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
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *p = dummy , *p_offset = dummy;
        
        for(int i = 0; i < n && p_offset -> next != NULL; i++){
            p_offset = p_offset -> next;
        }
        
        while(p_offset -> next != NULL){
            p = p -> next;
            p_offset = p_offset -> next;
        }
        
        ListNode *temp = p -> next;
        p -> next = temp -> next;
        delete temp;
        
        return dummy -> next;
    }
};