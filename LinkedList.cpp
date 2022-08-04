#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int data;
    node *next;
};
class LinkedList
{
private:
    node *pHead;
    node *pTail;

public:
    LinkedList()
    {
        pHead = NULL;
        pTail = NULL;
    }
    node *createNode(int data)
    {
        node *p = new node;

        pNode->data = data;
        pNode->next = NULL;

        return p;
    }
    bool isEmpty(){
        return this->pHead == NULL && this->pTail == NULL;
    }
    void addFirstElement(int data){
        this->pHead = this->pTail = createNode(data);
    }
    void addAtTail(int data)
    {
        // nếu danh sách rỗng
        if (this->isEmpty())
            addFirstElement(data);
        else{
            node *p = createNode(data);
            pTail->next = p;
            pTail = p;
            p = NULL;
        }
    }
    void addAtHead(int data){
        // nếu danh sách rỗng
        if (this->isEmpty())
            addFirstElement(data);
        else{
            node *pNode = createNode(data);
            pNode->next = this->pHead->next
            pHead = pNode;
            pNode = NULL;
        }
    }
    void addAt(int k, int data){
        //con trỏ dùng để duyệt
        node* pNode = this->pHead;
        for(int i = 0; i < k-1; i++)
            pNode = pNode->next;

        //con trỏ trỏ tới node mới
        node* qNode = createNode(data);
        qNode->next = pNode->next;
        pNode->next = qNode;

        pNode = NULL;
        qNode = NULL;
    }
    
    bool deleteNode(int k)
    {
        node *p = pHead;
        //xoá phần tử đầu
        if(k == 0){
            pHead = pHead->next;
            delete p;
            p = NULL;
            return true;
        }

        for (int i = 0; i < k - 1; i++)
            p = p->next;

        node *temp = p->next;
        p->next = p->next->next;
        delete (temp);
        return pHead;
    }
    int dataAt(int index){
        node* p = this->pHead;
        for(int i = 0; i < index; i++)
            p = p->next;
        return p->data;
    }
    void inputList(int n)
    {
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            this->addAtTail(temp);
        }
    }
    void destroy(){
        node* p = NULL;
        while(this->pHead != NULL){
            p = this->pHead;
            this->pHead = this->pHead->next;
            delete p;
            p = NULL;
        }
    }
    void printList()
    {
        node *pNode = pHead;
        while (pNode != NULL)
        {
            cout << pNode->data << " ";
            pNode = pNode->next;
        }
        cout << "\n";
    }
};
int main()
{
    LinkedList list;
    int n;
    cin >> n;
    list.inputList(n);


    list.printList();
    return 0;
}