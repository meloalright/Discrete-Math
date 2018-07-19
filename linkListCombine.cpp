#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node * List(int d[], int n) {
    Node *head = new Node();
    head->value = d[0];
    Node *pre = head;
    Node *next = head;
    for(int i = 1; i < n; i++){
        Node * tmp = new Node();
        tmp->value = d[i];
        pre->next = tmp;
        pre = tmp;
    }
    return head;
}

Node * Combine(Node * list0, Node * list1) {

    Node *p0 = list0;
    Node *p1 = list1;
    Node *newList = NULL;
    Node *tmpNode = NULL;
    Node *pre = NULL;

    int sum = p0->value + p1->value;
    if (sum >= 10) {
        sum = sum - 10;
    }

    newList = new Node();

    newList->value = sum;
    pre = newList;

    while ((p0->next) && (p1->next)) {
        p0 = p0->next;
        p1 = p1->next;
        sum = p0->value + p1->value;
        if (sum >= 10) {
            sum = sum - 10;
        }
        tmpNode = new Node();
        tmpNode->value = sum;
        pre->next = tmpNode;
        pre = pre->next;
    }

    return newList;
}

int main(){
    int numList0[3] = {2, 4, 3};
    int numList1[3] = {5, 6, 4};
    Node *l0 = List(numList0, 3);
    Node *l1 = List(numList1, 3);

    Node *l = Combine(l0, l1);
    while (l) {
        cout << l->value << endl;
        l = l->next;
    }
    return 0;
}
