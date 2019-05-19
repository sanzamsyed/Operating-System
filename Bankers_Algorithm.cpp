/*
Author : Syed Sanzam
Course No. : 3124
Course Title: Operating System Lab
Session: 13 Simulating Banker's Algorithm
*/

#include <bits/stdc++.h>
#define LIM 100

using namespace std;

int proc;
int res;
int totRes[LIM];
int sumRes[LIM];
int availableRes[LIM];
int  maxTab[LIM][LIM];
int allocatedTab[LIM][LIM];
bool isBusy[LIM];

void Init()
{
    cin >> proc >> res;

    for(int i = 0; i < res; i++)
    {
        cin >> totRes[i];
    }

    for(int i = 0; i < proc; i++)
    {
        isBusy[i] = true;
    }
    for(int i = 0; i < proc; i++)
    {
        for(int j = 0; j < res; j++)
        {
            cin >> maxTab[i][j];
        }
    }

    for(int i = 0; i < proc; i++)
    {
        for(int j = 0; j < res; j++)
        {
            cin >> allocatedTab[i][j];
        }
    }

    for(int i = 0; i < proc; i++)
    {
        for(int j = 0; j < res; j++)
        {
            sumRes[j] = sumRes[j] + allocatedTab[i][j];
        }
    }

    for(int i = 0; i < res; i++)
    {
        availableRes[i] = totRes[i] - sumRes[i];
    }
}

void Print()
{
    cout <<"Max Table:" << endl;
    for(int i = 0; i < proc; i++)
    {
        for(int j = 0; j < res; j++)
        {
            cout << maxTab[i][j] << "\t";
        }

        cout << endl;
    }

    cout << endl;

    cout <<"Need Matrix:" << endl;
    for(int i = 0; i < proc; i++)
    {
        for(int j = 0; j < res; j++)
        {
            cout << maxTab[i][j]-allocatedTab[i][j] << "\t";
        }

        cout << endl;
    }

    cout << endl;


    for(int i = 0; i < res; i++)
    {
        cout << availableRes[i] << "\t";
    }
    cout << endl;
}


void Bankers()
{
	vector<int> result;
	bool isSafe;
	bool proceed;
	int check = proc;

	while(check != 0)
	{
		isSafe = false;
		for(int i = 0; i < proc; i++)
		{
			if(isBusy[i])
			{
				proceed = true;
				for(int j = 0; j < res; j++)
				{
					if(maxTab[i][j] - allocatedTab[i][j] > availableRes[j])
					{
						proceed = false;
						break;
					}
				}

				if(proceed)
				{
					isSafe = true;
					isBusy[i]= false;
					check--;
					int temp = i+1;
					result.push_back(temp);
					for(int k = 0; k < res; k++)
					{
						availableRes[k] = availableRes[k] + allocatedTab[i][k];
					}

					break;
				}
			}
		}

		if(!isSafe)
		{
			cout << "Not Safe!";
			return;
		}
	}

	cout << "Safe Sequence : " << endl;

	for(int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}

	cout << endl;
}


int main()
{
    //freopen("BankersInput.txt","r",stdin);
    Init();
    Print();
    Bankers();


}

/*
4 3
9 3 6
3 2 2
6 1 3
3 1 4
4 2 2
1 0 0
5 1 1
2 1 1
0 0 2
*/
