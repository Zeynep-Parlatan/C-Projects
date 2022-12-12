#include<stdio.h>                                                                      /*Definitions of printf and scanf*/

/*Function prototypes*/
int sum (int n, int flag);                                                             /*The sum of the numbers up to the number entered, depending on whether it is even or odd.*/
int mult (int n, int flag);                                                            /*Multiplication of the numbers up to the number entered, depending on whether it is even or odd.*/

int main(){

	int num;                                                                       /*Input - Number received from the user*/
	int operation_flag;  						               /*Input - The type of operation*/                                                     
	int flag;							               /*Input - the type of numbers with for doing operation*/

	printf("Please enter an integer:");
	scanf("%d",&num);
	
	printf("\nPlease enter '0' for sum, enter '1' for multiplication: \n");        /*choosing which operation to do*/
	scanf("%d",&operation_flag);

	switch(operation_flag){
			
			case 0:
				printf("\nPlease enter '0' to work on even number, enter '1' to work on odd number: \n");      /*Choosing the type of numbers with for doing operation*/
				scanf("%d",&flag);

				if(flag!=0 && flag!=1){
					printf("Invalid value for odd/even selection\n");
					break;
				}

				printf(" %d\n",sum(num,flag));

				break;

			case 1:
				printf("\nPlease enter '0' to work on even number, enter '1' to work on odd number: \n");
				scanf("%d",&flag);

				if(flag!=0 && flag!=1){
					printf("Invalid value for odd/even selection\n");
					break;
				}

				printf(" %d\n",mult(num,flag));
				break;

			default:
				printf("\nUnsported operation!!\n");
	}
}


int sum(int n, int flag){

	int i,sum_of_numbers=0;

	if(flag==0){                                                               /*For even numbers*/
		
		for(i=2; i<=n; i=i+2){

/*If the user enters an even number and wants to add even numbers up to that number, the last number equals the number itself. If the user wants to enter an even number and add the odd numbers up to that number, the last number becomes one less than the number entered.*/
			
			if(i==n || i==n-1){
                                        
				sum_of_numbers = sum_of_numbers+i;
				printf("%d = ",i);
				return sum_of_numbers;
			}
			
/*the sum of numbers until the last number*/

			printf("%d + ",i);
			sum_of_numbers = sum_of_numbers+i;
		}
	}


	if(flag==1){                                                               /*For odd numbers*/

		for(i=1; i<=n; i=i+2){

			if(i==n || i==n-1){

				sum_of_numbers = sum_of_numbers+i;
				printf("%d =",i);
				return sum_of_numbers;
			}

			printf("%d + ",i);
			sum_of_numbers = sum_of_numbers+i;
		}
	}
}


int mult(int n,int flag){
	
	int i, mult_of_numbers=1;

	if(flag==0){                                                             /*For even numbers*/

		for(i=2;i<=n;i=i+2){

/*If the user enters an even number and wants to multiple of even numbers up to that number, the last number equals the number itself. If the user wants to enter an even number and multiple of the odd numbers up to that number, the last number becomes one less than the number entered.*/

			if(i==n || i==n-1){

				mult_of_numbers = mult_of_numbers * i;
				printf("%d = ",i);
				return mult_of_numbers;
			}
			
/*the multiple of numbers until the last number*/

			printf("%d * ",i);
			mult_of_numbers = mult_of_numbers * i;
		}
	}

	
	if(flag==1){                                                              /*For odd numbers*/


		for(i=1; i<=n; i=i+2){

			if(i==n || i==n-1){

				mult_of_numbers = mult_of_numbers * i;
				printf("%d = ",i);
				return mult_of_numbers;
			}

			printf("%d * ",i);
			mult_of_numbers = mult_of_numbers * i;
		}
	}
}

			



