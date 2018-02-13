#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
    //����
    map<int, const char*> m;

    //����Ԫ��
    m.insert(make_pair(1, "ONE"));
    m.insert(make_pair(10, "TEN"));
    m[100] = "HUNDRED";

    //����Ԫ��
    map<int, const char*>::iterator ite;
    ite = m.find(1);
    puts(ite->second);

    ite = m.find(2);
    if(ite == m.end())
        puts("not found");
    else
        puts(ite->second);

    puts(m[10]);

    //ɾ��
    m.erase(10);

    //����һ������Ԫ��
    for(ite = m.begin(); ite != m.end(); ite++)
        printf("%d  %s", ite->first, ite->second);

    return 0;
}
