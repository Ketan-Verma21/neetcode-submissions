/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        map<Node*, int> org;
        int i=0;
        while(temp){
            org[temp]=i;
            temp=temp->next;
            i++;
        }
        temp=head;
        map<int, Node*> dup;
        Node* prev= new Node(-1);
        Node* head_newll=prev;
        int x=0;
        while(x<i){
            Node* new_node = new Node(0);
            prev->next=new_node;
            dup[x]=new_node;
            prev=new_node;
            x++;
        }
        prev=head_newll->next;
        while(temp){
            prev->val=temp->val;
            if(temp->random==nullptr) prev->random=nullptr;
            else prev->random=dup[org[temp->random]];
            temp=temp->next;
            prev=prev->next;
        }
        return head_newll->next;

    }
};
