#include<vector>
#include<cstring>
#include<iostream>
#include<stack>

using namespace std;


class MinStack {
public:
	vector<int> v;
	vector<int> min_value;
	
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		v.push_back(x);
		if (min_value.empty() || x < min_value.back())
			min_value.push_back(x);
		else
			min_value.push_back(min_value.back());
	}

	void pop() {
		min_value.pop_back();
		v.pop_back();
	}

	int top() {
		return v.back();
	}

	int getMin() {
		return min_value.back();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */