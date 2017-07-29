#include "SinglyList.h"

using namespace std;

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
    josephus(5,0,2);
    return 0;
}


