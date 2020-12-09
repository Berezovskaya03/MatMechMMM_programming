#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int c[n-1][m-1];
    int dp[n-1][m-1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    dp[0][0] = c[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i || j) {
                if (i - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + c[i][j]);
                }

                if (j - 1 >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] + c[i][j]);
                }
            }
        }
    }

    cout << dp[n - 1][m - 1];
}
