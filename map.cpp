#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
    //声明
    map<int, const char*> m;

    //插入元素
    m.insert(make_pair(1, "ONE"));
    m.insert(make_pair(10, "TEN"));
    m[100] = "HUNDRED";

    //查找元素
    map<int, const char*>::iterator ite;
    ite = m.find(1);
    puts(ite->second);

    ite = m.find(2);
    if(ite == m.end())
        puts("not found");
    else
        puts(ite->second);

    puts(m[10]);

    //删除
    m.erase(10);

    //遍历一遍所有元素
    for(ite = m.begin(); ite != m.end(); ite++)
        printf("%d  %s", ite->first, ite->second);

    return 0;
}
