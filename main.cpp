#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "include/list/listheader.h"
// #include "include/list/XArrayListDemo.h"
// #include "include/list/DLinkedListDemo.h"
// #include "include/ann/dataset.h"
// #include "include/ann/dataloader.h"
// #include "include/ann/funtions.h"
// #include "include/ann/xtensor_lib.h"
// #include "include/util/Point.h"

void dlistDemo1(){
    List<int> dlist;
    for(int i = 0; i< 20 ; i++)
        dlist.add(i, i*i);
    dlist.println();
    for(List<int>::Iterator it=dlist.begin(); it != dlist.end(); it++ )
        cout << *it << " ";
    cout << endl;
}

void dlistDemo2() {
    DLinkedList<int*> list1(&DLinkedList<int*>::free);
    list1.add(new int(23));
    list1.add(new int(24));
    list1.add(new int(12));
    // ...

    for(DLinkedList<int*>::Iterator it = list1.begin(); it != list1.end(); it++)
        cout << **it << endl;
  
    int* p1 = new int(24); //found in list
    int* p2 = new int(124); //not found
    cout << *p1 << "=> " << (list1.contains(p1)? "found; " : "not found; ")
                << " indexOf returns: " << list1.indexOf(p1) << endl;
    cout << *p2 << "=> " << (list1.contains(p2)? "found; " : "not found; ")
                << " indexOf returns: " << list1.indexOf(p2) << endl;

    delete p1; delete p2;
}

bool intComparator(int*& p1, int*& p2) {
    return *p1 == *p2;
}

string LintPtr2Str(int*& ptr) {
    stringstream os;
    os << *ptr;
    return os.str();
}

void dlistDemo4() {
    DLinkedList<int*> dList(&DLinkedList<int*>::free, &intComparator);
    dList.add(new int(1));
    dList.add(new int(2));
    dList.add(new int(1));
    dList.println(&LintPtr2Str);

    cout << "test for indexOf: " << endl;
    int* p = new int(1);
    cout << *p << " at: " << dList.indexOf(p) << endl;
    delete p;
}

int main() {
    dlistDemo1();
    dlistDemo2();
    // dlistDemo4();
    return 0;
}