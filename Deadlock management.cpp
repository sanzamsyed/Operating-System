/*

Author : Syed Sanzam
Course No. : 3124
Course Title: Operating System Lab
Session: 07 Deadlock management with Resource Allocation Graph


*/


#include <bits/stdc++.h>

#define MAX 100
#define UNVISITED 1
#define WORKING 2
#define FINISHED 3

using namespace std;

vector<int>graph[MAX];
vector<int>cycle(MAX);
vector<int>status(MAX);

int vertex;
int edge;
bool isCyclic = false;


int ToInt(char c)
{
    return int(c - 'a');
}

char ToChar(int i)
{
    return char(i + 'a');
}


void Create()
{
    cin >> vertex >> edge;
    for(int i = 0; i < edge; i++)
    {
        char u;
        char v;
        int uInt;
        int vInt;

        cin >> u >> v;
        uInt = ToInt(u);
        vInt = ToInt(v);

        status[uInt] = UNVISITED;
        status[vInt] = UNVISITED;

        graph[uInt].push_back(vInt);
    }
}



int DfsStart(int node)
{
    cycle.push_back(node);
    status[node] = WORKING;
    for(int i = 0; i < (int)graph[node].size(); i++)
    {
        int adjNode = graph[node][i];

        if(status[adjNode] == WORKING)
        {
            isCyclic = true;
            cout << "Cycle Found!" << endl;
            int trackParent = 0;
            while(cycle[trackParent] != adjNode) trackParent++;
            for(int j = trackParent; j <cycle.size(); j++)
            {
                cout << ToChar(cycle[j]) << " ";
            }

            cout << endl;


        }

        if(status[adjNode] == UNVISITED)
        {
            DfsStart(adjNode);

        }


    }

        cycle.pop_back();
        status[node] = FINISHED;

}





void Dfs()
{
    for(int i = 0; i < MAX; i++)
    {
        if(status[i] == UNVISITED)
        {
            cycle.clear();
            DfsStart(i);
        }
    }
}



int main()
{
    Create();
    Dfs();







}
