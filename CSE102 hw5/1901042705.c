#include<stdio.h>						      /*Definitions of printf,scanf,fprintf,fgetc,fopen,fclose*/
#include<stdlib.h>						      /*to use exit() */

//Function prototypes
void menu();
void read_news(char buffer[500], char file_path[11], int is_only_title);
void append_file(char *file_path, char c);
void readed_news(char *file_path);
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]);
double f_func(int x);
double g_func(double f(int x) , int a);

#define size 500

int main(){

	menu();
return 0;
}

void menu(){
			
	char buffer[500];							 /*The array in which the text is read and saved*/
	int title_or_text=1;							 /*Variable used to print only the title or all text*/
	char choice;								 /*Variable used to select which operation to perform in the menu*/
	char a,b,c;								 /*Options in the menu*/
	int which_news,l;								 /*Variable that holds which news is selected*/
	char append_number;							 /*The variable used to send the selected news to the function as a character*/
	char keep_on;								 /*Variable in which the answer received from the user is kept to continue or end the program*/
	
	printf("************* Daily Press *************\n");
	printf("\nToday's news are listed for you:\n\n");
	do{
	char file_path1[11]="news/1.txt";					 /*The array used to send the text to the function */
	printf("\nTitle of 1.news: ");
	read_news(buffer,file_path1,title_or_text);

	char file_path2[11]="news/2.txt";
	printf("\nTitle of 2.news: ");
	read_news(buffer,file_path2,title_or_text);

	char file_path3[11]="news/3.txt";
	printf("\nTitle of 3.news: ");
	read_news(buffer,file_path3,title_or_text);

	char file_path4[11]="news/4.txt";
	printf("\nTitle of 4.news: ");
	read_news(buffer,file_path4,title_or_text);

	printf("\n\nWhat do you want to do?\n");
	printf("a.Read a new\n");
	printf("b.Listed readed news\n");
	printf("c.Get decrypted information from the news\n");
	scanf(" %c",&choice);
	
	if(choice=='a'){

		title_or_text--;						      /*The value of the variable is reduced by one to be able to read the entire text*/

		
		printf("Which news do you want to read?: ");
		scanf("%d",&which_news);
		printf("\n");
		if(which_news==1){
			append_number=which_news+'0';				      /*Integer converted to char to send it to function*/
			append_file("readed_news_id.txt", append_number);	      /*Sending the selected news and writing it to the file if it is not in the file*/
			read_news(buffer,file_path1,title_or_text);		      /*Reading all the sent text and pressing on the screen*/
			
		}

		else if(which_news==2){
			append_number=which_news+'0';
			append_file("readed_news_id.txt",append_number);
			read_news(buffer,file_path2,title_or_text);
		}
		
		else if(which_news==3){
			append_number=which_news+'0';
			append_file("readed_news_id.txt",append_number);
			read_news(buffer,file_path3,title_or_text);
		}

		else if(which_news==4){
			append_number=which_news+'0';
			append_file("readed_news_id.txt",append_number);
			read_news(buffer,file_path4,title_or_text);
		}

		else{
			printf("!!Error. This number should be in the range[1-4]!!");  /*An error message is given to the user when a value is entered more than the number of news in the program.*/
			
		}
		
		title_or_text++;			/*When the program is continued again, the value of the variable is increased by 1 so that news headlines can be written in the menu.*/

		
	}

	else if(choice=='b'){
		printf("\nReaded news are listed below:\n");
		readed_news("readed_news_id.txt");	                               /*View the news that is read and saved in the file in the append_file function*/
		 
	}

	else if(choice=='c'){
		title_or_text--;						       /*The value of the variable is reduced by one to be able to read the entire text*/
		char buffer_news[500];						       /*The array in which the text is read and saved*/
		char buffer_magic[10];						       /*The array in which the magic numbers in the texts are kept*/							
		printf("Which news would you like to decrypt?: ");
		scanf("%d",&which_news);
		printf("\n");

		if(which_news==1){
		
			read_news(buffer_news,file_path1,title_or_text);	       /*Reading the news and saving it to buffer_news*/
			printf("\nThe number of tests performed: ");
			read_magic_numbers(buffer_magic,buffer_news);		       /*Finding magic numbers in the text saved in buffer_news and saving them in buffer_magic*/
		
		}

		else if(which_news==2){
		
			read_news(buffer_news,file_path2,title_or_text);
			printf("\nThe number of sick people: ");
			read_magic_numbers(buffer_magic,buffer_news);
		}

		else if(which_news==3){
		
			read_news(buffer_news,file_path3,title_or_text);
			printf("\nThe number of deaths: ");
			read_magic_numbers(buffer_magic,buffer_news);
		}

		else if(which_news==4){
		
			read_news(buffer_news,file_path4,title_or_text);
			printf("\nExpected number of sick people: ");
			read_magic_numbers(buffer_magic,buffer_news);
		}
		else{
			printf("!!Error. This number should be in the range[1-4]!!");  /*An error message is given to the user when a value is entered more than the number of news in the program.*/
		}

		title_or_text++;   /*When the program is continued again, the value of the variable is increased by 1 so that news headlines can be written in the menu.*/

	}
	else{
		printf("Error! Please enter only the letters a,b,c !");   /*User be warned when entering a different letter than the options in the menu*/
	}

	printf("\n\nDo you want to continue? Yes(y) / No(n)\n");
	scanf(" %c",&keep_on);	
	
	if(keep_on!='y' && keep_on!='n'){			          /*If the user enters a different value than the options we offer, the error is given and the value is received again.*/
		printf("!!Error Please just enter 'y' or 'n'\n");
		scanf(" %c",&keep_on);
	}
	if(keep_on=='n'){
		printf("Good byee :) ");
	}

	}while(keep_on=='y' && keep_on!='n');

	exit(0);
}


