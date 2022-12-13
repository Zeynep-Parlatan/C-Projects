#include<stdio.h>						/*Definitions of printf,scanf,fseek,fprintf,fgetc,fputc,fopen,fclose*/
#include<stdlib.h>						/*to use rand(), exit() and system()*/
#include<time.h>
#include<math.h>						/*Definitions of sqrt and pow*/

/*Function prototypes*/

void menu();
void decrypt_and_print(char *file_path);
char decrypt_numbers(int number);
void deep_decrypt_and_print(char *file_path);
char decrypt_numbers(int number);
void track_machine();
void refresh_position(int *X, int *Y, double *D, double *R);
void encrypt_messages(char *file_path);
int decrypt_shapes(char shape);



int main(){

	menu();

return 0;
}

void menu(){
	
	int choice;
	
	do{
	
		printf("\n1-) Decrypt and print encrypted_p1.img\n");				/*Displaying the menu*/
		printf("2-) Decrypt and print encrypted_p2.img\n");
		printf("3-) Switch on the tracking machine\n");
		printf("4-) Encrypt the message\n");
		printf("5-) Switch off\n\n");

		printf("Please enter your choice: ");
		scanf("%d",&choice);
		printf("\n");

		if(choice == 1){
			decrypt_and_print("encrypted_p1.img");
		}

		else if(choice == 2){
			deep_decrypt_and_print ("encrypted_p2.img");
		}

		else if(choice == 3){
			track_machine ();
		}
	
		else if(choice == 4){
			encrypt_messages("decrypted_p4.img");
		}

		else if(choice == 5){
			exit(0);
		}

		else{
			printf("Error! This number should be in the range[1-5]. Please again enter a number: \n");
		}
	
	}while(choice != 5);

}

//part1
void decrypt_and_print(char *file_path){

	FILE *fp = fopen(file_path,"r");					/*Opening the file to read the characters*/
	char character;								/*One character of input file*/
	int num;

/*In order to read from the file, the file must exist. If the file does not exist, it will give an error and exit this part.*/

	if(fp==NULL){
		printf("!!Error File not found on the system!!\n");
	}

	else{

/*Since the numbers in the file are unified , they are not taken as integer. It was taken one by one in the form of character. If received character is end of the line ,it passed to a lower line. If not the end of the line, it is converted to integer.*/

		while((character = fgetc(fp))!=EOF){


			if(character == '\n' ){
				printf("\n");
			}
		
			else{
			num = character-'0';
		
			printf("%c",decrypt_numbers(num));
			}
		
		}	
	
	fclose(fp);

	}
}
	
/*The converted integer is sent to this function, its equivalent is found as a symbol, and used for decryption.*/

char decrypt_numbers(int number){

	char sign;
	switch(number){

			case 0:
				sign = ' ';
				return sign;
			case 1: 
				sign= '-';
				return sign;
			case 2:
				sign= '_';
				return sign;
	
			case 3: 
				sign = '|';
				return sign;

			case 4: 
				sign = '/';
				return sign;
			
			case 5: 
				sign = '\\';
				return sign;
			
			case 6:
				sign = 'O';
				return sign;
	}
}

//part2
void deep_decrypt_and_print(char *file_path){

	FILE *fp = fopen(file_path,"r");						/*Opening the file to read the characters*/
	char character;									/*One character of input file*/
	int num;									/*variable that holds the character converted to integer */					
	int sum=0;
	int code=0;									/*The variable used to write the secret message to the terminal*/

	if(fp==NULL){
		printf("!!Error File not found on the system!!\n");
	}

	else{

		while((character = fgetc(fp))!=EOF){
		
			sum = 0;
			num = character-'0';					/*The integer value was found by subtracting '0' (so ASCII value 48) from the ASCII value of the character.*/
			sum+=num;
		
				for(int i=1; i<3; i++){
			
					character=fgetc(fp);

						if(character == '\n'){		/*Since there is no character to be taken at the end of the line according to the formula, it is considered zero*/ 
							sum = sum;		/*so the total does not change. The loop breaks and pass to the next line*/
							break;
						}

						else{
							num = character-'0';
				 			sum = sum+num;
						}
				}
	
			code = sum % 7;
			printf("%c",decrypt_numbers(code));			/*Displaying the secret message on terminal*/
	
/*When it reaches the end of the line it passes to the next line. If it did not come end of line, it comes back from where it was in the file and continues to take characters there.*/
			if(character == '\n'){
				fseek(fp,0,SEEK_CUR);
				printf("\n");
			}

			else{
				fseek(fp,-2,SEEK_CUR);
			}
		}

	fclose(fp);

	}
}

