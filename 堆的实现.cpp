/*
#define MAX_N 100

int heap[MAX_N], sz = 0;

void push(int x)
{
    int i = sz++;

    while(i > 0)
    {
        int p = (i - 1) / 2;

        if(heap[p] <= x)
            break;

        heap[i] = heap[p];

        i = p;
    }

    heap[i] = x;
}

int pop()
{
    int ret = heap[0];

    int x = heap[--sz];

    int i = 0;
    while(i * 2 + 1 < sz)
    {
        int a = i * 2 + 1, b = i * 2 + 2;
        if(b < sz && heap[b] < heap[a])
            a = b;

        if(heap[a] >= x)
            break;

        heap[i] = heap[a];

        i = a;
    }

    heap[i] = x;

    return ret;

}
*/
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main()
{
    priority_queue<int> pque;

    pque.push(3);
    pque.push(5);
    pque.push(1);
    pque.push(6);

    while( !pque.empty() )
    {
        cout << pque.top() << '\n';
        pque.pop();
    }

    return 0;
}
