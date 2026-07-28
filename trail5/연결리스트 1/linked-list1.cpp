#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;

    Node *prev, *next;

    Node(string data) :
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

void PrintNode(Node *n) {
    if(n->prev == nullptr) {
        cout << "(Null) ";
    } else {
        cout << n->prev->data << " ";
    }

    cout << n->data << " ";

    if(n->next == nullptr) {
        cout << "(Null)";
    } else {
        cout << n->next->data;
    }

    cout << endl;
}

int main() {
    string s;
    cin >> s;

    Node *node = new Node(s);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int q;
        cin >> q;

        if(q == 1) {
            cin >> s;
            Node *tmp = new Node(s);

            InsertPrev(node, tmp);
        }

        if(q == 2) {
            cin >> s;
            Node *tmp = new Node(s);
            InsertNext(node, tmp);
        }


        if(q==3) {
            if(node->prev != nullptr) {
                node = node->prev;
            }
        }

        if(q==4) {
            if(node->next != nullptr) {
                node = node->next;
            }
        }

        PrintNode(node);
    }

    return 0;
}