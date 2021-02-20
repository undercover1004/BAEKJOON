#include <iostream>

using namespace std;

int arr[1025][1025];
int dp[1025][1025];
int n, m;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == 1 && i == 1) dp[i][j] = arr[i][j];
			else if (j - 1 == 0)
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (i - 1 == 0)
				dp[i][j] = dp[i][j - 1] + arr[i][j];
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
	}
	// 시간초과가 생겨서 dp로 해결
	// 그래도 생겨서 endl을 '\n'으로 바꿨더니 해결
}