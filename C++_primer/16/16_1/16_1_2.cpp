#include "Blob.h"
#include "Vec.h"


void ex16_12(){
    Blob<string> b1; // empty Blob
    cout << b1.size() << endl;
    {  // new scope
        Blob<string> b2({"a", "an", "the"});
        b1 = b2;  // b1 and b2 share the same elements
        b2.push_back("about");
        cout << b1.size() << " " << b2.size() << endl;
    } // b2 is destroyed, but the elements it points to must not be destroyed
    cout << b1.size() << endl;
    for (BlobPtr<string> p = b1.begin(); p != b1.end(); ++p)
        cout << *p << endl;
}

void ex16_16(){
    Vec<string> svec = getVec(cin);
    print(svec);

    cout << "copy " << svec.size() << endl;
    Vec<string> svec2 = svec;
    print(svec2);

    cout << "assign" << endl;
    Vec<string> svec3;
    svec3 = svec2;
    print(svec3);

    Vec<string> v1, v2;
    Vec<string> getVec(istream &);
    v1 = v2;            // copy assignment
    v2 = getVec(cin);   // move assignment
    print(v1);
    print(v2);
    cout << "----- end -----";
}


         

int main() {
    //ex16_12();
    ex16_16();
    return 0;
}
