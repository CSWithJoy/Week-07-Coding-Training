#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10000005;
int st[maxn];
int m, n, k, j, tot;

void add(int k, int x) {
    while (k<=n+1) {
        st[k]+=x;
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

int find(int x) {
    //printf("%d %d\n", x, tot);
    x=(x-1)%tot+1;
    int l=1, r=n+2, mid;
    while (l<r) {
        mid=(l+r)>>1;
        if (query(mid)>=x) {
            r=mid;
        }else {
            l=mid+1;
        }
    }
    return l;
}

int main() {
    int ans1, ans2, cur;
    ans1=ans2=-1;
    scanf("%d%d%d%d", &n, &m, &k, &j);
    tot=n+1;
    cur=(m-1)%(n+1)+1;
    memset(st, 0, sizeof(st));
    for (int i=1;i<=n+1;++i) add(i, 1);
    for (int i=1;(ans1<0||ans2<0);++i) {
        add(cur, -1);
        --tot;
        //printf("%d\n", cur);
        if (i==k) ans1=cur;
        if (cur==j) ans2=i;
        cur=find(query(cur)+m);
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
