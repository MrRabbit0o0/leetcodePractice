// It's wired, the atoi funciont in C++ is different with the version.

class Solution {
public:
    int myAtoi(string str) {
        vector<char> digital;
        int sign(1), i(0);
        long flag = INT32_MAX;
        flag = flag * 100;
        while ( flag >= 10 && i < str.size()) {
            if (str[i] == ' ' && digital.size() == 0) {
                ++i;
                continue;
            } else if (str[i] == '+' && digital.size() == 0) {
                ++i;
                sign = 1;
                digital.push_back('0');
            } else if (str[i] == '-' && digital.size() == 0) {
                ++i;
                sign = -1;
                digital.push_back('0');
            } else if ((str[i] < '0' || str[i] > '9')&&(digital.size() == 0)) {
                return 0;
            }
            
            if (str[i] >= '0' && str[i] <= '9') {
                digital.push_back(str[i]);
                ++i;
                flag = flag / 10;
            } else {
                break;
            }
        }
        long result(0);
        for (i = 0; i != digital.size(); ++i) {
            result = result*10 + (digital[i]-'0');
        }
        if (sign > 0 && result > INT32_MAX){
            result = INT32_MAX;
        } else if (sign < 0 && result-1 > INT32_MAX){
            result = -INT32_MAX - 1;
        } else {
            result = sign * result;
        }
        return result;
    }
};
