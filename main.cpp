#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    while (head) {
        Node* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

Node* addTwoLists(Node* head1, Node* head2) {
    head1 = reverse(head1);
    head2 = reverse(head2);

    int carry = 0;
    Node* dummy = new Node(0);
    Node* tail = dummy;

    while (head1 || head2 || carry) {
        int sum = carry;
        if (head1) { sum += head1->data; head1 = head1->next; }
        if (head2) { sum += head2->data; head2 = head2->next; }

        tail->next = new Node(sum % 10);
        tail = tail->next;
        carry = sum / 10;
    }

    Node* result = reverse(dummy->next);

    while (result && result->data == 0 && result->next)
        result = result->next;

    return result;
}

Node* buildList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* node = new Node(x);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n1, n2;

    cout << "Enter number of digits for first number: ";
    cin >> n1;
    cout << "Enter digits for first number (space separated): ";
    Node* head1 = buildList(n1);

    cout << "Enter number of digits for second number: ";
    cin >> n2;
    cout << "Enter digits for second number (space separated): ";
    Node* head2 = buildList(n2);

    Node* result = addTwoLists(head1, head2);

    cout << "Result: ";
    printList(result);
}