class Node {
public:
    int val;
    int key;
    int cnt;
    Node* prev;
    Node* next;

    Node(int x, int y) {
        key = x;
        val = y;
        prev = nullptr;
        next = nullptr;
        cnt = 1;
    }
};


class LFUCache {
public:
    int capacity;
    unordered_map<int, Node*> hash;
    unordered_map<int, pair<Node*, Node*>> freq_hash_ep;
    int freq;
    void _delete(Node* node) {
        Node* _next = node->next;
        Node* _prev = node->prev;
        _prev->next = _next;
        _next->prev = _prev;

        int f = node->cnt;
        Node* head = freq_hash_ep[f].first;
        Node* tail = freq_hash_ep[f].second;

        if (head->next == tail) {
            freq_hash_ep.erase(f);
            if (freq == f) {
                freq++;
            }
        }
    }
    void _insert(Node* node) {

        int f = node->cnt;
        if (freq_hash_ep.find(f) == freq_hash_ep.end()) {

            Node* head = new Node(-1, -1);
            Node* tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            freq_hash_ep[f] = {head, tail};
        }

        Node* head = freq_hash_ep[f].first;
        Node* next = head->next;
        head->next = node;
        node->prev = head;
        node->next = next;
        next->prev = node;
    }
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->freq = 0;
    }

    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }
        Node* node = hash[key];
        _delete(node);
        node->cnt++;
        _insert(node);
        return node->val;
    }


    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (hash.find(key) != hash.end()) {
            Node* node = hash[key];
            _delete(node);
            node->val = value;
            node->cnt++;
            _insert(node);
            return;
        }

        if (hash.size() == capacity) {
            Node* tail = freq_hash_ep[freq].second;
            Node* to_del = tail->prev;
            _delete(to_del);
            hash.erase(to_del->key);
            delete to_del;
        }
        Node* node = new Node(key, value);
        hash[key] = node;
        freq = 1;
        _insert(node);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */