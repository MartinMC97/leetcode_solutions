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
class Solution
{
private:
    /**
	 * Divide the linked list into two lists,
     * while the first list contains first n ndoes
	 * return the second list's head
	 */
    ListNode *split(ListNode *head, int left_length)
    {
        //ListNode *tmp = head;
        int index = 1;

        while (head != NULL && index < left_length)
        {
            head = head -> next;
            index++;
        }

        if (!head)
            return NULL;

        ListNode *second_head = head -> next;
        head -> next = NULL;

        return second_head;
    }
	/**
	  * merge the two sorted linked list l1 and l2,
	  * then append the merged sorted linked list to the node head
	  * return the tail of the merged sorted linked list
	 */
    ListNode *merge(ListNode *l_tmp, ListNode *r_tmp, ListNode *head)
    {
        //ListNode *l_tmp = lhs, *r_tmp = rhs;
        ListNode *tmp_head = head;
        while (l_tmp && r_tmp)
        {
            if (l_tmp->val > r_tmp->val)
            {
                tmp_head -> next = r_tmp;
                tmp_head = r_tmp;

                r_tmp = r_tmp -> next;
            }
            else
            {
                tmp_head -> next = l_tmp;
                tmp_head = l_tmp;

                l_tmp = l_tmp->next;
            }
        }

        tmp_head->next = ((l_tmp) ? l_tmp : r_tmp);
        while (tmp_head->next)
            tmp_head = tmp_head->next;
        return tmp_head;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        
        //ListNode *tmp = head;
        int size = 0;
        for (ListNode *tmp = head; tmp != NULL; tmp = tmp->next)
        {
            size++;
        }

        ListNode *dummy_head = new ListNode(0);
        dummy_head->next = head;

        ListNode *left, *right, *tail;
        ListNode *tmp = dummy_head->next;
        for (int step = 1; step < size; step <<= 1)
        {
            tmp = dummy_head->next;
            tail = dummy_head;
            while (tmp != NULL)
            {
                left = tmp;
                right = split(left, step);
                tmp = split(right, step);
                tail = merge(left, right, tail);
            }
        }

        return dummy_head->next;
    }
};