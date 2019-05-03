#include <stdio.h>
void asm_ldr_test(void);
int mem[5];
int total;
asm("					\n\
.global	asm_ldr_test			\n\
asm_ldr_test: 				\n\
ldr r1,=mem		@Read Memory address in mem to r1\n\
ldr r2,[r1]				\n\
ldr r3,[r1,#4]!				\n\
ldr r4,[r1,#4]!				\n\
ldr r5,[r1,#4]!				\n\
ldr r6,[r1,#4]				\n\
add r7, r2,r3				\n\
add r7,r7,r4				\n\
add r7,r7,r5				\n\
add r7,r7,r6				\n\
ldr r1, =total				\n\
str r7,[r1]				\n\
mov pc,lr				\n\
");

int main(){
	
	mem[0]=10;
	mem[1]=20;
	mem[2]=30;
	mem[3]=40;
	mem[4]=50;
	asm_ldr_test();
	printf("Total value is %d\n",total);
	return 0;
}
