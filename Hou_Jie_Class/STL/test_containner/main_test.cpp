#include "1_test_arrar.h"
#include "2_test_vector.h"
#include "3_test_list.h"
#include "4_test_forward_list.h"
#include "5_test_deque.h"
#include "6_test_stack.h"
#include "7_test_queue.h"
#include "8_test_multset.h"
#include "9_test_multimap.h"
#include "10_test_unorrdered_multiset&multimap.h"
#include "11_test_set&map.h"

void test_Vector(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_vector(value);
}

void test_List(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_list(value);
}

void test_Fward_list(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_forward_list(value);
}

void test_Deque(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_deque(value);
}

void test_Stack(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_stack(value);
}

void test_Queu(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_queue(value);
}

void test_Multset(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_multiset(value);
}

void test_Multimap(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_multimap(value);
}

void test_Unordered_multiset(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_unordered_multiset(value);
}

void test_Unordered_multimap(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_unordered_multimap(value);
}

void test_Map(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_map(value);

}
void test_Set(){
    long value;
    cout << "hou many elements: ";
    cin >> value;
    test_set(value);
}
int main(){
    cout << "main test-------------" << endl;
    int choice;
    cout << "your choice: 1-array, 2-vector, 3-list, 4-forward_list, 5-deque, 6-stack"
         << ",7-queue, 8-multiset, 9-multimap, 10-unordered_multiset, 11-unordered_multimap" 
         << ",12-set, 13-map" << endl;
    cin >> choice;
    switch(choice){
        case 1:
            test_array();
            break;
        case 2:
            test_Vector();
            break;
        case 3:
            test_List();
            break;
        case 4:
            test_Fward_list();
            break;
        case 5:
            test_Deque();
            break;
        case 6:
            test_Stack();
            break;
        case 7:
            test_Queu();
            break;
        case 8:
            test_Multset();
            break;
        case 9:
            test_Multimap();
            break;
        case 10:
            test_Unordered_multiset();
            break;
        case 11:
            test_Unordered_multimap();
            break;
        case 12:
            test_Set();
            break;
        case 13:
            test_Map();
            break;
        default:
            break;
    }
}
