#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		int minPrices = prices[0];
		int maxProfit = 0;
		for (auto p : prices)
		{
			if (p < minPrices) minPrices = p;
			else if (maxProfit < (p - minPrices)) maxProfit = p - minPrices;
		}
		return maxProfit;
	}
};