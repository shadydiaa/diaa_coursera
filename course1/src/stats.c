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
#include "../include/common/stats.h"




void print_statistics(unsigned char* arr,unsigned int length)
{
	PRINTF("Min : %d\n",find_minimum(arr,length));
	PRINTF("Max : %d\n",find_maximum(arr,length));
	PRINTF("Mean : %d\n",find_mean(arr,length));
	PRINTF("Median : %d\n",find_median(arr,length));
}
void print_array(unsigned char* arr,unsigned int length)
{
	#ifdef VERBOSE 
	unsigned char counter; 
	for(counter=0;counter<length;counter++)
	{
		PRINTF("arr[%d]=%d\n",counter,arr[counter]);
	}
	#endif
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
