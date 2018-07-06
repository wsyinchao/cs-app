#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef unsigned char* byte_point;


void show_bytes(byte_point start, size_t len)
{
	size_t i;
	for (i = 0; i < len; ++i){
		printf(" %.2x", start[i]);
	}
	printf("\n");
}


void show_int(int value)
{
	show_bytes( (byte_point) &value, sizeof(int) );
}

void show_float(float value)
{
	show_bytes( (byte_point) &value, sizeof(float) );
}

void show_point(void *value)
{
	show_bytes( (byte_point) &value, sizeof( void* ) );
}


int main()
{
	int vi = 10;
	float vf = (float) vi;
	int *vp = &vi;

	show_int(vi);
	show_float(vf);
	show_point(vp);

	printf("abcdef\n");
	const char *s = "abcdef";
	show_bytes( (byte_point) &s, strlen(s));




	return 0;
}
