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

void count_sort(int v[],int dim, int d)
{
    int fr[10]={0};
    int final[dim];

    for(int i=0; i<dim; i++)
        fr[(v[i]/d)%10]++;

    for(int i=1; i<10; i++)
        fr[i]=fr[i]+fr[i-1];

    for(int i=dim-1; i>=0; i--)
    {
        final[fr[(v[i]/d)%10]-1]=v[i];
        fr[(v[i]/d)%10]--;
    }
    for(int i=0; i<dim; i++)
        v[i]=final[i];
}
int maxim (int v[],int m)
{ 
    int max=v[0];
    for(int i=1; i<=m; i++)
        if(max < v[i])
            max=v[i];
    return max;
}
void radix_sort(int v[], int m)
{
    int max=maxim(v,m);
    for(int d=1; max/d>0; d=d*10)
        count_sort(v,m,d);
}
int main() {
    int n, v[100];
    cout<<"n=";
    cin>>n;
    cout<<"citire vector: ";
    for(int i=0; i<=n-1; i++)
        cin>>v[i];
    // merge_sort(v,0, n-1);
    radix_sort(v, n);
    for (int i = 0; i <= n-1; i++)
        cout << v[i] <<" ";
    return 0;
}