//
// P3375 【模板】KMP 字符串匹配
// Created by Lyney's OtherHalf on 2023/9/27 20:53 .
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN int(1e6 + 10)

vector <int> ans;
int l;
vector <int> get_pre(string s){
    int n = s.length();
    vector <int> pi(n);
    for (int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
        if (pi[i] == l && i >= l){
            ans.push_back(i - 2 * l + 1);
        }
    }
    return pi;
}
string a, b;
int main(){
    cin >> a >> b;
    l = b.length();
    b = b + "#" + a;
    vector <int> as = get_pre(b);
    for (int i = 0; i < ans.size(); ++i){
        printf("%d\n", ans[i]);
    }
    for (int i = 0; i < l; i++){
        printf("%d ", as[i]);
    }
}