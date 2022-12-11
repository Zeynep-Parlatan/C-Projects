#include<stdio.h>						/*Definitons of printf,scanf*/
#include<math.h>                                                /*Definitions of sqrt and fabs*/
#include<stdlib.h>                                              /*Definitions of abs*/                                               						

/*Function prototypes*/
void find_root();	                                        /*Finding the roots of quadratic equation*/					

void find_newtonian_root();                                     /*Finding the root with Newton algorithm*/
    float func(float x,float a,float b,float c);                /*Finding the value of function. Used to easily find the value of function in each iteration*/
    float derivative(float x,float a,float b);                  /*Finding the value of the derivative of function.Used to easily find the value of the derivative of the function in each iteration*/

int find_multiple_closest(int i, int j);                        /*Finding the closest divisible integer*/

int main(){

	printf("Part 1: \n");

		find_root();
	
	printf("Part 2: \n");

		find_newtonian_root();

	printf("Part 3: \n");
	
		int a,b;
                                                                                             
		printf("Please enter the first integer:");
		scanf("%d", &a);
		printf("Please enter the second integer:");
		scanf("%d", &b);

		find_multiple_closest(a,b);
}


void find_root(){

	int a,b,c;      					    /*Input-Quadratic equations coefficients*/
	float dis,root1,root2;                                      /*Output-Discriminant and roots of quadratic equations*/
	
	printf("Please enter the first coefficient: ");             /*Coefficients taken from the user to create a quadratic equations.*/
	scanf("%d", &a);

	printf("Please enter the second coefficient: ");
	scanf("%d", &b);

	printf("Please enter the third coefficient: ");
	scanf("%d", &c);


/*To find roots in quadratic equations,first we must calculate the discriminant.*/	

	dis= (b*b)-(4*a*c);                                     
	
	
	if(dis>0){                                              
	           
                    root1=(-b+sqrt(dis)) / (2*a);
		    root2=(-b-sqrt(dis)) / (2*a);

		printf("Your equations %dx^2%+dx%+d have real roots {%.1f,%.1f}\n\n",a,b,c,root1,root2);     /*Display the quadratic equation and roots*/
	}

	else if (dis==0){

		printf("Both root are the same.\n");
		
		    root1=(-b) / (2*a);
                   
		printf("Your equations %dx^2%+dx%+d have real root {%.1lf}\n\n",a,b,c,root1);                /* + flag character used to clearly show the sign*/
	}
	
	else{		
		printf("Your equations %dx^2%+dx%+d does not have any real roots.\n\n",a,b,c);
	
	}
}

void find_newtonian_root(){
	 
	int a,b,c;											   /*Input-Quadratic equations coefficients*/
	float i;											   /*Input-Iteration start value*/
	float dis,root1,root2,real_root;                                                                   /*Output-Discriminant and roots of quadratic equations*/	   
	float firstx,secondx,thirdx,fourthx,fifthx,sixthx;                                                 /*Output- Root candidates of quadratic equations*/       
        float firstfx,secondfx,thirdfx,fourthfx,fifthfx;                                                   /*Output- Function value of root candidates*/
 
	printf("Please enter the first coefficient: ");                                                    /*Coefficients taken from the user to create a quadratic equations.*/
	scanf("%d", &a);

	printf("Please enter the second coefficient: ");
	scanf("%d", &b);

	printf("Please enter the third coefficient: ");
	scanf("%d", &c);

	printf("Please enter the initial number: ");
	scanf("%f",&i);


	dis= (b*b)-(4*a*c);                                                                               /*The real root of the equation must be found with the discriminant.*/ 

	if(dis>=0){                                              
	           
                    root1=(-b+sqrt(dis)) / (2*a);
		    root2=(-b-sqrt(dis)) / (2*a);

	}

		if(fabs(i-root1)<fabs(i-root2))                                                          /*The root that is close to the initial number is selected.*/
			real_root=root1;

		else
			real_root=root2;

 
	
	printf("Your equations is %dx^2%+dx%+d and iterations are : \n\n",a,b,c);                       /*Display the quadratic equation . + flag character used to clearly show the sign*/



/*According to Newton algorithm, this formula should be used for each iteration. X = X0-f(X0)/f'(X0) */

		firstx=i-(func(i,a,b,c) / derivative(i,a,b));
			
		secondx=firstx-(func(firstx,a,b,c) / derivative(firstx,a,b));
			
		thirdx= secondx-(func(secondx,a,b,c) / derivative(secondx,a,b));
			
		fourthx= thirdx-(func(thirdx,a,b,c) / derivative(thirdx,a,b));
			
		fifthx=fourthx-(func(fourthx,a,b,c) / derivative(fourthx,a,b));
			

/*Function value should be calculated for each iteration.*/

		firstfx= func(firstx,a,b,c);

		secondfx=func(secondx,a,b,c);

		thirdfx=func(thirdx,a,b,c);

		fourthfx=func(fourthx,a,b,c);

		fifthfx= func(fifthx,a,b,c);
	

printf("Step\tx\t\tf(x)\t\tDifference \n");                                                                  /*Display each iterations*/

printf("x1\t%.4f\t\t%.4f\t\t%.4f \n",firstx,firstfx,firstx-real_root);

printf("x2\t%.4f\t\t%.5f\t\t%.4f \n",secondx,secondfx,secondx-real_root);

printf("x3\t%.4f\t\t%.5f\t\t%.4f \n",thirdx,thirdfx,thirdx-real_root);

printf("x4\t%.4f\t\t%.5f\t\t%.4f \n",fourthx,fourthfx,fourthx-real_root);

printf("x5\t%.4f\t\t%.5f\t\t%.4f \n\n",fifthx,fifthfx,fifthx-real_root);

}

       float func(float x,float a,float b,float c){							/*Calling for the calculation of the function in each iterations*/                       
	
	      return a*x*x+b*x+c;
       }
       float derivative(float x,float a,float b){                                                       /*Calling for the calculation of the derivative of the function in each iterations.*/
	     return 2*a*x+b;
       }
	

int find_multiple_closest(int i, int j){
	
	                                                                                            
	int k= i/j;
	int remainder=i-(j*k);                                                                               /*The remainder must be calculated to determine if the number is exactly multiple.*/
	int first_possibility= k*j;							                     
	int second_possibility;                                                                              

	if(j==0)										            /*Division operation is undefined when the number is zero.*/
		printf("Error! Please enter different number from zero !!");

	else{
/*There are two possibilities when finding the closest divisible integer.When the numbers are divided, it can be equal to the multiplication of the divisor by the quotient.Or it may be equal to a surplus or a deficit of the divisor according to the negative and positive state of the numbers.*/

		if(remainder==0)									    /*If the remainder is zero, the number is divided exactly,and closest multiple is itself.*/
			printf("Closest number to %d that is multiple of %d is itself.",i,j);
		
		else {

			if((i*j) > 0)
				second_possibility= j* (k+1);

			else
				second_possibility= j* (k-1);


/*Finding the closest divisible to the number received from the user*/


				if (abs(i-first_possibility) < abs(i-second_possibility))
		
					printf("Closest number to %d that is multiple of %d is %d\n",i,j,first_possibility);
		
				else if(abs(i-first_possibility)==abs(i-second_possibility))                                   /*If the two possibilities are equal, the big one must be chosen*/
	
					printf("Closest numbers to %d that is multiple of %d is %d\n",i,j,second_possibility);

				else
					printf("Closest number to %d that is multiple of %d is %d\n",i,j,second_possibility);
	        }
	}	
}	
		

