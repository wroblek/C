#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

struct test {
	int i1, i2;
	double d;
	char i3;
};

void *alloc(const char *fmt,...){
	va_list ap;
	int i;
	int ilosci = 0;
	struct test *p  = malloc (sizeof*p);
	size_t bytes_needed = 0;
	va_start(ap,fmt);

	for(i=0;i<strlen(fmt);i++){
		switch(fmt[i])
		case 'i':
			bytes_needed += sizeof int;
			break;
		case 'd':
			bytes_needed += sizeof double;
			break;

	}
	
	/* dopisac poprawki */
	for(i=0;i<strlen(fmt);i++){
		if(fmt[i]=='i'){
			if(ilosci==0) p->i1=va_arg(ap,int);
			else if(ilosci==1) p->i2=va_arg(ap,int);
			else if(ilosci==2) p->i3=va_arg(ap,char);
			ilosci++;
		}
		else if(fmt[i]=='d') p->d=va_arg(ap,double);
	}

	va_end(ap);
	return (void*)p;
}

int main(){
	struct test *p = alloc("iidi",33,44,3.14,55);

	printf("%d %d %f %d\n",p->i1,p->i2,p->d,p->i3);
	return 0;
}
