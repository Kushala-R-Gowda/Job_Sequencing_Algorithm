/**************************************************
Problem Statement : JOB SEQUENCING WITH DEADLINES
Implemented Language : C
***************************************************/

#include<stdio.h>
#include<stdlib.h>

int flag=0;

//Insertion Sort to sort the profits of the given jobs in descending order
void insertion_sort(int profits_sorted[100], int n,int deadlines[100])
{
	int temp,i,j,a[100];
	for(i=0;i<n;i++)
    {
		j=i;
		while(j>0 && profits_sorted[j-1]>profits_sorted[j])
        {	        
			temp = profits_sorted[j];
			profits_sorted[j] = profits_sorted[j-1];
			profits_sorted[j-1] = temp;
            j--;
        }
    }
    j=0;
    for(i=n-1;i>=0;i--)
    {
    	a[j++] = profits_sorted[i];
    }
    for(i=0;i<n;i++)
    {
    	profits_sorted[i] = a[i];
    }
}

//Recursive function to assign the particular job in the job_sequence array to get the optimal sequence
void recursion_job_sequence(int job_number,int n,int deadlines[100],int job_sequence[100])
{
	if(job_sequence[n]==-1&&n>0)
	{
		job_sequence[n] = job_number;
		flag++;
		return;
	}
	if(n<=0)
	{
		flag++;
		return;	
	}	
	else
	{
		recursion_job_sequence(job_number,n-1,deadlines,job_sequence);
	}	
}

int main()
{
	int number_of_jobs,total_profit=0,job_profit,job_number,i,n,j; 
	int profits[100],deadlines[100],profits_sorted[100],profits_copy[100],job_sequence[100];
	
	printf("Enter the number of jobs : ");
	scanf("%d",&number_of_jobs);
	
	printf("Enter the profits and deadlines for all the jobs\n");
	for(i=0;i<number_of_jobs;i++)
	{
		scanf("%d%d",&profits[i],&deadlines[i]);
	}
	
	for(i=0;i<number_of_jobs;i++)
	{
		profits_sorted[i] = profits[i];
		profits_copy[i] = profits[i];
	}
	
	for(i=1;i<=number_of_jobs;i++)
	{
		job_sequence[i] = -1;
	}
	
	insertion_sort(profits_sorted,number_of_jobs,deadlines);
	
	i=0;
	while(flag<number_of_jobs)
	{
		job_profit = profits_sorted[i];
		for(j=0;j<number_of_jobs;j++)
		{
			if(job_profit == profits_copy[j])
			{
				profits_copy[j]=-1;
				job_number = j;
				break;
			}
		}
		n=deadlines[job_number];
		recursion_job_sequence(job_number,n,deadlines,job_sequence);
		i++;
	}
	
	printf("******** JOB SEQUENCE ******** \n");
	for(i=1;i<=number_of_jobs;i++)
	{
		if(job_sequence[i]!=-1)
			printf("Job %d\n",job_sequence[i]+1);
	}
	
	for(i=1;i<=number_of_jobs;i++)
	{
		if(job_sequence[i]!=-1)
			total_profit = total_profit + profits[job_sequence[i]];
	}
	printf("TOTAL PROFIT = %d\n",total_profit);
	return 0;
}

/*
TEST CASES

Test Case :1
Enter the number of jobs : 6
Enter the profits and deadlines for all the jobs
30 4
20 2
60 2
30 2
10 1
80 4
******** JOB SEQUENCE ******** 
Job 4
Job 3
Job 1
Job 6
TOTAL PROFIT = 200


Test Case :2
Enter the number of jobs : 4
Enter the profits and deadlines for all the jobs
20 4
10 1
40 1
30 1
******** JOB SEQUENCE ******** 
Job 3
Job 1
TOTAL PROFIT = 60


Test Case :3
Enter the number of jobs : 5
Enter the profits and deadlines for all the jobs
100 2
19 1
27 2
25 1
15 3
******** JOB SEQUENCE ******** 
Job 3
Job 1
Job 5
TOTAL PROFIT = 142


Test Case :4
Enter the number of jobs : 4
Enter the profits and deadlines for all the jobs
50 2
10 1
15 2
25 1
******** JOB SEQUENCE ******** 
Job 4
Job 1
TOTAL PROFIT = 75


Test Case :5
Enter the number of jobs : 6
Enter the profits and deadlines for all the jobs
200 5
180 3
190 3
300 2
120 4
100 2
******** JOB SEQUENCE ******** 
Job 2
Job 4
Job 3
Job 5
Job 1
TOTAL PROFIT = 990


Test Case :6
Enter the number of jobs : 5
Enter the profits and deadlines for all the jobs
60 2
100 1
20 3
40 2
20 1
******** JOB SEQUENCE ******** 
Job 2
Job 1
Job 3
TOTAL PROFIT = 180
*/

/*ANALYSIS OF THE ALGORITHM

Part 1: Sorting the array profits in descending order using Insertion sort
		* It takes nlogn time complexity.
Part 2: Sequencing and Linear Search.
		* It takes number_of_jobs*number_of_jobs = number_of_jobs^2 time complexity.
		
The maximum of the nlogn+number_of_jobs^2 is number_of_jobs^2.
TIME COMPLEXITY OF JOB SEQUENCING ALGORITHM is O(number_of_jobs^2).
*/
