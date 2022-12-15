#include<stdio.h>						/*Definitions of printf,scanf,fgets,fopen,fclose*/
#include<stdlib.h>						/*to use exit()*/
#include<string.h>						/*to use strcmp,strtod*/

#define game_num 2001
#define lenght 200

/*Function prototypes*/
void read_file(char *file_path, char game[game_num][lenght]);					/*It was used to make reading from the file and save it to the array.*/
void list_genres(char genres[200][15], int num_g);						/*Used to list all unique genres*/
void list_platforms(char platforms[200][15], int num_p);					/*Used to list all unique platforms*/
void average_score(float main_array[game_num][7]);						/*to calculate average user score*/
void genres_frequency(float main_array[game_num][7], char genres[200][15]);			/*It was used to show how many times a genres repeats.*/
void platforms_frequency(float main_array[game_num][7], char platforms[200][15]);		/*It was used to show how many times a platforms repeats.*/

int main(){

	char game[2001][200];						/*The array in which the entire file is read and saved line by line*/
	char names[2001][100];						/*In the information separated by commas, the array in which the names are kept*/
	char genres[200][15];						/*An array in which only unique genres(i.e. each genre is saved once) are kept*/						
	char platforms[200][15];					/*An array in which only unique platforms(i.e. each platform is saved once) are kept*/
	char year[2001][20];						/*In the information separated by commas, the array in which the years are kept*/
	char nsales[2001][20];						/*In the information separated by commas, the array in which the na sales are kept*/
	char eusales[2001][20];						/*In the information separated by commas, the array in which the eu sales are kept*/
	char gsales[2001][20];						/*In the information separated by commas, the array in which the global sales are kept*/
	char score[2001][20];						/*In the information separated by commas, the array in which the user score are kept*/
	char genres1[2001][20];						/*Array in which all genres in the file are saved*/
	char platforms1[2001][20];					/*Array in which all platforms in the file are saved*/
	float main_array[2001][7];					/*Array in which the information received from the file (except the name) is transferred.*/					
	
	read_file("Video_Games.txt",game);

	int k=1;
	int count1=0;							/*The counter used to save information according to commas to the corresponding array*/
	int count=0;							/*Counters used to prevent rewrites of the same genres and same platforms*/
	int count2=0;
	int a1=0,w=0,a=0,b=0,c=0;					
	int e=0,f=0,g=0,h=0, b1=0;					
	int p=0,r=0,c1=0,d1=0,d=0;					
	int x=0,y=0,t=0,u=0;
/*First of all, the file was read line by line and saved to an array. Then, with the help of commas in the lines, each of them was recorded in a separate array. At this stage, these variables were kept in order for the indices of the arrays after the names array to start from zero.*/
	for(k=1;k<2001;k++){
		count1=0;
		b=0; d=0; f=0; h=0; f=0; r=0; 
		u=0; y=0; b1=0; d1=0;
		for(int m=0; m<180;m++){

			if(game[k][m]==','){
				count1++;
				continue;
			}
			if(count1==0){

				names[k-1][m]=game[k][m];
			}
			else if(count1==1){
				genres1[a][b]=game[k][m];
				b++;
			}
			else if(count1==2){
				platforms1[c][d]=game[k][m];
				d++;
			}
			else if(count1==3){
				year[e][f]=game[k][m];
				f++;
			}
			else if(count1==4){
				nsales[g][h]=game[k][m];
				h++;
			}
			else if(count1==5){
				eusales[p][r]=game[k][m];
				r++;
			}
			else if(count1==6){
				gsales[t][u]=game[k][m];
				u++;
			}
			
		}
/*Each time it is compared to the elements before it, the same word is prevented from being rewritten.A genres that didn't exist before is saved in the array.*/	
	count=0;
	for(int q=0; q<a; q++){								
		if(strcmp(genres1[a],genres1[q])==0){
			count++;
		}
	}						
	if(count==0){
		
		count1=0;
		for(int w=0; w<180; w++){
			
			if(game[k][w]==','){
				count1++;
				continue;
			}
			
			if(count1==1){
				genres[a1][b1]=game[k][w];
				b1++;
			}
		}
		a1++;
	}
	a++;
/*The same operations are repeated for the platform.*/
	count2=0;
	for(int q=0; q<c; q++){
		if(strcmp(platforms1[c],platforms1[q])==0){
			count2++;
		}
	}
	if(count2==0){
		
		count1=0;
		for(int w=0; w<180; w++){
			
			if(game[k][w]==','){
				count1++;
				continue;
			}
			
			if(count1==2){
				platforms[c1][d1]=game[k][w];
				d1++;
			}
		}
		c1++;
	}
	c++;			/*The index (line number) of each array is incremented for the next word to come.*/
	e++;
	g++;
	p++;
	t++;
	}
/*The relevant index is found from the array of genres, and the float array is recorded.(So the index of the genres is kept in the float array)*/
	int ind=0,x2=0;
	for(int i=0; i<2000; i++){
		ind=0;
		x2=0;
		if(strcmp(genres1[i],genres[x2])!=0){
			while(strcmp(genres1[i],genres[x2])!=0){
				x2++;
			}
		}
		if(strcmp(genres1[i],genres[x2])==0){
			main_array[i][ind]= (float)x2;
			
		}
	}
/*The relevant index is found from the array of platforms, and the float array is recorded.(So the index of the platform is kept in the float array)*/	
	for(int i=0; i<2000; i++){
		ind=1;
		x2=0;
		if(strcmp(platforms1[i],platforms[x2])!=0){
			while(strcmp(platforms1[i],platforms[x2])!=0){
				x2++;
			}
		}
		if(strcmp(platforms1[i],platforms[x2])==0){
			main_array[i][ind]=(float)x2;
			
		}

	}

/*According to the number of commas, user scores were recorded in the related series.*/
	for(k=1;k<2001;k++){
		count1=0;
		y=0;
		for(int m=0; m<180;m++){

			if(game[k][m]==','){
				count1++;
				continue;
			}
			if(count1==7){
				score[x][y]=game[k][m];
				y++;
			}
		}
	x++;
	}
	
	double n;
	char *end;
/*String sequences were converted to float by strtod function and saved to float array*/
	for(int z=0; z<2000; z++){
		for(int v=2; v<7; v++){
			if(v==2){
				n=strtod(year[z],&end);
				main_array[z][v]=n;
			}

			else if(v==3){
				n=strtod(nsales[z],&end);
				main_array[z][v]=n;
			}

			else if(v==4){
				n=strtod(eusales[z],&end);
				main_array[z][v]=n;
			}
		
			else if(v==5){
				n=strtod(gsales[z],&end);
				main_array[z][v]=n;
			}

			else if(v==6){
				n=strtod(score[z],&end);
				main_array[z][v]=n;
				
			}
			//printf("%.2lf\t",main_array[z][v]);
		}
	}
		
	int choice,option;
	int counter=0,counter2=0, index,order=0;
	float user_year;			/*Variable that holds the year received from the user*/
	char game_name[100];			/*Variable in which the game name received from the user is kept*/
	do{

	printf("0: List of the Genres\n");
	printf("1: List of the Platforms\n");
	printf("2: List of the games through the years\n");
	printf("3: All informations of a single game\n");
	printf("4: Average of the user score\n");
	printf("5: Geographical information of a single game\n");
	printf("6: Frequence of the genres\n");
	printf("7: Frequence of the platforms\n");
	printf("8: Exit\n");
	
	printf("Please select the operations: \n");
	scanf("%d",&choice);
	printf("\n\n");

		if(choice==0){
			list_genres(genres,a1);
			printf("\n\n");
		}

		else if(choice==1){
			list_platforms(platforms,c1);
			printf("\n\n");
		}
		else if(choice==2){
			counter=0;
			while(counter==0){						/*When user entered invalid values, counter was used to get values again.*/
			printf("Please enter a year: ");
			scanf("%f",&user_year);
			printf("Until(0) or since(1) %.0f: ", user_year);
			scanf("%d",&option);
			printf("\n\n");
			/*When the user chooses zero, if the year user enters is not greater than the first year in our array, the years until the user enters cannot be displayed.*/
			if(option==0){
				for(int i=0; i<2000; i++){
					if(main_array[1][2]>user_year){		
						counter=0;
						printf("Try again\n");
						break;
					}
					else if(main_array[i][2]<user_year){
						counter=1;
						printf("%s\n",names[i]);
					}
				}
			}
			/*When the user chooses one, if the year user enters is greater than the last year in our series, the years after the user enters cannot be shown*/
			else if(option==1){
				for(int i=0; i<2000; i++){
					if(main_array[1999][2]<user_year){
						counter=0;
						printf("Try again\n");
						break;
					}
					 if(main_array[i][2]>user_year){
						counter=1;
						printf("%s\n",names[i]);
					}
				}
			}
			else{
				printf("Please just enter '0' or '1'\n\n");
				count=0;
			}
		}
		printf("\n\n");
		}
		else if(choice==3){
			counter=0;
			counter2=0;
			/*Checking if the game name entered by the user is in the names array and retrieving it if not. Also, if there are two of the same game name, the first one is taken.*/
			while(counter==0){
				printf("Please enter the name of the game:\n");
				scanf("%s",game_name);
				for(int i=0; i<2000; i++){
					if(strcmp(game_name,names[i])==0){
						counter=1;
						counter2++;
						if(counter2==1)
							index=i;
					}
				}
			}
			if(counter==1){
				order=0;
				double num = main_array[index][order];		/*Used to find the string corresponding to the indexes held in the float array.*/
				int valid=(int)num;
				double num2= main_array[index][order+1];
				int valid2=(int)num2;
				
				printf("Name:            %s\n",names[index]);
				printf("Genres:          %s\n",genres[valid]);
				printf("Platforms:       %s\n",platforms[valid2]);
				printf("Year:            %.0f\n",main_array[index][order+2]);
				printf("Sales in NA:     %.3f\n",main_array[index][order+3]);
				printf("Sales in EU:     %.3f\n",main_array[index][order+4]);

				if(main_array[index][order+5]==0)
				printf("Total sales:     Not Available\n");
				else
				printf("Total sales:     %.3f\n",main_array[index][order+5]);

				printf("User score:      %.3f\n",main_array[index][order+6]);
			} 
			printf("\n\n");       
		}
			
		else if(choice==4){
			printf("Average: ");
			average_score(main_array);
			printf("\n\n");
		}
		
		else if(choice==5){
			counter=0;
			counter2=0;
			/*Checking if the game name entered by the user is in the names array and retrieving it if not. Also, if there are two of the same game name, the first one is taken.*/
			while(counter==0){
				printf("Please enter the name of the game:\n");
				scanf("%s",game_name);
				for(int i=0; i<2000; i++){
					if(strcmp(game_name,names[i])==0){
						counter=1;
						counter2++;
						if(counter2==1)
							index=i;
					}
				}
			}
			if(counter==1){
				if(main_array[index][3]>main_array[index][4])
					printf("This game most popular in North America\n\n");

				else if(main_array[index][3]==main_array[index][4])
					printf("This game is equally popular in both\n");

				else
					printf("This game most popular in Europe\n\n");
			}
			
		}
		else if(choice==6){
			genres_frequency(main_array,genres);
			printf("\n\n");
		}
		else if(choice==7){
			platforms_frequency(main_array,platforms);
			printf("\n\n");
		}
		else if(choice==8){
			exit(0);	
		}

		else{
			printf("Error.The number should be in the range [0-8]\n\n");
		}

		}while(choice!=8);

return 0;

}

