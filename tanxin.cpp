#include <iostream>
#include <algorithm>
using namespace std;
// 定义顾客结构体，包含原始编号 id 和服务时间 t
typedef struct {
    int id;
    int t;
} Customer;
// 贪心选择策略：按服务时间从小到大排序 
bool cmp(Customer x, Customer y) {
    return x.t < y.t;
}
int n;
Customer N[105];
int f[105]; // 存储每个顾客的开始服务时刻 
int t_sorted[105]; // 存储排序后的服务时间
// 计算每个顾客开始服务的时刻
void Service() {
    f[1] = 0; // 第1个顾客从时刻0开始服务 
    for (int i = 2; i <= n; i++) {
        // 第i个顾客的开始时间 = 前一个顾客的开始时间 + 前一个顾客的服务时间 
        f[i] = f[i - 1] + t_sorted[i - 1];
    }
}
int main() {
    // 循环处理输入，直到读取不到顾客数量 n
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            N[i].id = i;
            cin >> N[i].t;
        }
        // 1. 按照贪心策略排序：服务时间短的优先 
        sort(N + 1, N + n + 1, cmp);
        // 将排序后的服务时间存入辅助数组
        for (int i = 1; i <= n; i++) {
            t_sorted[i] = N[i].t;
        }
        // 2. 调用 Service 函数计算各顾客的等待时间（开始时刻） 
        Service();
        // 3. 计算总等待时间 (所有顾客开始服务时刻的总和) 
        int totalWaitingTime = 0;
        for (int i = 1; i <= n; i++) {
            totalWaitingTime += f[i];
        }
        // 输出结果：总等待时间
        cout<<"总等待时间" << endl;
        cout << totalWaitingTime << endl;
        // 输出安排的服务顺序（顾客原始 ID）
        cout<<"服务顺序(根据顾客ID)" << endl; 
        for (int i = 1; i <= n; i++) {
            cout << N[i].id << (i == n ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}