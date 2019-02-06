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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode(0),* round_up = new ListNode(0);
        ListNode *zero_a= new ListNode(0), *zero_b= new ListNode(0);

		// count the digit 
		answer->val = (l1->val + l2->val) % 10;
		round_up->val = (l1->val + l2->val) / 10;

		if(l1->next != NULL && l2->next != NULL)
			answer->next = addTwoNumbers(l1->next, l2->next, round_up);
		else if(l1->next == NULL && l2->next != NULL)
			answer->next = addTwoNumbers(zero_a, l2->next, round_up);
		else if (l1->next != NULL && l2->next == NULL)
			answer->next = addTwoNumbers(l1->next, zero_b, round_up);
		else if (round_up->val != 0)
			answer->next = addTwoNumbers(zero_a, zero_b, round_up);
        
        return answer;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, ListNode* round_up_in) {
		ListNode* answer = new ListNode(0),* round_up = new ListNode(0);
        ListNode *zero_a= new ListNode(0), *zero_b= new ListNode(0);

        // count the digit 
		answer->val = (l1->val + l2->val + round_up_in->val) % 10;
		round_up->val = (l1->val + l2->val + round_up_in->val) / 10;

		if (l1->next != NULL && l2->next != NULL)
			answer->next = addTwoNumbers(l1->next, l2->next, round_up);
		else if (l1->next == NULL && l2->next != NULL)
			answer->next = addTwoNumbers(zero_a, l2->next, round_up);
		else if (l1->next != NULL && l2->next == NULL)
			answer->next = addTwoNumbers(l1->next, zero_b, round_up);
		else if (round_up->val != 0)
			answer->next = addTwoNumbers(zero_a, zero_b, round_up);
        
        return answer;
	}
};
