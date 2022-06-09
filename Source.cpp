#include "Header.h"

int main()
{
    LIST l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.print();
    cout << l.FIRST() << endl;
    cout << l.END() << endl;
    l.pop_front();
    l.print();
    l.INSERT(0, 0);
    l.print();
    l.DELETE(1);
    l.print();
    l.DELETE(2);
    l.print();
    cout << l.LOCATE(2) << endl;
    cout << l.RETRIEVE(2) << endl;
    cout << l.NEXT(2) << endl;
    cout << l.FIRST() << endl;
    cout << l.END() << endl;
}
