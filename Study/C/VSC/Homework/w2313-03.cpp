#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n=0;
    while(cin>>n)
    {
        const int N=n;
        int a[N];int c[N];
        int num[N]; //储存原数组下标
        for(int i=0;i<N;i++) cin>>a[i];
        for(int q=0;q<N;q++) c[q]=a[q];
        for(int k=0;k<N;k++)
        {
            int s=k;int t=0;int min1=a[k];int min2=a[k];
            //if(k<N-1)
            //{
            for(int b=k+1;b<N;b++) //完成排序
            {
                if(a[b]<a[k])
                {
                    min1=a[b];
                    
                    if(min2<a[b]) //if上一个min值更小
                    {
                        min1=min2;  
                    }
                    else  //此a[b]更小
                    {
                        s=b;
                        num[k]=b;
                    }
                    min2=min1;
                }
            }
            
            if(s!=k)
            {
                t=a[s];
                a[s]=a[k];
                a[k]=t;
            }
            else
            {
                num[k]=k;
            }
            /*for(int y=0;y<N;y++)
            {
                cout<<a[y]<<" ";
            }
            cout<<endl;
            //if(k==N-1) break;*/
        }
        for(int y=N-1;y>=0;y--)
        {
            cout<<a[y]<<" ";
            for(int r=0;r<N;r++)
            {
                if(c[r]==a[y]) cout<<r<<endl;
            }
        }
        
    }
}