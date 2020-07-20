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
 * @file <stats.h> 
 * @brief <file contains all functions declaration>
 *
 * 
 *
 * @author <Shady Diaa>
 * @date <07/06/2020 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief <print_statistics of given array>
 *
 * This function takes pointer to char (arr) and length of this array (length)
 * then will print statistics of given array including minimum, maximum, mean, and median.
 *
 * @param <arr> <pointer to char for given array>
 * @param <length> <the length of given array>
 *
 * @return <No return data (void)>
 */

void print_statistics(unsigned char* arr,unsigned int length);

/**
 * @brief <Print elements in given array>
 *
 * This function takes pointer to char (arr) and length of this array (length)
 * then will print elements in this array.
 *
 * @param <arr> <pointer to char for given array>
 * @param <length> <the length of given array>
 *
 * @return <No return data (void)>
 */

void print_array(unsigned char* arr,unsigned int length);

/**
 * @brief <find median in given array>
 *
 * This function takes pointer to char (arr) and length of this array (length)
 * then will find median of this array.
 *
 * @param <arr> <pointer to char for given array>
 * @param <length> <the length of given array>
 *
 * @return <the median of given array>
 */
unsigned char find_median(unsigned char* arr,unsigned int length);

/**
 * @brief <find mean in given array>
 *
 * This function takes pointer to char (arr) and length of this array (length)
 * then will find mean of this array.
 *
 * @param <arr> <pointer to char for given array>
 * @param <length> <the length of given array>
 *
 * @return <the mean of given array>
 */

unsigned char find_mean(unsigned char* arr,unsigned int length);

/**
 * @brief <find maximum in given array>
 *
 * This function takes pointer to char (arr) and length of this array (length)
 * then will find maximum of this array.
 *
 * @param <arr> <pointer to char for given array>
 * @param <length> <the length of given array>
 *
 * @return <the maximum of given array>
 */

unsigned char find_maximum(unsigned char* arr,unsigned int length);

/**
 * @brief <find minimum in given array>
 *
 * This function takes pointer to char (arr) and length of this array (length)
 * then will find minimum of this array.
 *
 * @param <arr> <pointer to char for given array>
 * @param <length> <the length of given array>
 *
 * @return <the minimum of given array>
 */

unsigned char find_minimum(unsigned char* arr,unsigned int length);

/**
 * @brief <sort given array>
 *
 * This function takes pointer to char (arr) and length of this array (length)
 * then will sort this array.
 *
 * @param <arr> <pointer to char for given array>
 * @param <length> <the length of given array>
 *
 * @return <No return data (void)>
 */
 
void sort_array(unsigned char* arr,unsigned int length);

#endif /* __STATS_H__ */
