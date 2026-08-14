
#include <iostream>
using namespace std;

void bubble(int a[],int n){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
}

void selection(int a[],int n){
    for(int i=0;i<n-1;i++){
        int m=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[m]) m=j;
        swap(a[i],a[m]);
    }
}

void mergeSort(int a[],int l,int r){
    if(l>=r)return;
    int m=(l+r)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    int b[100],i=l,j=m+1,k=0;
    while(i<=m&&j<=r)b[k++]=a[i]<a[j]?a[i++]:a[j++];
    while(i<=m)b[k++]=a[i++];
    while(j<=r)b[k++]=a[j++];
    for(i=l,k=0;i<=r;i++)a[i]=b[k++];
}

void quick(int a[],int l,int r){
    if(l>=r)return;
    int i=l,j=r,p=a[l];
    while(i<j){
        while(i<j&&a[j]>=p)j--;
        while(i<j&&a[i]<=p)i++;
        if(i<j)swap(a[i],a[j]);
    }
    swap(a[l],a[i]);
    quick(a,l,i-1);
    quick(a,i+1,r);
}

void heap(int a[],int n){
    for(int i=n/2-1;i>=0;i--)
        for(int p=i;;){
            int c=2*p+1;
            if(c>=n)break;
            if(c+1<n&&a[c+1]>a[c])c++;
            if(a[p]>=a[c])break;
            swap(a[p],a[c]); p=c;
        }
    for(int i=n-1;i>0;i--)swap(a[0],a[i]);
}

void show(int a[],int n){
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int n,a[100],b[100],c[100],d[100],e[100];
    cout<<"Enter n: "; cin>>n;
    cout<<"Enter elements: ";

    for(int i=0;i<n;i++)
        cin>>a[i],b[i]=c[i]=d[i]=e[i]=a[i];

    mergeSort(a,0,n-1);
    cout<<"\nMerge Sort: "; show(a,n);

    quick(b,0,n-1);
    cout<<"Quick Sort: "; show(b,n);

    bubble(c,n);
    cout<<"Bubble Sort: "; show(c,n);

    selection(d,n);
    cout<<"Selection Sort: "; show(d,n);

    heap(e,n);
    cout<<"Heap Sort: "; show(e,n);

    return 0;
}