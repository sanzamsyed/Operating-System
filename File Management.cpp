/*

Author : Syed Sanzam
Course No. : 3124
Course Title: Operating System Lab
Session: 13 File Management


*/


//#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int totBlock = 0;
int sum = 0;

map<int,string> fileIndex;

void Init()
{
    cin >> totBlock;
}

void CreateFile(string fileName, int fileSize)
{
    if(fileSize < totBlock)
    {
        for(int i = 0; i < fileSize; i++)
        {
            fileIndex[sum++] = fileName;
        }

        totBlock = totBlock - fileSize;

        cout << fileName << " is created" << endl;
    }
    else
    {
        cout << fileName << " can not be created" << endl;
    }

}

void SearchFile(string fileName)
{
    bool found = false;
    for(auto it = fileIndex.begin(); it != fileIndex.end(); it++)
    {
        if(it -> second == fileName)
        {
            found = true;
            cout << "File " << fileName << " found in the blocks : ";
            for(; it != fileIndex.end(); it++)
            {
                if(it -> second == fileName)
                {
                    cout << it -> first << " ";
                }
                else
                {
                    break;
                }
            }

            cout << endl;
        }
    }

    if(!found)
    {
        cout << "File " << fileName << " is not found!" << endl;
    }


}


int main()
{
    //cout << "Hello world!" << endl;

    Init();
    CreateFile("A",4);
    CreateFile("B",400);
    CreateFile("C",40);


    SearchFile("D");



}
