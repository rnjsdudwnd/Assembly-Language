#include <stdio.h>
void asm_adr_test(void);
void addr_test(unsigned int add){
	printf("Addr_test function address is %#x\n",add);
	
}
asm("					\n\
.global asm_adr_test			\n\
asm_adr_test:				\n\
adr	r1,addr_test			\n\
mov	r0,r1				\n\
mov 	pc,rl				\n\
mov	pc,lr				\n\
");

int main(){
	asm_adr_test();
	return 0;
}
