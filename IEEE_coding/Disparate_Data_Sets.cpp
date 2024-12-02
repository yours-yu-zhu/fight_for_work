#include <bits/stdc++.h>
using namespace std;

// Struct to hold event information
struct Event {
    string event_id;
    string event_title;
    string acronym;
    string project_code;
    string project_code_3d;
    string record_type;
};

// Struct to hold a serialized set
struct Set {
    string acronym;
    Event parent;
    vector<Event> children;
};

// Function to parse a CSV line into fields
vector<string> parseCSVLine(const string& line) {
    vector<string> fields;
    int n = line.size();
    int i = 0;
    while (i < n) {
        if (line[i] == '"') {
            // Quoted field
            string field = "";
            i++; // Skip initial quote
            while (i < n) {
                if (line[i] == '"' && i + 1 < n && line[i + 1] == '"') {
                    field += '"';
                    i += 2;
                }
                else if (line[i] == '"') {
                    i++; // Skip closing quote
                    break;
                }
                else {
                    field += line[i];
                    i++;
                }
            }
            fields.push_back(field);
            // Skip comma after quoted field
            if (i < n && line[i] == ',') {
                i++;
            }
        }
        else {
            // Unquoted field
            string field = "";
            while (i < n && line[i] != ',') {
                field += line[i];
                i++;
            }
            fields.push_back(field);
            // Skip comma after field
            if (i < n && line[i] == ',') {
                i++;
            }
        }
    }
    return fields;
}

// Function to escape and quote a field (for Event Title, Acronym, Record Type)
string escapeAndQuote(const string& field) {
    string escaped = "";
    for(char c : field){
        if(c == '"') {
            escaped += "\"\"";
        }
        else {
            escaped += c;
        }
    }
    return "\"" + escaped + "\"";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<Event> events;
    string line;
    while(getline(cin, line)){
        if(line.empty()) continue; // Skip empty lines
        vector<string> fields = parseCSVLine(line);
        // Ensure we have at least 6 fields
        while(fields.size() < 6){
            fields.push_back("");
        }
        Event e;
        e.event_id = fields[0];
        e.event_title = fields[1];
        e.acronym = fields[2];
        e.project_code = fields[3];
        e.project_code_3d = fields[4];
        e.record_type = fields[5];
        events.push_back(e);
    }
    
    // Maps to hold parents and children by acronym
    unordered_map<string, vector<Event>> acronym_to_parents;
    unordered_map<string, vector<Event>> acronym_to_children;
    
    for(auto &e : events){
        if(e.acronym.empty()){
            // Exclude records with empty acronym
            continue;
        }
        if(e.record_type == "Parent Event"){
            acronym_to_parents[e.acronym].push_back(e);
        }
        else if(e.record_type == "IEEE Event"){
            acronym_to_children[e.acronym].push_back(e);
        }
        // Else: invalid record type, ignore
    }
    
    // Now, build the sets
    vector<Set> included_sets;
    for(auto &pair : acronym_to_parents){
        string acronym = pair.first;
        vector<Event> &parents = pair.second;
        // Exclude sets with multiple parents
        if(parents.size() != 1){
            continue;
        }
        // Check if there are children
        if(acronym_to_children.find(acronym) == acronym_to_children.end()){
            continue;
        }
        vector<Event> &children = acronym_to_children[acronym];
        if(children.empty()){
            continue;
        }
        // Now, include this set
        Set s;
        s.acronym = acronym;
        s.parent = parents[0];
        s.children = children;
        // Determine parent's 3 Digit Project Code
        string common_code = "";
        bool same = true;
        for(auto &child : children){
            if(common_code.empty()){
                common_code = child.project_code_3d;
            }
            else{
                if(child.project_code_3d != common_code){
                    same = false;
                    break;
                }
            }
        }
        if(same){
            s.parent.project_code_3d = common_code;
        }
        else{
            s.parent.project_code_3d = "???";
        }
        included_sets.push_back(s);
    }
    
    // Now, sort the sets by acronym
    sort(included_sets.begin(), included_sets.end(), [&](const Set &a, const Set &b) -> bool{
        return a.acronym < b.acronym;
    });
    
    // For each set, sort the children
    for(auto &s : included_sets){
        sort(s.children.begin(), s.children.end(), [&](const Event &a, const Event &b) -> bool{
            if(a.event_title != b.event_title){
                return a.event_title < b.event_title;
            }
            return a.event_id < b.event_id;
        });
    }
    
    // Now, output the sets
    bool first_set = true;
    for(auto &s : included_sets){
        // Output parent
        // Event ID,"Event Title","Acronym",Project Code,3 Digit Project Code,"Record Type"
        string parent_line = s.parent.event_id + ",";
        parent_line += escapeAndQuote(s.parent.event_title) + ",";
        parent_line += escapeAndQuote(s.parent.acronym) + ",";
        parent_line += s.parent.project_code + ","; // Project Code is empty or as is
        parent_line += s.parent.project_code_3d + ","; // 3 Digit Project Code without quotes
        parent_line += escapeAndQuote(s.parent.record_type);
        cout << parent_line << "\n";
        // Output children
        for(auto &child : s.children){
            string child_line = child.event_id + ",";
            child_line += escapeAndQuote(child.event_title) + ",";
            child_line += escapeAndQuote(child.acronym) + ",";
            child_line += child.project_code + ",";
            child_line += child.project_code_3d + ",";
            child_line += escapeAndQuote(child.record_type) + ",";
            child_line += s.parent.event_id;
            cout << child_line << "\n";
        }
    }
    
    return 0;
}
