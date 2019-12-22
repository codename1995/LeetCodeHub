#include<vector>
#include<queue>
#include<iostream>

using namespace std;

class Solution {
public:
	int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
		queue<int> q;
		for (auto b : initialBoxes) {
			q.push(b);
		}

		int TotalCandies = 0;
		while (!empty(q)) {
			int box = q.front();
			q.pop();

			if (status[box]) {
				// 此箱子available
				// 更新总的糖数、更新箱子状态（有钥匙即可将states置1）、更新待检查箱子（队列）
				TotalCandies += candies[box];
				candies[box] = 0;

				for (auto bb : containedBoxes[box]) q.push(bb);
				for (auto k : keys[box]) status[k] = 1;
			}
			else {
				// 将第一个status为1的箱子推到队列头上
				// 若没有status为1的箱子，则返回TotalCandies
				bool allBoxesNotAvailable = true;
				for (int i = 0; i < q.size(); ++i) {
					int bb = q.front();
					if (status[bb] == 0) {
						q.pop();
						q.push(bb);
					}
					else {
						allBoxesNotAvailable = false;
						break;
					}
				}
				q.push(box);
				if (allBoxesNotAvailable) return TotalCandies;
			}
		}
		return TotalCandies;
	}
};

void main() {
	Solution solu;

	vector<int> s{ 1,0,1,0 };
	vector<int> c{ 7,5,4,100 };
	vector<vector<int>> k;
	k.push_back({});
	k.push_back({});
	k.push_back({1});
	k.push_back({});
	vector<vector<int>> cb;
	cb.push_back({1,2});
	cb.push_back({3});
	cb.push_back({});
	cb.push_back({});
	vector<int> ib{ 0 };


	cout << (solu.maxCandies(s, c, k, cb, ib)) << endl;

}