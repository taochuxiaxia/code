#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e7 + 10;
ll nxt[N], ext[N];
void qnxt(char *c)
{
	int len = strlen(c);
	int p = 0, k = 1, l; //我们会在后面先逐位比较出 nxt[1] 的值，这里先设 k 为 1
	//如果 k = 0，p 就会锁定在 |c| 不会被更改，无法达成算法优化的效果啦
	nxt[0] = len; //以 c[0] 开始的后缀就是 c 本身，最长公共前缀自然为 |c|
	while(p + 1 < len && c[p] == c[p + 1]) p++;
	nxt[1] = p; //先逐位比较出 nxt[1] 的值
	for(int i = 2; i < len; i++)
	{
		p = k + nxt[k] - 1; //定义
		l = nxt[i - k]; //定义
		if(i + l <= p) nxt[i] = l; //如果灰方框小于初始的绿方框,直接确定 nxt[i] 的值
		else
		{
			int j = max(0, p - i + 1);
			while(i + j < len && c[i + j] == c[j]) j++; //否则进行逐位比较
			nxt[i] = j;
			k = i; //此时的 x + nxt[x] - 1 一定刷新了最大值，于是我们要重新赋值 k
		}
	}
}
void exkmp(char *a, char *b)
{
	int la = strlen(a), lb = strlen(b);
	int p = 0, k = 0, l;
	while(p < la && p < lb && a[p] == b[p]) p++; //先算出初值用于递推
	ext[0] = p;
	for(int i = 1; i < la; i++) //下面都是一样的逻辑啦
	{
		p = k + ext[k] - 1;
		l = nxt[i - k];
		if(i + l <= p) ext[i] = l;
		else
		{
			int j = max(0, p - i + 1);
			while(i + j < la && j < lb && a[i + j] == b[j]) j++;
			ext[i] = j;
			k = i;
		}
	}
}
int la, lb;
char a[N], b[N];
ll ans;
int main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> a >> b;
	qnxt(b);
	exkmp(a, b);
	la = strlen(a), lb = strlen(b), ans = 0;
	for(int i = 0; i < lb; i++) //要注意下标从 0 开始
	{
		ans ^= (i + 1) * (nxt[i] + 1);
	}
	cout << ans << "\n";
	ans = 0;
	for(int i = 0; i < la; i++)
	{
		ans ^= (i + 1) * (ext[i] + 1);
	}
	cout << ans;
	return 0;
}