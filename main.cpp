#include <iostream>
#include <vector>

using namespace std;

int ploca[100][100];
int trans_T[100][100];
int s, r, k;

int max_(vector<int> nns) {
	int max_broj = nns[0];
	for (int nn : nns) {
		if (nn > max_broj) {
			max_broj = nn;
		}
	}

	return max_broj;

}

int dinamika(int x, int y, int moves) {
	if (x == s - 1) {
		return ploca[x][y];
	}

	if (trans_T[x][y] != 0) {
		return trans_T[x][y];
	}

	int value;

	if (moves == 0) {
		value = ploca[x][y] + dinamika(x + 1, y, moves);
	}
	else {
		value = ploca[x][y] + max_({ dinamika(x + 1, y, moves) , dinamika(x + 1, y + 1, moves - 1) , dinamika(x + 1, y - 1, moves - 1) });
	}

	trans_T[x][y] = value;

	return value;
}

int main(void) {
	cin >> r >> s >> k;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < r; j++) {
			int broj;
			cin >> broj;
			ploca[i][j] = broj;
		}
	}

	int max_value = 0;

	for (int i = 0; i < r; i++) {
		int this_value = dinamika(0, i, k);
		if (this_value > max_value) {
			max_value = this_value;
		}
	}

	cout << max_value;

}
