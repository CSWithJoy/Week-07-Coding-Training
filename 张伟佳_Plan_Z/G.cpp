#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<ll, int> pli;
const int maxn=500005;
pli arr[maxn];
int n, st[maxn], b[maxn];

void add(int k, int num) {
    while (k<maxn) {
        st[k]+=num;
        k+=k&-k;
    }
}
int query(int k) {
    int ans=0;
    while (k) {
        ans+=st[k];
        k-=k&-k;
    }
    return ans;
}

int main() {
    ll ans;
    while (scanf("%d", &n)&&n) {
        ans=0;
        for (int i=0;i<n;++i) {
            scanf("%lld", &arr[i].ff);
            arr[i].ss=i;
        }
        sort(arr, arr+n);
        for (int i=0;i<n;++i) {
            b[arr[i].ss]=i+1;
        }
        memset(st, 0, sizeof(st));
        for (int i=0;i<n;++i) {
            ans+=query(maxn-1)-query(b[i]);
            add(b[i], 1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
