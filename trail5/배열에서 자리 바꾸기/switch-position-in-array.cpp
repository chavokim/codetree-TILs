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

void Connect(Node *s, Node *e) {
    if(nullptr != s)
        s->next = e;
    if(nullptr != e)
        e->prev = s;
}

void PopRange(Node *s, Node *e) {
    Connect(s->prev, e->next);
    s->prev = e->next = nullptr;
}

void InsertPrevRange(Node *s, Node *e, Node *v) {
    Connect(v->prev, s);
    Connect(e, v);
}

void InsertNextRange(Node *s, Node *e, Node *v) {
    Connect(e, v->next);
    Connect(v, s);
}

Node *nodes[250001];
Node *startNode = new Node(-2);

void PrintNode() {
    Node *node = startNode->next;
    while(node->data != -1) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
        if(i == 1) {
            Connect(startNode, nodes[i]);
        } else {
            Connect(nodes[i - 1], nodes[i]);
        }
    }

    Node *endNode = new Node(-1);
    Connect(nodes[n], endNode);

    for(int i = 0; i < q; i++) {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        if(nodes[a]->prev->data == nodes[d]->data) {
            Connect(nodes[c]->prev, nodes[a]);
            Connect(nodes[d], nodes[b]->next);
            Connect(nodes[b], nodes[c]);
        } else if(nodes[b]->next->data == nodes[c]->data) {
            Connect(nodes[a]->prev, nodes[c]);
            Connect(nodes[b], nodes[d]->next);
            Connect(nodes[d], nodes[a]);
        } else {
            Node *a_prev = nodes[a]->prev;
            Node *b_next = nodes[b]->next;
            Connect(nodes[c]->prev, nodes[a]);
            Connect(nodes[b], nodes[d]->next);
            Connect(a_prev, nodes[c]);
            Connect(nodes[d], b_next);
        }
    }

    PrintNode();

    return 0;
}