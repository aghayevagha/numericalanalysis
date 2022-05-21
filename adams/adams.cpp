#include<iostream>
#include<cmath>
using namespace std;
double f(double x,double y);
int main(){
	double y[100],x[100],k1[3],k2[3],k3[3],k4[3],q[100],dq[100],d2q[100],d3q[100],dy[100],h;
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
	for(i=0;i<=3;i++){
		q[i]=f(x[i],y[i])*h;
	}
	dq[2]=q[3]-q[2];
	d2q[1]=q[3]-2*q[2]+q[1];
	d3q[0]=q[3]-3*q[2]+3*q[1]-q[0];

	for(i=4;i<=20;i++){
	dy[i-1]=q[i-1]+dq[i-2]/2+5*d2q[i-3]/12+3*d3q[i-4]/8;
	y[i]=y[i-1]+dy[i-1];
	x[i]=i*h;
	q[i]=f(x[i],y[i])*h;
	dq[i-1]=q[i]-q[i-1];
	d2q[i-2]=q[i]-2*q[i-1]+q[i-2];
	d3q[i-3]=q[i]-3*q[i-1]+3*q[i-2]-q[i-3];
	cout<<x[i]<<";"<<y[i]<<endl;
}

	return 0;
		
}
double f(double x,double y){
	return pow(x,2)+pow(y,2);
}
