
/**************************************************************************
 * 
 * FILE NAME:     main.c
 * 
 * DESCRIPTION:   contains the main function invoking sorting functions
 *  
 *  DATE           NAME            REFERENCE       REASON
 * -------------------------------------------------------------
 *                                                 
 * Copyrights 2015 Aricent Technolegies (Holdings) ltd
 *                                                                 
 ****************************************************************************/

/**************************************************************************
 *                       Header Files                                      *
 ***************************************************************************/
#include"header.h"

/***********************************************************************
 *       FUNCTION NAME :  main
 *       DESCRIPTION   :  invokes various sorting functions 
 *************************************************************************/
int main()
{
	int array[MAX];
  	char *array1[MAX];
	int i,n;	
        int choice;

	printf("\n\nEnter no of numbers you want to enter:");
	scanf("%d",&n);
	printf("\nEnter elements:\n");
	
	//reading the elements into the array
	for(i=0; i < n; i++)
	{
	   scanf("%d", &array[i]);
	}

	//displaying the array elements before sorting

	printf("\nElements Before sorting :\n");
	for(i=0;i<n;i++)
	{
	   printf("%4d\n",array[i]);
	}

        printf("\n Please enter your choice of sorting technique:");
        printf("\n 1. Insertion Sort");
        printf("\n 2. Quick Sort");
        printf("\n 3. Merge Sort\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                     insertion_sort(array, n);
                     break;
            case 2:
                     quick_sort(array, 0, n-1);
                     break;
            case 3:
					
					printf("\n\nEnter no of numbers you want to enter:");
					scanf("%d",&n);
					printf("\nEnter elements:\n");
	
					//reading the elements into the array
						for(i=0; i < n; i++)
						{
	  						 scanf("%s", &array1[i]);
						}



  						merge_sort(array1, 0, n-1);
                     break;
        }

	//displaying the array elements after sorting

	printf("\n\nelements After sorting :\n");
	for(i=0; i < n; i++)
	{
		printf("%4d\n", array[i]);
	}

	printf("\n");
	return EXIT_SUCCESS;
}

