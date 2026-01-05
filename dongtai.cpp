#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int k, y;
    int g[4][4];    // g[k][x]
    int F[4][11] = {0};  // 初始化为0
    int Re[4][11] = {0}; // 记录决策
    int z[4];
    // 输入
    cin >> k >> y;  // k=3, y=10
    // 输入g函数值
    for(int x = 0; x <= 3; x++) {
        for(int i = 1; i <= k; i++) {
            cin >> g[i][x];
        }
    }
    // 动态规划
    for(int i = 1; i <= k; i++) {       // 考虑前i个变量
        for(int j = 0; j <= y; j++) {   // 平方和限制
            int max_val = 0;
            int best_x = 0;
            // 遍历x_i的可能取值
            for(int x = 0; x * x <= j; x++) {
                int value;
                if(i == 1) {
                    // F?(y) = g?(使g?最大的x?)
                    value = g[i][x];
                } else {
                    value = F[i-1][j - x*x] + g[i][x];
                }
                if(value > max_val) {
                    max_val = value;
                    best_x = x;
                }
            }
            F[i][j] = max_val;
            Re[i][j] = best_x;
        }
    }
    // 输出最大值
    cout << "最大值"<< F[k][y] << endl;
    // 回溯求具体解
    int i = k;
    int remaining_y = y;
    while(i > 0) {
        z[i] = Re[i][remaining_y];
        remaining_y -= z[i] * z[i];
        i--;
    }
    cout << "x取值为"<< F[k][y] << endl;
    // 输出解
    for(i = 1; i <= k; i++) {
        cout << z[i] << ",";
    }
    cin >> k >> y;
    return 0;
}