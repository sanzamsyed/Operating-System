#include <bits/stdc++.h>

using namespace std;

struct process
{
    int pid;
    int burst;
    int arrival;
    int turnaround;
    int waiting;
    int completion;
};


bool sortByAT(process a, process b)
{
    return a.arrival < b.arrival;
}
int main()
{
    freopen("input.txt","r",stdin);
    int n;
    cin >> n;

    vector<process>p;
    for(int i = 1; i <= n; i++)
    {
        process temp;
        int a,b;
        cin >> a >> b;
        temp.pid = i;
        temp.arrival = a;
        temp.burst = b;
        temp.turnaround  = 0;
        temp.waiting = 0;
        temp.completion = 0;
        p.push_back(temp);
    }

    sort(p.begin(),p.end(),sortByAT);

    float res = 0;
    int current = p[0].arrival;

    for(int i = 0; i < n; i++)
    {
        p[i].completion = current + p[i].burst;
        current = p[i].completion;

        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;


        res = res + p[i].waiting;
    }

    cout << "result is " << res/n << endl;
}
