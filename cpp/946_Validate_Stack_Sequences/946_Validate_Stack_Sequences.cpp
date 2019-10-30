#include<vector>
#include<stack>
#include<iostream>
#include<cstring>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> s;
		int j = 0;
		for (int i = 0; i < pushed.size(); i++)
		{
			s.push(pushed[i]);
			while (!s.empty() && j < popped.size() && s.top() == popped[j])
			{
				s.pop();
				j++;
			}
		}
		if (s.empty()) return true;
		return false;
	}
};


