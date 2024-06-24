#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 摩尔斯电码字典
const char *morseCode[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// 将单词转换为摩尔斯电码
void toMorseCode(const char *input, char *result) {
    result[0] = '\0';
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            strcat(result, morseCode[toupper(input[i]) - 'A']);
        }
    }
}

// 计算部分匹配表（前缀函数）
void getNext(int *next, const char *s) {
    int j = 0;
    next[0] = 0;
    for (int i = 1; s[i] != '\0'; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        next[i] = j;
    }
}

// KMP算法查找模式
int strStr(const char *haystack, const char *needle) {
    int k = 0;
    if (needle[0] == '\0') {
        return 0;
    }
    int n = strlen(needle);
    int *next = (int *)malloc(n * sizeof(int));
    getNext(next, needle);
    int j = 0;
    for (int i = 0; haystack[i] != '\0'; i++) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = next[j - 1];
        }
        if (haystack[i] == needle[j]) {
            j++;
        }
        if (j == n) {
            k++;
            j = next[j - 1];
        }
    }
    free(next);
    return k;
}

void change(char **lll, int n, const char *ms) {
    for (int i = 0; i < n; i++) {
        printf("%d\n", strStr(ms, lll[i]));
    }
}

int main() {
    int n;
    char ms[1000001];
    scanf("%1000000s", ms);
    scanf("%d", &n);

    char ll[101];
    char llms[1001];
    char **lll = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        scanf("%100s", ll);
        toMorseCode(ll, llms);
        lll[i] = (char *)malloc((strlen(llms) + 1) * sizeof(char));
        strcpy(lll[i], llms);
    }

    change(lll, n, ms);

    for (int i = 0; i < n; i++) {
        free(lll[i]);
    }
    free(lll);

    return 0;
}
