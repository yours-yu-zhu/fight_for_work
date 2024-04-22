#include "1_test_arrar.h"
#include "2_test_vector.h"

void test_Vector(){
    long value;
    cout << "hou mant elements: ";
    cin >> value;
    test_vector(value);
}

int main(){
    //test_array();
    test_Vector();
    return 0;
}
