class Node {
    public: 
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;

    MyLinkedList() {
        head = NULL;
    }

    // To calculate the length of the Linked List
    int length(){
        int count=0;
        Node*temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    
    int get(int index) {
        int len = length();
        if(head==NULL) {
            return -1;
        } else if(len<index) {
            return -1;
        } else {
            int count = 0;
            Node* temp = head;
            while(count<index) {
                temp = temp->next;
                count++;
            }
            if(temp==NULL) {
                return -1;
            } return temp->data;
        }
    }
    
    void addAtHead(int val) {
        Node* newHead = new Node(val);
        newHead->next = head;
        head = newHead;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head==NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next!=NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    void addAtIndex(int index, int val) {
        Node* newNode = new Node(val);
        if(index==0) {
            addAtHead(val);
        } else {
            int count = 0;
            Node* temp = head;
            while(temp!=NULL && count<index-1) {
                temp = temp->next;
                count++;
            }
            if(temp == NULL) {
                return;
            } 
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    void deleteAtIndex(int index) {
        if(head==NULL) {
            return;
        } else if(index==0) {
            Node* del = head;
            head = head->next;
            delete del;
        } else {
            int count = 0;
            Node* temp = head;
            while(count<index-1) {
                temp = temp->next;
                count++;
            }
            if(temp==NULL || temp->next==NULL) {
                return;
            }
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }
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