#include <cstdio>
using namespace std;
typedef long long ll;

ll fastpow_mod(ll x, ll y, ll m) {
    ll base=x, res=1;
    while (y) {
        if (y&1) (res*=base)%=m;
        (base*=base)%=m;
        y>>=1;
    }
    return res;
}

int main() {
    int T;
    scanf("%d", &T);
    ll n;
    while (T--) {
        scanf("%lld", &n);
        printf("%lld\n", fastpow_mod(n, n, 10));
    }
    return 0;
}
