#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define MAX_N 100
#define MAX_M 100

int N, M;//line and cow

char maze[MAX_N][MAX_M + 1];//maze

int sx, sy;//the start point
int gx, gy;//the goal point

int d[MAX_N][MAX_M];//record the distance

//(dx, dy) is the vector that determine which direction to go
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

const int INF = 100000000;//a number which is big enough
typedef pair<int, int> pr;//point

queue <pr> que;//queue ( the core data structure of BFS)

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> maze[i];
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			if (maze[i][j] == 'G')
			{
				gx = i;
				gy = j;
			}
			d[i][j] = INF;//initialize distance by a big number
		}

	}

	que.push(pr(sx, sy));
	d[sx][sy] = 0;

	while (que.size())
	{
		pr p = que.front(); que.pop();

		if (p.first == gx && p.second == gy)
			break;

		for (int i = 0; i < 4; i++)
		{
		    //use vectors to go to the four directions
			int nx = p.first + dx[i], ny = p.second + dy[i];

			//if the point is fine to go
			if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
			{
				que.push(pr(nx, ny));//push it into the queue
				d[nx][ny] = d[p.first][p.second] + 1;//record distance
			}
		}
	}

	cout << d[gx][gy] << endl;

	return 0;
}

