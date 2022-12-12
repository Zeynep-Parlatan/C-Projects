#include<stdio.h>                                                       /*Definitions of printf and scanf*/

/*Function prototypes*/

int andop(int a, int b);                                               /*Implementing logical "AND" operation on integers*/

int number_length(int number);                                         /*Calculating the length of the number taken from the user*/ 
int find_digit(int number,int n);                                      /*Calculation of any digit of the number taken from the user*/

int main(){

	int num1,num2,n;
	int digit1,digit2;

do{
	printf("Please enter first integer: ");
	scanf("%d", &num1);
	printf("Please enter second integer: ");
	scanf("%d", &num2);

	n = number_length(num1);
	
	while(n>0){

/*In order to find out whether the number is binary, the number is sent to the function of finding the digit value as many as the number of digits. If it is not binary (that is, it is not equal to 1 and 0), the loop is broken and the user is asked for a number again.*/

		digit1 = find_digit(num1,n);

		if(digit1!=0 && digit1!= 1){
			printf("Integer should be binary, please enter two new integer!\n\n");
			break;
		}

		n--;
	}

	n = number_length(num2);
	
	while(n>0){

		digit2 = find_digit(num2,n);
		
		if(digit2!=0 && digit2!= 1){
			printf("Integer should be binary, please enter two new integer!\n\n");
			break;
		}

		n--;
	}

/*If the two numbers entered are not the same length, the user is asked for the number again.*/

	if(number_length(num1)!=number_length(num2)){
	
		printf("Integer should have the same lenght, please enter two new integer!\n\n");
	}



} 
while((digit1!=0 && digit1!=1 || digit2!=0 && digit2!=1) || number_length(num1)!=number_length(num2));


	printf("%d AND %d = ",num1,num2);

	printf("%d\n", andop(num1,num2));                              /*Displaying the the result of "and" operation*/
	
}

/*Calculating the length of the number*/
int number_length(int number){              
		
	int length=0;                                                               

	while(number>0){
		number=number/10;
		length++;
	}

	return length;
}

/*Implementing "and" operation and returning the result to main*/
int andop(int a, int b){

	int n,num;
	int parse, digit_value;                                           /*Using for extract numbers from numbers*/
	 
	num=0;
	parse=1;
	n = number_length(a);

/*If the number is considered to be decimal while calculating; for example, let's have a number called 1010. This number is resolved by 1*10^3+ 0*10^2+ 1*10^1+ 0*10^0 it can be written as. Here we go backwards and create the number analysis and get the number from here.*/

	while(n>0){

/*If our number is 4 digits, the digits go up to x*10^3 in the analysis of the number. Therefore, 1 is subtracted from the digit value.*/

		digit_value = n-1;
		parse=1;

		while(digit_value >= 1){
				
				parse = parse*10;
				digit_value--;
			}
/*If the same digit of both numbers is 1, that digit value is multiplied by 1 and added to the number. If not, multiply by 0 and added the number.*/

		if(find_digit(a,n) == 1 && find_digit(b,n) == 1)

			num = num + 1*parse;

		else
			num = num + 0*parse;

		
		n--;
		
	}
	
	return num;

}

/*Calculation of any digit of the number taken from the user*/
int find_digit(int number,int n){

/*To find the tens digit of a number, it is necessary to first find the remainder of the number from 100 and then find out how many 10 numbers are in the result. When we use this method to find any digit of the number, we can get a general formula. The n.th digit of the number= (number%10^n) / 10^n-1. The desired digit of the number was calculated by writing this process in a loop.*/

		
	int i,numerator,denominator,digit;

		i=0;
		numerator=1;
		while(i<n){                                                /*Calculating of 10^n */
			numerator = numerator*10;
			i++;
		}
		
		i=0;
		denominator=1;
		while(i<n-1){                                             /*Calculating of 10^n-1 */
			denominator = denominator*10;
			i++;
		}
		
		digit = (number % numerator) / denominator;
	
	return digit;

}
		



