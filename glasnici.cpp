#include <cstdio>
#include <vector>
using namespace std;


vector<double> lok;

int main()
{
    int n, g;
    double a, d, t;
    scanf("%d", &g);
    for(int k = 0; k < g; k++)
    {
        lok.clear();
        t = 0;
        scanf("%lf %d", &d, &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%lf", &a);
            lok.push_back(a);
        }
        for(int i = 1; i < n; i++)
        {
            a = lok[i] - lok[i-1] - d;
            if(a >= 0)
            {
                if(a >= t)
                {
                    a -= t;
                    lok[i] -= t;
                    t += a/2;
                    lok[i] -= a/2;
                }
                else
                {
                    lok[i] = lok[i-1] + d;
                }
            }
            else
			{
				if(-a <= t) lok[i] = lok[i-1] + d;
				else lok[i] += t;
            }
        }
        printf("%.3lf\n", t);
    }
    return 0;
}
