#include<stdio.h>                                                                     /*Definitions of printf and scanf*/
#include<math.h>                                                                      /*Definitions of sqrt */

/*Function prototypes*/

int number_lenght(int number);                                                        /*Finding the number of digits of the number entered by the user*/      
int find_digit(int number, int index);                                                /*Finding the desired digit of the number*/

int main(){
	int num,choice,lenght;
	printf("Please enter a number(maximum 6 digits): \n");
	scanf("%d",&num);
	printf("Your number has %d digits\n",number_lenght(num));
	lenght = number_lenght(num);


	if(lenght>6)                                                                   /*If the number of digits is more than 6, the user encountered an error.*/
		printf("\nError!! Please enter maximum 6 digits of number\n");
	
	else{

	printf("\nWhen your number is written 100 times next to each other, which digits of this number would you like to see?: \n");
	scanf("%d",&choice);


/*Determining the range that the user can enter by multiplying the number by 100 by the number of digits.For example, let us have a two-digit number.When we type this number 100 times in a row, our number is 200 digits.If the digit value that the user wants to find is more than 200, user will encounter an error.*/

	if(choice>lenght*100)

		printf("\nError!!The number of digits, if we write it 100 times in a row, will be the digit value of 100 * digits. Please enter a suitable number for it.\n");
	
	else
		printf("\n%d.th digit of the big number squence: %d\n",choice,find_digit(num,choice));
	
        }
}


int number_lenght(int number){                                                                /*Calculation of the digit value with the help of logarithms.*/

	int basamak_sayisi;
	basamak_sayisi=log10(number)+1;
	return basamak_sayisi;
}

int find_digit(int number, int index){

	int number_of_digits,result;
	int remainder;
	int which_digit;
	
	number_of_digits=number_lenght(number);                                               /*Calculating the number of digits to get the appropriate mode of the number. */
	
	if(number_of_digits==1){
		printf("It is equal to itself, because the number is one digit\n");
		result=number;
	}

/*To find the tens digit of a number, it is necessary to first find the remainder of the number from 100 and then find out how many 10 numbers are in the result. When we use this method to find any digit of the number, we can get a general formula. The n.th digit of the number= (sayı%10^n) / 10^n-1
*/

	remainder= index % number_of_digits;


/*If the Digit the user wants to find is zero in the mode based on the number of digits, the first digit must be calculated. For example, if we want to find the 24th digit when we write the number 120 100 times in a row, the first digit must be calculated because the remaining zero from the section of 24 to 3 is*/



	if(remainder==0)

		result=(number % (int)pow(10,1)) / pow(10,0);                                       /*Calculation of the first digit of the number */

	
else{

/*The digit values begin to be calculated from the right (such as the ones digit, tens digit).The nth term of any number is found from the left.So it was found that the desired value from the left corresponds to the digit value from the right.*/


		 which_digit = number_of_digits-remainder+1;
                 result = (number % (int) pow(10,which_digit))/pow(10,which_digit-1);               /*Calculation of the digit value found.*/
		}

return result;
}
		




