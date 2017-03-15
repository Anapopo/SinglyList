#include <iostream>
#include "Node.h"
template <class T>
class SinglyList
{
public:
	Node<T> *head;

	SinglyList();
	SinglyList(T values[], int n);
	SinglyList(SinglyList<T> &list);
	~SinglyList();

	bool empty();
	int count();

	T& get(int i);
    Node<T>* search(T value);
	void set(int i,T x);//virtual
	
	
	Node<T>* insert(int i, T x);
	Node<T>* insert(T x);

	T remove(int i);

	void removeAll();

	

	void printAll();//friend ostream& std::operator<<<>(ostream&, SinglyList<T>&);

	void operator+=(SinglyList<T> &list);//virtual
	//2-1
	bool operator==(SinglyList<T> &list);
	//2-2
	bool contain(SinglyList<T> &list);
    //2-3
    SinglyList<T> sub(int i, int n);
    //2-4
    SinglyList<T> insert(int i, SinglyList<T> &list);
    //2-5
    SinglyList<T> operator+(SinglyList<T> &list);
    //2-6
    SinglyList<T> remove(int i, int n);
    //2-12 ★★
    void removeAll(SinglyList<T> &pattern);
    //2-13 ★★★
    void replaceAll(SinglyList<T> &pattern, SinglyList<T> &list);

	bool operator!=(SinglyList<T> &list);
	void operator=(SinglyList<T> &list);//SinglyList<T>& operator=(SinglyList<T> &list);
	
};

