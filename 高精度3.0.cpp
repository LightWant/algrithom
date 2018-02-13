//乘法
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define L(x) (1 << (x))
const double PI = acos(-1.0);
const int Maxn = 133015;
double ax[Maxn], ay[Maxn], bx[Maxn], by[Maxn];
char sa[Maxn/2],sb[Maxn/2];
int sum[Maxn];
int x1[Maxn],x2[Maxn];
int revv(int x, int bits)
{
    int ret = 0;
    for (int i = 0; i < bits; i++)
    {
        ret <<= 1;
        ret |= x & 1;
        x >>= 1;
    }
    return ret;
}
void fft(double * a, double * b, int n, bool rev)
{
    int bits = 0;
    while (1 << bits < n) ++bits;
    for (int i = 0; i < n; i++)
    {
        int j = revv(i, bits);
        if (i < j)
            swap(a[i], a[j]), swap(b[i], b[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        int half = len >> 1;
        double wmx = cos(2 * PI / len), wmy = sin(2 * PI / len);
        if (rev) wmy = -wmy;
        for (int i = 0; i < n; i += len)
        {
            double wx = 1, wy = 0;
            for (int j = 0; j < half; j++)
            {
                double cx = a[i + j], cy = b[i + j];
                double dx = a[i + j + half], dy = b[i + j + half];
                double ex = dx * wx - dy * wy, ey = dx * wy + dy * wx;
                a[i + j] = cx + ex, b[i + j] = cy + ey;
                a[i + j + half] = cx - ex, b[i + j + half] = cy - ey;
                double wnx = wx * wmx - wy * wmy, wny = wx * wmy + wy * wmx;
                wx = wnx, wy = wny;
            }
        }
    }
    if (rev)
    {
        for (int i = 0; i < n; i++)
            a[i] /= n, b[i] /= n;
    }
}
int solve(int a[],int na,int b[],int nb,int ans[])
{
    int len = max(na, nb), ln;
    for(ln=0; L(ln)<len; ++ln);
    len=L(++ln);
    for (int i = 0; i < len ; ++i)
    {
        if (i >= na) ax[i] = 0, ay[i] =0;
        else ax[i] = a[i], ay[i] = 0;
    }
    fft(ax, ay, len, 0);
    for (int i = 0; i < len; ++i)
    {
        if (i >= nb) bx[i] = 0, by[i] = 0;
        else bx[i] = b[i], by[i] = 0;
    }
    fft(bx, by, len, 0);
    for (int i = 0; i < len; ++i)
    {
        double cx = ax[i] * bx[i] - ay[i] * by[i];
        double cy = ax[i] * by[i] + ay[i] * bx[i];
        ax[i] = cx, ay[i] = cy;
    }
    fft(ax, ay, len, 1);
    for (int i = 0; i < len; ++i)
        ans[i] = (int)(ax[i] + 0.5);
    return len;
}
string mul(string sa,string sb)
{
    int l1,l2,l;
    int i;
    string ans;
    memset(sum, 0, sizeof(sum));
    l1 = sa.size();
    l2 = sb.size();
    for(i = 0; i < l1; i++)
        x1[i] = sa[l1 - i - 1]-'0';
    for(i = 0; i < l2; i++)
        x2[i] = sb[l2-i-1]-'0';
    l = solve(x1, l1, x2, l2, sum);
    for(i = 0; i<l || sum[i] >= 10; i++) // 进位
    {
        sum[i + 1] += sum[i] / 10;
        sum[i] %= 10;
    }
    l = i;
    while(sum[l] <= 0 && l>0)    l--; // 检索最高位
    for(i = l; i >= 0; i--)    ans+=sum[i] + '0'; // 倒序输出
    return ans;
}
int main()
{
    cin.sync_with_stdio(false);
    string a,b;
    while(cin>>a>>b)  cout<<mul(a,b)<<endl;
    return 0;
}
//除法
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int L=110;
int sub(int *a,int *b,int La,int Lb)
{
    if(La<Lb) return -1;   //如果a小于b，则返回-1
    if(La==Lb)
    {
        for(int i=La-1;i>=0;i--)
            if(a[i]>b[i]) break;
            else if(a[i]<b[i]) return -1;   //如果a小于b，则返回-1

    }
    for(int i=0;i<La;i++)   //高精度减法
    {
        a[i]-=b[i];
        if(a[i]<0) a[i]+=10,a[i+1]--;
    }
    for(int i=La-1;i>=0;i--)
        if(a[i]) return i+1;   //返回差的位数
    return 0;   //返回差的位数

}
string div(string n1,string n2,int nn)   //n1,n2是字符串表示的被除数，除数,nn是选择返回商还是余数
{
    string s,v;  //s存商,v存余数
     int a[L],b[L],r[L],La=n1.size(),Lb=n2.size(),i,tp=La;   //a，b是整形数组表示被除数，除数，tp保存被除数的长度
     fill(a,a+L,0);fill(b,b+L,0);fill(r,r+L,0);   //数组元素都置为0
     for(i=La-1;i>=0;i--) a[La-1-i]=n1[i]-'0';
     for(i=Lb-1;i>=0;i--) b[Lb-1-i]=n2[i]-'0';
     if(La<Lb || (La==Lb && n1<n2)) {
            //cout<<0<<endl;
     return n1;}    //如果a<b,则商为0，余数为被除数
     int t=La-Lb;   //除被数和除数的位数之差
     for(int i=La-1;i>=0;i--)    //将除数扩大10^t倍
        if(i>=t) b[i]=b[i-t];
        else b[i]=0;
     Lb=La;
     for(int j=0;j<=t;j++)
     {
         int temp;
         while((temp=sub(a,b+j,La,Lb-j))>=0)   //如果被除数比除数大继续减
         {
             La=temp;
             r[t-j]++;
         }
     }
     for(i=0;i<L-10;i++) r[i+1]+=r[i]/10,r[i]%=10;    //统一处理进位
     while(!r[i]) i--;    //将整形数组表示的商转化成字符串表示的
     while(i>=0) s+=r[i--]+'0';
     //cout<<s<<endl;
     i=tp;
     while(!a[i]) i--;    //将整形数组表示的余数转化成字符串表示的</span>
     while(i>=0) v+=a[i--]+'0';
     if(v.empty()) v="0";
     //cout<<v<<endl;
     if(nn==1) return s;
     if(nn==2) return v;
}
