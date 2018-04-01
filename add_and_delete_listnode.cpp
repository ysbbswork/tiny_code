//链表的增删改查
//如果要删除的是第一个节点，需要改变链表的头指针，所以要用ListNode **phead,做参数，或者用ListNode *&phead做参数
//同样的道理，如果往一个空链表插入一个节点的话，新插入的节点即为头指针，仍然需要改变链表的头，所以也需要用ListNode **phead,做参数


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
void AddNode2(ListNode &head, int val) {//传入链表的第一个节点，前提是有至少一个节点的链表存在
    ListNode *newnode = new ListNode(val);
        ListNode *phead = &head;
        while (phead->next) {
            phead = phead->next;
        }
        phead->next = newnode;


}
void AddNode3(ListNode *head,int val) {//传入链表的头指针，当头指针为空的时候，无法处理！
    ListNode *newnode = new ListNode(val);
    if (head == NULL) {
        head = newnode;//这里只是改变了副本，实际并没有改变head，要改变就要用指针的引用AddNode3(ListNode *&head,int val)
    }
    else {
        while (head->next)
        {
            head = head->next;
        }
        head->next = newnode;
    }
}
//如果要删除的是第一个节点，头结点是要改变的，所以要用指针的引用
void RemoveNode(ListNode *&head, int value) {
    if (head == NULL) { return; }
    ListNode * tobedeleted_node = NULL;
    if (head->val == value) {
        tobedeleted_node = head;
        head =head->next;
    }
    else {
        ListNode *phead = head;
        while (phead->next != NULL&&phead->next->val != value) {
            phead = phead->next;
        }
        if (phead->next != NULL&&phead->next->val == value) {
            tobedeleted_node = phead->next;
            phead->next = phead->next->next;
        }
    }
    if (tobedeleted_node) {
        delete tobedeleted_node;
        tobedeleted_node = NULL;
    }

}


void PrintNode(ListNode * head) {
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }

}
int main() {
    //增测试
    ListNode *nullnode=NULL;
    AddNode(&nullnode,0);
    PrintNode(nullnode);
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    a.next = &b;
    b.next = &c;
    AddNode2(a,4);
    PrintNode(&a);
    ListNode *pnode = &a;
    AddNode(&pnode,99);
    PrintNode(&a);
    AddNode3(&a, 666);
    PrintNode(&a);
    //删测试
    cout << "删除测试" << endl;
    ListNode *onelist = NULL;
    AddNode(&onelist, 1);
    PrintNode(onelist);
    cout << "--------"<<endl;
    RemoveNode(onelist,1);
    PrintNode(onelist);
    cout << "--------" << endl;
    AddNode(&onelist, 1);
    AddNode(&onelist, 2);
    AddNode(&onelist, 3);
    AddNode(&onelist, 4);
    PrintNode(onelist);
    cout << "--------" << endl;
    RemoveNode(onelist, 4);
    PrintNode(onelist);
    cout << "--------" << endl;
    RemoveNode(onelist, 2);
    PrintNode(onelist);



    cin.get();
    return 0;
}
