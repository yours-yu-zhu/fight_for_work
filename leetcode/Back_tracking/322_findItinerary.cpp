#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> path;
    unordered_map<string, map<string, int>> record;
    void back_tracking(int ticket_num){
        if(path.size() == ticket_num + 1) {
            result = path;
            return;
        }
        for(auto& target : record[path.back()]){
            if(target.second > 0){
                path.push_back(target.first);
                --target.second;
                //打印path
                for(auto& str : path){
                    cout << str << " ";
                }
                cout << endl;

                back_tracking(ticket_num);
                ++target.second;
                path.pop_back();

            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto ticket : tickets){
            record[ticket[0]][ticket[1]]++;
        }
        path.push_back("JFK");
        back_tracking(tickets.size());
        return path;
    }
};
int main(){
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution sol;
    sol.findItinerary(tickets);
    // //打印record
    // for(auto& record : sol.record){
    //     cout << record.first << ": ";
    //     for(auto& target : record.second){
    //         cout << target.first << " " << target.second << " ";
    //     }
    //     cout << endl;
    // }
    // //打印结果
    // for(auto& str : sol.result){
    //     cout << str << " ";
    // }
    
    return 0;
}