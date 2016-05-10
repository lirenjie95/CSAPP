/*********************************************************
* Kernels to be optimized for the CS:APP Performance Lab
********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "defs.h"


/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "13307130279",              /* Team name */
    "13307130279",     		/* First member full name */
    "13307130279@fudan.edu.cn",	/* First member email address */


    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};


/***************
 * ROTATE KERNEL
 ***************/


/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/


/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;


    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}


/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
	int i,j;
	dst += dim*(dim-1);// Move to the last bvisk
	for(i = 0;i < dim;i += 32)
	{
		for(j = 0;j < dim;j++)
		{
			*dst = *src; src += dim; dst++;//1
			*dst = *src; src += dim; dst++;//2
			*dst = *src; src += dim; dst++;//3
			*dst = *src; src += dim; dst++;//4
			*dst = *src; src += dim; dst++;//5
			*dst = *src; src += dim; dst++;//6
			*dst = *src; src += dim; dst++;//7
			*dst = *src; src += dim; dst++;//8
			*dst = *src; src += dim; dst++;//9
			*dst = *src; src += dim; dst++;//10
			*dst = *src; src += dim; dst++;//11
			*dst = *src; src += dim; dst++;//12
			*dst = *src; src += dim; dst++;//13
			*dst = *src; src += dim; dst++;//14
			*dst = *src; src += dim; dst++;//15
			*dst = *src; src += dim; dst++;//16
			*dst = *src; src += dim; dst++;//17
			*dst = *src; src += dim; dst++;//18
			*dst = *src; src += dim; dst++;//19
			*dst = *src; src += dim; dst++;//20
			*dst = *src; src += dim; dst++;//21
			*dst = *src; src += dim; dst++;//22
			*dst = *src; src += dim; dst++;//23
			*dst = *src; src += dim; dst++;//24
			*dst = *src; src += dim; dst++;//25
			*dst = *src; src += dim; dst++;//26
			*dst = *src; src += dim; dst++;//27
			*dst = *src; src += dim; dst++;//28
			*dst = *src; src += dim; dst++;//29
			*dst = *src; src += dim; dst++;//30
			*dst = *src; src += dim; dst++;//31
			*dst = *src; src++;
			src -= (dim<<5)-dim;// src = src-dim*31
			dst -= 31+dim;// Find the next row or column.
		}
		dst += dim*dim;dst += 32;
		src += (dim<<5)-dim;// Reset
	}
}


/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/


void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    /* ... Register additional test functions here */
}




/***************
 * SMOOTH KERNEL
 **************/


/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/


/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;


/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }


/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}


/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}


/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}


/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;


    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);


    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}


/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/


/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;


    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}


