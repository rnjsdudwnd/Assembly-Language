#include <stdio.h>
int asm_cmp_test();
int mem[5];
asm("				\n\
.global	asm_cmp_test		\n\
asm_cmp_test:			\n\
mov	r4,r0			\n\
mov	r5,#0			\n\
mov	r6,#9			\n\
mov	r8,lr			\n\
loop:				\n\
add	r5,r5,#1		\n\
add	r1,r5			\n\
mov	r0,r4			\n\
bl 	asm_print		\n\
cmp	r5,r6			\n\
bcc loop			\n\
mov	lr,r8			\n\
mov	pc,lr			\n\
");
int main(){
	unsigned int num;
	printf("Type Number: ");
	scanf("%d",&num);
	asm_cmp_test(num);
	return 0;
}
