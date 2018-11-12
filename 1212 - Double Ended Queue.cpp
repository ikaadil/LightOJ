#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        int n,m,mq;
        cin>>n>>m;
        cout<<"Case "<<i<<":"<<endl;
        string s;
        deque<int>q;
        while(m--)
        {
            cin>>s;
            if(s=="pushLeft")
            {
                cin>>mq;
                if(q.size()!=n)
                {
                    q.push_front(mq);
                    cout<<"Pushed in left: "<<mq<<endl;
                }
                else
                    cout<<"The queue is full"<<endl;

            }
            else if(s=="pushRight")
            {
                cin>>mq;
                if(q.size()!=n)
                {
                    q.push_back(mq);
                    cout<<"Pushed in right: "<<mq<<endl;
                }
                else

                    cout<<"The queue is full"<<endl;

            }
            else if(s=="popLeft")
            {
                if(q.size()!=0)
                {
                    mq=q.front();
                    cout<<"Popped from left: "<<mq<<endl;
                    q.pop_front();
                }
                else
                    cout<<"The queue is empty"<<endl;
            }
            else if(s=="popRight")
            {
                if(q.size()!=0)
                {
                    mq=q.back();
                    cout<<"Popped from right: "<<mq<<endl;
                    q.pop_back();
                }
                else
                    cout<<"The queue is empty"<<endl;
            }
        }
    }
    return 0;
}
