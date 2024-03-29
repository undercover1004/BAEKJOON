#include <iostream>
#define MOD 1000000007
using namespace std;
int n, m;
long long int dp[1001][1001];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) dp[i][0] = 1;
	for (int j = 0; j < m; j++)dp[0][j] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] += dp[i][j - 1];
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= MOD;
		}
	}

	cout << dp[n - 1][m - 1];
}