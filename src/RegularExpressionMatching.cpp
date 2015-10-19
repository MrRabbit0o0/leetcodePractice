#include <vector>
#include <string>

using std::vector;
using std::string;

//First try without DP
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0){
            return true;
        }else if (p.size() == 0) {
            return false;
        }
        
        int i(0), j(0);
        char last, current;
        last = '\0';
        bool flag = false;
        while (i < s.size() && j < p.size()) {
            current = p[j];
            if (current == '*' && j != 0) {
                ++j;
                if (j == p.size()) {
                    if (last == '.') {
                        return true;
                    }
                    while (i < s.size()) {
                        if (s[i] != last) {
                            return false;
                        }
                        ++i;
                    }
                    return true;
                }
                string subp = p.substr(j-2, 2);
                //Map
                string nullstring("");
                if (isMatch(s.substr(i), subp)) {
                    subp = p.substr(j);
                    flag = isMatch(nullstring, subp);
                }
                subp = p.substr(j);
                while (!flag && i < s.size()) {
                    flag = isMatch(s.substr(i), subp);
                    ++i;
                    //Filter
                    if (last != '.' && last != s[i-1]) {
                        return flag;
                    }
                }
                if (flag) {
                    return true;
                } else{
                    return false;
                }
            } else if (j+1 < p.size() && p[j+1] == '*'){
                last = p[j];
                ++j;
            } else if (current == '.' || s[i] == current){
                ++i;
                ++j;
            } else {
                return false;
            }
            
        }
        if (i != s.size()) {
            return false;
        } else if (j == p.size()) {
            return true;
        } else if ((p.size()-j)%2 == 0){
            while (j < p.size()-1) {
                if ( p[j+1] != '*') {
                    return false;
                }
                j = j + 2;
            }
            return true;
        } else {
            return false;
        }     }
};

//using the boolen operation, the programme is very clear now 
class Solution {
public:
    bool isMatch(string s, string p) {
        // dynamic programming
        int m=s.length(), n = p.length();
        vector<vector<bool>> dp (m+1, vector<bool> (n+1, false));
        // initial state
        dp[0][0] = true;
        for(int i = 0; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(p[j-1] != '*') {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
                else {
                    dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
            }
        }
        return dp[m][n];
    }
};
