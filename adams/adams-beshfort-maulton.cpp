#include<iostream>
#include<cmath>
using namespace std;
double f(double x,double y);
int main(){
	double y[100],x[100],k1[3],k2[3],k3[3],k4[3],dy[100],h;
	int i;
	cout<<"x0=";
	cin>>x[0];
	cout<<"y0=";
	cin>>y[0];
	cout<<"h-i daxil edin:";
	cin>>h;
	cout<<x[0]<<";"<<y[0]<<endl;
		for(i=0;i<=2;i++){
		k1[i]=f(x[i],y[i]);
		k2[i]=f(x[i]+h/2,y[i]+h*k1[i]/2);
		k3[i]=f(x[i]+2*h/3,y[i]+h*k2[i]/2);
		k4[i]=f(x[i]+2*h/3,y[i]+h*k3[i]);
		y[i+1]=y[i]+h*(k1[i]+3*k3[i])/4;
		x[i+1]=x[i]+h;
		cout<<x[i+1]<<";"<<y[i+1]<<endl;
	}
	for(i=3;i<=19;i++){
	x[i+1]=(i+1)*h;
	dy[i+1]=y[i]+h*(55*f(x[i],y[i])-59*f(x[i-1],y[i-1])+37*f(x[i-2],y[i-2])-9*f(x[i-3],y[i-3]))/24;
	y[i+1]=y[i]+h*(9*f(x[i+1],dy[i+1])+19*f(x[i],y[i])-5*f(x[i-1],y[i-1])+f(x[i-2],y[i-2]))/24;
	cout<<x[i+1]<<";"<<y[i+1]<<endl;
}


	return 0;
		
}
double f(double x,double y){
	return (x+y)/2;
}