void read_news(char buffer[500], char file_path[11], int is_only_title){


	FILE *fp=fopen(file_path,"r");

	char character;							 /*Variable in which the characters read from the file are kept*/
	int number_of_character;					 /*Variable in which the number of characters read is kept*/
	int i=0;							 /*indexsi of the array*/
	
	if(fp==NULL){
		printf("!!Error File not found on the system!!\n");      /*In order to be able to read from the file, the file must exist on the system ,if it's not exist the user is given an error.*/
	}
	
	else{
/*If only_title is 1, it is read until the end of the line and only the title of the news is printed, otherwise the file is read to the end and all text is printed.*/

		if(is_only_title==1){   	

			while((character=fgetc(fp))!='\n'){

				buffer[i]=character;
				i++;
			}

			number_of_character=i;
			for(i=0; i<number_of_character; i++){
			printf("%c",buffer[i]);
			}
		}
	
		else{
			while((character=fgetc(fp))!=EOF){

				buffer[i]=character;
				i++;
			}

			number_of_character=i;
			for(i=0; i<number_of_character; i++){
			printf("%c",buffer[i]);
			}
		}
	
	fclose(fp);
	}
}

/*When the user enters the news number, the function used to check the file and give a warning message if it has been read before,or  to write to the file if it is not in the file.*/
void append_file(char *file_path, char c){

	FILE *fp1=fopen(file_path,"a+");		       /*Append mode was used for both reading from and writing to the file.*/

	char ch;					       /*Variable in which the characters read from the file are kept*/
	int keep;					       /*The variable in which the answers to the questions asked to are kept to continue the program*/
	int counter=0;					       /*The counter was used to print the read news to the file only once*/
 
	if(c=='1'){

		while((ch=fgetc(fp1))!=EOF){
			
			if(ch=='1'){
				counter++;		       /*If the selected news is in the file,the counter is increased and the news is not reprinted in the file.*/
				printf("This news has been read before. Do you want to read it again? Yes(1) / No(0) !!Please just enter '1' or '0' !!\n");
				scanf("%d",&keep);
				if(keep==0){
					printf("Would you like to continue? Yes(1) / No(0) !!Please just enter '1' or '0' !!\n");
					scanf("%d",&keep);
					if(keep==0){
						printf("Good bye :)");
						exit(0);
					}
					else
						menu();			/*If the user wants to continue the program, the menu function is called.*/
				}
			}
		}
		
		if(counter==0){
			
			fprintf(fp1,"%c",c);
			fclose(fp1);
		}
	}

	else if(c=='2'){
		
		while((ch=fgetc(fp1))!=EOF){
			
			if(ch=='2'){
				counter++;
				printf("This news has been read before.Do you want to read it again? Yes(1) / No(0) !!Please just enter '1' or '0' !!\n");
				scanf("%d",&keep);
				if(keep==0){
					printf("Would you like to continue? Yes(1) / No(0) !!Please just enter '1' or '0' !!\n");
					scanf("%d",&keep);
					if(keep==0){
						printf("Good bye :)");
						exit(0);
					}
					else
						menu();
				}
			}
		}

		if(counter==0){
			fprintf(fp1,"%c",c);
			fclose(fp1);
		}
	}

	else if(c=='3'){

		while((ch=fgetc(fp1))!=EOF){
			
			if(ch=='3'){
				counter++;
				printf("This news has been read before.Do you want to read it again? Yes(1) / No(0) !!Please just enter '1' or '0' !!\n");
				scanf("%d",&keep);
				if(keep==0){
					printf("Would you like to continue? Yes(1) / No(0) !!Please just enter '1' or '0' !!\n");
					scanf("%d",&keep);
					if(keep==0){
						printf("Good bye :)");
						exit(0);
					}
					else
						menu();
				}
			}
		}

		if(counter==0){
			fprintf(fp1,"%c",c);
			fclose(fp1);
		}
	}

	else if(c=='4'){

		while((ch=fgetc(fp1))!=EOF){
			
			if(ch=='4'){
				counter++;
				printf("This news has been read before.Do you want to read it again? Yes(1) / No(0) !!Please just enter '1' or '0' !!\n");
				scanf("%d",&keep);
				if(keep==0){
					printf("Would you like to continue? Yes(1) / No(0) !!Please just enter '1' or '0' !!\n");
					scanf("%d",&keep);
					if(keep==0){
						printf("Good bye :)");
						exit(0);
					}
					else
						menu();
				}
			}
		}

		if(counter==0){
			fprintf(fp1,"%c",c);
			fclose(fp1);
		}
	}				
}			
	

