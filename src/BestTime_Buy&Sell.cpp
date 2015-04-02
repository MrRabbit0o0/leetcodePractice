class Solution {
public:
    Solution(){
        buy_prices = 0;
        sell_prices = 0;
    }
    int maxProfit(vector<int> &prices) {
        vector<int>::iterator start = prices.begin();
        vector<int>::iterator end = prices.end();
        if (start == end) return 0;
        buy_prices = *start;
        sell_prices = *start;
        int profie = 0;
        for (start += 1; start != end; ++start) {
            if (*start > sell_prices) {
                sell_prices = *start;
                if ((sell_prices - buy_prices) > profie)
                profie = sell_prices - buy_prices;
            }
            else if (*start <= buy_prices) {
                buy_prices = *start;
                sell_prices = *start;
            }
        }
        return profie;
    }
private:
    int buy_prices;
    int sell_prices;
};
