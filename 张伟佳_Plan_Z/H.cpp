#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;
const int maxn=1000005;
pii arr[maxn];
ll st[1005];

void add(int k, int num) {
    while (k<=1000) {
        st[k]+=num;
        k+=k&-k;
    }
}

ll query(int k) {
    ll ans=0;
    while (k) {
        ans+=st[k];
        k-=k&-k;
    }
    return ans;
}

int main() {
    int m, n, k, icase=1, T;
    ll ans=0;
    scanf("%d", &T);
    while (T--) {
        ans=0;
        scanf("%d%d%d", &n, &m, &k);
        for (int i=0;i<k;++i) {
            scanf("%d%d", &arr[i].ff, &arr[i].ss);
        }
        sort(arr, arr+k);
        memset(st, 0, sizeof(st));
        for (int i=0;i<k;++i) {
            ans+=query(1000)-query(arr[i].ss);
            add(arr[i].ss, 1);
        }
        printf("Test case %d: %lld\n", icase++, ans);
    }
    return 0;
}
