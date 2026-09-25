class Solution {
public:

    ListNode* merge(ListNode* left, ListNode* right) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(left && right) {

            if(left->val <= right->val) {
                temp->next = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right = right->next;
            }

            temp = temp->next;
        }

        if(left) {
            temp->next = left;
        }

        if(right) {
            temp->next = right;
        }

        return dummy->next;
    }


    ListNode* mergeSort(ListNode* head) {

        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rightHead = slow->next;

        // Break the list
        slow->next = nullptr;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(rightHead);

        return merge(left, right);
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) {
            return nullptr;
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        // Concatenate all lists
        for(int i = 0; i < lists.size(); i++) {

            temp->next = lists[i];

            while(temp->next) {
                temp = temp->next;
            }
        }

        return mergeSort(dummy->next);
    }
};