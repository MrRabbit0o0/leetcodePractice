//A simple version, just find the lenght of the longest common substring
//In order to find what is the substring, there should be another N*M array

int lcsub(string str1, string str2, vector<vector<int>>& store){
    if (str1.size() == 0 || str2.size() == 0) {
        return 0;
    }
    if (str1.back() == str2.back()) {
        str1.resize(str1.size()-1);
        str2.resize(str2.size()-1);
        int len = store[str2.size()-1][str1.size()-1];
        if (len == -1) {
            len = lcsub(str1, str2, store);
            store[str2.size()-1][str1.size()-1] = len;
        }
        return len + 1;
    } else {
        string l1(str1), l2(str2);
        str1.resize(str1.size()-1);
        str2.resize(str2.size()-1);
        int len1 = store[str2.size()-1][l1.size()-1];
        if (len1 == -1) {
            len1 = lcsub(l1, str2, store);
            store[str2.size()-1][l1.size()-1] = len1;
        }
        int len2 = store[l2.size()-1][str1.size()-1];
        if (len2 == -1) {
            len2 = lcsub(str1, l2, store);
            store[l2.size()-1][str1.size()-1] = len2;
        }
        if (len1 >= len2) {
            return len1;
        } else {
            return len2;
        }
    }
}
