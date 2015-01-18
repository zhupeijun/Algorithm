#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

vector <string> g;
int vis[25];
int ans;
class OrderOfTheHats
{
	public:
	void elimate(int col)
	{
		int n = g.size();
		for(int i = 0;i < n;i++)
			g[i][col] = 'N';
	}
	bool isFinished()
	{
		int n = g.size();
		for(int i = 0;i < n;i++)
			if(vis[i] == 0) return false;
		return true;
	}
	void ProcessY()
	{
		int n = g.size();
		for(int i = 0;i < n;i++)
		{
			if(vis[i] == 0)
			{
				for(int j = 0;j < n;j ++)
				{
					if(g[i][j] == 'Y')
					{
						g[i][j] = 'N';
						ans ++;
						return ;
					}
				}
			}
		}
	}
	bool isNoIn(int x)
	{
		int n = g.size();
		for(int i = 0;i < n;i ++)
			if(g[x][i] == 'Y') return false;
		return true;
	}
	int minChanged(vector <string> spellChart)
	{
		g = spellChart;
		int n = g.size();
		int i;
		memset(vis,0,sizeof(vis));
		ans = 0;
		while(true)
		{
			for(i = 0;i < n;i++)
				if(isNoIn(i))
				{
					vis[i] = 1;
					elimate(i);
				}
			if(isFinished()) break;
			else ProcessY();
		}
		return ans;
	}
};