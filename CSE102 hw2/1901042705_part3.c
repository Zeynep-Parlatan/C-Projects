#include<stdio.h>                                                               /*Definitions of printf and scanf*/
#include<math.h>                                                                /*Definitions of sqrt */

int main(){

	int choice;                                                            /*Input-Getting a selection from the user for the menu*/
	double amount;                                                         /*Input-The amount of money that we have*/
	

	printf("\n\n  ********Welcome to ABC Exchange Office********\n\n");     /*Display the menu*/
	printf("Please enter your amount :");
	scanf("%lf",&amount);
	printf("\nPlease select your currency\n");
	printf("1. Turkish Lira \n");
	printf("2. Euro \n");
	printf("3.Dollar \n\n");
	scanf("%d",&choice);

	switch(choice){

/*The amount of money the user had was printed on the screen and the necessary actions were done according to the unit user wanted to convert. For this, a new switch-case structure was used inside each case.*/
		
		case 1:
			printf("You have %lf Turkish Liras.\n",amount);
			printf("Choose which currency you want to convert.\n");
			scanf("%d",&choice);
			switch(choice){

				case 1:
					printf("\nYou have %lf turkish liras\n", amount);
					break;
				case 2:
					
					amount=amount/6.69;
					printf("\nYou have %lf euro\n", amount);
					break;
			
				case 3:
					amount=amount/6.14;
					printf("\nYou have %lf dollar\n",amount);
					break;

				default :
					printf("\nYour selection is invalid!!\n");
					
			}
		break;
		case 2:
			printf("You have %lf Euro.\n",amount);
			printf("Choose which currency you want to convert.\n");
			scanf("%d", &choice);
			switch(choice){

				case 1:
					amount=6.69*amount;
					printf("\nYou have %lf Turkish Liras.\n", amount);
					break;

				case 2:
					printf("\nYou have %lf Euro.\n", amount);
					break;

				case 3:
					amount=6.69*amount;                                                   /*To convert the euro into dollars, it was first converted into Turkish liras*/
					amount=amount/6.14;                                                   /*and then converted into dollars.*/
					printf("\nYou have %lf Dollars.\n",amount);
					break;

				default :
					printf("\nYour selection is invalid!!\n");
					
			}
		break;

		case 3:
			printf("You have %lf Dollar.\n",amount);
			printf("Choose which currency you want to convert.\n");
			scanf("%d",&choice);
			switch(choice){
				
				case 1:
					amount=amount*6.14;
					printf("\nYou have %lf Turkish Liras.\n",amount);
					break;

				case 2:
					amount=amount*6.14;                                                 /*To convert the dollar into euros, it was first coverted into Turkish liras*/
					amount=amount/6.69;                                                 /*and then converted into euros*/
					printf("\nYou have %lf Euro.\n",amount);
					break;

				case 3:
					printf("\nYou have %lf Dollar.\n",amount);
					break;

				default:
					printf("\nYour selection is invalid!!\n");
					
			}
		break;

		default :
			printf("Your selection is invalid!!\n");                                           /*User was warned when enter a number that is not valid in the menu.*/
			break;




	}
}

