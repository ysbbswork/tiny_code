//反向打印链表两种方法，启示：递归本身就是个栈结构。用栈可以的，试试用递归
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int number) :val(number), next(NULL) {

    }
};

void AddNode(ListNode **head, int val) {
    ListNode *newnode = new ListNode(val);
    if (*head == NULL) {
        *head = newnode;
    }
    else {
        ListNode *phead = *head;
        while (phead->next) {
            phead = phead->next;
        }
        phead->next = newnode;

    }
}




void PrintNode(ListNode * head) {
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }

}

//反向打印链表的值
#include<stack>
void PrintListFromTail(ListNode *head) {
    std::stack<ListNode*> s;
    while (head) {
        s.push(head);
        head = head->next;
    }
    while (!s.empty()) {
        cout << s.top()->val << endl;
        s.pop();
    }
}

//反向打印链表的值,使用递归实现，因为递归本身就是个栈结构
void PrintListFromTail2(ListNode *head) {
    if(head == NULL){return; }
    PrintListFromTail2(head->next);
    cout << head->val << endl;
}
int main() {

    ListNode *nodelist = NULL;
    AddNode(&nodelist, 1);
    AddNode(&nodelist, 2);
    AddNode(&nodelist, 3);
    AddNode(&nodelist, 4);
    PrintListFromTail(nodelist);
    PrintListFromTail2(nodelist);
    cin.get();
    return 0;
}
