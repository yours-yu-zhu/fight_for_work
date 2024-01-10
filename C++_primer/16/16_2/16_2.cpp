#include <iostream>
using namespace std;

template <class T> int compare(const T&, const T&){
    return 1;
}

//16.40
template <typename T>
auto sum(T lhs, T rhs) -> decltype(lhs + rhs){
    return lhs + rhs;
}

void ex16_40(){
    auto val = sum(1, 2);
    cout << val << endl;
}

//16.47
template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2){
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2){
    f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2){
    f(t2, t1);
}

void f(int v1, int &v2){
    cout << v1 << " " << ++v2 << endl;
}

void g(int &&i, int &j){
    cout << i << " " << j << endl;
}

void ex16_47(){
    int i = 0, j = 0, k = 0, l = 0;
    cout << i << " " << j << " " << k << " " << l << endl;

    f(42, i);               // f 改变其实参 i
    flip1(f, j, 42);        // 通过 flip1 调用 f 不会改变 j
    flip2(f, k, 42);        // 正确：k 被改变了
    g(1, i);
    flip(g, i, 42);         // 正确：第三个参数的右值属性被保留了
    cout << i << " " << j << " " << k << " " << l << endl;

}

int main(){
    ex16_47();
    return 0;
}  