#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
};

Node *head, *tail, *cur, *del, *newnode, *maha;

void in() {
    head = NULL;
    tail = NULL;
}

