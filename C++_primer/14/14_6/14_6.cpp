#include "14_6.h"



//14.16
bool operator==(const StrBlob &lhs, const StrBlob &rhs){
    return lhs.data == rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs){
    return !(lhs == rhs);
}

void ex_12_2(){
    const StrBlob csb{"hello","world","pezy"};
    StrBlob sb{ "hello", "world", "Mooophy" };
    cout << csb.front() << " " << csb.back() << endl;

    sb.back() = "pezy";
    cout << sb.front() << " " << sb.back() << endl;
}

//12.6
vector<int> *new_vector(){
    return new vector<int>();
}

void read_ints(vector<int> *p){
    int v;
    while(cin >> v){
        p->push_back(v);
    }
}

void print_ints(vector<int> *p){
    for(const auto &i : *p){
        cout << i << " ";
    }
    cout << endl;
}

void ex_12_6(){
    auto p = new_vector();
    read_ints(p);
    print_ints(p);
    delete p;
}

//12.7
shared_ptr<vector<int>> new_vector_sp(){
    return make_shared<vector<int>>();
}

void read_ints_sp(shared_ptr<vector<int>> p){
    int i;
    while(cin >> i){
        p->push_back(i);
    }
}

void print_ints_sp(shared_ptr<vector<int>> p){
    for(const auto &i : *p){
        cout << i << " ";
    }
    cout << endl;
}

void ex_12_7(){
    auto p = new_vector_sp();
    read_ints_sp(p);
    print_ints_sp(p);
}

//12.14 && 12.15
struct connection{
    string ip;
    int port;
    connection(string ip_,int port_):ip(ip_),port(port_){}
};

struct destination{
    string ip;
    int port;
    destination(string ip_,int port_):ip(ip_),port(port_){}
};

connection connect(destination *pDest){
    shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    cout << "creating connection(" << pConn.use_count() << ")" << endl;
    return *pConn;
}

void disconnect(connection Conn){
    cout << "connection close(" << Conn.ip << ":" << Conn.port << ")" << endl;
}

void end_conncetion(connection *pConn){
    disconnect(*pConn);
}

void f(destination &d){
    connection conn = connect(&d);
    shared_ptr<connection> p(&conn,end_conncetion);
    cout<<  "connecting now(" << p.use_count() << ")" << endl;
}

void f2(destination &d){
    connection conn = connect(&d);
    shared_ptr<connection> p(&conn,[](connection *p) -> void {disconnect(*p);});
    cout<<  "connecting now(" << p.use_count() << ")" << endl;
}

void ex_12_14(){
    destination dest("220.181.111.111", 10086);
	f(dest);
}

void ex_12_15(){
    destination dest("220.181.111.111", 10086);
	f2(dest);
}

void ex_12_16(){
    unique_ptr<string> p1(new string("pezy"));
    // unique_ptr<string> p2(p1); // copy
    //                      ^
    // Error: Call to implicitly-deleted copy constructor of 'unique_ptr<string>'
    //
    // unique_ptr<string> p3 = p1; // assign
    //                      ^
    // Error: Call to implicitly-deleted copy constructor of 'unique_ptr<string>'
    // std::cout << *p1 << std::endl;
    // p1.reset(nullptr);
}


StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
    return StrBlobPtr(*this,data->size());
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if(l == r){
        return (!r || lhs.curr == rhs.curr);
    }else{
        return false;
    }
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs){
    return !(lhs == rhs);
}

//12.20
void ex_12_20(){
    ifstream ifs("/home/ubuntu/fight_for_work/C++_primer/12/12_1.cpp");
    StrBlob blob;
    string s;
    while(ifs >> s){
        blob.push_back(s);

    }
    for(StrBlobPtr p = blob.begin();p.get_curr() != blob.end().get_curr(); p.incr()){
        cout << p.deref() << endl;
    } 
}
StrBlobPtr& StrBlobPtr::operator++(){
    check(curr,"increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--(){
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}
StrBlobPtr StrBlobPtr::operator++(int){
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}
StrBlobPtr StrBlobPtr::operator--(int){
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}
StrBlobPtr& StrBlobPtr::operator+=(size_t n){
    check(curr, "increment past end of StrBlobPtr");
    curr += n;
    return *this;
}
StrBlobPtr& StrBlobPtr::operator-=(size_t n){
    curr -= n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}

void ex_14_27(){
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << b2.size() << endl;
    }
    // b2 在花括号外失效，作用域仅限于花括号内
    // cout << b2.size() << endl;
    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;

    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;


    // 练习 14.27
    for (StrBlobPtr iter = b1.begin(); iter != b1.end(); iter++)
        cout << iter.deref() << " ";
    cout << endl;  
}
            

int main() {
    // ex_12_2();
    // ex_12_6();
    // ex_12_7();    
    // ex_12_14();
    // ex_12_15();
    // ex_12_16();
    // ex_12_20();
    ex_14_27();
}
