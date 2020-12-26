//#define _GLIBCXX_DEBUG
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
typedef long long ll;
int W, H, N, D, B;
void dfs(int x, int y, int& cnt, vector<vector<int>> &boms) {
	boms[x][y] = 0;
	cnt++;
	//x方向に探索
	for (int dx = -D; dx <= D; dx++) {
		int nx = x + dx;
		if (nx < 0 || nx >= W || y < 0 || y >= H) continue;
		else if (boms[x + dx][y] == 1) {
			dfs(x + dx, y, cnt, boms);
		}
	}
	//y方向に探索
	for (int dy = -D; dy <= D; dy++) {
		int ny = y + dy;
		if (ny < 0 || ny >= H || x < 0 || x >= W) continue;
		else if (boms[x][y + dy] == 1) {
			dfs(x, y + dy, cnt, boms);
		}
	}
}
int main() {
	while (1) {
		cin >> W >> H >> N >> D >> B;
		vector<vector<int>> boms(W, vector<int>(H, 0));
		vector<int> X(N), Y(N);
		if (W == 0 && H == 0 && N == 0 && D == 0 && B == 0) break;
		//0-indexにする
		B--;
		for (int i = 0; i < N; i++) {
			cin >> X[i] >> Y[i];
			X[i]--, Y[i]--;
			boms[X[i]][Y[i]] = 1;
		}
		int cnt = 0;
		dfs(X[B], Y[B], cnt, boms);
		cout << cnt << endl;
	}
	return 0;
}