#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <utility>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second
const int maxn=100005;
struct P {
    int x, y, id;
    P() {}
    P(int x, int  y, int id):x(x), y(y), id(id) {}
    bool operator <(const P &rhs) const {
        return (x==rhs.x)?y>rhs.y:x<rhs.x;
    }
};P pts[maxn];
int st[maxn], ans[maxn];

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
    int n;
    while (scanf("%d", &n) && n>0) {
        memset(ans, 0, sizeof(ans));
        memset(st, 0, sizeof(st));
        for (int i=0;i<n;++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            pts[i]=P(x, y, i);
        }
        sort(pts, pts+n);
        for (int i=0;i<n;++i) {
            int x=pts[i].x, y=pts[i].y, id=pts[i].id;
            if (i>0&&pts[i-1].x==x&&pts[i-1].y==y) {
                ans[id]=ans[pts[i-1].id];
                add(y, 1);
            }else {
                ans[id]=query(maxn-1)-(y>0?query(y-1):0);
                add(y, 1);
            }
        }
        for (int i=0;i<n;++i) printf("%d%c", ans[i], (i<n-1)?' ':'\n');
    }
    return 0;
}
