#include <iostream>
#include <vector>
#include <string>
#include <set>

int main() {
    std::string S;
    std::cin >> S;
    int n = S.length();
    
    if (n == 0 || n > 2000) {
        std::cout << -1 << std::endl;
        return 0;
    }
    
    std::set<char> cmds;
    for (char c : S) {
        if (c == 'L' || c == 'R') {
            cmds.insert(c);
        } else if (c != 'U') {
            std::cout << -1 << std::endl;
            return 0; // Invalid character
        }
    }
    
    int num_cmds = cmds.size(); // Number of unique commands excluding 'U'
    int N = 2 + num_cmds;       // Nodes: 1 (B), 2 (A), plus one node per command
    
    if (N > 2 * n) {
        std::cout << -1 << std::endl;
        return 0;
    }
    
    int A = 2;
    int B = 1;
    std::vector<int> leftChild(N + 1, 0);
    std::vector<int> rightChild(N + 1, 0);
    
    // Node B (1) is the parent of node A (2)
    leftChild[B] = A;
    
    // Assign children to A based on unique commands
    int nextNode = 3;
    for (char cmd : cmds) {
        if (cmd == 'L') {
            leftChild[A] = nextNode++;
        } else if (cmd == 'R') {
            rightChild[A] = nextNode++;
        }
    }
    
    // Output
    std::cout << N << " " << A << " " << B << std::endl;
    for (int i = 1; i <= N; ++i) {
        std::cout << leftChild[i] << " " << rightChild[i] << std::endl;
    }
    
    return 0;
}
