struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size) return -1;
        Node* curr = head;
        for(int i=0; i<index; i++){
            curr = curr->next;
        }
        return curr->data;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        if(head == NULL){
            head = temp;
            tail = temp;
            size++;
            return;
        }
        temp->next = head;
        head = temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);
        if(tail == NULL){
            head = temp;
            tail = temp;
        }
        tail->next = temp;
        tail = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size){
            addAtTail(val);
            return;
        }
        Node* curr = head;
        for(int i=0; i<index-1; i++){
            curr = curr->next;
        }
        Node* temp = new Node(val);
        temp->next = curr->next;
        curr->next = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size) return;
        if(head == NULL) return;
        if(index == 0){
            Node* temp = head;
            if(head->next == NULL){
                head = NULL;
                tail = NULL;
            } else{
                head = head->next;
            }
            delete temp;
            size--;
            return;
        }
        Node* curr = head;
        for(int i=0; i<index-1; i++){
            curr = curr->next;
        }
        if(index == size-1) tail = curr;
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */