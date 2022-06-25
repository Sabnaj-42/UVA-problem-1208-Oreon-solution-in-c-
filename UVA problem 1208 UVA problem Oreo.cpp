#include<bits/stdc++.h>
using namespace std;
struct node
{
    char a,b;
    int w;
};
bool comp(node c,node d)
{
    if(c.w<d.w)return true;
    else if(c.w==d.w)
    {


            if(c.a<d.a)return true;
            else return false;
    }
    else return false;
}
struct node ar[1000000];
map<char,char>parent;
char findd(char a)
{
    if(parent[a]==a)return a;
    else
        return parent[a]=findd(parent[a]);
}
void unionn(char a,char b)
{
    parent[a]=b;
}


int main()
{
    int t;cin>>t;int o=1;
    while(t--)
    {
        int n;cin>>n;
        int input[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char c;
                cin>>input[i][j];
                if(j<(n-1))
                   cin>>c;
            }

        }
        int k=0;
        for(int i=0;i<n;i++)
        {
            char u='A'+i;
            for(int j=0;j<n;j++)
            {
                    if(input[i][j]!=0)
                   {
                       char v='A'+j;
                    parent[u]=u;
                    parent[v]=v;
                    ar[k].a=u;
                    ar[k].b=v;
                    ar[k].w=input[i][j];
                    k++;
                   }

                }
            }
        sort(ar,ar+k,comp);
        printf("Case %d:\n",o);o++;

        for(int i=0;i<k;i++)
        {
            char u=findd(ar[i].a);
            char v=findd(ar[i].b);
            if(u!=v)
            {
                unionn(u,v);
                cout<<ar[i].a<<"-"<<ar[i].b<<" "<<ar[i].w<<endl;
            }
        }
    }
}
