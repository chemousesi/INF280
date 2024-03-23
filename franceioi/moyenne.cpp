#include <cstdio>




int main()
{
	int n,t ;
	float s=0;
	scanf("%d\n", &n);
	for (int i=0; i < n; i++)
	{
		scanf("%d\n",&t);
	       	s += t;	
	}
	printf("%f\n", s/n);
}




