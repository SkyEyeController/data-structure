#include "linearList.h"
#include<bits/stdc++.h>
using namespace std;
bool compare(float a,float b)
{
    return b-a>1e-8;
}
// 顺序表打印
void sequenceList::print()
{
    cout << curNumberOfItem << ":";

    for (int i = 0; i < curNumberOfItem - 1; i++)
    {
        cout << myList[i] << ",";
    }

    cout << myList[curNumberOfItem - 1] << endl;
}
// 顺序表构建
sequenceList::sequenceList(const int &a, const int &b, float c[]) // 顺序表容量，初始化数组长度，初始化数组
{
    maxCapcity = a;
    myList = new float[a];
    curNumberOfItem = b;
    for (int s = 0; s < b; s++)
    {
        myList[s] = c[s];
    }
}
sequenceList::~sequenceList() {}
bool sequenceList::addItem(const float &num) // 添加元素顺序表尾，成功返回true，失败返回false
{
    if (myList != NULL && curNumberOfItem != maxCapcity)
    {
        myList[curNumberOfItem] = num;
        curNumberOfItem++;
        return true;
    }
    return false;
}
bool sequenceList::insertItem(const int &location, const float &target) // 插入元素target到location位置，成功返回true，失败返回false
{
    if (myList != NULL && location <= curNumberOfItem && curNumberOfItem < maxCapcity && location > -1)
    {
        curNumberOfItem++;
        for (int i = location; i < curNumberOfItem - 1; i++)
            myList[location + 1] = myList[location];
        myList[location] = target;
        return true;
    }
    return false;
}
int sequenceList::deleteItem(const float &target) // 返回删除位置，找不到返回-1
{
    for (int j = 0; j < curNumberOfItem; j++)
    {
        if (myList[j] == target)
        {
            curNumberOfItem--;
            for (int i = j; i < curNumberOfItem; i++)
            {
                myList[i] = myList[i + 1];
            }
            return j;
        }
    }
    return -1;
}
bool sequenceList::locate(const int &location, float &val)
{
    if (location > -1 && location < curNumberOfItem)
    {
        val = myList[location];
        return true;
    }
    return false;
}

int sequenceList::locate(const float &num)
{
    for (int i = 0; i < curNumberOfItem; i++)
    {
        if (myList[i] == num)
            return i;
    }
    return -1;
}

void sequenceList::reverse()
{
    for (int i = 0, j = curNumberOfItem - 1; i <= j; i++, j--)
    {
        float s=myList[j];
        myList[j]=myList[i];
        myList[i]=s;
    }
}
// 链表打印
void linkList::print()
{
    curNode = firstNode;

    cout << listSize << ":";

    while (curNode != lastNode)
    {
        if (curNode->next == lastNode)
            cout << curNode->next->data << endl;
        else
        {
            cout << curNode->next->data << ",";
        }

        curNode = curNode->next;
    }
}
linkList::linkList(const int &a, float b[])
{
    listSize = a;
    firstNode = new listNode;
    firstNode->next=new listNode;
    listNode *head = firstNode->next;
    for (int i = 0; i < a - 1; i++)
    {
        head->data = b[i];
        head->next = new listNode;
        head = head->next;
    }
    head->data = b[a - 1];
    lastNode = head;

}
linkList::~linkList() {}
bool linkList::headInsertItem(const float &num)
{
    listSize++;
    listNode *p = new listNode;
    p->data = num;
    p->next = firstNode->next;
    firstNode->next = p;
    return true;
}
bool linkList::tailInsertItem(const float &num)
{
    listSize++;
    listNode *p = new listNode;
    p->data = num;
    lastNode->next = p;
    lastNode = p;
    return true;
}
int linkList::insertItem(const int &location, const float &num)
{
    if (location > -1 && location < listSize)
    {
        curNode = firstNode->next;
        for (int i = 1; i <= location - 1; i++)
        {
            curNode = curNode->next;
        }
        listNode *target = new listNode;
        target->data = num;
        target->next = curNode->next;
        curNode->next = target;
        listSize++;
        return location;
    }
    return -1;
}
int linkList::deleteItem(const float &num)
{
    int ans = 0;
    listNode *p = firstNode->next;
    while (p->data == num)
    {
        listSize--;
        firstNode->next = p->next;
        p = firstNode->next;
        ans=0;
        return ans;
    }
    listNode *beforep = p;
    p = p->next;
    for (int i = 1; i < listSize - 1; i++, beforep = p, p = p->next)
    {
        while (p->data == num)
        {
            listSize--;
            beforep->next = p->next;
            p = p->next;
            ans=i;
            return ans;
        }
    }
    while (lastNode->data == num)
       {p->next = NULL;return listSize-1;}
    return ans;
}
bool linkList::locate(const int &location, float &val)
{
    if (location > -1 && location < listSize)
    {
        curNode = firstNode->next;
        for (int i = 1; i <= location; i++)
        {
            curNode = curNode->next;
        }
        val=curNode->data;
        return true;
    }
    return false;
}
int linkList::locate(const float& num)//按值查找
{
    curNode=firstNode->next;
    int i=0;
    while(curNode->data!=num&&curNode->next!=NULL)
    {
        i++;
        curNode=curNode->next;
    }
    if(curNode->next==NULL)return -1;
    return i;

}                 
void linkList::ascendingOrder()
{
    float *a=new float[listSize];
    curNode=firstNode->next;
    for(int i=0;i<listSize-1;i++,curNode=curNode->next)
    {
        a[i]=curNode->data;
    }
    a[listSize-1]=curNode->data;
    sort(a,a+listSize,compare);
    curNode=firstNode->next;
    for(int i=0;i<listSize-1;i++,curNode=curNode->next)
    {
        curNode->data=a[i];
    }
    curNode->data=a[listSize-1];
    delete[] a;
}
void linkList::reverse()
{
    listNode *ahead=firstNode->next;
    listNode *targetnow=ahead;
    listNode *before=NULL;
    while(targetnow!=NULL)
    {
        ahead=targetnow->next;
        targetnow->next=before;
        before=targetnow;
        targetnow=ahead;
    }
    lastNode=firstNode->next;
    firstNode->next=before;
}
void merge(linkList& a, linkList& b)
{
    a=a+b;
    a.ascendingOrder();
    a.reverse();
    return;
}