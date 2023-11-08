#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Person {
friend istream& read(istream& is, Person &x);
friend ostream& print(ostream& os, const Person &x);

private:
    string name;
    string address;
public:
    Person() = default;
    Person(const string &sname, const string &saddress):name(sname),address(saddress){}
    Person(istream &is);

    string const& get_name() const {
        return name;
    }

    string const& get_address() const {
        return address;
    }
};


istream& read(istream& is, Person &x){
    is >> x.name>> x.address;
    return is;
}
ostream& print(ostream& os, const Person &x){
    os << x.name<<x.address;
    return os;
}

Person::Person(istream &is){
        read(is, *this);
    }

int main(int argc, char **argv)
{

    string a(10,'c');
    cout <<a<<endl;
}