void read_file(char *file_path, char game[game_num][lenght]){

	FILE *fp=fopen(file_path,"r");
	int i=0;
	if(fp==NULL){
		printf("!Error.This file could not found on system!");
		exit(1);
	}
	
	else{
		while(fgets(game[i],200,fp)){
			i++;
		}
	}
	fclose(fp);
}

void list_genres(char genres[200][15], int num_g){

	for(int i=0; i<num_g; i++){
		printf("%s\n",genres[i]);
	}

}

void list_platforms(char platforms[200][15], int num_p){
	for(int i=0; i<num_p; i++){
		printf("%s\n",platforms[i]);
	}
}


void genres_frequency(float main_array[game_num][7], char genres[200][15]){
	int counter=0;
	int k=0,l=0;
	for(k=0; k<12; k++){
		counter=0;
		for(l=0; l<2000; l++){
			if(main_array[l][0]==k){
				counter++;
			}
		
		}
	printf("%-18s%-12d\n",genres[k],counter);
	}
}

void platforms_frequency(float main_array[game_num][7], char platforms[200][15]){
	int counter=0;
	int k=0,l=0;
	for(k=0; k<10; k++){
		counter=0;
		for(l=0; l<2000; l++){
			if(main_array[l][1]==k)
				counter++;
		}
	printf("%-10s%-9d\n",platforms[k],counter);

	}
}


void average_score(float main_array[game_num][7]){
	double sum=0,av=0;
	for(int i=0; i<2000; i++){
		for(int j=0; j<7; j++){
			if(j==6){
				sum+=main_array[i][j];
			}
		}
		
	}
	av=sum/2000;
	printf("%.3lf",av);
	
}









