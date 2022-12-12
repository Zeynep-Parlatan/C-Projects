#include<stdio.h>                                                              /*Definitions of printf and scanf*/
#include<math.h>                                                               /*Definitions of sqrt */

/*Function prototypes*/
int isprime(int a);                                                            /*Determining whether the numbers up to the number entered by the user are prime or not*/

int main(){

	int n;                                                                  /*Input - Number received from the user*/
	int i;                                                                  /*Number sent to function*/

	printf("Please enter a integer\n");
	scanf("%d",&n);
	printf("\n");


	if(n<=0)                                                                /*If the user enters a negative number, it encounters an error because it cannot be a negative prime number.*/
		printf("Error!! Prime numbers are positive numbers. Cannot be negative");

	
	for(i=2; i<n; i++){                                                     /*Since the smallest prime number is 2, the loop must start from two and continue until the number entered by the user*/
		
		if(isprime(i)==0 )

			printf("%d is a prime number\n\n", i);
		else

			printf("%d is not a prime number, it is dividible by %d\n\n",i,isprime(i));
	}


}

int isprime(int a){

	int check_num;
	int least_divisor;
	int flag=0;
	int x;

/*To understand whether the number is prime or not, it is enough to take the square root of the number and see if it can be divided by numbers up to this value.*/

	check_num=sqrt(a);

/*2 and 3 are prime numbers. Since it cannot enter the loop when the numbers are 2 and 3, it is specified as a separate state and zero is assigned to the flag.*/
	if(a==2 & a==3)                                   
		flag=0;
	
	for(x=2; x<=check_num; x++){
		
		flag=0;                                       /*If the number is prime, that is, if it is not fully divided, the flag is zero and the function returns the flag.*/
		if(a%x==0){                                   /*If it divides completely, the smallest divisor is found and the loop is broken. The smallest divider was returned in the function.*/
			flag=1;
			least_divisor=x;
			break;
		}
	}

	if(flag==0)                                           
		
		return flag;

	else
		return least_divisor;
	
}

	
	
