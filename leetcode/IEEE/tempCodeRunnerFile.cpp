#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Data structures for graph
vector<vector<int>> adj_rest_to_ent; // Adjacency list from restaurants to entertainments
vector<vector<int>> adj_ent_to_rest; // Adjacency list from entertainments to restaurants
vector<bool> safe_restaurants, safe_entertainments;
vector<bool> visited_rest, visited_ent;

// Check if a safe path/cycle can be formed starting from a given restaurant
bool valid_start_from_restaurant(int start) {
    set<int> cycle_entertainments;
    visited_rest[start] = true;
    
    // Explore all connected entertainments
    for (int ent : adj_rest_to_ent[start]) {
        if (safe_entertainments[ent]) {
            cycle_entertainments.insert(ent);
            // Explore all restaurants from this entertainment
            for (int rest : adj_ent_to_rest[ent]) {
                if (safe_restaurants[rest] && (rest == start || visited_rest[rest])) {
                    visited_rest[start] = false;
                    return true;
                }
            }
        }
    }
    
    visited_rest[start] = false;
    return false;
}

// Check if all reachable restaurants from an entertainment are safe
bool valid_start_from_entertainment(int start) {
    for (int rest : adj_ent_to_rest[start]) {
        if (!safe_restaurants[rest]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m, k0, k1;
    cin >> n >> m >> k0 >> k1;

    adj_rest_to_ent.resize(n);
    adj_ent_to_rest.resize(m);
    safe_restaurants.resize(n, false);
    safe_entertainments.resize(m, false);
    visited_rest.resize(n, false);
    visited_ent.resize(m, false);

    int x, y;
    for (int i = 0; i < k0; ++i) {
        cin >> x >> y;
        adj_rest_to_ent[x].push_back(y);
    }
    for (int i = 0; i < k1; ++i) {
        cin >> x >> y;
        adj_ent_to_rest[x].push_back(y);
    }

    int ns, ms;
    cin >> ns >> ms;
    for (int i = 0; i < ns; ++i) {
        cin >> x;
        safe_restaurants[x] = true;
    }
    for (int i = 0; i < ms; ++i) {
        cin >> y;
        safe_entertainments[y] = true;
    }

    vector<int> valid_starting_restaurants, valid_starting_entertainments;
    // Check for valid starting restaurants
    for (int i = 0; i < n; ++i) {
        if (safe_restaurants[i] && valid_start_from_restaurant(i)) {
            valid_starting_restaurants.push_back(i);
        }
    }

    // Check for valid starting entertainments
    for (int i = 0; i < m; ++i) {
        if (safe_entertainments[i] && valid_start_from_entertainment(i)) {
            valid_starting_entertainments.push_back(i);
        }
    }

    // Output results
    sort(valid_starting_restaurants.begin(), valid_starting_restaurants.end());
    sort(valid_starting_entertainments.begin(), valid_starting_entertainments.end());

    cout << valid_starting_restaurants.size() << " " << valid_starting_entertainments.size() << endl;
    for (int r : valid_starting_restaurants) {
        cout << r << " ";
    }
    cout << endl;
    for (int e : valid_starting_entertainments) {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
