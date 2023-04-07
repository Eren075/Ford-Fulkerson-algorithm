#include<bits/stdc++.h>
using namespace std;

#define V 6 // Graph'un toplam d���m say�s�

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    bool visited[V];
    memset(visited, 0, sizeof(visited)); // visited dizisini s�f�rla

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) // BFS algoritmas�n� uygula
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0) // E�er hen�z ziyaret edilmemi� ve artan bir yol varsa
            {
                q.push(v); // Kuyru�a ekle
                parent[v] = u; // Parent dizisini g�ncelle
                visited[v] = true; // Ziyaret edildi olarak i�aretle
            }
        }
    }
    return (visited[t] == true); // Hedef d���me ula��labildi mi?
}

int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v]; // Residual Graph'u ba�lang��ta graf ile ayn� yap

    int parent[V];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) // BFS algoritmas�n� kullanarak artan bir yol bulana kadar d�ng�y� s�rd�r
    {
        int path_flow = INT_MAX; // Artan yoldaki minimum kapasiteyi bulmak i�in MAX_INT ile ba�lat

        for (v = t; v != s; v = parent[v]) // Yolun t�m d���mlerini dola�arak minimum kapasiteyi bul
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) // Yolu yeniden dola�arak residual graph'u g�ncelle
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow; // Artan yoldaki minimum kapasiteyi maksimum ak��a ekle
    }

    return max_flow; // Maksimum ak��� d�nd�r
}

int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      }; // �rnek bir graph

     cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);

    return 0;
}
