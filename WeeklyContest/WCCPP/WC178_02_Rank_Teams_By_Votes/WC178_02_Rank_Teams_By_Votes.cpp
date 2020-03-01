#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	string rankTeams(vector<string>& votes) {
		if (votes.size() == 1 || votes[0].size() == 1) return votes[0]; //一人或一队

		// 建二维表，每行是每个字母的得票情况，第一列是得第一的次数，以此类推
		vector<vector<int>> v(26, vector<int>(1010, 0));
		for (auto s : votes) {
			int rank = 0;
			for (char ch : s) ++v[ch - 'A'][rank++];
		}

		// 数据填入26*1000（行和列的最大可能值）的表中
		int N_group = votes[0].size();
		vector<string> prf(26);
		for (int i = 0; i < N_group; ++i) {
			char X = votes[0][i];
			int x = X - 'A';
			for (int j = 0; j < N_group; ++j) {
				prf[x] += to_string(2000 - v[x][j]); //排序从小到大，但我希望从大到小，因此以2000来减，新值域[1000,2000]
			}
			prf[x] += X;// 将字母放在特征值末尾，一方面根据题目要求参与排序，另一方面便于最终取回字母
		}
		// 删除空行
		int l = 0, r = 25;
		while (l < r) {
			while (l < r && prf[r].size() == 0) --r;
			if (prf[l].size() == 0) {
				prf[l++] = prf[r];
				prf[r--] = "";
			}
			else ++l;
		}

		// 根据列进行选择排序
		int mi = 0;
		string res;
		for (int i = 0; i < N_group; ++i) {
			for (int j = i + 1; j < N_group; ++j) {
				if (prf[i].compare(prf[j]) > 0) {
					string t = prf[i];
					prf[i] = prf[j];
					prf[j] = t;
				}
			}
			res.push_back(prf[i].back());
		}
		return res;
	}
};

void main()
{
	Solution so1;
	vector<string> v{ "FVSHJIEMNGYPTQOURLWCZKAX", "AITFQORCEHPVJMXGKSLNZWUY", "OTERVXFZUMHNIYSCQAWGPKJL", "VMSERIJYLZNWCPQTOKFUHAXG",
		"VNHOZWKQCEFYPSGLAMXJIUTR", "ANPHQIJMXCWOSKTYGULFVERZ", "RFYUXJEWCKQOMGATHZVILNSP", "SCPYUMQJTVEXKRNLIOWGHAFZ",
		"VIKTSJCEYQGLOMPZWAHFXURN", "SVJICLXKHQZTFWNPYRGMEUAO", "JRCTHYKIGSXPOZLUQAVNEWFM", "NGMSWJITREHFZVQCUKXYAPOL",
		"WUXJOQKGNSYLHEZAFIPMRCVT", "PKYQIOLXFCRGHZNAMJVUTWES", "FERSGNMJVZXWAYLIKCPUQHTO", "HPLRIUQMTSGYJVAXWNOCZEKF",
		"JUVWPTEGCOFYSKXNRMHQALIZ", "MWPIAZCNSLEYRTHFKQXUOVGJ", "EZXLUNFVCMORSIWKTYHJAQPG", "HRQNLTKJFIEGMCSXAZPYOVUW",
		"LOHXVYGWRIJMCPSQENUAKTZF", "XKUTWPRGHOAQFLVYMJSNEIZC", "WTCRQMVKPHOSLGAXZUEFYNJI"
	};
	string a = so1.rankTeams(v);
	return;
}
