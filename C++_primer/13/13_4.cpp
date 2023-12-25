#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Folder;

class Message{
    friend class Folder;
    friend void swap(Message&, Message&);
    friend void ex_13_33();
public:
    //默认构造函数
    explicit Message(const string& str = ""):contents(str){}
    //拷贝构造函数
    Message(const Message& m): contents(m.contents), folders(m.folders){
        add_to_Folders(m);
    }
    //拷贝赋值运算符    
    Message& operator=(const Message& rhs){
        remove_from_Folders();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
        return *this;
    }
    //析构函数
    ~Message(){
        remove_from_Folders();
    }
    void save(Folder& f);
    void remove(Folder& f);
private:
    string contents;
    set<Folder*> folders;
    void add_to_Folders(const Message& m);
    void remove_from_Folders();
};

class Folder{
    friend class Message;
    friend void swap(Message&, Message&);
    friend void ex_13_33();

public:
    Folder() = default;
    Folder(const Folder& f):msgs(f.msgs){
        add_to_Messages(f);
    }
    Folder& operator=(const Folder& rhs){
        remove_from_Messages();
        msgs = rhs.msgs;
        add_to_Messages(rhs);
        return *this;
    } 
    ~Folder() {
        remove_from_Messages();
    }
private:
    set<Message*> msgs;
    void add_to_Messages(const Folder&){
        for(auto m : msgs){
            m->folders.insert(this);
        }
    }
    void remove_from_Messages(){
        for(auto m : msgs){
            m->folders.erase(this);
        }
    }
    void addMsg(Message* m){
        msgs.insert(m);
    }
    void remMsg(Message* m){
        msgs.erase(m);
    }

};
 
void swap(Message& lhs, Message& rhs){
    using std::swap;
    for(auto f :lhs.folders){
        f->remMsg(&lhs);
    }
    for(auto f :rhs.folders){
        f->remMsg(&rhs);
    }
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(auto f :lhs.folders){
        f->addMsg(&lhs);
    }
    for(auto f :rhs.folders){
        f->addMsg(&rhs);
    }
}

void Message::save(Folder& f){
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message& m){
    for(auto f : m.folders){
        f->addMsg(this);
    }
}

void Message::remove_from_Folders(){
    for(auto f : folders){
        f->remMsg(this);
    }
}


void ex_13_33(){
    //test Message and Folder
    Message m1("hello");
    Message m2("world");
    Folder f1;
    Folder f2;
    m1.save(f1);
    m2.save(f2);
    cout << "m1's folders: " << endl;
    for(auto f : m1.folders){
        cout << f << endl;
    }
    cout << "m2's folders: " << endl;
    for(auto f : m2.folders){
        cout << f << endl;
    }
    cout << "m1's messages: " << endl;
    cout << m1.contents << endl;
    cout << "m2's messages: " << endl;
    cout << m2.contents << endl;
    cout << "f1's messages: " << endl;
    for(auto m : f1.msgs){
        cout << m->contents << endl;
    }
    cout << "f2's messages: " << endl;
    for(auto m : f2.msgs){
        cout << m->contents << endl;
    }
    swap(m1, m2);
    cout << "after swap: " << endl;
    cout << "m1's folders: " << endl;
    for(auto f : m1.folders){
        cout << f << endl;
    }
    cout << "m2's folders: " << endl;
    for(auto f : m2.folders){
        cout << f << endl;
    }
    cout << "m1's messages: " << endl;
    cout << m1.contents << endl;
    cout << "m2's messages: " << endl;
    cout << m2.contents << endl;
}

int main() {
    ex_13_33();
    return 0;
    
}
