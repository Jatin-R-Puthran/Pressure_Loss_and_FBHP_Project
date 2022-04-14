//Code in C language for Calculation of Pressure Loss due to Hills:
//By Jatin R Puthran 
//18JE0379
//All symbols have their usual meanings

#include<stdio.h>
#include<math.h>
int main()
{
//Defining all the Variables
double ql,d,qg,GLR,yw,yo,yl,xo,xw;
int unit=1,nohs,Lof;
double Pav,Tav,Zav,Rhol;
double HF,PD,Vsg,Htotal=0;
printf("Enter the values of the input variables in order:\n")
;
//Taking INPUT Values from USER
scanf("%lf%lf%lf%lf%lf%lf",&d,&Zav,&ql,&GLR,&Tav,&Pav);
scanf("%lf%lf%lf%lf%d%d",&yw,&yo,&xw,&xo,&nohs,&Lof);
int hs[nohs];
//Defining array to store vertical heights of hilly terrains
printf("\nEnter values of vertical heights of all the hills:
\n");
for(int i=0;i<nohs;i++)
{
scanf("%d",&hs[i]);
Htotal=Htotal+hs[i];
}
Tav=Tav+ 459.67; //Fahrenheit to Rankin conversion
qg = ql*GLR/1000000; //Conversion to unit MMscfd
Vsg = 31194*qg*Zav*Tav;
double factor1;
factor1=520*Pav*d*d;
8
Vsg=Vsg/factor1; //Final value of Superficial gas velocity(Vsg)
//Now according to Vsg value we calculate Elevation component of total static
pressure drop (fraction) (HF)
if(Vsg<50)
 //If superficial gas velocity < 50
{
printf("Calculated Vsg = %lf ft/sec",Vsg);
Vsg=pow(Vsg,1.006);
HF = 1 + (0.3264*Vsg);
HF=1/HF;
}
else
//If superficial gas velocity > 50
{
printf("Calculated Vsg = %lf ft/sec",Vsg);
Vsg=pow(Vsg,0.7);
Lof=pow(Lof,0.5);
HF = 0.00967*Lof;
HF=HF/Vsg;
}
yo = yo+ 131.5; //Conversion of API to specific gravity (Water =1basis)
yo = 141.5/yo;
yl = (yo*xo) + (yw*xw);
printf("\nWhich unit are you following :-");
printf("\nIf FPS, then enter : 1 , \nif CGS, then enter : 2\n
");
scanf("%d",&unit);
9
if(unit==1)
{
Rhol= yl*62.4; //In FPS, density=62.4*specific gravity
}
else
{
Rhol=Rhol; //In CGS, density=specific gravity (both are same value)
}
//Now using HF, the pressure drop through the pipe is calculatd as:-
PD= (Rhol*HF*Htotal)/144;
printf("The Pressure drop/loss due to hills ΔP = %lf psi",PD)
;
return 0;
}
