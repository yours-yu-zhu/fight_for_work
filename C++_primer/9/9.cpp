#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <deque>
#include <vector>

using namespace std;

std::vector<int> global_vec; // 定义一个全局的 int 类型 vector


//9.4函数
bool find(vector<int>::iterator begin,vector<int>::iterator end,int a){
    while (begin != end)
    {
        if(*begin == a){
            return true;
        }else{
            begin++;
        }
    }
    return false;
}

//9.5函数
vector<int>::iterator find(int a, vector<int>::iterator begin, vector<int>::iterator end){
    while (begin != end)
    {
        if(*begin == a){
            return begin;
        }else{
            begin++;
        }
    }
    return end;    
}
//9.11 六种方法初始化vector
vector<int> other_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int> vec1; //0
vector<int> vec2(10); //10个0
vector<int> vec3(10,1);//10个1
vector<int> vec4 = {10,21,3134,12};//列表初始化
vector<int> vec5 = other_vector;//拷贝初始化
vector<int> vec6(other_vector.begin(), other_vector.end());//迭代器范围初始化

//9.13
list<int> ilst(5, 4);
vector<int> ivc(5, 5);
vector<double> dvc(ilst.begin(),ilst.end());
vector<double> dvc2(ivc.begin(),ivc.end());


int main(int argc, char **argv)
{
    vector<int> myVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout<<"test 9.4:--"<<find(myVector.begin(),myVector.end(),8)<<endl;
    cout<<"test 9.4:--"<<*find(8,myVector.begin(),myVector.end())<<endl;
    //9.14
    list<const char*> l{ "hello", "world" };
    vector<string> v ;
    v.assign(l.begin(),l.end());

    //9.18 deque实现
    // deque<string> din;
    // string input;
    // while(cin >> input){
    //     din.push_back(input);
    // }    
    //     cout<<"----test 9.18:----"<<endl;
    // for(auto begin = din.cbegin(); begin != din.cend(); ++begin){
    //     cout << *begin <<endl;
    // }

    //9.19 list实现
    // list<string> din;
    // string input;
    // while(cin >> input){
    //     din.push_back(input);
    // }    
    //     cout<<"----test 9.19:----"<<endl;
    // for(auto begin = din.cbegin(); begin != din.cend(); ++begin){
    //     cout << *begin <<endl;
    // }
    
    //9.20
    list<int> v20{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    deque<int> odd, even;
    for(auto x : v20){
        if(x % 2 == 0){
            even.push_back(x);
        }else{
            odd.push_back(x);
        }
    }
    cout<<"----test 9.19:----"<<endl;
    for (auto i : odd) cout << i << " ";
    cout << endl;
    for (auto i : even)cout << i << " ";
    cout << endl;

    //9.24 编写程序，分别使用at、下标运算符、front 和 begin 提取一个vector中的第一个元素。在一个空vector上测试你的程序。
    cout<<"----test 9.24:----"<<endl;
    vector<int> v24 = {1,2,3,4};
    cout<< v24.at(0)<<endl;
    cout<< v24[0]<<endl;
    cout<< v24.front()<<endl;
    cout<< *v24.begin()<<endl;
    //9.26  使用下面代码定义的ia，将ia拷贝到一个vector和一个list中。是用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。
    cout<<"----test 9.26:----"<<endl;
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> v26(ia,ia+sizeof(ia)/sizeof(ia[0]));
    list<int> lst26(v26.begin(),v26.end());
    for(auto idx = v26.begin();idx != v26.end();){
        if(*idx % 2 == 0){
            idx=v26.erase(idx);
        }else{
            ++idx;
        }
    }
    for (auto element : v26) {
        std::cout << element << " ";
    }
    cout << endl;
    for(auto idx = lst26.begin();idx != lst26.end();){
        if(*idx % 2 == 1){
            idx = lst26.erase(idx);
        }else{
            idx++;
        }
    }
    for (auto element : lst26) {
        std::cout << element << " ";
    }

}