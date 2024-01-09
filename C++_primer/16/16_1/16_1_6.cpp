#include "SharedPtr.h"
#include "UniquePtr.h"

int main(){
    SharedPtr<int> sp1(new int(42), DebugDelete("smart pointer"));
    UniquePtr<int> sp2(new int(43), DebugDelete("unique_ptr"));
}