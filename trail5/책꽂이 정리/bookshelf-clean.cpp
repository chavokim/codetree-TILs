#include <iostream>
using namespace std;

// Represents an individual element in the list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Controls the list operations and maintains state
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    int count;

    DoublyLinkedList() : head(new Node(0)), tail(new Node(0)), count(0) {
        reset();
    }

    // Destructor to clean up allocated heap memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    int size() {
        return count;
    }

    // Adds a new node at the front of the list
    void pushFront(Node* newNode) {
        newNode->next = head->next;
        head->next->prev = newNode;
        newNode->prev = head;
        head->next = newNode;
        count++;
    }

    // Adds a new node at the back of the list
    void pushBack(Node* newNode) {
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        newNode->next = tail;
        tail->prev = newNode;
        count++;
    }

    Node* popFront() {
        if(count == 0) {
            return nullptr;
        }

        Node* popped = head->next;
        head->next = popped->next; 
        popped->next->prev = head;
        popped->next = popped->prev = nullptr;
        count--;       

        return popped;
    }

    Node* popBack() {
        if(count == 0) {
            return nullptr;
        }

        Node* popped = tail->prev;
        tail->prev = popped->prev;        
        popped->prev->next = tail;
        popped->next = popped->prev = nullptr;
        count--;

        return popped;
    }

    void reset() {
        head->next=tail;
        tail->prev=head;
        count = 0;
    }

    // Prints all items from head to tail
    void displayForward() const {
        cout << count << " ";

        Node* current = head->next;
        while (current && current->data != 0) {
            std::cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

DoublyLinkedList lists[101];

int n, k, q;

int main() {
    cin >> n >> k >> q;
    
    for(int i = 1; i <= n; i++) {
        lists[1].pushBack(new Node(i));
    }

    for(int i = 0; i < q; i ++) {
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 1) {
            Node* node = lists[a].popFront();
            if(node != nullptr) {
                lists[b].pushBack(node);
            }
        }

        if(t == 2) {
            Node* node = lists[a].popBack();
            if(node != nullptr) {
                lists[b].pushFront(node);
            }
        }

        if(t == 3 && a != b && lists[a].size()) {
            Node* b_first = lists[b].head->next;
            lists[b].head->next = lists[a].head->next;
            lists[a].head->next->prev = lists[b].head;
            lists[a].tail->prev->next = b_first;
            b_first->prev = lists[a].tail->prev;
            lists[b].count += lists[a].count;
            lists[a].reset();
        }

        if(t == 4 && a != b && lists[a].size()) {
            Node* b_last = lists[b].tail->prev;
            lists[b].tail->prev = lists[a].tail->prev;
            lists[a].tail->prev->next = lists[b].tail;
            lists[a].head->next->prev = b_last;
            b_last->next = lists[a].head->next;
            lists[b].count += lists[a].count;
            lists[a].reset();
        }
    }

    for(int i = 1; i <= k; i++) {
        lists[i].displayForward();
    }

    return 0;
}