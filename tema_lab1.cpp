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
void merge_sort (int v[], int s, int d)
{
    if (s<d)
    {
        int m = (s + d) / 2;
        merge_sort(v, s, m);
        merge_sort(v,m+1,d);
        merge(v,s,m,d);
    }
}
int main() {
    int n, v[100];
    cout<<"n=";
    cin>>n;
    cout<<"citire vector: ";
    for(int i=0; i<=n-1; i++)
        cin>>v[i];
    merge_sort(v,0, n-1);
    for (int i = 0; i <= n-1; i++)
        cout << v[i] <<" ";
    return 0;
}