/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst)
{
	int i,j;
	// Four corners: only consider four blocks.
	dst[0].red = (src[0].red+src[1].red+src[dim].red+src[dim+1].red)>>2;
	dst[0].blue = (src[0].blue+src[1].blue+src[dim].blue+src[dim+1].blue)>>2;
	dst[0].green = (src[0].green+src[1].green+src[dim].green+src[dim+1].green)>>2;
	//corner[0][0]
	dst[dim-1].red = (src[dim-1].red+src[dim-2].red+src[dim*2-1].red+src[dim*2-2].red)>>2;
	dst[dim-1].blue = (src[dim-1].blue+src[dim-2].blue+src[dim*2-1].blue+src[dim*2-2].blue)>>2;
	dst[dim-1].green = (src[dim-1].green+src[dim-2].green+src[dim*2-1].green+src[dim*2-2].green)>>2;
	//corner[0][dim-1]
	dst[dim*(dim-1)].red = (src[dim*(dim-1)].red+src[dim*(dim-1)+1].red+src[dim*(dim-2)].red+src[dim*(dim-2)+1].red)>>2;
	dst[dim*(dim-1)].blue = (src[dim*(dim-1)].blue+src[dim*(dim-1)+1].blue+src[dim*(dim-2)].blue+src[dim*(dim-2)+1].blue)>>2;
	dst[dim*(dim-1)].green = (src[dim*(dim-1)].green+src[dim*(dim-1)+1].green+src[dim*(dim-2)].green+src[dim*(dim-2)+1].green)>>2;
	//cornor[dim-1][0]
	dst[dim*dim-1].red = (src[dim*dim-1].red+src[dim*dim-2].red+src[dim*(dim-1)-1].red+src[dim*(dim-1)-2].red)>>2;
	dst[dim*dim-1].blue = (src[dim*dim-1].blue+src[dim*dim-2].blue+src[dim*(dim-1)-1].blue+src[dim*(dim-1)-2].blue)>>2;
	dst[dim*dim-1].green = (src[dim*dim-1].green+src[dim*dim-2].green+src[dim*(dim-1)-1].green+src[dim*(dim-1)-2].green)>>2;
	//corner[dim-1][dim-1]
	int pos = dim-1;//Four sides
	for(i=1;i<pos;i++)
	{
		dst[i].red = (src[i].red+src[i-1].red+src[i+1].red+src[i+dim].red+src[i+1+dim].red+src[i-1+dim].red)/6;
		dst[i].green = (src[i].green+src[i-1].green+src[i+1].green+src[i+dim].green+src[i+1+dim].green+src[i-1+dim].green)/6;
		dst[i].blue = (src[i].blue+src[i-1].blue+src[i+1].blue+src[i+dim].blue+src[i+1+dim].blue+src[i-1+dim].blue)/6;
	}//row[0]
	pos = dim*dim-1;
	for(i=dim*(dim-1)+1;i<pos;i++)
	{
		dst[i].red = (src[i].red+src[i-1].red+src[i+1].red+src[i-dim].red+src[i+1-dim].red+src[i-1-dim].red)/6;
		dst[i].green = (src[i].green+src[i-1].green+src[i+1].green+src[i-dim].green+src[i+1-dim].green+src[i-1-dim].green)/6;
		dst[i].blue = (src[i].blue+src[i-1].blue+src[i+1].blue+src[i-dim].blue+src[i+1-dim].blue+src[i-1-dim].blue)/6;
	}//row[dim-1]
	pos = dim*dim-dim;
	for(i=dim;i<pos;i+=dim)
	{
		dst[i].red = (src[i].red+src[i-dim].red+src[i+1].red+src[i+dim].red+src[i+1+dim].red+src[i-dim+1].red)/6;
		dst[i].green = (src[i].green+src[i-dim].green+src[i+1].green+src[i+dim].green+src[i+1+dim].green+src[i-dim+1].green)/6;
		dst[i].blue = (src[i].blue+src[i-dim].blue+src[i+1].blue+src[i+dim].blue+src[i+1+dim].blue+src[i-dim+1].blue)/6;
	}//column[0]
	pos = dim*dim-1;
	for(i=dim+dim-1;i<pos;i+=dim)
	{
		dst[i].red = (src[i].red+src[i-1].red+src[i-dim].red+src[i+dim].red+src[i-dim-1].red+src[i-1+dim].red)/6;
		dst[i].green = (src[i].green+src[i-1].green+src[i-dim].green+src[i+dim].green+src[i-dim-1].green+src[i-1+dim].green)/6;
		dst[i].blue = (src[i].blue+src[i-1].blue+src[i-dim].blue+src[i+dim].blue+src[i-dim-1].blue+src[i-1+dim].blue)/6;
	}//column[dim-1]
	/*-------------------------So, we have solved all special points.------------------------------------------------*/
	pixel *vis1=&src[0];//src[0][0]
	pixel *vis2=&src[dim];//src[1][0]
	pixel *vis3=&src[dim+dim];//src[2][0]
	pixel *vis4=&src[dim+dim+dim];//src[3][0]
	int sum0_red,sum0_green,sum0_blue;
	int sum1_red,sum1_green,sum1_blue;
	int sum2_red,sum2_green,sum2_blue;
	int sum3_red,sum3_green,sum3_blue;
	int sum4_red,sum4_green,sum4_blue;
	int sum5_red,sum5_green,sum5_blue;
	int first=dim+1;
	int next=first+dim;// Next row of 'first'
	for(i=1;i<dim-2;i+=2)// Two rows for one time
	{
		sum0_red=vis2->red;     sum0_blue=vis2->blue;	sum0_green=vis2->green;
		sum0_red+=vis3->red;    sum0_blue+=vis3->blue;	sum0_green+=vis3->green;
		sum3_red=sum0_red+vis4->red;
		sum3_green=sum0_green+vis4->green;
		sum3_blue=sum0_blue+vis4->blue;
		sum0_red+=vis1->red;	sum0_blue+=vis1->blue;	sum0_green+=vis1->green;	
		vis1++;vis2++;vis3++;vis4++;	
		//First bvisk
		sum1_red=vis2->red;	    sum1_blue=vis2->blue;	sum1_green=vis2->green;
		sum1_red+=vis3->red;    sum1_blue+=vis3->blue;	sum1_green+=vis3->green;
		sum4_red=sum1_red+vis4->red;
		sum4_green=sum1_green+vis4->green;
		sum4_blue=sum1_blue+vis4->blue;
		sum1_red+=vis1->red;	sum1_blue+=vis1->blue;	sum1_green+=vis1->green;	
		vis1++;vis2++;vis3++;vis4++;	
		//Next block
		sum2_red=vis2->red;	    sum2_blue=vis2->blue;	sum2_green=vis2->green;
		sum2_red+=vis3->red;    sum2_blue+=vis3->blue;	sum2_green+=vis3->green;
		sum5_red=sum2_red+vis4->red;
		sum5_green=sum2_green+vis4->green;
		sum5_blue=sum2_blue+vis4->blue;
		sum2_red+=vis1->red;	sum2_blue+=vis1->blue;	sum2_green+=vis1->green;	
		vis1++;vis2++;vis3++;vis4++;	
		//Third block
		dst[first].red=(sum0_red+sum1_red+sum2_red)/9;
		dst[first].blue=(sum0_blue+sum1_blue+sum2_blue)/9;
		dst[first].green=(sum0_green+sum1_green+sum2_green)/9;
		first++;	
		// Make the first row.
		dst[next].red=(sum3_red+sum4_red+sum5_red)/9;
		dst[next].blue=(sum3_blue+sum4_blue+sum5_blue)/9;
		dst[next].green=(sum3_green+sum4_green+sum5_green)/9;
		next++;	
		// Make the next row.
		sum0_red=sum1_red;		sum1_red=sum2_red;
		sum0_green=sum1_green;	sum1_green=sum2_green;
		sum0_blue=sum1_blue;	sum1_blue=sum2_blue;    
		sum3_red=sum4_red;		sum4_red=sum5_red;
		sum3_green=sum4_green;	sum4_green=sum5_green;
		sum3_blue=sum4_blue;	sum4_blue=sum5_blue;
		// Save these to calculate the next.
		for(j=2;j<dim-4;j+=4)
		{
			sum2_red=vis2->red;	    sum2_blue=vis2->blue;	sum2_green=vis2->green;
			sum2_red+=vis3->red;    sum2_blue+=vis3->blue;	sum2_green+=vis3->green;
			sum5_red=sum2_red+vis4->red;
			sum5_green=sum2_green+vis4->green;
			sum5_blue=sum2_blue+vis4->blue;
			sum2_red+=vis1->red;	sum2_blue+=vis1->blue;	sum2_green+=vis1->green;	
			vis1++;vis2++;vis3++;vis4++;	
			//First bvisk
			dst[first].red=((sum0_red+sum1_red+sum2_red)/9);
			dst[first].blue=((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[first].green=((sum0_green+sum1_green+sum2_green)/9);
			first++;	
			// Make the first row.
			dst[next].red=((sum3_red+sum4_red+sum5_red)/9);
			dst[next].blue=((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[next].green=((sum3_green+sum4_green+sum5_green)/9);
			next++;	
			// Make the next row.
			sum0_red=sum1_red;		sum1_red=sum2_red;
			sum0_green=sum1_green;	sum1_green=sum2_green;
			sum0_blue=sum1_blue;	sum1_blue=sum2_blue;    
			sum3_red=sum4_red;		sum4_red=sum5_red;
			sum3_green=sum4_green;	sum4_green=sum5_green;
			sum3_blue=sum4_blue;	sum4_blue=sum5_blue;
			// Save these to calculate the next.
			sum2_red=vis2->red;	    sum2_blue=vis2->blue;	sum2_green=vis2->green;
			sum2_red+=vis3->red;    sum2_blue+=vis3->blue;	sum2_green+=vis3->green;
			sum5_red=sum2_red+vis4->red;
			sum5_green=sum2_green+vis4->green;
			sum5_blue=sum2_blue+vis4->blue;
			sum2_red+=vis1->red;	sum2_blue+=vis1->blue;	sum2_green+=vis1->green;	
			vis1++;vis2++;vis3++;vis4++;	
			dst[first].red=((sum0_red+sum1_red+sum2_red)/9);
			dst[first].blue=((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[first].green=((sum0_green+sum1_green+sum2_green)/9);
			first++;	
			dst[next].red=((sum3_red+sum4_red+sum5_red)/9);
			dst[next].blue=((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[next].green=((sum3_green+sum4_green+sum5_green)/9);
			next++;
			sum0_red=sum1_red;		sum1_red=sum2_red;
			sum0_green=sum1_green;	sum1_green=sum2_green;
			sum0_blue=sum1_blue;	sum1_blue=sum2_blue;    
			sum3_red=sum4_red;		sum4_red=sum5_red;
			sum3_green=sum4_green;	sum4_green=sum5_green;
			sum3_blue=sum4_blue;	sum4_blue=sum5_blue;
			// 2 road
			sum2_red=vis2->red;	    sum2_blue=vis2->blue;	sum2_green=vis2->green;
			sum2_red+=vis3->red;	sum2_blue+=vis3->blue;	sum2_green+=vis3->green;
			sum5_red=sum2_red+vis4->red;
			sum5_green=sum2_green+vis4->green;
			sum5_blue=sum2_blue+vis4->blue;
			sum2_red+=vis1->red;	sum2_blue+=vis1->blue;	sum2_green+=vis1->green;	
			vis1++;vis2++;vis3++;vis4++;
			dst[first].red=((sum0_red+sum1_red+sum2_red)/9);
			dst[first].blue=((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[first].green=((sum0_green+sum1_green+sum2_green)/9);
			first++;
			dst[next].red=((sum3_red+sum4_red+sum5_red)/9);
			dst[next].blue=((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[next].green=((sum3_green+sum4_green+sum5_green)/9);
			next++;
			sum0_red=sum1_red;		sum1_red=sum2_red;
			sum0_green=sum1_green;	sum1_green=sum2_green;
			sum0_blue=sum1_blue;	sum1_blue=sum2_blue;    
			sum3_red=sum4_red;		sum4_red=sum5_red;
			sum3_green=sum4_green;	sum4_green=sum5_green;
			sum3_blue=sum4_blue;	sum4_blue=sum5_blue;
			// 3 road
			sum2_red=vis2->red;	sum2_blue=vis2->blue;	sum2_green=vis2->green;
			sum2_red+=vis3->red;	sum2_blue+=vis3->blue;	sum2_green+=vis3->green;
			sum5_red=sum2_red+vis4->red;
			sum5_green=sum2_green+vis4->green;
			sum5_blue=sum2_blue+vis4->blue;
			sum2_red+=vis1->red;	sum2_blue+=vis1->blue;	sum2_green+=vis1->green;	
			vis1++;vis2++;vis3++;vis4++;
		    dst[first].red=((sum0_red+sum1_red+sum2_red)/9);
		    dst[first].blue=((sum0_blue+sum1_blue+sum2_blue)/9);
		    dst[first].green=((sum0_green+sum1_green+sum2_green)/9);
		    first++;
			dst[next].red=((sum3_red+sum4_red+sum5_red)/9);
			dst[next].blue=((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[next].green=((sum3_green+sum4_green+sum5_green)/9);
			next++;
		    sum0_red=sum1_red;		sum1_red=sum2_red;
			sum0_green=sum1_green;	sum1_green=sum2_green;
			sum0_blue=sum1_blue;	sum1_blue=sum2_blue;    
			sum3_red=sum4_red;		sum4_red=sum5_red;
			sum3_green=sum4_green;	sum4_green=sum5_green;
			sum3_blue=sum4_blue;	sum4_blue=sum5_blue;
			// 4 road
		}
		for(;j<dim-1;j++)
		{
			sum2_red=vis2->red;	    sum2_blue=vis2->blue;	sum2_green=vis2->green;
			sum2_red+=vis3->red;	sum2_blue+=vis3->blue;	sum2_green+=vis3->green;
			sum5_red=sum2_red+vis4->red;
			sum5_green=sum2_green+vis4->green;
			sum5_blue=sum2_blue+vis4->blue;
			sum2_red+=vis1->red;	sum2_blue+=vis1->blue;	sum2_green+=vis1->green;	
			vis1++;vis2++;vis3++;vis4++;	
			dst[first].red=((sum0_red+sum1_red+sum2_red)/9);
			dst[first].blue=((sum0_blue+sum1_blue+sum2_blue)/9);
			dst[first].green=((sum0_green+sum1_green+sum2_green)/9);
			first++;
			dst[next].red=((sum3_red+sum4_red+sum5_red)/9);
			dst[next].blue=((sum3_blue+sum4_blue+sum5_blue)/9);
			dst[next].green=((sum3_green+sum4_green+sum5_green)/9);
			next++;
		    sum0_red=sum1_red;		sum1_red=sum2_red;
			sum0_green=sum1_green;	sum1_green=sum2_green;
			sum0_blue=sum1_blue;	sum1_blue=sum2_blue;    
			sum3_red=sum4_red;		sum4_red=sum5_red;
			sum3_green=sum4_green;	sum4_green=sum5_green;
			sum3_blue=sum4_blue;	sum4_blue=sum5_blue;
		}
		first+=dim+2;//next row
		next+=dim+2;//third row
		vis1+=dim;
		vis2+=dim;
		vis3+=dim;
		vis4+=dim;//src[+1][0]
	}
}




/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/


void register_smooth_functions() {
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}
