#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}

    void connect(Node* node) {
        next = node;
        
        if(node != nullptr)
            node->prev=this;
    }

    void pop() {
        prev->connect(next);
        prev=next=nullptr;
    }

    bool popped() {
        return prev==nullptr && next==nullptr;
    }
};

Node* nodes[100001];

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {
        head = new Node(-1);
        tail = new Node(-1);
        head->connect(tail);
    }

    void pushBack(int val) {
        Node* node = new Node(val);
        nodes[val] = node;
        Node* tail_prev = tail->prev;
        node->connect(tail);
        tail_prev->connect(node);
    }

    void display() {
        Node* current = head->next;

        if(current->data == -1) {
            cout << "-1";
            return;
        }

        while(current->data != -1) {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

LinkedList lists[11];

int n, m, q;

int main() {
    cin >> n >> m >> q;

    for(int i = 0; i < m; i++) {
        int l;
        cin >> l;
        for(int j = 0; j < l; j++) {
            int tmp;
            cin >> tmp;
            lists[i].pushBack(tmp);
        }
    }

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int a, b;
            cin >> a >> b;
            if(nodes[a]->popped() || nodes[b]->popped()) {
                continue;
            }
            nodes[a]->pop();
            Node* b_prev = nodes[b]->prev;
            nodes[a]->connect(nodes[b]);
            b_prev->connect(nodes[a]);
        }

        if(t == 2) {
            int a;
            cin >> a;
            nodes[a]->pop();
        }

        if(t == 3) {
            int a, b, c;
            cin >> a >> b >> c;

            if(nodes[a]->popped() || nodes[b]->popped() || nodes[c]->popped()) {
                continue;
            }

            nodes[a]->prev->connect(nodes[b]->next);
            
            Node* c_prev = nodes[c]->prev;
            c_prev->connect(nodes[a]);
            nodes[b]->connect(nodes[c]);
        }
    }

    for(int i = 0; i < m; i++) {
        lists[i].display();
        cout << endl;
    }
    
    return 0;
}