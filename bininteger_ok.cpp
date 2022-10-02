#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
void SameNumber();
void UnSameNumber();
int SIGN(long A);
double CalculateSame(long X, long Y, int n);
long CalculateUnSame(long X, long Y, int xn, int yn);
 
int main()
{
    UnSameNumber();
    return (0);
}
 
  
void UnSameNumber()
{
    long X=0,Y=0;
    int xn=0,yn=0;
    printf("������״̬���÷���");
    printf("������������������\nX=");
    scanf("%ld",&X);
    printf("Y=");
    scanf("%ld",&Y);
    /*�����һ����������X�ĳ��� */
	//   xn=countlong(X);
	//   yn=countlong(Y);
	//
	//
	 
    printf("������X�ĳ��ȣ�xn=");
    scanf("%ld",&xn);
    printf("������Y�ĳ��ȣ�xn=");
    scanf("%ld",&yn);
 
    long sum = CalculateUnSame(X, Y, xn,yn);
 
    printf("��ͨ�˷� X*Y=%ld*%ld=%ld\n",X,Y,X*Y);
    printf("���γ˷� X*Y=%ld*%ld=%ld\n",X,Y,sum);
}
 
long CalculateUnSame(long X, long Y, int xn, int yn)
{
    
	if (X == 0 || Y == 0)
        return 0;
    else if ((xn == 1 && yn == 1) || xn == 1 || yn == 1)
        return X * Y;
    else
    {
        int xn0 = xn / 2, yn0 = yn / 2;   //xn0 ��ʾX��λ���� 
        int xn1 = xn - xn0, yn1 = yn - yn0;   //12345/100 
 
        long A = (long)(X / (long)pow(10, xn0));
        long B = (long)(X % (long)pow(10, xn0));
        long C = (long)(Y / (long)pow(10, yn0));
        long D = (long)(Y % (long)pow(10, yn0));
 
        long AC = CalculateUnSame(A, C, xn1, yn1);
        long BD = CalculateUnSame(B, D, xn0, yn0);
        long ABCD = CalculateUnSame((long)(A * pow(10, xn0) - B), (long)(D - C * pow(10, yn0)), xn1, yn1);
 
        return (long)(2 * AC * pow(10, (xn0 + yn0)) + ABCD + 2 * BD);
    }
}

int SIGN(long A)
{
    return A > 0 ? 1 : -1;
}
 
void SameNumber()
{
    double X=0,Y = 0;
    int n=0;
    printf("����״̬���÷���");
    printf("������������������\nX=");
    scanf("%lf",&X);
    printf("Y=");
    scanf("%lf",&Y);
    printf("�����������������ĳ��ȣ�n=");
    scanf("%d",&n);
 
    double sum = CalculateSame(X, Y, n);
 
    printf("��ͨ�˷� X*Y=%lf*%lf=%lf\n",X,Y,X*Y);
    printf("���γ˷� X*Y=%lf*%lf=%lf\n",X,Y,sum);
}
 
double CalculateSame(long X, long Y, int n)
{
   // int sign = SIGN(X) * SIGN(Y);
 
  // X = labs(X);
  //  Y = labs(Y);
    if (X == 0 || Y == 0)
        return 0;
    else if (n == 1)
       // return sign * X * Y;
       return X*Y;
    else
    {   
        
        double A = (long)(X / (long)pow(10, n / 2));
        double B = (X % (long)pow(10, n / 2));
        double C = (long)(Y / (long)pow(10, n / 2));
        double D = (Y % (long)pow(10, n / 2));
        
		
		    
        double AC = CalculateSame(A, C, n-n/2);
        double BD = CalculateSame(B, D, n/2);
        
		
	    
	    double ABCD = CalculateSame((A - B), (D - C), n/2) + AC + BD;  
        
        
 
       // return (double)(sign * (AC * pow(10, n/2*2) + ABCD * pow(10, n / 2) + BD));
         return (double)( AC * pow(10, n/2*2) + ABCD * pow(10, n / 2) + BD);
    }
}
