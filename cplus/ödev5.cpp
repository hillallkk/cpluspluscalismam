#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main()
 {
 	
 	srand(time(NULL));
 	
 	int sayi;
 	
 	for(int i=0;i<500;i++)
 	{
 		float sayi=(rand () % (1-0+1)+0)+((float)rand()/(float)RAND_MAX);
		 cout<<sayi<<endl; 		
 		
 		
}

	return 0;
}
