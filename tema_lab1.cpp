#include <iostream>
using namespace std;

void merge (int v[], int s, int m, int d)
{
    int i=s;
    int j=m+1;
    int k=s;
    int a[100];
    while(i<=m && j<=d)
    {
        if(v[i]<=v[j]) {
            a[k] = v[i];
            i++;
            k++;
        }
        else {
            a[k] = v[j];
            j++;
            k++;
        }
    }
    while (i<=m) {
        a[k] = v[i];
        i++;
        k++;
    }
    while (j<=d) {
        a[k] = v[j];
        j++;
        k++;
    }

    for(int p=s; p<=d; p++)
        v[p]=a[p];
}