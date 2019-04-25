#include <bits/stdc++.h>
#define time 3

using namespace std;

struct process
{
    int pid;
    int arr;
    int burst;
    int originalburst;
    int waiting;
    int turnaround;
    int completion;
};

bool ATSort(process a, process b)
{
    return a.arr < b.arr ;
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
        int a;
        int b;
        cin >> a >> b;
        temp.pid = i;
        temp.arr = a;
        temp.burst = b;
        temp.originalburst = b;
        temp.waiting = 0;
        temp.turnaround = 0;
        temp.completion = 0;
        p.push_back(temp);

    }

    cout << "Check" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << "Burst" << p[i].burst << endl;
    }


    sort(p.begin(),p.end(),ATSort);

    queue<process>q;
    vector<process> result;

    q.push(p[0]);
    int track = 1;
    int current = 0;

    while(!q.empty())
    {
        process temp;
        temp = q.front();
        if(temp.burst >= time)
        {
            current = current + time;
            temp.burst = temp.burst - time;


        }
        else
        {

            current = current + temp.burst;
            temp.burst = 0;
        }

        for(int i = track; i < n; i++)
        {
            if(p[i].arr <= current)
            {
                q.push(p[i]);
                track++;
            }
        }

        if(temp.burst > 0)
        {
            q.push(temp);
        }
        else
        {
            temp.completion = current;
            result.push_back(temp);
        }

        q.pop();

    }

    float res = 0;
    for(int i = 0; i < n; i++)
    {

        result[i].turnaround = result[i].completion - result[i].arr;

        result[i].waiting = result[i].turnaround - result[i].originalburst;
        res = res + result[i].waiting;
    }

    cout << "Result is " << res/n << endl;




}
