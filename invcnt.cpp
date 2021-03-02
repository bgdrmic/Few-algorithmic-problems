#include <cstdio>
#include <vector>
using namespace std;
 
int niz[200010][20];
int pot[25];
int n;
long long rez;
 
void sortiranje(int lv)
{
	int l, d;
	for(int i = 0; i < n; i += pot[lv+1])
	{
		l = 0;
		d = 0;
		for(int j = 0; j < pot[lv+1]; j++)
		{
			if(i+j >= n) goto kraj;
			if(i+l >= n) break;
 
			if(i+pot[lv]+d >= n || d == pot[lv])
			{
				niz[i+j][lv+1] = niz[i+l][lv];
				l++;
			}
			else if(l == pot[lv])
			{
				niz[i+j][lv+1] = niz[i+pot[lv]+d][lv];
				rez += (long long)pot[lv]-l;
				d++;
			}
			else if(niz[i+l][lv] < niz[i+d+pot[lv]][lv])
			{
				niz[i+j][lv+1] = niz[i+l][lv];
				l++;
			}
			else
			{
				niz[i+j][lv+1] = niz[i+d+pot[lv]][lv];
				rez += (long long)pot[lv]-l;
				d++;
			}
		}
	}
	kraj:
	if(pot[lv+1] < n) sortiranje(lv+1);
}
 
int main()
{
	int t;
	pot[0] = 1;
	for(int i = 1; i < 21; i++) pot[i] = pot[i-1]*2;
 
	scanf("%d", &t);
	for(int k = 0; k < t; k++)
	{
		rez = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &niz[i][0]);
		sortiranje(0);
		printf("%lld\n", rez);
	}
	return 0;
}