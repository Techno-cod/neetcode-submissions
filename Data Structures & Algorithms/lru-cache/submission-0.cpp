class Node{
    public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k,int v){
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
public:
int capacity;
unordered_map<int,Node*>keyToAddress;
Node* head;
Node* tail;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=NULL;
        tail=NULL;
        
    }
    Node* addToTail(int key,int value){
        Node* n=new Node(key,value);
        if(!head){
            head=tail=n;

        }
        else{
            tail->next=n;
            n->prev=tail;
            n->next=NULL;
            tail=n;
        }
        return n;
    }
    void moveToTail(Node* node,int value){
        node->value=value;
        if(node==tail) return;
        if(node==head){
            head=head->next;
            head->prev=NULL;
        }
        else{
            node->prev->next=node->next;
            node->next->prev=node->prev;

        }
        node->prev=tail;
        node->next=NULL;
        tail->next=node;
        tail=node;
    }
    void deleteHead(){ //delete least recently used node(head)
        if(head==NULL) return;
        if(head==tail){
            delete head;
            head=tail=NULL;
            return;
        }
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;

    }
    
    int get(int key) {
        if(keyToAddress.find(key)==keyToAddress.end()){
            return -1;

        }
        else{
            Node* node=keyToAddress[key];
            int ans=node->value;
            moveToTail(node,node->value);
            return ans;
        }
        
    }
    
    void put(int key, int value) {
          if(keyToAddress.find(key) != keyToAddress.end()) {

            moveToTail(keyToAddress[key], value);
            return;
        }
          // Cache not full
        if(keyToAddress.size() < capacity) {

            keyToAddress[key] = addToTail(key, value);
        }

        // Cache full
        else {

            keyToAddress.erase(head->key);

            deleteHead();

            keyToAddress[key] = addToTail(key, value);
        }
    }
        
    
};