//构造函数
template <class T>
SinglyList<T>::SinglyList()
{ 
	this->head = new Node<T>();
}
//构造函数
template <class T>
SinglyList<T>::SinglyList(T values[], int n)
{
	this->head = new Node<T>();
	Node<T> *rear = this->head;
	for (int i = 0; i<n; i++) {
		rear->next = new Node<T>(values[i]);
		rear = rear->next;
	}
}
//复制构造函数
template <class T>
SinglyList<T>::SinglyList(SinglyList<T> &list) {
	this->head = new Node<T>();
	Node<T> *rear = this->head;
	Node<T> *other = list.head->next;

	while(other)
	{
		rear->next = new Node<T>(other->data, rear->next);
		rear = rear->next;
		other = other->next;
	}
}
//析构函数
template <class T>
SinglyList<T>::~SinglyList() 
{
	this->removeAll();
	delete this->head;
}
//判断是否空
template <class T>
bool SinglyList<T>::empty() { return (this->head->next == nullptr); }
//获取链表长度
template <class T>
int SinglyList<T>::count()
{   
    int count = 0;
    Node<T> *start = this->head;
    while (start->next)
    {   
        count++;
        start = start->next;//定位到最后一位元素
    }
    return count;
}
//获取元素
template <class T>
T& SinglyList<T>::get(int i)
{   

    if (i < 0) i = 0;//提高容错
	Node<T> *current = this->head->next;

	for (int j = 0; current != nullptr && j < i; j++) current = current->next;
	
	if (current) return current->data;
	
	throw std::out_of_range("Your get() function can not find the specify element.");
}
//插入元素
template <class T>
Node<T>* SinglyList<T>::insert(int i, T x)
{
	Node<T> *front = this->head;
	for (int j = 0; front->next != nullptr && j < i; j++) front = front->next;

	front->next = new Node<T>(x, front->next);
	return front->next;
}
//尾部插入元素
template <class T>
Node<T>* SinglyList<T>::insert(T x){
	Node<T> *front = this->head;

    while (front->next) front = front->next;

	front->next = new Node<T>(x);

	return front->next;
}
//设定元素
template <class T>
void SinglyList<T>::set(int i, T x) {
	Node<T> *front = this->head;
	for (int j = 0;front->next != nullptr && j < i; j++) front = front->next;//指向第(i-1)位元素
	front->next->data = x;//给第i位元素赋值x
}
//查找元素 返回找到的元素的前一结点
template<class T>
Node<T>* SinglyList<T>::search(T value)
{
	Node<T> *front = this->head;
	//head | A | B | C | nullptr 
	while (front->next && front->next->data != value) front = front->next;

	return (front->next && front->next->data == value) ? front : nullptr;
}
//打印所有元素
template <class T>
void SinglyList<T>::printAll()
{
	std::cout << "(";
    Node<T> *front = this->head;

    while (front->next)
    {
        std::cout << front->next->data;
        if (front->next->next) std::cout << ",";

        front = front->next;
    }
    std::cout << ")length:" << this->count() << std::endl;

}
//移除指定元素
template <class T>
T SinglyList<T>::remove(int i)
{   
	Node<T> *front = this->head;

	for (int j = 0; front->next && j < i; j++) front = front->next;

	if (i >= 0 && front->next)
    {   
        Node<T> *temp = front->next;
		T old = front->next->data;
		front->next = front->next->next;
		delete temp;
		return old;
	}
	throw std::out_of_range("Your get() function can not find the specify element.");
}
//移除所有元素
template <class T>
void SinglyList<T>::removeAll()
{
	Node<T>* front = this->head;
	while (front->next)
	{
		Node<T>* temp = front->next;
        front->next = front->next->next;
		delete temp;
	}

	this->head->next = nullptr;
}
//删除*this中所有与pattern匹配的子表，包含模式匹配
template <class T>
void SinglyList<T>::removeAll(SinglyList<T> &pattern)
{   
    Node<T> *remember = this->head;
    Node<T> *current = this->head->next;
    Node<T> *rear = pattern.head->next;

    while (current)
    {
        if (current->data == rear->data)
        {
            rear = rear->next;
            current = current->next;
        }
        else
        {
            remember = remember->next;//remember指针往后移动
            rear = pattern.head->next;//rear归位
            current = remember->next;
        }

        if (!rear)//找到匹配的啦
        {
            current = remember;
            rear = pattern.head->next;

            while (rear)
            {
                Node<T> *temp = current->next;
                current->next = current->next->next;
                delete temp;
                rear = rear->next;
            }

            current = current->next;//current移动到下一位
            rear = pattern.head->next;//rear指针归位
        }
    }
}
//单链表连接（清空被连接的表）
template<class T>
void SinglyList<T>::operator+=(SinglyList<T> &list) {

	Node<T> *rear = this->head;
	while (rear->next)
		rear = rear->next;
	rear->next = list.head->next;
	list.head->next = nullptr;

}
//重载=的函数
template <class T>
void SinglyList<T>::operator=(SinglyList<T> &list)
{
	this->head = new Node<T>();

	Node<T> *rear = this->head;

	Node<T> *other = list.head->next;

	while (other)
	{
		rear->next = new Node<T>(other->data, rear->next);
		rear = rear->next;
		other = other->next;
	}
}
//判断两条单链表是否相等
template <class T>
bool SinglyList<T>::operator==(SinglyList<T> &list)
{
	if (this->head == list.head) return true;

	Node<T> *p = this->head->next;
	Node<T> *q = list.head->next;
	while (p&&q)
	{
		if (p->data != q->data) return false;
		p = p->next;
		q = q->next;
	}

	return (p == nullptr && q == nullptr) ? true : false;
}
//判断两条单链表是否不等
template <class T>
bool SinglyList<T>::operator!=(SinglyList<T> &list)
{
	if (this->head == list.head) return false;

	Node<T> *p = this->head->next;
	Node<T> *q = list.head->next;
	while (p&&q)
	{
		if (p->data != q->data) return true;
		p = p->next;
		q = q->next;
	}

	return (p == nullptr && q == nullptr) ? false : true;
}
//判断*this是否包含list的所有结点
template <class T>
bool SinglyList<T>::contain(SinglyList<T> &list)
{   
    Node<T> *rear = list.head->next;

    while (rear) {
        if (!this->search(rear->data)) return false;
        rear = rear->next;
    }
    return true;
}
//返回从第i个结点开始、长度为n的子表
template <class T>
SinglyList<T> SinglyList<T>::sub(int i, int n)
{   
    SinglyList<T> list;//新建一个新链表
    int length = this->count();
    if (i < 0 || i >= length) return list;//提高容错性
    if ((length - i) < n) n = (length - i);//提高容错性

    Node<T> *start = this->head->next;
    for (int j = 0; start != nullptr && j < i; j++) start = start->next;//定位到第i个元素
    
    Node<T> *rear = list.head;

    while (n)
    {
        rear->next = new Node<T>(start->data);
        rear = rear->next;
        start = start->next;
        n--;
    }
    return list;
}
//返回复制的*this，并在其第i个结点前插入list的所有结点，不改变*this和list
template <class T>
SinglyList<T> SinglyList<T>::insert(int i, SinglyList<T> &list)
{   
    SinglyList<T> raw(*this);
    SinglyList<T> extra(list);

    Node<T> *start = raw.head;
    if (i > 0 && start->next != nullptr) {
        for (int j = 0; start != nullptr && j < i; j++) 
            start = start->next;//①start = 第(i-1)个元素的内存地址
    }
    Node<T> *temp = start->next;//②temp = 第i个元素的内存地址

    start->next = extra.head->next;//③接入新链表

    extra.head->next = nullptr;//④释放extra链表指针

    Node<T> *p = start->next;
    while (p->next) p = p->next;
    p->next = temp;//⑤给新接入的链表收尾

    return raw;
}
//返回在*this最后添加list中所有结点的链表，并集
template <class T>
SinglyList<T> SinglyList<T>::operator+(SinglyList<T> &list)
{
    SinglyList<T> raw(*this);
  
    Node<T> *rear = raw.head;
    while (rear->next) rear = rear->next;//rear定位到最后一个元素

    Node<T> *current = list.head;

    while (current->next) {

        if (!raw.search(current->next->data)) {//如果不存在此元素
            rear->next = new Node<T>(current->next->data);
            rear = rear->next;
        }
        current = current->next;
    }
    return raw;
}
//返回删除的从第i个结点开始、长度为n子表
template <class T>
SinglyList<T> SinglyList<T>::remove(int i, int n)//todo
{
    SinglyList<T> list;//新建一个新的链表
    Node<T> *front = this->head;//front指针指向头节点
    for (int j = 0; front != nullptr && j < i; j++) front = front->next;//front指针定位到第(i-1)个元素

    Node<T> *rear = list.head;//rear指针指向新链表的头结点

    while (n)//当n不等于0时执行
    {
        rear->next = new Node<T>(front->next->data);//给新链表接上新的结点

        rear = rear->next;//rear指针往后推

        Node<T> *temp = front->next;//temp指向第i个元素的内存地址
        front->next = front->next->next;//front->next指向第(i+1)个元素的内存地址
        delete temp;//删除原来的第i个元素

        n--;//要操作的结点数减一
    }
    return list;
}
//将*this中所有与pattern匹配子表替换为list，包含模式匹配
template <class T>
void SinglyList<T>::replaceAll(SinglyList<T> &pattern, SinglyList<T> &list)
{   
   
    Node<T> *remember = this->head;
    Node<T> *current = this->head->next;

    Node<T> *rear = pattern.head->next;

    Node<T> *replace = list.head->next;
    

    while (current)
    {
        if (current->data == rear->data)
        {
            current = current->next;
            rear = rear->next;
        }

        else //比较两元素不等
        {   

            remember = remember->next;//remember指针往后移动
            rear = pattern.head->next;//pattern链表指针回到第一个元素
            current = remember->next;
        }

        if (!rear)//找到匹配的啦
        {   
            current = remember;
            rear = pattern.head->next;//rear指向pattern第一个元素

            while (rear) //current指针不动 ，删除 pattern长度的元素
            {
                Node<T> *temp = current->next;
                current->next = current->next->next;
                delete temp;
                rear = rear->next;
            }

            while (replace) //给删除部分添加元素
            {
                current->next = new Node<T>(replace->data, current->next);
                current = current->next;
                replace = replace->next;
            }

            remember = current;//移动remember指针到current指针的位置
            current = current->next;//current移动到remember指针后一位
            replace = list.head->next;//指针归位
            rear = pattern.head->next;//指针归位
        }
    }
}
