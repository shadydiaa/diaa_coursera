/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <make statstics for given array>
 *
 * 
 *
 * @author <Shady Diaa>
 * @date <07/06/2020 >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
  
  printf("Array Elements : \n");
  print_array(test,sizeof(test));
  printf("*************************\n");
  printf("Statistics : \n");
  print_statistics(test,sizeof(test));
  printf("*************************\n");
  printf("Array Elements after sorted descending:\n");
  print_array(test,sizeof(test));
}


void print_statistics(unsigned char* arr,unsigned int length)
{
	printf("Min : %d\n",find_minimum(arr,length));
	printf("Max : %d\n",find_maximum(arr,length));
	printf("Mean : %d\n",find_mean(arr,length));
	printf("Median : %d\n",find_median(arr,length));
}
void print_array(unsigned char* arr,unsigned int length)
{
	unsigned char counter; 
	for(counter=0;counter<length;counter++)
	{
		printf("arr[%d]=%d\n",counter,arr[counter]);
	}
}
unsigned char find_median(unsigned char* arr,unsigned int length)
{
	sort_array(arr,length);
	//even 
	if(length%2==0)
	{
		return ((arr[(length/2)]+arr[(length/2)+1])/2);
	}
	//odd
	else
	{
		return (arr[(length/2)+1]);
	}
}

unsigned char find_mean(unsigned char* arr,unsigned int length)
{
	unsigned int sum=0;
	unsigned char counter;
	
	for(counter=0;counter<length;counter++)
	{
		sum+=arr[counter];
	}
	
	return sum/length;

}

unsigned char find_maximum(unsigned char* arr,unsigned int length)
{
	unsigned char counter,max=arr[0];
	
	for(counter=1;counter<length;counter++)
	{
		if(arr[counter]>max)
		{
			max=arr[counter];
		}
	}
	
	return max;
}


unsigned char find_minimum(unsigned char* arr,unsigned int length)
{
	unsigned char counter,min=arr[0];
	
	for(counter=1;counter<length;counter++)
	{
		if(arr[counter]<min)
		{
			min=arr[counter];
		}
	}
	
	return min;

}

void sort_array(unsigned char* arr,unsigned int length)
{
	unsigned char i ,j,temp;
	
	for (i = 0; i < length; ++i) 
    {
		for (j = i + 1; j < length; ++j) 
		{
			if (arr[i] < arr[j]) 
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
    }
}
