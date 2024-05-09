#include <bits/stl_tree.h>
#include <iostream>
using namespace std;

int main(){
    cout << "\ntest_Rb_tree().......... \n";
    _Rb_tree<int, int, _Identity<int>, less<int>> itree;
    cout << itree.empty() << endl;
    cout << itree.size() << endl;
    itree._M_insert_unique(3);
	itree._M_insert_unique(8);
	itree._M_insert_unique(5);
	itree._M_insert_unique(9);
	itree._M_insert_unique(13);
	itree._M_insert_unique(5);  //no effect, since using insert_unique().
	cout << itree.empty() << endl;  //0
	cout << itree.size() << endl;   //5
	cout << itree.count(5) << endl; //1

	itree._M_insert_equal(5);
	itree._M_insert_equal(5);
	cout << itree.size() << endl;   //7, since using insert_equal().
	cout << itree.count(5) << endl; //3   
    

}