#include <vector>
#include <string>
#include <cassert>
using std::vector;
using std::string;

class Solution {
public:
    Solution(){
    }
    ~Solution(){
        delete position;
    }
    vector<vector<string> > solveNQueens(int n) {
        init(n);
        searchSolution(0);
        return result;
    }
    
    void searchSolution(int currentNumber){
        if (currentNumber == queenNumber) {
            vector<string> solution;
            for (int i = 0; i != queenNumber; ++i) {
                solution.push_back(printResult(i));
            }
            result.push_back(solution);
        } else {
            for (int i = 0; i != queenNumber; ++i) {
                if (isSafe(currentNumber, i)){
                    position[currentNumber] = i;
                    searchSolution(currentNumber+1);
                }
            }
        }
    }
    
    string printResult(int index){
        string result;
        for (int i = 0; i != queenNumber; ++i) {
            if (i == position[index]) {
                result = result + "Q";
            } else {
                result = result + ".";
            }
        }
        return result;
    }
    
    bool isSafe(int queenNumber, int col_position){
        for (int i = 0; i < queenNumber; ++i) {
            int other_row_pos = position[i];
            if (other_row_pos == col_position \
                || other_row_pos == col_position - (queenNumber - i) \
                || col_position == other_row_pos - (queenNumber - i))
                return false;
        }
        return true;
    }
private:
    void init(int n){
        position = new int[n];
        assert(position != 0);
        queenNumber = n;
    }
private:
    vector<vector<string>> result;
    int *position;
    int queenNumber;
};
