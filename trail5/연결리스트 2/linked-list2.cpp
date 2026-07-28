#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;

    Node *prev, *next;

    Node(int data) :
        data(data),
        prev(nullptr),
        next(nullptr) {}
};

void InsertNext(Node *u, Node *singleton) {
    singleton->prev = u;
    singleton->next = u->next;

    if(nullptr != singleton->prev)
        singleton->prev->next = singleton;
    if(nullptr != singleton->next)
        singleton->next->prev = singleton;
}

void InsertPrev(Node *u, Node *singleton) {
    singleton->next = u;
    singleton->prev = u->prev;

    if(nullptr != singleton->next)
        singleton->next->prev = singleton;
    if(nullptr != singleton->prev)
        singleton->prev->next = singleton;
}

void Pop(Node *u) {
    if(nullptr != u->next)
        u->next->prev = u->prev;
    if(nullptr != u->prev)
        u->prev->next = u->next;

    u->next=nullptr;
    u->prev=nullptr;
}

void PrintNode(Node *n) {
    if(n->prev == nullptr) {
        cout << 0 << " ";
    } else {
        cout << n->prev->data << " ";
    }

    if(n->next == nullptr) {
        cout << 0;
    } else {
        cout << n->next->data;
    }

    cout << endl;
}

Node *nodes[100001];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    int q;

    cin >> q;

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int a;
            cin >> a;
            Pop(nodes[a]);
        }

        if(t == 2) {
            int a, b;
            cin >> a >> b;
            InsertPrev(nodes[a], nodes[b]);
        }


        if(t == 3) {
            int a, b;
            cin >> a >> b;
            InsertNext(nodes[a], nodes[b]);
        }

        if(t == 4) {
            int a;
            cin >> a;
            PrintNode(nodes[a]);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(nodes[i]->next != nullptr) {
            cout << nodes[i]->next->data << " ";
        } else {
            cout << 0 << " ";
        }
    }

    return 0;
}