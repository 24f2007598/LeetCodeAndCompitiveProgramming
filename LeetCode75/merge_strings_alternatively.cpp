//0ms runtime - beats 100%
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2);
};

string Solution::mergeAlternately(string word1, string word2) {
    int n = word1.length(), m = word2.length();
    int mx = max(n, m);

    string merged = "";
    for (int i = 0; i < mx; i++) {
        if (i < n){
            merged += word1[i];
        }
        if (i < m){
            merged += word2[i];
        }
    }
    return merged;
}

/*
int main() {
    Solution s;
    cout << s.mergeAlternately("ab", "pqrs") << endl;

}
*/