#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

// 定义摩尔斯电码字典
unordered_map<char, string> morse_code_dict = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}
};

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word;
    TrieNode() : is_end_of_word(false) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end_of_word = true;
    }

    void search_from(const string& text, int start, vector<int>& dp) {
        TrieNode* node = root;
        for (int i = start; i < text.size(); ++i) {
            char chara = text[i];
            if (node->children.find(chara) == node->children.end()) {
                break;
            }
            node = node->children[chara];
            if (node->is_end_of_word) {
                dp[i + 1] += dp[start];
            }
        }
    }
};

string word_to_morse(const string& word) {
    string morse;
    for (char c : word) {
        morse += morse_code_dict[c];
    }
    return morse;
}

int main() {
    string morse_code_cipher;
    cin >> morse_code_cipher;
    
    int n;
    cin >> n;
    
    vector<string> word_list(n);
    for (int i = 0; i < n; ++i) {
        cin >> word_list[i];
    }

    // 构建 Trie 树
    Trie trie;
    vector<string> morse_words(n);
    for (int i = 0; i < n; ++i) {
        morse_words[i] = word_to_morse(word_list[i]);
        trie.insert(morse_words[i]);
    }

    // 动态规划数组
    vector<int> dp(morse_code_cipher.size() + 1, 0);
    dp[0] = 1; // 初始状态

    // 搜索密文中的所有匹配
    for (int i = 0; i < morse_code_cipher.size(); ++i) {
        if (dp[i] > 0) {
            trie.search_from(morse_code_cipher, i, dp);
        }
    }

    // 结果数组
    vector<int> result(n, 0);
    for (int i = 0; i < n; ++i) {
        string morse_word = word_to_morse(word_list[i]);
        int len = morse_word.length();
        for (int j = 0; j <= morse_code_cipher.size() - len; ++j) {
            if (morse_code_cipher.substr(j, len) == morse_word) {
                result[i] += dp[j];
            }
        }
    }

    // 输出结果
    for (int i = 0; i < n; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
