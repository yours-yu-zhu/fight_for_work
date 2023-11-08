#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <iostream>

void printBinary(int num) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {
        if (num & (1 << i)) {
            std::cout << "1";
        } else {
            std::cout << "0";
        }

        if (i % 4 == 0) {
            std::cout << " "; // 用空格分隔每4位
        }
    }
    std::cout << std::endl;
}

int main() {
    int num = 10-42; // 你可以替换成你想要打印的整数
    std::cout << "Binary representation of " << num << " is: ";
    printBinary(num);
    return 0;
}
