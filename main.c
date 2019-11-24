/* Note:Your choice is C IDE */
//Support expression input!!!!!!!!!!!!
//   Amazing   !!!


#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "math.h"
#define  pi  acos(-1.0)
#define e exp(1.0)

int n;
char record[20];
float product();
float change();
float chengfang();
float p;
int x=0;
float y[25];
int w=0;


float muli()
{
	float summ;
	summ=product();
	while(record[n]=='-'||record[n]=='+')
	{
		switch(record[n])
		{
			case '+':n++;summ+=product();break;
			case '-':n++;summ-=product();break;
		}
	}
	return summ;
}

float product()
{
	float sump;
	sump =chengfang();
	while(record[n]=='*'||record[n]=='/')
	{
		switch(record[n])
		{
			case '*':n++;sump*=chengfang();break;
			case '/':n++;sump/=chengfang();break;
		}
	}
	return sump;
}

/*float turn_rad(float x)
{
	float y=x*3.141592/180;
	return y;
}*/

float chengfang()
{
	float cheng;
	cheng =change();
	while (record[n]=='^'||record[n]=='s'||record[n]=='c'||record[n]=='t'||record[n]=='l'||record[n]=='#')
	{
		switch(record[n])
		{
			case '^':n++;cheng=pow( cheng,change() );break;
			case '#':n++;cheng=powf(cheng,1.0/change());break;
			case 's':n=n+3;cheng=sin( change() );break;
			case 'c':n=n+3;cheng=cos( change() );break;
			case 't':n=n+3;cheng=tan( change() );break;
			case 'l':
				switch(record[++n])
				{
					case 'g':n++;cheng=log10( change() );break;
					case 'n':n++;cheng=log( change() );break;
				}
				break;
		}
	}
	return cheng;
}

float change()
{
	float sumc;
	char rec[20],i=0;
	if(record[n]=='(')
	{
		n++;
		sumc=muli();
	}
	if(record[n]==')')
	n++;
	while(isdigit(record[n])||record[n]=='.'||record[n]=='x'||record[n]=='p'||record[n]=='e')
	{
		if (record[n]=='p')
		{
			n=n+2;
			sumc=pi;
		}
		else if (record[n]=='e')
		{
			n++;
			sumc=e;
		}		
		else if(record[n]=='x')
		{
			n++;
			sumc=p;
		}
		else 
		{
		//	while(record[n]=='x')
		//	{
		//		n++;
		//		sumc=p;
		//	}
			while(isdigit(record[n])||record[n]=='.')
				rec[i++]=record[n++];
			rec[i]='\0';
			sumc=atof(rec);
		}
	}
	return sumc;	
}

void main()
{
	while(1)
	{
		n=0;
		scanf("%s",record);
		x=0;
		for ( p=0.1;p<2;p=p+0.1)
		{

			y[x]=muli();
				x++;
				n=0;
		}
		for (w=0;w<20;w++)
		{
			printf("%f \n",y[w]);
		}
		//printf("%s=%g\n",record,muli());
	} 
}


