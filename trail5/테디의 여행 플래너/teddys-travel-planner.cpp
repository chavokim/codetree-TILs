#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;

    Node(string val) : data(val), prev(nullptr), next(nullptr) {}

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


int main() {
    cin >> n >> q;

    string initial;
    cin >> initial;
    Node* initialNode = new Node(initial);
    Node* current = initialNode;

    int count = n;

    for(int i = 1; i < n; i++) {
        string temp;
        cin >> temp;
        Node* node = new Node(temp);
        current->connect(node);
        current = node;
    }

    current->connect(initialNode);
    current = initialNode;

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            current = current->next;
        }

        if(t == 2) {
            current = current->prev;
        }

        if(t == 3 && current->next->data != current->data) {
            current->next->pop();
            count--;
        }

        if(t == 4) {
            string tmp;
            cin >> tmp;

            Node* node = new Node(tmp);
            Node* current_next = current->next;
            
            current->connect(node);
            node->connect(current_next);

            count++;
        }

        if(count <= 2) {
            cout << -1 << endl;
        } else {
            string left = current->prev->data;
            string right = current->next->data;
            cout << left << " " << right << endl;
        }
    }

    return 0;
}