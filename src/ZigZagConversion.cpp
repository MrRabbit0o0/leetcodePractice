#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
        string result("");
        if (numRows <= 1) {
            return s;
        }
        vector<char> line;
        vector<vector<char>> text(numRows, line);
        int i = 0;
        int mod;
        if (mod >= 3){
            mod = numRows*2 - 2;
        } else {
            mod = numRows;
        }
        int index;
        while (i < s.size()) {
            index = i % mod;
            if (index < numRows) {
                text[index].push_back(s[i]);
            } else {
                index = index - numRows;
                index = numRows - index - 2;
                text[index].push_back(s[i]);
            }
            ++i;
        }
        for (int i = 0; i != numRows; ++i) {
            for (int j = 0; j != text[i].size(); ++j) {
                result += text[i][j];
            }
        }
        return result;
    }
};
