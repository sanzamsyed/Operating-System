#include <bits/stdc++.h>

using namespace std;

struct process
{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int turnaround;
    int waiting;
    int completion;
};

bool SortByAT(process a, process b)
{
    return a.arrival < b.arrival;
}


bool SortByPID(process a, process b)
{
    return a.pid < b.pid;
}

bool operator<(process a, process b)
{
    return (a.remaining > b.remaining);
}



int main()
{
    freopen("input.txt","r",stdin);
    vector<process> p;
    vector<pair<int,int> > gannt;
    int n;
    cin >> n;

    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        process temp;
        int a;
        int b;
        cin >> a >> b;
        temp.pid = ++cnt;
        temp.arrival = a;
        temp.burst = b;
        temp.remaining = b; ///Initially rem time = burst time
        temp.completion = 0;
        temp.turnaround = 0;
        temp.waiting = 0;

        p.push_back(temp);

    }

    sort(p.begin(),p.end(),SortByAT);

    priority_queue<process> pq;
    vector<process> result;

    pq.push(p[0]);
    int currentTime = 0;
    int check = 1;

    while(!pq.empty())
    {
        process temp;
        temp = pq.top();
        pq.pop();
        if(temp.remaining > 0)
        {
            currentTime++;
            temp.remaining--;
            pq.push(temp);
            gannt.push_back(make_pair(temp.pid,currentTime));

        }

        else
        {
            temp.completion = currentTime;
            gannt.push_back(make_pair(temp.pid,currentTime));
            result.push_back(temp);

        }

        for(int i = check; i < n; i++)
        {
            if(p[i].arrival <= currentTime)
            {
                pq.push(p[i]);
                check++;
            }
        }
    }

    ///result er vitore shobgulo completed process

    float totWaiting = 0;

    for(int i = 0; i < n; i++)
    {
        result[i].turnaround = result[i].completion - result[i].arrival;
        result[i].waiting = result[i].turnaround - result[i].burst;

        totWaiting = totWaiting + result[i].waiting;


    }


    for(int i = 0; i < gannt.size(); i++)
    {
        cout << "P" << gannt[i].first << "\t";

    }

    cout << endl;



    cout << "AWT: " << totWaiting/n << endl;




















}





















