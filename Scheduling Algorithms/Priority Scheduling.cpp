#include<bits/stdc++.h>

using namespace std;

struct process
{
    int processNumber;
    int arrivalTime;
    int cpuTime;
    int originalCpuTime;
    int allowedTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
    int priority;
};

int N,CurrentTime=0;
vector <process> v,v1,v2;
queue <process> RunningQueue;


priority_queue <process> pq; //THIS IS THE READY QUEUE

bool myop(process a,process b)
{
    return a.arrivalTime<b.arrivalTime;
}

bool myop1(process a,process b)
{
    return a.processNumber<b.processNumber;
}

bool operator<(process a,process b)
{
    return a.priority>b.priority;;
}

int main(void)
{
    cin>>N;
    for(int i=0; i<N; i++)
    {
        int t;
        process p;
        cin>>t;
        p.processNumber=t;
        cin>>t;
        p.arrivalTime=t;
        cin>>t;
        p.cpuTime=t;
        p.originalCpuTime=t;
        cin>>t;
        p.priority=t;
        v.push_back(p);
    }

    printf("\n\n");
    sort(v.begin(),v.end(),myop);


    for(int i=0; i<N; i++)
    {

        printf("%d  %d  %d %d\n",v[i].processNumber,v[i].arrivalTime,v[i].cpuTime,v[i].priority);
    }

    int track=1;
    pq.push(v[0]);

    while(!pq.empty())
    {

        process p;
        p=pq.top();

        pq.pop();

        if(p.cpuTime>0)
        {
            CurrentTime=CurrentTime+1;
            p.cpuTime=p.cpuTime-1;
            p.allowedTime=CurrentTime;
            RunningQueue.push(p);
        }

        if(p.cpuTime>0)
        {
            pq.push(p);
        }
        else
        {
            p.completionTime=CurrentTime;
            v1.push_back(p);
        }

        if(track<N)
        {

            for(int i=track; i<N; i++)
            {

                if(v[i].arrivalTime<=CurrentTime)
                {
                    pq.push(v[i]);
                    track++;
                }
            }
        }

    }
    printf("\n\n");
    for(int i=0; i<v1.size(); i++)
    {

        printf("%d  %d  %d %d  completion time %d\n",v1[i].processNumber,v1[i].arrivalTime,v1[i].cpuTime,v1[i].priority,v1[i].completionTime);
    }
    while(!RunningQueue.empty())
    {
        process p=RunningQueue.front();
        RunningQueue.pop();
        v2.push_back(p);
    }
    printf("\n\n");

    for(int i=0; i<v2.size(); i++)
    {

        printf("P%d|",v2[i].processNumber);
    }
    printf("\n\n0 ");

    for(int i=0; i<v2.size(); i++)
    {

        printf("%d ",v2[i].allowedTime);
    }
    sort(v1.begin(),v1.end(),myop1);


    printf("\n\n");

    for(int i=0; i<v1.size(); i++)
    {
        v1[i].turnAroundTime=v1[i].completionTime-v1[i].arrivalTime;
        v1[i].waitingTime=v1[i].turnAroundTime-v1[i].originalCpuTime;
        printf("\nP%d Waiting Time %d Arrival Time %d\n",v1[i].processNumber,v1[i].waitingTime,v1[i].turnAroundTime);

    }
    return 0;
}
