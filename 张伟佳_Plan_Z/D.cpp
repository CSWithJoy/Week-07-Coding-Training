#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=(1<<16)+1;
int st[maxn], ans[15005];

void add(int k, int num) {
    while (k<maxn) {
        st[k]+=num;
        k+=k&-k;
    }
}

int query(int k) {
    int sum=0;
    while (k) {
        sum+=st[k];
        k-=k&-k;
    }
    return sum;
}

int main() {
    int n, x, y;
    scanf("%d", &n);
    memset(st, 0, sizeof(st));
    memset(ans, 0, sizeof(ans));
    for (int i=0;i<n;++i) {
        scanf("%d%d", &x, &y);
        ++x;
        ans[query(x)]++;
        add(x, 1);
    }
    for (int i=0;i<n;++i) printf("%d\n", ans[i]);
    return 0;
}