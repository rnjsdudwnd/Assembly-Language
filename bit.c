#include <stdio.h>
#include <stdlib.h>
void asm_bit_test(void);
void bit_print(unsigned int bit){
	printf("Bit value is %#x\n", bit);
}
asm("			\n\
.global asm_bit_test	\n\
asm_bit_test:		\n\
mov	r3, #0x8c000000	\n\
orr 	r3,r3,#0xf40000	\n\
orr	r3,r3,#0x7a00	\n\
orr	r3,r3,#0x36	\n\
mov	r8,lr		\n\
mov	r0,r3		\n\
mov 	r7,r3 @for bic	\n\
bl	bit_print	\n\
bic	r7,r7,#0xc000000\n\
mov	r0,r7		\n\
bl	bit_print	\n\
mov	lr,r8		\n\
mov	pc,lr		\n\
");
int main(){
	asm_bit_test();
	return 0;
}
