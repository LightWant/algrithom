#include <cstdio>
#include <iostream>
using namespace std;

#define MAX_N 10

bool used[MAX_N];
int perm[MAX_N];

void permutation(int pos, int n)
{
	if( pos == n + 1){
        for (int i = 1; i <= n; i++) {
		    printf("%d%c", perm[i], i == n?'\n':' ');
	    }
	}

	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
            perm[pos] = i;
			used[i] = true;
			permutation(pos + 1, n);
			used[i] = false;
		}
	}
}
/*
void permutation(int n)
{
	for (int i = 0; i < n; i++) {
		perm[i] = i;
	}

	do {

	} while ( next_permutation(perm, perm + n) );
}
*/

int main()
{
    for (int i = 1; i <= 8; i++) {
		perm[i] = i;
	}

    permutation(1, 8);

    return 0;
}
