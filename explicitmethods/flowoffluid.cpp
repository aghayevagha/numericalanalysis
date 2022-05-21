#include<iostream>
#include<math.h>
using namespace std;
/*
p0[i] oten laydaki qiymet
p1[i] cari laydaki qiymet
fi 0-ci laydaki serhed sertidir
Pu x(0) daki serhed sertidir
pw x(N) deki serhed serti
dx- delta x -dir
dt-delta t- dir.
mu-ozluluk
betta-sixilma emsali 
*/
float dx,dt,mu;
double betta;
double k(float x){
	return (1+log10(x)/10)*pow(10,-12);
}
float siqma(float x){
	return k(x)/(mu*betta);
}
float x( float i){
	return i*dx;
} 
float fi(float x){
	return 100*101325;
}
float Pw(float t){
	return 100*101325+20*t;
}
float Pu(float t){
	return 300*101325-50*t;
}
int main(){
	int m,n,i,capi,capj,mesafe,zaman;
	float p1[100000],p0[100000],max;
	cout<<"uzunluqu daxil edin:";
	cin>>mesafe;
	cout<<"zamani daxil edin:";
	cin>>zaman;
	cout<<"deltax-i daxil edin:";
	cin>>dx;
	cout<<"deltat-ni daxil edin:";
	cin>>dt;
	cout<<"mu-nu daxil edin:";
	cin>>mu;
	cout<<"bettani daxil edin:";
	cin>>betta;
	
	n=(int)mesafe/dx;
	m=(int)zaman/dt;
	max=siqma(0);
	for(int i=1;i<=n;i++){
		if(max<siqma(x(i))) max=siqma(x(i));
	}
	if((dt*max)/pow(dx,2)>0.5){
		cout<<"mesele dayaniqli deyil";
		return 0;
	}
	cout<<"mesele dayaniqlidir"<<endl;
	capi=(int)n/5;
	capj=(int)m/5;
	for(i=0;i<190;i++) cout<<"-";
	cout<<endl;
	for(i=0;i<=n;i++){
		p0[i]=fi(x(i));
		if(i%capi==0 ){
		printf("p(%d,0)=%.0f |",i,p0[i]);}
					}
	cout<<endl;
	for(int j=1;j<=m;j++){
	// xettin capi
		if( j%capj==0){
		
	for(i=0;i<190;i++) cout<<"-";
	cout<<endl;	}
	//dovrlu p(i,j) un hesablanmasi
	for(i=1;i<n;i++){
	p1[i]=p0[i]+ (dt/dx)*(siqma(x(i+0.5))*(p0[i+1]-p0[i])/dx - siqma(x(i-0.5))*(p0[i]-p0[i-1])/dx);
	}
	p1[0]=Pw(j*dt);
	p1[n]=Pu(j*dt);
	//menimsetme ve cap 
		for(i=0;i<=n;i++){
		if(i%capi==0 && j%capj==0){
		printf("p(%d,%d)=%.0f |",i,j,p1[i]);}
		p0[i]=p1[i];
		}
	if(j%capj==0)
	cout<<endl;
}
return 0;
}