/*When the user chooses option b, the function where the news read is printed on the screen by opening the file where the previously read news is saved only once.*/
void readed_news(char *file_path){
	
	char read_c;							 /*Variable in which the characters read from the file are kept*/							

	FILE *fp2=fopen(file_path,"r");

	if(fp2==NULL){
		printf("!!Error File not found on the system!!\n");      /*In order to be able to read from the file, the file must exist on the system ,if it's not exist the user is given an error.*/
	}
	
	else{
		while((read_c=fgetc(fp2))!=EOF){
		
			if(read_c=='\n')
				continue;
				
			printf("%c.new is readed\n",read_c);
		}
	fclose(fp2);
	}
}

/*The function that is used to find hidden numbers in texts, send them to the function that is needed to solve them, and find the secret password*/
void read_magic_numbers(char buffer_magic[10], char buffer_news[500]){
	
	int magic_num=0;							/*The variable used to convert the character to integer*/
	double secret_num=0;							/*Variable in which the values of all magic numbers are saved*/
	int j=0,i=0;								/*indexsi of the arrays*/

	for(i=0; i<size; i++){

		if(buffer_news[i]=='#'){

			buffer_magic[j]=buffer_news[i+1];
			
			magic_num=buffer_magic[j]-'0';				/*Converting the hidden number saved in buffer_magic into integer so that it can be sent to the function*/
			
			secret_num += g_func(f_func,magic_num);
			
			j++;
		}

	}
	
	printf("%.2lf\n",secret_num);
}

/*Functions used in solving hidden numbers*/
double f_func(int x){

	double result1;

	result1=(x*x*x)-(x*x)+2;						/*The formula used x^3-x^2+2 */				

	return result1;
}

double g_func(double f(int x), int a){

	double result2;

	result2=f(a)*f(a);						

	return result2;
}




