#include <iostream>
#include <vector>

using std::vector;
using std::string;

int kmp(string str, string word){
    //Craete the table T to store the element of word location
    if (word.size() <1) {
        return -1;
    } else if (word.size() == 1){
        for (int m = 0; m != str.size(); ++m) {
            if (str[m] == word[0]) {
                return m;
            }
        }
    }
    int index(-1);
    vector<int> T(word.size(), 0);
    T[0] = -1;
    for (int i = 2; i < word.size(); ++i) {
        char curent = word[i-1];
        char comp = word[T[i-1]];
        if (curent == comp){
            T[i] = T[i-1]+1;
        }
    }
    //the major KMP, m is the index of str, i is the index of word
    int m(0), i(0);
    while ((m+i) < str.size()) {
            if (word[i] == str[m+i]) {
                if (i == word.size()-1){
                    //Success, update the result
                    index = m;
                    break;
                }
                ++i;
            } else if (T[i] == -1){
                ++m;
                i = 0;
            } else {
                m = m + i - T[i];
                i = T[i];
            }
        }
    return index;
}

int main(int argc, const char * argv[]){
    string line;
    std::cout << "Enter the string:" << std::endl;
    getline(std::cin,line);
    string str(line);
    std::cout << "Enter the word:" << std::endl;
    getline(std::cin, line);
    string word(line);
    int index;
    index = kmp(str, word);
    if (index != -1){
        std::cout << index << std::endl;
    } else {
        std::cout << "Not match" << std::endl;
    }
    return 0;
}
