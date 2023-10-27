//
// Created by 96454 on 2023/10/6.
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN 2100

int t[MAXN], a[MAXN], b[MAXN], best_ans, ans;
int n;
vector<int> A, B;

bool cmpa(int x, int y){
    if (b[x] != b[x]) return b[x] < b[x];
    return a[x] < a[x];
}
bool cmpb(int x, int y){
    if (a[x] != a[x]) return a[x] < a[x];
    return b[x] < b[x];
}

inline void calc(){
    int costa[2] = {0, 0}, costb[2] = {0, 0};
    for (auto i : A){
        costa[0] += a[i];
    }
    for (auto i : B){
        costb[0] += b[i];
        costa[0] = max(costa[0], costb[0]) + a[i];
    }
    for (auto i : A){
        costb[1] += b[i];
    }
    for (auto i : B){
        costa[1] += a[i];
        costb[1] = max(costb[1], costa[1]) + b[i];
    }
    ans = max(max(costa[0], costa[1]), max(costb[0], costb[1]));
}
inline void trytry(){
    if (rand() % 2 && A.size()){
        int x = rand() % A.size(), y = rand() % A.size();
        ans = 0;
        swap(A[x], A[y]);
        calc();
        if (ans < best_ans){
            best_ans = ans;
        }
        else swap(A[x], A[y]);
        return;
    }
    else if (B.size()){
        int x = rand() % B.size(), y = rand() % B.size();
        ans = 0;
        swap(B[x], B[y]);
        calc();
        if (ans < best_ans){
            best_ans = ans;
        }
        else swap(B[x], B[y]);
        return;
    }
}
inline void tryy(){
    sort(A.begin(), A.end(), cmpa);
    sort(B.begin(), B.end(), cmpb);
    for (int i = 1; i <= 3000; i++){
        trytry();
    }
}
inline void dfs(int x){
    if (x == n + 1){
        tryy();
        return;
    }
    if (t[x] == 1){
        A.push_back(x);
        dfs(x + 1);
        A.pop_back();
        return;
    }
    else if (t[x] == 2){
        B.push_back(x);
        dfs(x + 1);
        B.pop_back();
        return;
    }
    else{
        A.push_back(x);dfs(x + 1);A.pop_back();
        B.push_back(x);dfs(x + 1);B.pop_back();
        return;
    }
}
int main(){
    srand(time(0));
    best_ans = 0x3f3f3f3f;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d%d%d", &t[i], &a[i], &b[i]);
    }
    dfs(1);
    printf("%d", best_ans);
}
