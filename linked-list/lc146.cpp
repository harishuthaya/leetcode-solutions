#include <unordered_map>

class LRUCache {
    class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;
        Node(int key, int value): key{key}, value{value}, prev{nullptr}, next{nullptr} {}
    };
    const int capacity;
    int size;
    std::unordered_map<int, Node*> nodeMap;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity): capacity{capacity}, size{0}, head{new Node{0,0}}, tail{new Node{0,0}} {
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    
    int get(int key) {
        auto it = nodeMap.find(key);
        if (it == nodeMap.end()) return -1;
        Node* node = it->second;
        remove(node);
        addToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (auto it = nodeMap.find(key); it != nodeMap.end()) {
            Node* node = it->second;
            remove(node);
            addToHead(node);
            node->value = value;
            return;
        }
        
        if (capacity == size) {
            Node* lru = tail->prev;
            remove(lru);
            nodeMap.erase(lru->key);
            delete lru;
            --size;
        }
        nodeMap[key] = new Node(key, value);
        addToHead(nodeMap[key]);
        ++size;
    }
};

