#include <iostream>
#include <string>
#include <vector>

using namespace std;

//13.22 值类型
class HasPtr {
public:
	HasPtr(const string& s = string()):ps(new string(s)), i(0) { }
    HasPtr(const HasPtr& hp): ps(new string(*(hp.ps))), i(hp.i){ cout << "copy constructor" << endl; }
    string get_ps() const { return *ps; }
    HasPtr& operator=(const HasPtr& hp){
        cout << "copy assignment" << endl;
        if(this != &hp){
            delete ps;
            ps = new string(*(hp.ps));
            i = hp.i;              
        }
        return *this;
    }
    ~HasPtr(){
        cout << "destructor" << endl;
        delete ps;
    }
private:
	string *ps;
	int i;
};

//13.27 指针类型
class HasPtr2 {
public:
    HasPtr2(const string& s = string()): ps(new string(s)), i(0), use(new size_t(1)){ }
    HasPtr2(const HasPtr2& hp): ps(hp.ps),i(hp.i),use(hp.use){
        ++(*use);
    }
    HasPtr2& operator=(const HasPtr2& hp){
        ++(*hp.use);
        if(--(*use) == 0){
            delete ps;
            delete use;
        }
        ps = hp.ps;
        i = hp.i;
        use = hp.use;
        return *this;
    }
    ~HasPtr2(){
        if(--(*use) == 0){
            delete ps;
            delete use;
        }
    }
    string get_ps() const { return *ps; }
    size_t get_use() const { return *use; }
private:
    string *ps;
    int i;
    size_t *use;
};

void ex_13_27(){
    //test HasPtr2
    HasPtr2 hp1("hello");
    HasPtr2 hp2 = hp1;
    HasPtr2 hp3;
    hp3 = hp1;
    cout << hp1.get_ps() << endl;
    cout << hp2.get_ps() << endl;
    cout << hp3.get_ps() << endl;
    cout << "----------------" << endl;
    cout << hp1.get_use() << endl;
    cout << hp2.get_use() << endl;
    cout << hp3.get_use() << endl;

}

class TreeNode{
public:
    TreeNode():value(string()), count(new int(1)), left(nullptr), right(nullptr){}
    TreeNode(const TreeNode& tn): value(tn.value), count(tn.count), left(tn.left), right(tn.right){
        ++(*count);
    }
    TreeNode& operator=(const TreeNode& tn){
        ++(*tn.count);
        if(--(*count) == 0){
            delete count;
            delete left;
            delete right;
        }
        value = tn.value;
        count = tn.count;
        left = tn.left;
        right = tn.right;
        return *this;
    }
    ~TreeNode(){
        if(--(*count) == 0){
            delete count;
            delete left;
            delete right;
        }
    }        


private:
    string value;
    int         *count;
    TreeNode    *left;
    TreeNode    *right;
};

int main() {
    ex_13_27();
    return 0;
}
