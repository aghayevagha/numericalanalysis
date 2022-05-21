#include<iostream>
#include<cmath>
using namespace std;
//f(x,y)=(x+y)^2,y(0)=0,h=0,1
double f(double x,double y);
int main(){
	double y[100],x[100],k1[100],k2[100],h;
	int i;
	cout<<"x0=";
	cin>>x[0];
	cout<<"y0=";
	cin>>y[0];
	cout<<"h-i daxil edin:";
	cin>>h;
	cout<<x[0]<<";"<<y[0]<<endl;
	for(i=0;i<=9;i++){
		k1[i]=f(x[i],y[i]);
		k2[i]=f(x[i]+h,y[i]+h*k1[i]);
		y[i+1]=y[i]+h*(k1[i]+k2[i])/2;
		x[i+1]=x[i]+h;
		cout<<x[i+1]<<";"<<y[i+1]<<endl;
	}	
	return 0;
}
double f(double x,double y){
	return pow(x+y,2);
}
