#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

/*Constants declaration*/
const long double INF = 1e18;
const int NB_NODES_MAX = 1005;
typedef pair<int, pair<long double, long double>> pill; // pair of (distance, node)
vector<pill> nxt[NB_NODES_MAX];                         // graph
int nb_nodes, nb_edges;
unordered_set<long double> flows;

/**Functions declarations */
void readGraph();
void printGraph();
long double get_distance(pill);
long double get_flow(pill);
int main()
{

    readGraph();
    printGraph();

    long double dist[NB_NODES_MAX];
    long double flow[NB_NODES_MAX];

    fill(dist, dist + NB_NODES_MAX, INF);
    fill(flow, flow + NB_NODES_MAX, INF);

    priority_queue<pill, vector<pill>, greater<pill>> p_queue; // Specify the vector container for the priority_queue

    int start_node = 1;
    p_queue.push(make_pair(start_node, make_pair(0, INF))); // (node, (distance, flow)) /: premier flow pas important
    dist[start_node] = 0;

    // take all the flows
    // and iterate over them

    set<long double> all_flows = get_all_flows();
    vector<long double> best_ratio;

    for (auto fl : all_flows)
    {
        cout << "flow: " << fl << endl;

        while (!p_queue.empty())
        {
            // pair<long double, long double> dist_flow_pair;
            auto [node, dist_flow_pair] = p_queue.top();

            p_queue.pop();

            if (dist[node] == dist_flow_pair.first) // lazy priority queue
                for (auto v : nxt[node])
                {
                    // get the min flow first
                    auto [d, f] = dist_flow_pair;

                    if ((d / f) + get_distance(v) / get_flow(v) < dist[v.first] / flow[v.first]) // this will be changed
                    {
                        dist[v.first] = d + get_distance(v);
                        p_queue.push(make_pair(v.first, make_pair(dist[v.first], flow[v.first])));
                    }
                }
        }
    }
}
cout << dist[nb_nodes] << endl;
return 0;
}

void readGraph()
{
    scanf("%d %d", &nb_nodes, &nb_edges);
    for (int i = 1; i <= nb_edges; i++)
    {
        int a, b, w, f;
        scanf("%d %d %d %d", &a, &b, &w, &f);

        pair<long double, long double> dist_flow = make_pair(w, f);
        nxt[a].push_back(make_pair(b, dist_flow));
        nxt[b].push_back(make_pair(a, dist_flow));
    }
}

void printGraph()
{
    for (int i = 1; i <= nb_nodes; i++)
    {
        printf("Node %d: ", i);
        for (auto v : nxt[i])
        {
            printf("(%d, (%Lf,%Lf) ", v.first, v.second.first, v.second.second);
        }
        printf("\n");
    }
}

long double get_distance(pill p)
{
    return p.second.first;
}

long double get_flow(pill p)
{
    return p.second.second;
}

set<long double> get_all_flows()
{
    set<long double> flows;
    for (int i = 1; i <= nb_edges; i++)
    {
        for (auto v : nxt[i])
        {
            flows.insert(v.second.second);
        }
    }
    return flows;
}