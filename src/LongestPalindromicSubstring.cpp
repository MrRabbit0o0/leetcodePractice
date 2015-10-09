#include <vector>

using std::vector;
using std::string;

class Solution1 {
    // Try a DP solution
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }
        vector<int> element(s.size(), -1);
        vector<vector<int>> store(s.size(), element);
        int size = (int) s.size();
        for (size_t i = s.size()-1; i > 0; --i) {
            for (size_t j = i; j > 0; --j) {
                if (i == j) {
                    store[i][j] = 1;
                } else {
                    store[i][j] = 0;
                }
            }
        }
        vector<int> res(3, 0);
        dp_find(s, 0, size, store, res);
        string result;
        for (int i = res[0]; i <= res[1]; ++i){
            result += s[i];
        }
        std::cout << result << std::endl;
        return result;
    }
    void dp_find(string s, int i, int j, vector<vector<int>>& store, vector<int>& res){
        if (i == j) {
            return;
        }
        if ((j-i == 1) && (s[i] == s[j])) {
            store[i][j] = 1;
            if (res[2] < 1) {
                res[0] = i;
                res[1] = j;
                res[2] = 1;
            }
            return;
        } else if ((j-i == 1) && (s[i] == s[j])) {
            store[i][j] = 0;
            return;
        }

        if (s[i] != s[j]) {
            store[i][j] = 0;
            dp_find(s, i+1, j, store, res);
            dp_find(s, i, j-1, store, res);
            return;
        } else {
            if (store[i+1][j-1] == -1) {
                dp_find(s, i+1, j-1, store, res);
            }
            if (store[i+1][j-1] == 1) {
                store[i][j] = 1;
                if ((j-i+1) > res[2]) {
                    res[2] = j-i+1;
                    res[0] = i;
                    res[1] = j;
                }
            } else {
                store[i][j] = 0;
            }
            return;
        }
    }
};

class Solution2 {
    // another search method, time: O(N^2), space: O(1)
public:
    string longestPalindrome(string s) {
        int size = (int) s.size();
        if (size <= 1) {
            return s;
        }
        vector<int> center(1, 0);
        string palidromic;
        for (int i = 0 ; i != size; ++i) {
            center[0] = i;
            string temp = find(center, s);
            if (temp.size() > palidromic.size()) {
                palidromic = temp;
            }
        }
        center.push_back(0);
        for (int i = 0; i != size-1; ++i) {
            center[0] = i;
            center[1] = i+1;
            string temp = find(center, s);
            if (temp.size() > palidromic.size()) {
                palidromic = temp;
            }
        }
        return palidromic;
    }
    
    string find(vector<int> center, string s){
        int size = (int) center.size();
        int i(center.front()-1), j(center.front()+size);
        string res = s.substr(center.front(), center.front()+size);
        while (i > 0 && j < s.size()) {
            if (s[i] == s[j]) {
                res = s.substr(i, j+1);
                --i;
                ++j;
            } else {
                break;
            }
        }
        return res;
    }
};
