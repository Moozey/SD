#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
ifstream fin("input.txt");

using namespace std;

///este sau nu vectorul sortat bine?
int verificare (vector<int> vector, int n)
{
    for ( int i=0; i<n-1; i++)
        if (vector[i] > vector[i+1])
            return 0;
    return 1;
}

///functie care atriubuie valori random
///vectorului in functie de numarul de numere
///si numarul maxim

void vectăr ( vector <int> &v, int n, int max)
{
    srand(time(0));
    for (int i=0; i<n; i++)
    {
        int nr = (rand()*rand()) % (max +1);
        v.push_back(nr);
    }
}

void merge (vector<int> &v, int s, int m, int d)
{
    int i=s;
    int j=m+1;
    vector<int>a;
    while(i<=m && j<=d)
    {
        if(v[i]<=v[j])
            a.push_back(v[i++]);

        else
            a.push_back(v[j++]);

    }
    while (i<=m)
        a.push_back(v[i++]);
    while (j<=d)
        a.push_back(v[j++]);

    for(i=s, j=0; i<=d; i++, j++)
        v[i]=a[j];

    a.clear();
}
void merge_sort (vector<int> &v, int s, int d)
{
    if (s<d)
    {
        int m = (s + d) / 2;
        merge_sort(v, s, m);
        merge_sort(v,m+1,d);
        merge(v,s,m,d);
    }

}

void rad_count_sort(vector<int> &v,int dim, int d)
{
    int fr[10]={0};
    vector<int>final;
    for (int i=0; i<=dim;i++) final.push_back(0);

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
int maxim (vector<int> v,int m)
{
    int max=v[0];
    for(int i=1; i<=m; i++)
        if(max < v[i])
            max=v[i];
    return max;
}
void radix_sort( vector<int> v, int m)
{
    auto pornire_ceas = high_resolution_clock::now();

    int max=maxim(v,m);
    for(int d=1; max/d>0; d=d*10)
        rad_count_sort(v,m,d);


    auto stop = high_resolution_clock::now();
    auto cat_dureaza = duration_cast<microseconds>(stop - pornire_ceas);
    if (verificare(v, m))
        cout<<"Radix_sort dureaza: "<<cat_dureaza.count()/1000000.00000000000 <<" secunde"<< endl;
    else
        cout<<"Radix_sort nu sorteaza bine"<<endl;
}

void count_sort(vector<int> v, int n, int maxim)
{
    auto pornire_ceas = high_resolution_clock::now();

    int lungime = v.size();
    vector<int> a;
    for (int i = 0 ; i <= maxim; i++) a.push_back(0);
    for (auto it: v) a[it]++;
    v.clear();
    for (int i = 0; i <= maxim; i++)
    {
        if (a[i])
        {
            for (int j = 1; j <= a[i]; j++) v.push_back(i);
        }
    }

    auto stop = high_resolution_clock::now();
    auto cat_dureaza = duration_cast<microseconds>(stop - pornire_ceas);
    if (verificare(v, n))
        cout<<"Count_sort dureaza: "<<cat_dureaza.count()/1000000.00000000000 <<" secunde"<< endl;
    else
        cout<<"Count_sort nu sorteaza bine"<<endl;

    a.clear();
}


void bubblesort(vector<int>  &v, int n )
{
    auto pornire_ceas = high_resolution_clock::now();
    int i, ok=0;
    do
    {
        ok = 1;
        for(i = 0; i < n; i++)
            if(v[i] > v[i+1])
            {
                v[i] += v[i+1];
                v[i+1] = v[i] - v[i+1];
                v[i] -= v[i+1];
                ok = 0;
            }
    }
    while(!ok);

    auto stop = high_resolution_clock::now();
    auto cat_dureaza = duration_cast<microseconds>(stop - pornire_ceas);
    if(verificare(v, n))
        cout << "Bubblesort dureaza: "<<cat_dureaza.count()/1000000.00000000000000<<" secunde "<<'\n';
    else
        cout << "Bubblesort nu sorteaza bine"<<endl;
}
void insersion_sort (vector<int> &v, int n)
{
    for (int i = 1; i < n; i++){
        int ecurent = v[i];
        int j = i - 1;
        while (j >= 0 and v[j] > ecurent){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = ecurent;
    }
}
void ShellSort (vector<int> v, int n)
{
    auto start = high_resolution_clock::now();
    int prapastie;
    for (prapastie = (n - 1) / 2; prapastie > 1; prapastie /= 2 ){
        for (int i = 0; i < prapastie; i ++){
            if (v[i] > v[i+prapastie]) swap(v[i], v[i+prapastie]);
        }
        for (int i = 2 * prapastie; i < n - prapastie ; i++){
            if ((i + prapastie < n) and (v[i] > v[i+prapastie])) swap(v[i], v[i+prapastie]);
        }

        //daca timpul de rulare sare de 5 minute(300 secunde), pentru ca nu am rabdare, opresc sortarea si afisez msj coresp.

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if (duration.count()/1000000.00000000000 > 300){
            cout<<"Nu am rabdare sa astept mai mult de 5 minute. Asa ca am oprit sortarea."<<endl;
            return;

        }

    }
    if (prapastie == 1 and !verificare(v, n)) insersion_sort(v, n); // prapastie = 1 si vectorul inca nu e sortat

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if (verificare(v, n))
        cout<<"ShellSort dureaza: "<<duration.count()/1000000.00000000000 <<" secunde"<< endl;
    else
        cout<<"ShellSort nu a sortat numerele corect"<<endl;
}




int main() {


    int n, maxim, teste;
    vector <int> v;
    cin>>teste;
    for (int i = 1; i <= teste; i++)
    {
        cin>>n>>maxim;
        cout<<"n = "<<n<<" "<<"maxim = "<<maxim<<" "<<endl;
        vectăr(v, n, maxim);

//        for (auto it:v) cout<<it<<" ";
//        cout<<endl;
//        bubblesort(v, n);
//        for (auto it: v) cout<<it<<" ";
//        cout<<endl;

        //sortarea nativă =))))))))))))
        vector<int> aux;
        for (auto it: v) aux.push_back(it);
        auto start = high_resolution_clock::now();
        sort(aux.begin(), aux.end());
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        if (verificare(aux, n))
            cout<<"Sortarea nativa dureaza: "<<duration.count()/1000000.00000000000 <<" secunde"<< endl;
        else
            cout<<"Sortarea nativa nu sorteaza bine nativ :("<<endl;
        aux.clear();

        //MergeSort
        for (auto it: v)
            aux.push_back(it);

        start = high_resolution_clock::now();

        merge_sort(aux, 0 , n-1);

        stop = high_resolution_clock::now();
        duration = duration_cast<microseconds>(stop - start);
        if (verificare(aux, n))
            cout<<"Merge_sort dureaza: "<<duration.count()/1000000.00000000000 <<" secunde"<< endl;
        else
            cout<<"Merge_sort nu sorteaza bine"<<endl;
        aux.clear();

        //bubblesort
        if (n >= 1000000)
            cout<<"Prea multe numere. Va dura mult. Nu ne convine"<<endl;
        else{
            for (auto it: v)
                aux.push_back(it);
            bubblesort(aux, n);
            aux.clear();
        }

        //Radix_sort
        radix_sort(v, n);

        //count_sort
        count_sort(v, n, maxim+1);

        //ShellSort
        if (n >= 10000000)
            cout<<"Prea multe numere. Va dura mult. Nu ne convine"<<endl;
        else
            ShellSort(v, n);

        cout<<endl;
        v.clear();

    }

    return 0;
}
