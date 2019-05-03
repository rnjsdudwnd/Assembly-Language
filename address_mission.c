#include <stdio.h>
void asm_print();
int mem[5];
int total;
int add_print(unsigned int value){
	printf("Memory Value:%d\n",value);
	return 0;
}
asm("					\n\
.global asm_print			\n\
asm_print:				\n\
mov r9,lr				\n\
ldr r10,=mem				\n\
ldr r4,[r10]				\n\
mov r0,r4				\n\
bl add_print				\n\
ldr r5,[r10,#4]!			\n\
mov r0,r5				\n\
bl add_print				\n\
ldr r6,[r10,#4]!			\n\
mov r0,r6				\n\
bl add_print				\n\
ldr r7,[r10,#4]!			\n\
mov r0,r7				\n\
bl add_print				\n\
ldr r8,[r10,#4]				\n\
mov r0,r8				\n\
bl add_print				\n\
add r3,r4,r5				\n\
add r3,r3,r6				\n\
add r3,r3,r7				\n\
add r3,r3,r8				\n\
ldr r1,=total				\n\
str r3,[r1]				\n\
mov lr,r9				\n\
mov pc,lr				\n\
    ");
int main(){
	printf("Enter the 5 numbers:");
	for(int i=0;i<5;i++){
		scanf("%d",&mem[i]);
	}
	asm_print();
	printf("Total: %d", total);
	return 0;
}
