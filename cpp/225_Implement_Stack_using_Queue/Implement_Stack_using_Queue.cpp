class MyStack {
public:
	queue<int> q1;
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		q1.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		int n = q1.size();
		for (int i = 0; i != n - 1; i++)
		{
			q1.push(q1.front());
			q1.pop();
		}
		int x = q1.front();
		q1.pop();
		return x;
	}

	/** Get the top element. */
	int top() {
		int n = q1.size();
		for (int i = 0; i != n - 1; i++)
		{
			q1.push(q1.front());
			q1.pop();
		}
		int x = q1.front();
		q1.push(q1.front());
		q1.pop();
		return x;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty();
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */