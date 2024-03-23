#include <iostream>
#include <vector>

using namespace std;

const int ID_NODE_MAX = 1000;

const int N, M;
const int NOT_VISITED = 0, IN_VISIT = 1, VISITED = 2;
int state[ID_NODE_MAX];

vector<int> nxt_blue[ID_NODE_MAX];
vector<int> nxt_red[ID_NODE_MAX];

int main()
{

    cin >> N >> M;

    int light[N][N]{0};

    for (size_t i; i < M; i++)
    {
    }
}

void dfs(int node)
{
    if (state[node] == NOT_VISITED)
    {
        state[node] = IN_VISIT;
        for (auto v : nxt[node])
            dfs(v);
        state[node] = VISITED;
    }
}