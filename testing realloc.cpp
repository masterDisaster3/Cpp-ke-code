#include<stdio.h>
#include<stdlib.h>

int main ()
{
	//declaring pointer
	int n , *arr ;

	printf("Enter the size of array: ");

	scanf("%d",&n);

	arr=(int *) calloc( n ,sizeof(int));

	if(arr==NULL)
	printf("NO memory available.\n");
	else
	printf("Enter the elements: \n");

	for(int i = 0 ; i < n ; i++)
	{
		scanf("%d",&arr[i]);
	}


	int size = n;
	//printing the array
		printf("The array is: \n");
	 	for(int i = 0 ; i < n ; i++)
			printf("%d\n",*(arr+i));


	
	//asking to change the size of the array
	printf("Do you want to change the capacity of the array?\n Type 1 for yes \n Type 0 for no\n");


	int y;
	scanf("%d",&y);

	switch(y){

		case 1: printf("Enter the new capacity: ");
		scanf("%d",&n);

		arr = (int *)realloc((arr), n * sizeof(int));

		//if array got a increase in size
		if(n>size){
			printf("Enter elements after previous array: \n");
			for(int j=size ; j<n ; j++)
				scanf("%d",&arr[j]);	
		
			// printing the changed array
			printf("The array is\n");		 
		 	for( int p = 0 ; p < n ; p++)
				printf("%d\n",*(arr+p));
		}


		//if the changed array is less in size than the inital array
		if(n<size){

			printf("Do you want to replace the old values?\n Type 1 for yes \n Type 0 for no\n");

			int y;
			scanf("%d",&y);
			if(y==1){

				printf("Enter the elements: \n");
				for( int p = 0 ; p < n ; p++)
					scanf("%d",&arr[p]);

			// printing the changed array
				printf("The array is\n");		 
			 	for( int display = 0 ; display < n ; display++)
					printf("%d\n",*(arr+display));
			}break;

		case 0: if(y==0){
		// printing the changed array
				printf("The array is\n");		 
			 	for( int display = 0 ; display < n ; display++)
					printf("%d\n",*(arr+display));	
			}break;

		default: printf("Wrong input kind user"); break;
		}
	
	}

}
