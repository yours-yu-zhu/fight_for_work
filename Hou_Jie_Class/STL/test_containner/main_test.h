#ifndef main_test
#define main_test
    using namespace std;
    long get_a_target_long(){
        cout << "target (0~" << RAND_MAX << "): ";
        long target = 0;
        cin >> target;
        return target;
    }

    int compareLongs(const void* a, const void* b){
        return (*(long*)a -*(long*)b);
    }

    string get_a_target_string(){
        cout << "target (0~" << RAND_MAX << "): ";
        long target = 0;
        cin >> target;
        return to_string(target);
    }
    int comepareStrings(const void* a, const void* b){
        if(*(string*)a > *(string*)b){
            return 1;
        }else if(*(string*)a < *(string*)b){
            return -1;
        }else{
            return 0;
        }
    }
#endif