//Part3
void track_machine(){

	int num1=0, num2=0;  							/*The first position of the enemy camp (0,0) */							
	double distance=0;							/*The distance between the enemy and our camp*/							
	double displacement=0;							/*The distance between the enemy's new position and its current position*/
	char choice;								/*Character received from the user to continue or finish the program */
	int k=0;								/*Counter that use indicate that we won and the program ends when the enemy camp and our camp are the same point.*/	
	int m=0;								/*The counter use to indicate this when the enemy camp is very close to us */

   do{

	system("clear");

/*It was not shown on the map as it was the first position of the enemy (0,0). Using the other function, random numbers were discarded each time and the map was created with two nested loops.*/

	refresh_position(&num1, &num2, &distance, &displacement);

			
			for(int i=1; i<=11; i++){

				for(int j=1; j<=11; j++){
					
					if(num1==6 && num2==6){	
					/*If we are in the same position as the enemy, the counter is increased and the loops are broken in order and exit the program */

						printf("Perfect! Mission complete! We caught the enemy :)\n");
						k=1;
						break;
					}

					if(i==6 && j==6)
						printf("O\t");
					
					else if(i==num1 && j==num2){
						printf("E\t");
							if(num1==7 && num2==6 || num1==5 && num2==6)
							/*If the enemy is near our camp, the counter is increased and the warning message is written.*/
									m=1;
					}
			
					else
						printf(".\t");
				}

			if(k==1)
				break;

			printf("\n");
			}
		
		if(k==1)
			break;
		if(m==1){
			printf("Attention! The enemy is very close!!\n");
			m=0;
		}

		printf("Enemies X position: %d, Y position: %d, Displacement: %.2lf, Distance to our camp: %.2lf",num1,num2,displacement,distance);
		printf("\nCommand waiting:\n");
		scanf(" %c",&choice);
		printf("\n");
		
	
     }	while(choice!='E' && choice=='R');
	
}

/*Assigning random values to the enemy's position at each step to refresh the map and calculating distance and displacement accordingly.*/
void refresh_position(int *X, int *Y, double *D, double *R){

	double dis=0;
	double dis2=0;
	
	int k;
	int m;

	k=*X;						/*Storing its current position in other variables to calculate the enemy's displacement.*/
	m=*Y;
	
	*X=0;						/*Used to assign a new random number between 1 and 11 by resetting the current value in the pointer each time.*/
	*Y=0;
	
	srand(time(NULL));

	*X=*X+(1+rand()%11);
	*Y=*Y+(1+rand()%11);
	

	dis=pow(*X-6,2)+ pow(*Y-6,2);
	*D=sqrt(dis);

	dis2=pow(*X-k,2)+pow(*Y-m,2);
	*R=sqrt(dis2);

}

//part4
void encrypt_messages(char *file_path){

	FILE *fp1=fopen(file_path,"r");						/*Opening the file to read the characters*/
	
	char character;								/*One character of input file*/
	int var1=0,var2=0;							/*Variables used to apply the formula. The two variables must be assigned zero, because the file will initially be*/ 
	int var3;								/*considered to include zero at the beginning.*/							
	int sum=0;								
	int code=0;
	


	if(fp1==NULL){
		printf("!!Error File not found on the system!!\n");
	}

	else{
		FILE *fp2=fopen("encrypted_p4.img","w");			/*Opening the file to be written by encrypting the characters being read.*/
		
		while((character=fgetc(fp1))!=EOF){
			
	
			sum=0;
			if(character=='\n'){					/*Whenever it passes to the lower line, variables are assigned zeros*/
				var1=0;						/*because they are considered to have a zero at the beginning of the line.*/
				var2=0;
				fputc('\n',fp2);
			}
		
			else{
/*The received character is sent to the other function to match the integer.The formula is applied to the variables.For the next step, variables are saved to each other by a swapping.*/

				var3=decrypt_shapes(character);
				sum=var1+var2+var3;
				code=sum%7;
				fprintf(fp2,"%d",code);
				var1=var2;					/*swapping process*/			
				var2=var3;
			}

		}
	fclose(fp2);

	fclose(fp1);
	}
	
	
}

/*The received characters (figures) are sent to this function. Integer equivalent is found and used for encryption.*/
int decrypt_shapes(char shape){

	int num;
	switch(shape){

			case ' ':
				num=0;
				return num;
				
			case '-': 
				num= 1;
				return num;
			case '_':
				num=2;
				return num;
	
			case '|': 
				num = 3;
				return num;

			case '/': 
				num = 4;
				return num;
			
			case '\\': 
				num = 5;
				return num;
			
			case 'O':
				num = 6;
				return num;
	}
}








