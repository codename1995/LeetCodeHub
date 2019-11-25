
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
/*
作者：mxsyxin
链接：https ://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/cshi-xian-qian-zhui-shu-by-mxsyxin/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
const int N_Max_Sub_Node = 26;
class Trie {
private:
	bool is_end;
	Trie *p[N_Max_Sub_Node];
public:
	Trie() {
		is_end = false;
		memset(p, 0, sizeof(p));
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie* cur = this;		// 初始化为根节点指针
		for (auto ch : word) {
			if (!cur->p[ch - 'a']) {
				Trie* new_node = new Trie();
				cur->p[ch - 'a'] = new_node;
			}
			cur = cur->p[ch - 'a'];
		}
		cur->is_end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie* cur = this;
		bool e = true;	//e - exist
		for (auto ch : word) {
			if (!cur->p[ch - 'a'])
			{
				e = false;
				break;
			}
			cur = cur->p[ch - 'a'];
		}
		return e && cur->is_end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie* cur = this;
		bool e = true;	//e - exist
		for (auto ch : prefix) {
			if (!cur->p[ch - 'a'])
			{
				e = false;
				break;
			}
			cur = cur->p[ch - 'a'];
		}
		return e;
	}
};

int main() {
	Trie* trie = new Trie();
	trie->insert("apple");
	cout << trie->search("apple");   // 返回 true
	cout << trie->search("app");     // 返回 false
	cout << trie->startsWith("app"); // 返回 true
	trie->insert("app");
	cout << trie->search("app");     // 返回 true
	return 0;
}
