#include "linearList.h"
using namespace std;
//顺序表打印
void sequenceList::print()
{
    cout << curNumberOfItem << ":";

    for(int i = 0; i < curNumberOfItem-1; i++)
    {
        cout << myList[i] << ",";
    }

    cout << myList[curNumberOfItem-1] << endl;
}
//顺序表构建
sequenceList::sequenceList(const int& a, const int& b, float c[] )//顺序表容量，初始化数组长度，初始化数组
{
    maxCapcity=a;
    myList=new float[a];
    curNumberOfItem=b;
    for(int s=0;s<b;s++)
    myList[s]=c[s];
}
sequenceList::~sequenceList(){}
bool sequenceList::addItem(const float& num)//添加元素顺序表尾，成功返回true，失败返回false
{
    if(myList!=NULL&&curNumberOfItem!=maxCapcity)
    {
        myList[curNumberOfItem]=num;
        curNumberOfItem++;
        return true;
    }
    return false;
}
bool sequenceList::insertItem(const int& location,const float& target)//插入元素target到location位置，成功返回true，失败返回false
{
    if(myList!=NULL&&location<maxCapcity&&location>-1)
    {
        myList[location]=target;
        return true;
    }
    return false;
}
int sequenceList::deleteItem(const float& target)//返回删除位置，找不到返回-1
{
    for(int j=0;j<maxCapcity;j++)
    {
        if(myList[j]==target)return j;
    }
    return -1;
}
bool sequenceList::locate(const int& location, float& val)
{
    if(lo)
}

















//链表打印
void linkList::print()
{
    curNode = firstNode;

    cout << listSize << ":";

    while(curNode != lastNode)
    {
        if(curNode->next == lastNode)
            cout << curNode->next->data << endl;
        else
        {
            cout << curNode->next->data << ",";
        }
        
        
        curNode = curNode->next;
    }
}

