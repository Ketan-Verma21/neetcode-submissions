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
    int tot_len;
    int rem;
    ListNode* solve(int i, ListNode* head){
        if(head==nullptr){
            this->tot_len=i-1;
            return head;
        }
        head->next=solve(i+1,head->next);
        if((this->tot_len-i+1)==rem){
            return head->next;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        this->rem=n;
        return solve(1,head);
    }
};
