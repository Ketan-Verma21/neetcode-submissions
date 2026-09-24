class Node{
    public:
    int val;
    int key;
    Node* prev;
    Node* next;
    Node(int x, int y){
        this->key= x;
        this->val=y;
        prev=nullptr;
        next=nullptr;
    }
};

class LRUCache {
public:
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> hash;
    void _delete(Node* node){
        Node* _next= node->next;
        Node* _prev= node->prev;
        _prev->next= _next;
        _next->prev= _prev;

    }
    void _insert(Node* node){
        Node* next= head->next;
        head->next=node;
        node->next=next;
        next->prev=node;
        node->prev=head;
        if(hash.size()>this->capacity){
            Node* to_del= tail->prev;
            _delete(to_del);
            hash.erase(to_del->key);
            delete to_del;
        }
    }
    LRUCache(int capacity) {
        this->capacity= capacity;
        hash.clear();
        Node* head= new Node(-1,-1);
        Node* tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        this->head=head;
        this->tail=tail;
    }
    
    int get(int key) {
        if(hash.find(key)!=hash.end()){
            Node* node= hash[key];
            _delete(node);
            _insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.find(key)!=hash.end()){
            Node* node= hash[key];
            _delete(node);
            _insert(node);
            node->val=value;
        }
        else{
            Node* node= new Node(key,value);
            hash[key]=node;
            _insert(node);
        }
    }
};
