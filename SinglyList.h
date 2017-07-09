#include <iostream>
#include "Node.h"
using namespace std;
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
    //2-12 ���
    void removeAll(SinglyList<T> &pattern);
    //2-13 ����
    void replaceAll(SinglyList<T> &pattern, SinglyList<T> &list);

	bool operator!=(SinglyList<T> &list);
	void operator=(SinglyList<T> &list);//SinglyList<T>& operator=(SinglyList<T> &list);
	
};

//���캯��
template <class T>
SinglyList<T>::SinglyList()
{ 
	this->head = new Node<T>();
}
//���캯��
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
//���ƹ��캯��
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
//��������
template <class T>
SinglyList<T>::~SinglyList() 
{
	this->removeAll();
	delete this->head;
}
//�ж��Ƿ��
template <class T>
bool SinglyList<T>::empty() { return (this->head->next == nullptr); }
//��ȡ������
template <class T>
int SinglyList<T>::count()
{   
    int count = 0;
    Node<T> *start = this->head;
    while (start->next)
    {   
        count++;
        start = start->next;//��λ�����һλԪ��
    }
    return count;
}
//��ȡԪ��
template <class T>
T& SinglyList<T>::get(int i)
{   

    if (i < 0) i = 0;//����ݴ�
	Node<T> *current = this->head->next;

	for (int j = 0; current != nullptr && j < i; j++) current = current->next;
	
	if (current) return current->data;
	
	throw std::out_of_range("Your get() function can not find the specify element.");
}
//����Ԫ��
template <class T>
Node<T>* SinglyList<T>::insert(int i, T x)
{
	Node<T> *front = this->head;
	for (int j = 0; front->next != nullptr && j < i; j++) front = front->next;

	front->next = new Node<T>(x, front->next);
	return front->next;
}
//β������Ԫ��
template <class T>
Node<T>* SinglyList<T>::insert(T x){
	Node<T> *front = this->head;

    while (front->next) front = front->next;

	front->next = new Node<T>(x);

	return front->next;
}
//�趨Ԫ��
template <class T>
void SinglyList<T>::set(int i, T x) {
	Node<T> *front = this->head;
	for (int j = 0;front->next != nullptr && j < i; j++) front = front->next;//ָ���(i-1)λԪ��
	front->next->data = x;//����iλԪ�ظ�ֵx
}
//����Ԫ�� �����ҵ���Ԫ�ص�ǰһ���
template<class T>
Node<T>* SinglyList<T>::search(T value)
{
	Node<T> *front = this->head;
	//head | A | B | C | nullptr 
	while (front->next && front->next->data != value) front = front->next;

	return (front->next && front->next->data == value) ? front : nullptr;
}
//��ӡ����Ԫ��
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
//�Ƴ�ָ��Ԫ��
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
//�Ƴ�����Ԫ��
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
//ɾ��*this��������patternƥ����ӱ�����ģʽƥ��
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
            remember = remember->next;//rememberָ�������ƶ�
            rear = pattern.head->next;//rear��λ
            current = remember->next;
        }

        if (!rear)//�ҵ�ƥ�����
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

            current = current->next;//current�ƶ�����һλ
            rear = pattern.head->next;//rearָ���λ
        }
    }
}
//���������ӣ���ձ����ӵı�
template<class T>
void SinglyList<T>::operator+=(SinglyList<T> &list) {

	Node<T> *rear = this->head;
	while (rear->next)
		rear = rear->next;
	rear->next = list.head->next;
	list.head->next = nullptr;

}
//����=�ĺ���
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
//�ж������������Ƿ����
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

	return (!p && !q) ? true : false;
}
//�ж������������Ƿ񲻵�
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
//�ж�*this�Ƿ����list�����н��
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
//���شӵ�i����㿪ʼ������Ϊn���ӱ�
template <class T>
SinglyList<T> SinglyList<T>::sub(int i, int n)
{   
    SinglyList<T> list;//�½�һ��������
    int length = this->count();
    if (i < 0 || i >= length) return list;//����ݴ���
    if ((length - i) < n) n = (length - i);//����ݴ���

    Node<T> *start = this->head->next;
    for (int j = 0; start != nullptr && j < i; j++) start = start->next;//��λ����i��Ԫ��
    
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
//���ظ��Ƶ�*this���������i�����ǰ����list�����н�㣬���ı�*this��list
template <class T>
SinglyList<T> SinglyList<T>::insert(int i, SinglyList<T> &list)
{   
    SinglyList<T> raw(*this);
    SinglyList<T> extra(list);

    Node<T> *start = raw.head;
    if (i > 0 && start->next != nullptr) {
        for (int j = 0; start != nullptr && j < i; j++) 
            start = start->next;//��start = ��(i-1)��Ԫ�ص��ڴ��ַ
    }
    Node<T> *temp = start->next;//��temp = ��i��Ԫ�ص��ڴ��ַ

    start->next = extra.head->next;//�۽���������

    extra.head->next = nullptr;//���ͷ�extra����ָ��

    Node<T> *p = start->next;
    while (p->next) p = p->next;
    p->next = temp;//�ݸ��½����������β

    return raw;
}
//������*this������list�����н�����������
template <class T>
SinglyList<T> SinglyList<T>::operator+(SinglyList<T> &list)
{
    SinglyList<T> raw(*this);
  
    Node<T> *rear = raw.head;
    while (rear->next) rear = rear->next;//rear��λ�����һ��Ԫ��

    Node<T> *current = list.head;

    while (current->next) {

        if (!raw.search(current->next->data)) {//��������ڴ�Ԫ��
            rear->next = new Node<T>(current->next->data);
            rear = rear->next;
        }
        current = current->next;
    }
    return raw;
}
//����ɾ���Ĵӵ�i����㿪ʼ������Ϊn�ӱ�
template <class T>
SinglyList<T> SinglyList<T>::remove(int i, int n)//todo
{
    SinglyList<T> list;//�½�һ���µ�����
    Node<T> *front = this->head;//frontָ��ָ��ͷ�ڵ�
    for (int j = 0; front != nullptr && j < i; j++) front = front->next;//frontָ�붨λ����(i-1)��Ԫ��

    Node<T> *rear = list.head;//rearָ��ָ���������ͷ���

    rear->next = front->next;

    Node<T> *temp = front;

    while (n)
    {
        front = front->next;
        n--;
    }

    rear->next = temp->next;

    temp->next = front->next;

    front->next = nullptr;

    return list;
}
//��*this��������patternƥ���ӱ��滻Ϊlist������ģʽƥ��
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

        else //�Ƚ���Ԫ�ز���
        {   

            remember = remember->next;//rememberָ�������ƶ�
            rear = pattern.head->next;//pattern����ָ��ص���һ��Ԫ��
            current = remember->next;
        }

        if (!rear)//�ҵ�ƥ�����
        {   
            current = remember;
            rear = pattern.head->next;//rearָ��pattern��һ��Ԫ��

            while (rear) //currentָ�벻�� ��ɾ�� pattern���ȵ�Ԫ��
            {
                Node<T> *temp = current->next;
                current->next = current->next->next;
                delete temp;
                rear = rear->next;
            }

            while (replace) //��ɾ���������Ԫ��
            {
                current->next = new Node<T>(replace->data, current->next);
                current = current->next;
                replace = replace->next;
            }

            remember = current;//�ƶ�rememberָ�뵽currentָ���λ��
            current = current->next;//current�ƶ���rememberָ���һλ
            replace = list.head->next;//ָ���λ
            rear = pattern.head->next;//ָ���λ
        }
    }
}
