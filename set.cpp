#include <cstdio>
#include <set>
using namespace std;

int main()
{
    //claim
    set<int> s;

    //insert
    s.insert(1);
    s.insert(8);
    s.insert(9);
    s.insert(5);

    //search way1
    set<int>::iterator ite;

    ite = s.find(9);
    if( ite == s.end() )
        printf("Not Found\n");

    //search way2
    if(s.count(1) == 0)
        printf("Not Found\n");

    //search way3
    for(ite = s.begin(); ite != s.end(); ite++)
        printf("%d\n", *ite);

    //delete
    s.erase(1);

    return 0;
}
