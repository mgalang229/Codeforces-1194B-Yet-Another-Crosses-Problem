#include <bits/stdc++.h>
using namespace std;

/*

*****
*.*.*
*****
..*.*
..***

4 3
.*.
***
*.*
.*.

*/

void test_case() {
    int n, m;
    cin >> n >> m;
    char grid[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    // by row
    int row_freq[n];
    memset(row_freq, 0, sizeof(row_freq));
    int id = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++)
            if (grid[i][j] == '.')
                cnt++;
        row_freq[id++] = cnt;
    }
    id = 0;
    // by column
    int col_freq[m];
    memset(col_freq, 0, sizeof(col_freq));
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (grid[j][i] == '.')
                cnt++;
        col_freq[id++] = cnt;
    }
    // cout << "row: ";
    // for (int x : row_freq)
    //     cout << x << " ";
    // cout << "\ncol: ";
    // for (int x : col_freq)
    //     cout << x << " ";
    // cout << "\n\n";
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = row_freq[i] + col_freq[j];
            if (grid[i][j] == '.')
                val--;
            mn = min(mn, val);
        }
    }
    cout << mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
        test_case();
}
