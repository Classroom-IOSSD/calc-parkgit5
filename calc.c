#include <stdio.h>
#include "operators.h"

int main(){
	FILE *fp = NULL;
	int operand1, operand2;
	char operator = ' ';
	double result=0;
	int line = 0;
	double(*function_pointer)(int,int);
	fp = fopen("read.txt","r");
	if(fp!=NULL){
		fscanf(fp, "%d", &line);
	
		for(int i=0; i<line; i++) {
			fscanf(fp, "%d %c %d",&operand1, &operator, &operand2);
			switch(operator) {
				case '+':
				function_pointer=add;
				break;
				case '-':
				function_pointer=minus;
				break;
				case '*':
				function_pointer=mul;
				break;
				case '/':
				function_pointer=div;
				break;
			}		
			result= function_pointer(operand1,operand2);
			printf("%d %c %d = %0.6f\n",
				 operand1, operator, operand2, result);
		}
	}
	return 0;
}

