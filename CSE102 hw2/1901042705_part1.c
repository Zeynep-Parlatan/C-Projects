#include<stdio.h>                                                           /*Definitions of printf and scanf*/
#include<math.h>                                                            /*Definitions of sqrt */

/*Function prototypes*/
int draw_triangle(int side1, int side2, int side3);                         /*Checking whether a triangle can be drawn*/

void type_triangle(int side1, int side2, int side3);                        /*Finding which type of triangle is drawn*/

int perimeter_triangle(int side1, int side2, int side3);                    /*Finding the perimeter of the drawn triangle*/

double area_triangle(int side1, int side2, int side3, int perimeter);       /*Finding the area of the drawn triangle*/

int main(){

	int first_side,second_side,third_side;                              /*Input-The edges of the triangle*/
	int p ;                                                             /*Output- The perimeter of triangle*/

	printf("Please enter the lenght of first side : ");                 /*Taking the sides of the triangle from the user*/
	scanf("%d",&first_side);
	printf("Please enter the lenght of the second side : ");
	scanf("%d",&second_side);
	printf("Please enter the lenght of the third side : ");
	scanf("%d",&third_side);


/*If a triangle can be drawn, the function return one. If one returns, calculations of other functions is passed, if one does not return, the program is finished.*/ 


	if ((draw_triangle(first_side, second_side, third_side))==1){

		type_triangle(first_side, second_side, third_side);
	
		printf("The perimeter of the triangle: %d\n",perimeter_triangle(first_side, second_side, third_side));             /*Display the perimeter of the triangle*/

		p=perimeter_triangle(first_side, second_side, third_side);

		printf("The area of the triangle: %.3lf\n", area_triangle(first_side, second_side, third_side, p));                   /*Display the area of the triangle*/
	}
}

int draw_triangle(int side1, int side2, int side3){

/*In order to draw a triangle according to the triangle inequality, the lenght of any edge must be less than the sum of the lenght of the other two edges.The function  must return one, ,if a triangle can drawn or zero if it cannot be drawn.*/


	
	if(side1 < side2+side3 & side2 < side1+side3 & side3 < side1+side2){
		printf("\nAccording to triangle inequality theorem, this triangle can be drawn.\n\n");
		return 1;
	}


	else{
		printf("\nAccording to the triangle inequality theorem, this triangle can not be drawn.\n\n");
		return 0; 
	}
}


void type_triangle(int side1, int side2, int side3){

/*Determination of the type of triangle. If all edges are equal to each other it is an equilateral triangle, if only two edges are aqual to each other it is an isosceles triangle,if all edges different from each other it is a scalene triangle.*/


	
	if(side1==side2 & side2==side3)
		printf("It is an equilateral triangle\n");


	else if(side1==side2 || side1==side3 || side2==side3)
		printf("It is an isosceles triangle\n");


	else if(side1!=side2 & side2!=side3 & side1!=side3)
		printf("It is a scalene triangle\n");

}


int perimeter_triangle(int side1,int side2, int side3){

	return side1+side2+side3;
}

double area_triangle(int side1, int side2, int side3, int perimeter){

	double p1;                                                           /*Output-The half of perimeter*/
	double area;                                                         /*Output- The area of triangle*/
	p1=(double)perimeter/2;

	area=sqrt(p1*(p1-side1)*(p1-side2)*(p1-side3));                      /*Calculating the area of triangle by using formula*/
	
	return area;
	
}


