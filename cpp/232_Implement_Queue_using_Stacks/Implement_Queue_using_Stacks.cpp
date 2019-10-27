#include<stack>
class MyQueue {
public:

	stack<int> s1;
	stack<int> s2;

	void s1tos2() {
		while (!s1.empty()) {
			int x = s1.top();
			s1.pop();
			s2.push(x);
		}
	}

	/** Initialize your data structure here. */
	MyQueue() {

	}

	/** Push element x to the back of queue. */
	void push(int x) {
		s1.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (s2.empty())
			s1tos2();
		int x = s2.top();
		s2.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		if (s2.empty())
			s1tos2();
		return s2.top();
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return (s1.empty() && s2.empty());
	}

};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */