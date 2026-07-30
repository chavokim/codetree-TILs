#include <iostream>
using namespace std;

int q;

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
};

Node* nodes[100001];

int main() {
    int current = 1;

    Node* head = new Node(-1);
    Node* tail = new Node(-1);
    Node* ini = new Node(current);
    nodes[current] = ini;
    head->connect(ini);
    ini->connect(tail);

    cin >> q;

    for(int i = 0; i < q; i++) {
        int t;

        cin >> t;

        if(t == 1) {
            int a, b;
            cin >> a >> b;

            Node* currentNode = nodes[a];
            Node* finalNode = currentNode->next;
            
            for(int j = 0; j < b; j++) {
                current++;
                Node* node = new Node(current);
                nodes[current] = node;
                currentNode->connect(node);
                currentNode = node;
            }

            currentNode->connect(finalNode);
        }

        if(t == 2) {
            int a, b;
            cin >> a >> b;

            Node* currentNode = nodes[a]->prev;
            Node* finalNode = nodes[a];
            
            for(int j = 0; j < b; j++) {
                current++;
                Node* node = new Node(current);
                nodes[current] = node;
                currentNode->connect(node);
                currentNode = node;
            }

            currentNode->connect(finalNode);
        }

        if(t == 3) {
            int a;
            cin >> a;

            if(nodes[a]->prev->data == -1 || nodes[a]->next->data == -1) {
                cout << -1 << endl;
            } else {
                cout << nodes[a]->prev->data << " " << nodes[a]->next->data << endl;
            }
        }
    }
    
    return 0;
}