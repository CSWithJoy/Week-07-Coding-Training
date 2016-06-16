#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2;
const ll mod=1000000007;
struct Matrix {
    ll m[maxn][maxn];
    Matrix() {}
    void clear() {
        memset(m, 0, sizeof(m));
    }
    void set1() {
        for (int i=0;i<maxn;++i)
            for (int j=0;j<maxn;++j)
                m[i][j]=(i==j)?1:0;
    }
    Matrix operator*(const Matrix &rhs) {
        Matrix ans;
        for (int i=0;i<maxn;++i) {
            for (int j=0;j<maxn;++j) {
                ans.m[i][j]=0;
                for (int k=0;k<maxn;++k) {
                    ans.m[i][j]+=(m[i][k]*rhs.m[k][j])%mod;
                    ans.m[i][j]%=mod;
                }
            }
        }
        return ans;
    }
};

Matrix fastpow(Matrix m, ll n) {
    Matrix base=m, res;
    res.set1();
    while (n) {
        if (n&1) { res=base*res; }
        base=base*base;
        n>>=1;
    }
    return res;
}

int main() {
    ll f1, f2, n;
    scanf("%I64d%I64d%I64d", &f1, &f2, &n);
    Matrix trans;
    trans.clear();
    trans.m[0][1]=1;
    trans.m[1][0]=-1;
    trans.m[1][1]=1;
    trans=fastpow(trans, n-1);
    printf("%I64d\n", (mod+mod+(f1*trans.m[0][0])%mod+(f2*trans.m[0][1])%mod)%mod);
    return 0;
}
