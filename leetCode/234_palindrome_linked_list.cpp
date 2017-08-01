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
    bool isPalindrome(ListNode* head) {
    	if (head == nullptr || head->next == nullptr) {
    		return true;
    	}

    	ListNode* slow = head;
    	ListNode* fast = head;

    	// find middle point
    	while (fast->next != nullptr && fast->next->next != nullptr) {
    		slow = slow->next;
    		fast = fast->next->next;
    	}

    	slow->next = reverseList(slow->next);
    	slow = slow->next;

    	while (slow) {
    		if (head->val != slow->val) {
    			return false;
    		}

    		head = head->next;
    		slow = slow->next;
    	}

    	return true;
    }
private:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* curr = head;

		while (curr) {
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}

		return prev;
	}
};
