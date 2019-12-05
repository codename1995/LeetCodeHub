#include<vector>
#include<iostream>

using namespace std;
class TicTacToe {
public:
	int cnt;
	vector<int> row_sum;
	vector<int> col_sum;
	vector<int> diag_sum;
	int nn;
	/** Initialize your data structure here. */
	TicTacToe(int n) {
		cnt = 0;
		nn = n;
		row_sum = vector<int>(n, 0);
		col_sum = vector<int>(n, 0);
		diag_sum = vector<int>(2, 0);
	}

	void updateGrid(int r, int c, int player) {
		int x = player == 2 ? 1 : -1;
		row_sum[r] += x;
		col_sum[c] += x;
		if (r == c) diag_sum[0] += x;
		if ((r + c) == (nn - 1)) diag_sum[1] += x;
	}

	int check(int r, int c, int player) {
		for (int i = 0; i < nn; ++i) {
			if (nn == abs(row_sum[i])) return player;
			if (nn == abs(col_sum[i])) return player;
		}
		if (nn == abs(diag_sum[0]) || nn == abs(diag_sum[1])) return player;
		return 0;
	}

	/** Player {player} makes a move at ({row}, {col}).
		@param row The row of the board.
		@param col The column of the board.
		@param player The player, can be either 1 or 2.
		@return The current winning condition, can be either:
				0: No one wins.
				1: Player 1 wins.
				2: Player 2 wins. */
	int move(int row, int col, int player) {
		++cnt;
		updateGrid(row, col, player);

		if (cnt >= nn) // 若轮流下棋，则cnt>=2*nn+1
			return check(row, col, player);
		return 0;
	}
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */