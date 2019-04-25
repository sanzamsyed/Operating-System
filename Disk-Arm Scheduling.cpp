/*

Author : Syed Sanzam
Course No. : 3124
Course Title: Operating System Lab
Session: 12 Disk-Arm Scheduling


*/




#include <bits/stdc++.h>
#define giv 7

using namespace std;

int n;
int head;
int pos[giv];
bool done[giv];

void Init()
{
    cin >> n >> head;
    for(int i = 0; i < giv; i++)
    {
        int temp;
        cin >> temp;
        pos[i] = temp;
        done[i] = false;
    }

}

void fcfs()
{
    int totMov = abs(pos[0] - head);
    for(int i = 1; i < giv; i++)
    {

        totMov = totMov + abs(pos[i] - pos[i-1]);

    }

    cout << "Total Movements :" << totMov << endl;
}

void sstf()
{
    int totMov = 0;
    int shortest = 0;
    int index = 0;
    queue<int> q;

    for(int i = 0; i < giv; i++)
    {
        index = 0;
        shortest = INT_MAX;

        for(int k = 0; k < giv; k++)
        {
            if(abs(head - pos[k]) < shortest && !done[k])
            {
                index = k;
                shortest = abs(head - pos[k]);
            }
        }

        totMov = totMov + shortest;
        head = pos[index];
        q.push(head);
        done[index] = true;

    }

    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    cout << "Total Movement : " << totMov << endl;

}


void cscan()
{
    int totMov = 0;
    int headIndex = 0;
    vector<int> v;
    queue<int> q;
    int ndone[giv];
    int key = 0;


    for(int i = 0; i < giv; i++)
    {
        v.push_back(pos[i]);
        ndone[i] = false;
    }
    sort(v.begin(),v.end());

    for(int i = 0; i < giv; i++)
    {
        if(v[i] > head && !ndone[i])
        {
            q.push(v[i]);
            ndone[i] = true;

        }

    }


    for(int i = 0; i < giv; i++)
    {
        if(v[i] < head && !ndone[i])
        {
            q.push(v[i]);
            ndone[i] = true;
        }

        if(v[i] == head)
        {

        }
    }

    while(!q.empty())
    {
        key = q.front();

        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;

    int lastLimit = 199;
    int firstLimit  = 0;

    totMov = abs(lastLimit - head) + abs(lastLimit - firstLimit) + key;
    cout << "Total Movement is " << totMov << endl;






}








int main()
{

    freopen("input.txt","r",stdin);
    Init();
    //fcfs();
    //sstf();

    cscan();
}

/*

200 50
82 170 43 140 24 16 190 

*/
