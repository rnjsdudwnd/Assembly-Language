#include <stdio.h>
void asm_adc_test(void);
void cpsr_print(unsigned int high,unsigned int low){
	unsigned long long int sum=(((long long)high<<16)<<16)+low;
	printf("Cpsr Value %llx\n",sum);
}
void cpsr_print2(unsigned long long sum){
	printf("Cpsr value2 %llx\n",sum);
}
union adc
{
	long long total;
	struct{
		unsigned int low;
		unsigned int high;
	};
};
void sum_64(unsigned int x, unsigned int y){
	union adc sum;
	sum.low = x;
	sum.high = y;
	printf("Total value 0x%llx\n",sum.total);
}
asm("			\n\
.global asm_adc_test	\n\
asm_adc_test:		\n\
mov	r0,#0xff000000	\n\
mov 	r1,#0x10000000	\n\
mov 	r2,#0x10000000	\n\
mov 	r3,#0x10000000	\n\
adds	r4,r0,r2	\n\
mov 	r7,lr		\n\
adc 	r5,r1,r3 	\n\
mov 	r1,r4		\n\
mov 	r0,r5		\n\
bl	cpsr_print	\n\
mov	r1,r4		\n\
mov 	r0,r5		\n\
bl	sum_64		\n\
mov	r1,r4		\n\
mov	r0,r5		\n\
bl	cpsr_print2	\n\
mov 	lr,r7		\n\
mov	pc,lr		\n\
");
int main(void){
	asm_adc_test();
	return 0;
}
