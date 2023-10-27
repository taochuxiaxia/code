#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define MOD 1e9

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>tr;
signed main(){
// 	freopen("pbds.in","r",stdin);
// 	freopen("pbds.out","w",stdout);
	int n, num, x;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld %lld", &num, &x);
		if (num == 1){
			tr.insert((x << 20) + i);
		}
		else if (num == 2){
			tr.erase(tr.lower_bound(x << 20));
		}
		else if (num == 3){
			printf("%lld\n", (int)(tr.order_of_key(x << 20)) + 1);
		}
		else if (num == 4){
			printf("%lld\n", (int)((*tr.find_by_order(x - 1)) >> 20));
		}
		else if (num == 5){
			printf("%lld\n", (int)((*(--tr.lower_bound(x << 20)) ) >> 20));
		}
		else{
			printf("%lld\n", (int)((*tr.upper_bound((x << 20) + n)) >> 20));
		}
	}
}
