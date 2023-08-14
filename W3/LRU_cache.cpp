class Node {
public:
    int key;
    int value;
    Node *next;
    Node *prev;
    
    // param ctor
    Node(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
    Node *head = new Node(-1, -1); 
    Node *tail = new Node(-1, -1); 
    
    int capacity; 
    unordered_map<int, Node*> m; 
public:
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node *node) {
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
    
    void deleteNode(Node *node) {
        Node *prev_node = node->prev;
        prev_node->next = node->next;
        node->next->prev = prev_node;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()) {
            Node *result_node = m[key];
            int result_val = result_node->value;
            m.erase(key);
            deleteNode(result_node);
            addNode(result_node);
            m[key] = head->next;
            return result_val;
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            Node *result_node = m[key];
            m.erase(key);
            deleteNode(result_node);
        }
        if(m.size() == capacity) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        m[key] = head->next;
    }
};
