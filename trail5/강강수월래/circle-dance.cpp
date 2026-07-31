#include <iostream>
#include <unordered_map>
#include <set>
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

int n, m, q;

unordered_map<int, Node*> nodes; 

void showCycle(int a) {
    Node* cur = nodes[a]->next;
    set<int> s;
    s.insert(nodes[a]->data);

    while(cur->data != nodes[a]->data) {
        s.insert(cur->data);
        cur = cur->next;
    }

    int startNum = *s.begin();
    cout << startNum << " ";

    Node* start = nodes[startNum];
    cur = start->prev;

    while(start->data != cur->data) {
        cout << cur->data << " ";
        cur = cur->prev;
    }
    
    cout << endl;
}

int main() {
    cin >> n >> m >> q;

    for(int i = 0; i < m; i++) {
        int l;
        cin >> l;

        int tmp;
        cin >> tmp;
        Node* ini = new Node(tmp);
        nodes[tmp] = ini;
        Node* cur = ini;

        for(int j = 1; j < l; j++) {
            cin >> tmp;
            Node* node = new Node(tmp);
            cur->connect(node);
            nodes[tmp] = node;
            cur=node;
        }

        cur->connect(ini);
    }

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int a, b;
            cin >> a >> b;
            Node* b_prev = nodes[b]->prev;
            Node* a_next = nodes[a]->next;
            nodes[a]->connect(nodes[b]);
            b_prev->connect(a_next);
        }

        if(t == 2) {
            int a, b;
            cin >> a >> b;
            
            Node* cur = nodes[a];

            Node* a_prev = nodes[a]->prev;
            Node* b_prev = nodes[b]->prev;
            a_prev->connect(nodes[b]);
            b_prev->connect(nodes[a]);
        }

        if(t == 3) {
            int a;
            cin >> a;

            showCycle(a);
        }
    }
    
    return 0;
}