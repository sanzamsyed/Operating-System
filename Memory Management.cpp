/*

Author : Syed Sanzam
Course No. : 3124
Course Title: Operating System Lab
Session: 09 Memory Management of an OS


*/

#include <bits/stdc++.h>
#define LIM 100
using namespace std;

int numReq;
int numBlock;
int block[LIM];
int req[LIM];
int result[LIM][LIM];
int cnt = 0;

void create()
{
    cin >> numBlock >> numReq;
    for(int i = 0; i < numBlock; i++)
    {
        cin >> block[i];
    }
    for(int i = 0; i < numReq; i++)
    {
        cin >> req[i];
    }
}

void firstFit()
{
    cnt = numReq;
    for(int i = 0; i < numReq; i++)
    {
        for(int j = 0; j < numBlock; j++)
        {
            if(block[j] >= req[i])
            {
                block[j] = block[j] - req[i];
                break;
            }
        }

        for(int k = 0; k < numBlock; k++)
        {
            result[k][i] = block[k];
        }
    }
}

void bestFit()
{
    int bestIndex = 0;
    cnt = 0;
    for(int i = 0; i < numReq; i++)
    {
        for(int j = 0; j < numBlock;j++)
        {
            if(block[j] >= req[i])
            {
                bestIndex = j;
            }
            for(int t = 0; t < numBlock; t++)
            {
                if(block[t] > block[bestIndex] && block[t] >= req[i])
                {
                    bestIndex = t;
                }
            }
        }

        block[bestIndex] = block[bestIndex] - req[i];
        if(block[bestIndex] < 0) break;
        cnt++;
        for(int k = 0; k < numBlock; k++)
        {
            result[k][i] = block[k];
        }


    }
}


void worstFit()
{
    int worstIndex = -1;
    for(int i = 0; i < numReq; i++)
    {
        for(int j = 0; j < numBlock; j++)
        {
            if(block[j] >= req[i])
            {
                worstIndex = j;
            }
        }

        for(int k = 0; k < numBlock; k++)
        {
            if(block[k] > block[worstIndex] && block[k] > req[i])
            {
                worstIndex = k;
            }
        }

        block[worstIndex] = block[worstIndex] - req[i];

        for(int l = 0; l < numBlock; l++)
        {
            result[l][i] = block[l];
        }
    }
}

void print()
{
    for(int i = 0; i < numBlock; i++)
    {
        for(int j = 0; j < cnt; j++)
        {
            cout << result[i][j] <<"\t";
        }

        cout << endl;
    }
}


int main()
{
    freopen("MemoryManagementInput.txt","r",stdin);
    create();
    firstFit();
    print();


}

/*


5 10
50 200 70 115 15
100 10 35 15 23 6 25 55 88 40


*/
