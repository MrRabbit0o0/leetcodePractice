class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int y = reverse(x);
        if (y == x) {
            return true;
        }else {
            return false;
        }
    }
    int reverse(int x) {
        long res(0);
        while (x >= 10 || x <= -10) {
            res = res*10 + x%10;
            x = x / 10;
        }
        res = res*10 + x;
        if (res > INT32_MAX || res < -INT32_MAX-1) {
            return 0;
        } else {
            return (int) res;
        }
        
    }
};
