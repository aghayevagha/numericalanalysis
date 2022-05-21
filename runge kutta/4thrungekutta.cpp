#include<iostream>
#include<cmath>
using namespace std;
//f(x,y)=(x+y)^2,y(0)=0,h=0,1
double f(double x,double y);
int main(){
	double y[100],x[100],k1[100],k2[100],k3[100],k4[100],h;
	int i;
	cout<<"x0=";
	cin>>x[0];
	cout<<"y0=";
	cin>>y[0];
	cout<<"h-i daxil edin:";
	cin>>h;
	cout<<x[0]<<";"<<y[0]<<endl;
		for(i=0;i<=20;i++){
		k1[i]=f(x[i],y[i]);
		k2[i]=f(x[i]+h/2,y[i]+h*k1[i]/2);
		k3[i]=f(x[i]+2*h/3,y[i]+h*k2[i]/2);
		k4[i]=f(x[i]+2*h/3,y[i]+h*k3[i]);
		y[i+1]=y[i]+h*(k1[i]+3*k3[i])/4;
		x[i+1]=x[i]+h;
		cout<<x[i+1]<<";"<<y[i+1]<<endl;
	}
	return 0;
		
}
double f(double x,double y){
	return pow(x,2)+pow(y,2);
}
