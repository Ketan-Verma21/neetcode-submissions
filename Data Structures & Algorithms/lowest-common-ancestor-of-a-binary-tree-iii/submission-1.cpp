/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        set<Node*> s;
        Node* temp=p;
        while(temp->parent!= nullptr){
            s.insert(temp);
            temp=temp->parent;
        }
        s.insert(temp);
        temp=q;
        while(true){
            if(s.find(temp)!=s.end()){
                return temp;
            }
            temp=temp->parent;
        }
        return p;
    }
};