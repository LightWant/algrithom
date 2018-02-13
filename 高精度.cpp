#include <stdio.h>
#include <string.h>
#define MAXLEN 200

int compare(char a[], char b[])
{
    int la = strlen(a), lb = strlen(b);

    if( la > lb )
        return 1;
    else if( la < lb )
        return -1;
    else
        for(int i = 0; i < la; ++i)
            if( a[i] > b[i] )
                return 1;
            else if( a[i] < b[i] )
                return -1;

    return 0;
}

//num1，num2存进c
int highadd( char num1[], char num2[], int c[] )
{
    int lena = strlen(num1), lenb = strlen(num2), lenc, i, x;//x 是上一位进的
    int a[100], b[100];

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));

    for( i = 0; i < lena; i++)
        a[lena - i - 1] = num1[i] - '0';

    for( i = 0; i < lenb; i++)
        b[lenb - i - 1] = num2[i] - '0';

    lenc = 0;
    x = 0;
    while( lenc <= lena || lenc <= lenb )
    {
        c[lenc] = a[lenc] + b[lenc] + x;
        x = c[lenc] / 10;
        c[lenc] %= 10;
        lenc++;
    }
    c[lenc] = x;

    if( c[lenc] == 0 )
        lenc--;

    return lenc;
}
//str1,str2是存数字的字符串，返回最后的位数
int highmult( char str1[], char str2[], int c[] )
{
    int len1 = strlen(str1), len2 = strlen(str2);
    int a[len1 + 1] = {0}, b[len2 + 1] = {0};
    int i, j;

    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));//用这个函数写1000阶乘时这句话没用了，不知道为啥，可把我无奈坏了，找了半天错

    for( i = len1 - 1, j = 0; i >= 0; i--)
        a[j++] = str1[i] - '0';

    for( i = 0; i < len1; i++)
        printf("W%d\n",a[i]);

    for( i = len2 - 1, j = 0; i >= 0; i--)
        b[j++] = str2[i] - '0';

    for( i = 0; i < len2; i++)
        printf("A%d\n",b[i]);

    for( i = 0; i < len1; i++)//i, j是权重，i+j就是c[]里面的权重
        for( j = 0; j < len2; j++)
        {
            c[i + j] += a[i] * b[j];
            printf("%d\n", c[i + j]);
            if( c[i + j] >= 10 )//因为9 + 9 * 9 < 100，所以只进一位
            {
                int k = c[i + j];
                c[i + j + 1] += k / 10;
                c[i + j] = k % 10;
            }
        }

    for( i = len1 + len2 + 2; (c[i] == 0) && (i >= 0); i-- )
        ;

    return i + 1;
}

int highsub( char a[], char b[], int c[] )
{
    for(int i = 0; i < MAXLEN; ++i)
        c[i] = 0;

    int la = strlen(a), lb = strlen(b);
    int sign(0), m(0);
    int com = compare(a, b);

    if( com > 0 )
    {
        sign = 1;
        m = la;
    }
    else if( com < 0)
    {
        sign = -1;
        m = lb;
    }
    else
        return 1;

    if(sign == 1)
    {
        int sub = la - lb;
        for(int i = 0; i < sub; ++i)
            c[i] = a[i] - '0';

        for(int i = sub; i < m; ++i)
        {
            if( a[i] > b[i - sub])
                c[i] = a[i] - b[i - sub];
            else if( a[i] == b[i - sub] )
                ;
            else
            {
                --c[i - 1];
                c[i] = (a[i] - '0') + 10 - (b[i - sub] - '0');
            }
        }
    }
    else
    {
        int sub = lb - la;
        for(int i = 0; i < sub; ++i)
            c[i] = b[i] - '0';//printf("%d\n", c[0]);

        for(int i = sub; i < m; ++i)
        {
            if( b[i] > a[i - sub])
                c[i] = b[i] - a[i - sub];
            else if( a[i - sub] == b[i])
                ;
            else
            {
                --c[i - 1];
                c[i] = (b[i] - '0') + 10 - (a[i - sub] - '0');
            }
        }
    }

    for(int i = m - 1; i >= 0; --i)
        if( c[i] < 0 )
        {
            --c[i - 1];
            c[i] += 10;
        }

    if(c[0] == 0)
        for(int i = 1; i < MAXLEN; ++i)
            if( c[i] != 0 )
            {
                for(int j = i; j < m; ++j)
                    c[j - i] = c[j];
                m -= i;
                break;
            }

    c[0] *= sign;

    return m;
}

int highdiv( char a[], char b[], char c[], int n )//因为要有小数点，就存字符了
{
    int d[MAXLEN];
    int j(0), k(0);
    int zs;

    while( compare( a, b ) >= 0 )
    {
        int len = highsub(a, b, d);
        memset(a, 0, sizeof(0));
        for(int i = 0; i < len; ++i)
            a[i] = d[i] + '0';
        a[len] = '\0';

        ++c[j];

        if(c[j] >= 10)
        {
            for(int i = j; i > 0; --i)
                if( c[i] >= 10 )
                {
                    ++c[i - 1];
                    c[i] %= 10;
                }

            if(c[0] >= 10)
            {
                for(int i = j; i >= 0; --i)
                    c[i + 1] = c[i];
                c[0] = 1;
                c[1] = 0;
                ++j;
            }
        }
    }

    zs = j + 2;

    for(int i = strlen(a); i < MAXLEN && k <= n; ++i, ++k)
    {
        a[i] = '0';
        if( k == n )
            a[i + 1] = '\0';
    }

    j += 2;
    while( compare( a, b ) >= 0 )
    {
        int len = highsub(a, b, d);
        memset(a, 0, sizeof(0));
        for(int i = 0; i < len; ++i)
            a[i] = d[i] + '0';
        a[len] = '\0';

        ++c[j];

        if(c[j] >= 10)
        {
            for(int i = j; i > zs; --i)
                if( c[i] >= 10 )
                {
                    ++c[i - 1];
                    c[i] %= 10;
                }

            if(c[zs] >= 10)
            {
                for(int i = j; i >= zs; --i)
                    c[i + 1] = c[i];
                c[zs] = 1;
                c[zs + 1] = 0;
                ++j;
            }
        }
    }

    k = j;
    if( c[k] >= 5 )
        do
        {
            ++c[k - 1];
            c[k] = 0;
        }
        while( c[--k] >= 10 );

    j = zs + n;

    for(int i = 0; i <= j; ++i)
        c[i] += '0';

    c[zs - 1] = '.';

    c[j] = '\0';

    return j + 1;
}

int main()
{
    int a[MAXLEN+ 10], b[MAXLEN+ 10], len1, len2, i, j;
    char str1[MAXLEN + 10], str2[MAXLEN + 10];
    char c[2 * MAXLEN + 10];

    for( i = 0; i < MAXLEN; i++)
        a[i] = b[i] = 0;

    for( i = 0; i < MAXLEN; i++)
        c[i] = '\0';

    scanf("%s%s",str1, str2);

    //printf("%d\n", highmult( str1, str2, c ));
    //printf("%dA\n", highadd( str1, str2, c ));
    //printf("%d\n", len1 = highsub( str1, str2, c ));
    printf("%d\n", len1 = highdiv( str1, str2, c, 4));
    //gets(str1); len1 = strlen(sre1);
    //gtes(str2); len2 = srelen(str2);

    //for( int i = 0; i < len1; i++)
    //  printf("%d",c[i]);

    printf("%s", c);

    return 0;
}
