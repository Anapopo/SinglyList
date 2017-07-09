#include "SinglyList.h"

using namespace std;
//2-1
void test_compare()
{
    string person1[] = { "Anapopo", "Angus", "Aoso", "Aodoso", "Soit" };
    string person2[] = { "Anapopo", "Angus", "Aosoooooooooo", "Aodoso", "Soit" };
    SinglyList<string> list1(person1, 5);
    SinglyList<string> list2(person2, 5);

    cout << (list1 == list2) << endl;

}
//2-2
void test_contain()
{
    string person1[] = { "Anapopo", "Angus", "Aoso", "Aodoso", "Soit" };
    string person2[] = { "Anapopo", "Angus"};
    SinglyList<string> list1(person1, 5);
    SinglyList<string> list2(person2, 2);

    cout << list1.contain(list2) << endl;


}
//2-3
void test_sub()
{
	string person[] = {"Anapopo", "Angus", "Aoso", "Aodoso", "Soit"};
	SinglyList<string> list1(person, 5);

    SinglyList<string> list2 = list1.sub(1, 3);
    list2.printAll();
}
//2-4
void test_insert()
{
    string person[] = { "Anapopo", "Angus", "Aoso"};
    string fruit[] = { "Apple", "Orange" };

    SinglyList<string> list1(person, 3);
    SinglyList<string> list2(fruit, 2);

    SinglyList<string> list3 = list1.insert(1, list2);
    list3.printAll();
}
//2-5
void test_plus()
{
    string person[] = { "Anapopo", "Anapopo", "Angus", "Aoso", "Aodoso", "Soit" };
    string fruit[] = { "Anapopo", "Apple", "Orange", "Watermelon", "Aoso", "Aodoso", "Soit"};
    SinglyList<string> list1(person, 6);
    SinglyList<string> list2(fruit, 7);
    
    SinglyList<string> list3 = list1 + list2;
    list3.printAll();
}
//2-6
void test_remove()
{
    string person[] = { "Anapopo", "Angus", "Aoso", "Aodoso", "Soit" };
    SinglyList<string> list1(person, 5);

    SinglyList<string> list2 = list1.remove(2,2);
    list1.printAll();
    list2.printAll();
}
//2-12
void test_removeAll()
{
    string person[] = { "Anapopo", "Angus", "Aoso", "Aodoso", "Soit" };
    string fruit[] = { "Angus", "Aodoso" };
    SinglyList<string> list1(person, 5);
    SinglyList<string> list2(fruit, 2);

    list1.removeAll(list2);
    list1.printAll();
}
//2-13
void test_replaceAll()
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
//2-14
void josephus(int num, int start, int distance)
{

    char person[] = { 'A','B','C','D','E' };
    SinglyList<char> list(person, 5);
    int i = start;
    while (list.count() > 1) {
        i = (i + distance - 1) % list.count();
        cout << "i:" << i << " ";
        cout << list.remove(i) << " is killed. These People survive:";
        
        list.printAll();
    }
}

int main()
{   
    //test_compare();//2-1
    //test_contain();//2-2
    //test_sub();//2-3
    //test_insert();//2-4
    //test_plus();//2-5
    test_remove();//2-6
    //test_removeAll();//2-12
    //test_replaceAll();//2-13
    //josephus(5,0,2);//2-14
    return 0;
}

