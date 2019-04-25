/*

Author : Syed Sanzam
Course No. : 3124
Course Title: Operating System Lab
Session: 10 Simulating Page Replacement- techniques of an OS


*/
#include <bits/stdc++.h>


using namespace std;


int numFrame;
int numReq;
vector<int> page;

void Init()
{
    cin >> numFrame >> numReq;
    for(int i = 0; i < numReq; i++)
    {
        int temp;
        cin >> temp;
        page.push_back(temp);
    }
}

void FIFO()
{
    unordered_set<int> s;
    queue<int> q;
    int pageFault = 0;

    for(int i = 0; i < numReq; i++)
    {
        if(s.size() < numFrame)
        {
            if(s.find(page[i]) == s.end())
            {
                s.insert(page[i]);
                q.push(page[i]);
                pageFault++;
            }

        }
        else
        {
            if(s.find(page[i]) == s.end())
            {
                int temp;
                temp = q.front();
                q.pop();

                s.erase(temp);
                s.insert(page[i]);
                q.push(page[i]);

                pageFault++;
            }

        }
    }

    cout << "Page Fault in FIFO : " << pageFault << endl;


}


void Other(bool isLRU)
{
    unordered_set<int> s;
    unordered_map<int,int> m;
    int pageFault = 0;

    for(int i = 0; i < numReq; i++)
    {
        if(s.size() < numFrame)
        {
            if(s.find(page[i]) == s.end())
            {
                s.insert(page[i]);
                pageFault++;
            }

            m[page[i]] = i;

        }

        else
        {
            if(s.find(page[i]) == s.end())
            {
                int cmp = 0;
                if(isLRU)
                {
                    cmp = 9999;
                }
                else
                {
                    cmp = -1;

                }
                int temp = 0;
                for(auto it = s.begin(); it != s.end(); it++)
                {
                    if(m[*it] < cmp)
                    {
                        cmp = m[*it];
                        temp = *it;
                    }

                }

                s.erase(temp);
                s.insert(page[i]);
                pageFault++;
            }

            m[page[i]] = i;

        }
    }


    if(isLRU)
    {
        cout << "Page Fault in LRU: " << pageFault << endl;
    }
    else
    {
        cout << "Page Fault in Optimum : " << pageFault << endl;
    }
}



int main()
{
    freopen("input.txt","r",stdin);
    Init();
    FIFO();
    Other(false);
    Other(true);


}
