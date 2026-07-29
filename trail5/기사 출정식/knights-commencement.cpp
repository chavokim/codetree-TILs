#include <iostream>
#include <unordered_map>
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
};

int n, q;
unordered_map<int, Node*> nodes;

int main() {
    cin >> n >> q;

    int ini;
    cin >> ini;
    Node* initialNode = new Node(ini);
    Node* current = initialNode;
    nodes[ini] = initialNode;

    for(int i = 1; i < n; i++) {
        int temp;
        cin >> temp;
        Node* node = new Node(temp);
        current->connect(node);
        current = node;
        nodes[temp] = node;
    }

    current->connect(initialNode);
    current = initialNode;

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        cout << nodes[t]->next->data << " " << nodes[t]->prev->data << endl;
        nodes[t]->pop();
    }

    return 0;
}