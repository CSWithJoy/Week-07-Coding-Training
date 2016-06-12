// handcrafted by njzwj
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
const int maxn=5;
struct Matrix {
    ll m[maxn][maxn];
    Matrix () {
        clear();
    }
    void diag1() {
        for (int i=0;i<maxn;++i) 
            for (int j=0;j<maxn;++j) 
                m[i][j]=(i==j);
    }
    void clear() {
        memset(m, 0, sizeof(m));
    }
    void out() {
        for (int i=0;i<maxn;++i) {
            for (int j=0;j<maxn;++j) printf("%lld ", m[i][j]);
            printf("\n");
        }
    }
    Matrix operator*(const Matrix &rhs) const {
        Matrix ans;
        for (int i=0;i<maxn;++i) {
            for (int j=0;j<maxn;++j) {
                ans.m[i][j]=0;
                for (int k=0;k<maxn;++k) {
                    ans.m[i][j]+=m[i][k]*rhs.m[k][j];
                    ans.m[i][j]%=mod;
                }
            }
        }
        return ans;
    }
};

Matrix operator^(const Matrix& m, ll n) {
    Matrix base=m, res;
    res.diag1();
    while (n) {
        if (n&1) res=res*base;
        base=base*base;
        n>>=1;
    }
    return res;
}

int main() {
    ll a0, b0, ax, ay, bx, by, n;
    Matrix m;
    while (scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &a0, &ax, &ay, &b0, &bx, &by)!=EOF) {
        m.clear();
        if (n==0) {
            printf("0\n");
            continue;
        }
        m.m[0][0]=ax%mod;
        m.m[4][0]=ay%mod;
        m.m[1][1]=bx%mod;
        m.m[4][1]=by%mod;
        m.m[0][2]=m.m[0][3]=(ax*by)%mod;
        m.m[1][2]=m.m[1][3]=(ay*bx)%mod;
        m.m[2][2]=m.m[2][3]=(ax*bx)%mod;
        m.m[4][2]=m.m[4][3]=(ay*by)%mod;
        m.m[3][3]=m.m[4][4]=1;
        m=m^(n-1);
        a0%=mod;
        b0%=mod;
        printf("%lld\n", (mod*5+(a0*m.m[0][3])%mod+(b0*m.m[1][3])%mod+((a0*b0)%mod*m.m[2][3])%mod+((a0*b0)%mod*m.m[3][3])%mod+(m.m[4][3])%mod)%mod);
    }
    return 0;
}