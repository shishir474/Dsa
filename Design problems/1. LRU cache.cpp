1. We have to implement two functions get(key) and put(key,val) in O(1) time.
2. get(key) -> if key is not present it will return -1, else it will retunn keys value.
3. put funcion will check if the size of current cache is equal to capacity the it will remove the LRU guy.
4. What is lru ? suppose u have 4 tshirts,first one u wear on monday then on tuesday,wed and thn thursday.  the tshirt which u wore on monday is the least recently used one
5. For implemneting LRU we will require a DLL(doubly linked list) & a hashmap. the hashmap will store key and node's address and the doubly linked list will initaily contain two dummy nodes head and tail pointing to each other like this
null<-head-> tail -> null
          <-




solution:

class Node{
  public:
    int key,val;
    Node* next;
    Node* prev;
    Node(int _key, int _val){
        key = _key;
        val = _val;
    }
};

class LRUCache {
public:
    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int,Node*> mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void deleteNode(Node* delnode){
        Node* delprev= delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    void addNode(Node* n){
        Node* temp = head->next;
        n->next = temp;
        temp->prev = n;
        head->next = n;
        n->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* resnode = mp[key];
            int ans=  resnode->val;
            mp.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            mp[key] = head->next;
            return ans;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existingnode = mp[key];
            mp.erase(key);
            deleteNode(existingnode);
        }
        if(mp.size()==cap){
            Node* lrunode = tail->prev;
            mp.erase(tail->prev->key);
            deleteNode(lrunode);
        }
        
        Node* newnode = new Node(key,value);
        addNode(newnode);
        mp[key] = head->next;
    }
};


TC: O(1) for both put(key,value) and get(key);


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */