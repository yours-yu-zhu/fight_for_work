#include "DebugDelete.h"
#include "Blob.h"

void ex16_21(){
    double *p = new double;
    DebugDelete d("plain pointer");    // 可像 delete 表达式一样使用的对象
    d(p);       // 调用 DebugDelete::operator()(double*)，释放 p

    int *ip = new int;
    // 在一个临时 DebugDelete 对象上调用 operator()(int*)
    DebugDelete("plain pointer")(ip);

    // illustrate other types using DebugDelete as their deleter
    std::shared_ptr<int> sp1(new int(42), DebugDelete("shared_ptr"));

}

void ex16_24(){
    vector<int> v1(3, 43), v2(10);
    int temp[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Blob<int> a1(v1.begin(), v1.end()),
            a3(v2.begin(), v2.end());
}

int main() {
    // ex16_21();
    ex16_24();
    return 0;
}
