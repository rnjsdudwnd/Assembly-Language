#include <stdio.h>
#include <stdlib.h>
void asm_cpm_test(void);
void cmp_print(unsigned int cmp){
	printf("Total value is %#d\n", cmp);
}
asm("				\n\
.global asm_cpm_test		\n\
asm_cpm_test:			\n\
mov	r1,#0 @output for loop	\n\
loop :	@label is the function  \n\
add	r1,r1,#1@add1&store at r1\n\
cmp	r1,#0x40@64 setting with carry\n\
add	r3,r1,r1@for accumulating\n\
bcc	loop@if carry is cleared,the loop executes\n\
mov  	r8,lr			\n\
mov	r0,r3			\n\
bl	cmp_print		\n\
mov	lr,r8			\n\
mov	pc,lr			\n\
");
int main(){
	asm_cpm_test();
	return 0;
}
