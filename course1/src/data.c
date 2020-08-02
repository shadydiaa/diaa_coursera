#include "../include/common/data.h"
#include "../include/common/platform.h"

#include <stdio.h>
#include <stdlib.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{	
	uint8_t * start_ptr=ptr;
	uint8_t counter=1;

	if(data<0)
	{
		*ptr++='-';
		start_ptr++;
		counter++;
		data=-data;
	}

	else if (data==0)
	{
		*ptr++='0';
		counter++;
	}

	while(data!=0)
	{
		int32_t rem=data%base;
		*ptr++=rem<10 ? rem+'0' : (rem-10) + 'a';
		counter++;
		data/=base;
	}


	*ptr='\0';
	ptr--;
	int32_t temp;
	while(ptr-start_ptr>0)
	{
		temp=*start_ptr;
		*start_ptr++=*ptr;
		*ptr--=temp;
	}
	
	return counter;
	
}
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	
	int32_t num=0;
	int signed_check=1;
	
	if(*ptr=='-')
	{
		ptr++;
		digits--;
		signed_check=-1;
	}
	while(--digits!=0)
	{
		num=(num*base);
		num+= *ptr<='9' ? (*ptr++ - '0') : ((*ptr++ + 10) - 'a');

	}
	return num*signed_check;		
}
