class MyLinkedList {
public:
    MyLinkedList() {
        size = 0;
        dummy_head = new ListNode(-1);
    }
    
    int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        ListNode *cur = dummy_head->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode *tmp = dummy_head->next;
        dummy_head->next = new ListNode(val);
        dummy_head->next->next = tmp;
        ++size;
    }
    
    void addAtTail(int val) {
        ListNode *newnode = new ListNode(val);
        ListNode *cur = dummy_head;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newnode;
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index < 0) index = 0;
        ListNode *newnode = new ListNode(val);
        ListNode *cur = dummy_head;//这样保证插入在index之前
        while(index--){
            cur = cur->next;
        }
        newnode->next = cur->next;
        cur->next = newnode;
        ++size;

    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size){
            return;
        }
        ListNode *cur = dummy_head;
        while(index--){
            cur = cur->next;
        }
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        --size;
    }
private:
    ListNode *dummy_head;
    int size;
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