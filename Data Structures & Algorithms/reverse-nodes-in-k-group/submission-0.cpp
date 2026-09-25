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
    pair<ListNode*, ListNode*> reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* next;
        ListNode* prev=nullptr;
        while(temp){
            next=temp->next;
            temp->next= prev;
            prev=temp;
            temp=next;
        }
        return {prev, head};
    }
    ListNode* solve(ListNode* head, int k){
        int x=1;
        ListNode* temp=head;
        while(x!=k && temp){
            temp=temp->next;
            x++;
        }
        if(x==k){
            if(temp){
                ListNode* next= temp->next;
                temp->next=nullptr;
                pair<ListNode*,ListNode*> rev= reverse(head);
                if(next){
                    rev.second->next= solve(next, k);
                }
                return rev.first;

            }
            else return head;
        }
        else{
            return head;
        }

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head,k);
    }
};
