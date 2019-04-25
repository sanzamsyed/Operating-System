#include <bits/stdc++.h>
#define n 3
#define arrivalTime 0
using namespace std;


struct process
{
    int pid;
    int burstTime;
};



int main()
{
    int bt[n] = {24,3,3};

    process p[n];
    int cnt = 1;
    for(int i = 0; i < n; i++)
    {
        p[i].pid = cnt;
        p[i].burstTime = bt[i];
        cnt++;
    }

    ///SORTING BASED ON BURST TIME

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(p[i].burstTime > p[j].burstTime)
                swap(p[i],p[j]);
        }
    }


    ///CHECKING IF THE SORTING WORKS PROPERLY
    for(int i = 0; i <n; i++)
    {
        cout << p[i].pid << " " << p[i].burstTime << endl;
    }

    ///FINDING OUT WAITING TIME

    int startingTime[n+1];
    startingTime[0] = 0;

    for(int i = 1; i < n+1; i++)
    {
        startingTime[i] = startingTime[i-1] + p[i-1].burstTime;
    }



    ///CGECKING STARTING TIME

    cout << "Starting Time:" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << startingTime[i] << endl;
    }

    int waitingTime[n];
    float totalWaitingTime = 0;
    float averageWaitingTime = 0;

    for(int i = 0; i < n; i++)
    {
        waitingTime[i] = startingTime[i] - arrivalTime;
        totalWaitingTime = totalWaitingTime + waitingTime[i];
    }

    averageWaitingTime = totalWaitingTime/n;

    ///DRAWING GANTT CHART


//    for(int i = 0; i < n; i++)
//    {
//        cout << "|---";
//        cout << "P" <<p[i].pid;
//        cout <<"---|";
//
//
//    }

    cout << endl;
    cout << 0 <<"         ";
    for(int i = 1; i < n+1; i++)
    {

         cout <<   startingTime[i] <<"        ";
    }



    cout << endl <<endl << endl;


    cout << "Total Waiting Time is : " << totalWaitingTime << endl;
    cout << "Average Waiting Time is : " << averageWaitingTime << endl;





}
