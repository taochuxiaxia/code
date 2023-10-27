//
// Created by 96454 on 2023/10/4.
//
#include <bits/stdc++.h>
using namespace std;

#define MAXN int(4e4 + 10)
#define INF int(2147483647)

vector <int> ver[MAXN << 4], val[MAXN << 4];
template <typename T> inline void read(T &x){
    int w = 1;char s; x = 0;
    while (!isdigit(s = getchar())) if (s == '-') w = -1;
    while (isdigit(s)) x = (x << 3) + (x << 1), x += s - '0', s = getchar();
    x *= w;
}
void add(int u, int v, int w = 0){
    ver[u].push_back(v);
    val[u].push_back(w);
}
int n, m, k, st, ed;
int d[MAXN << 4];
bool vis[MAXN << 4];
void Dijkstra(int x){
    memset(d,0x3f,sizeof(d));
    d[x]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > points;
    points.push(make_pair(0,x));
    while(!points.empty())
    {
        int u=points.top().second;
        points.pop();
        if(!vis[u])
        {
            vis[u]=1;
            int num = 0;
            for(auto to : ver[u])
            {
                if(d[to]>d[u]+val[u][num])
                {
                    d[to]=d[u]+val[u][num];
                    points.push(make_pair(d[to],to));
                }
                ++num;
            }
        }
    }
}
int main(){
    read(n);read(m);read(k);
    read(st);read(ed);
    for (int i = 1; i <= m; i++){
        int a, b, c;
        read(a);read(b);read(c);
        add(a, b, c);add(b, a, c);
        for (int j = 1; j <= k; j++){
            int aa = a + j * n;
            int bb = b + j * n;
            add(aa, bb ,c);add(bb, aa, c);
            add(aa - n, bb);add(bb - n, aa);
        }
    }
    Dijkstra(st);
    printf("%d", d[ed + (k) * n]);
}