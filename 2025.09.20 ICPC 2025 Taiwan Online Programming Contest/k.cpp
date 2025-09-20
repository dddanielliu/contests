#include <iostream>
#include <vector>

using namespace std;

int main (){

    int n;
    cin >> n;
    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    std::vector<int> row_sum(n, 0);
    std::vector<int> col_sum(n, 0);
    int over_cnt = 0;

    for(int i = 0; i < n;i++) {
        for(int j = 0;j < n; j ++) {
            cin >> grid[i][j];
            row_sum[i] += grid[i][j];
            col_sum[j] += grid[i][j];
            if (grid[i][j] > 1)
                over_cnt += grid[i][j] - 1;
        }
    }

    int cntA = 0;
    for (int i = 0; i < n; ++i) {
        if (row_sum[i] > n)
            cntA += row_sum[i] - n;
        if (col_sum[i] > n)
            cntA += col_sum[i] - n;
    }

    std::cout << std::max(cntA, over_cnt);
}

