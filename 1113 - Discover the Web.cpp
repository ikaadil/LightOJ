#include<bits/stdc++.h>
using namespace std;


int main()
{

	int tcs;
	scanf(" %d ",&tcs);
	for(int t = 1 ; t <= tcs ; t++)
	{
		printf("Case %d:\n",t);
		stack<string> fw,bw;
		string s;
		string cur = "http://www.lightoj.com/";
		while(cin >> s)
		{
			if(s == "QUIT")
				break;

			if(s == "VISIT")
			{
				bw.push(cur);
				cin >> cur;
				cout << cur << endl;
				while(!fw.empty())
					fw.pop();
			}
			else if(s == "BACK")
			{
				if(bw.empty())
				{
					puts("Ignored");
					continue;
				}
				fw.push(cur);
				cur = bw.top();
				bw.pop();
				cout << cur << endl;
			}
			else if(s == "FORWARD")
			{
				if(fw.empty())
				{
					puts("Ignored");
					continue;
				}

				bw.push(cur);
				cur = fw.top();
				fw.pop();
				cout << cur << endl;
			}
		}
	}
	return 0;
}

