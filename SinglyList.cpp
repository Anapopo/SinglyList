#include "stdafx.h"
using namespace std;

void josephus(int num, int start, int distance) {

	char person[] = { 'A','B','C','D','E' };
	SinglyList<char> list(person, 5);
	int i = start;
	while (list.count() > 1) {
		i = (i + distance - 1) % list.count();
		cout << list.get(i) << " is killed. These People survive:";
		list.remove(i);
		list.printAll();
	}
}

void testf()
{
	string person[] = {"Anapopo", "Angus", "Aoso", "Aodoso", "Soit"};
	string fruit[] = {"Apple","Orange","Watermelon"};
    string fakefruit[] = { "Apple","Orange"};
	SinglyList<string> list1(person, 5);
    SinglyList<string> list2 = list1.sub(1, 3);
    list2.printAll();

}

void testd()
{
    string person[] = { "Anapopo", "Angus", "Aoso", "Aodoso", "Soit" };
    string fruit[] = { "Apple", "Orange", "Watermelon", "Aoso", "Aodoso", "Soit"};

    SinglyList<string> list1(person, 5);
    SinglyList<string> list2(fruit, 6);
    
    SinglyList<string> list3 = list1 + list2;
    list3.printAll();
}

void teste()
{
    string person[] = { "Anapopo", "Angus", "Aoso", "Aodoso", "Soit" };
    string fruit[] = { "Angus", "Aodoso"};

    SinglyList<string> list1(person, 5);
    SinglyList<string> list2(fruit, 2);

    list1.removeAll(list2);
    list1.printAll();
    
}

void testg()
{
    string person[] = { "Anapopo", "Angus", "Aoso", "Aodoso", "Soit" };
    SinglyList<string> list1(person, 5);

    SinglyList<string> list3 = list1.remove(1,2);

    list1.printAll();
    list3.printAll();
}

void testh()
{
    char raw1[] = { 'A', 'B', 'C', 'D', 'E', 'B', 'C'};
    
    char pattern1[] = { 'B', 'C'};

    char replace1[] = { 'f', 'g', 'h'};


    SinglyList<char> raw(raw1, 7);
    SinglyList<char> pattern(pattern1, 2);
    SinglyList<char> replace(replace1, 3);

    raw.replaceAll(pattern,replace);

    raw.printAll();

    
}

int main()
{
	//josephus(5, 0, 2);
	testh();
    return 0;
}

