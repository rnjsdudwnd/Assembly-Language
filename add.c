#include <stdio.h>
#include <stdlib.h>
int asm_add_test(int x, int y);
// calling register x,y
// 
int add_print(int sum){
	printf("Sum Value is %d\n",sum);//to r0
	return sum;
}
//
asm("				\n\
.global asm_add_test		\n\
asm_add_test:			\n\
add	r3,r0,r1		 \n\
mov     r0, r3			 \n\
mov	r7, lr	        	\n\
bl      add_print       	\n\
add	 r2,r0, r0, lsl #2  	\n\
mov	 r0,r2			\n\
bl	 add_print		\n\
mov	 r5, #4			\n\
add	 r2, r0, r0, lsl r5	\n\
mov      r0,r2			\n\
bl	 add_print		\n\
mov 	r4, #0xff00		\n\
mov	r3, #0xf0000008		\n\
add 	r0,r3,r4		\n\
mov	 lr, r7			\n\
mov	 pc, lr			\n\
");//inline assembly language = C+ Assembly language
//you can order only 1 thing every each line
//lable name is an address.
//Add r0 + r1 =r3
//Copy lr into r7 in line 13
//Call the function in "add_print" in 14
//paste r7 into lr in line 15
int main(){
	int sum=0;
	sum = asm_add_test(10,20);//Can put until 4 register
	//return to r0
	printf("Main Sum Value %#x\n",sum);
	return 0;
}
