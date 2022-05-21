#include<iostream>
#include<cmath>
using namespace std;
double f(double x,double y){
	return pow(x,2)+pow(y,2);
}
double funk1(double x0,double y0, double h);
double funk2(double x0,double y0, double h);
double funk3(double x0,double y0, double h);
double funk4(double x0,double y0, double h);
int main(){
	int alfa ;
	double x0,y0,h;
	cout<<"1-siniq xetler usulu"<<endl;
	cout<<"2-tekmillesdirilmis usul"<<endl;
	cout<<"3-eyler-kosi usulu"<<endl;
	cout<<"4-eyler-kosinin iterasiyalisi"<<endl;
	cout<<"hansi usulu isteyirsinizse,o reqemi girin:";
	cin>>alfa;
	cout<<"x0-i daxil edin:";
	cin>>x0;
	cout<<"y0-i daxil edin:";
	cin>>y0;
	cout<<"h-i daxil edin:";
	cin>>h;
	
	if(alfa == 1){
		funk1(x0,y0,h);
	}
	if(alfa ==2){
			funk2(x0,y0,h);
	}
	if(alfa ==3){
			funk3(x0,y0,h);
	}
	if(alfa ==4){
			funk4(x0,y0,h);
	}
}
double funk1(double x0,double y0, double h){
	double y[100],x[100];
	y[0]=y0;x[0]=x0;
	cout<<x[0]<<";"<<y[0]<<endl;
	for(int i=1;i<10;i++){
		y[i]=y[i-1]+h*f(x[i-1],y[i-1]);
		x[i]=i*h;
		cout<<x[i]<<";"<<y[i]<<endl;
	}
}
double funk2(double x0,double y0, double h){
	double y[100],x[100],xp[100],yp[100];//xp ve yp ferqlendirmek ucundur yeni onlar x[i + 1/2] ni ifade edirler
		y[0]=y0;x[0]=x0;
	cout<<x[0]<<";"<<y[0]<<endl;
		for(int i=0;i<10;i++){
			xp[i]=i*h+0.5*h;
			yp[i]=y[i]+h*f(x[i],y[i])/2;
		y[i+1]=y[i]+h*f(xp[i],yp[i]);
		x[i+1]=(i+1)*h;
		cout<<x[i+1]<<";"<<y[i+1]<<endl;
	}
}
double funk3(double x0,double y0, double h){
double y[100],x[100],yp[100];//buradaki yp de hemcinin ferqlendirmek ucundur
		y[0]=y0;x[0]=x0;
	cout<<x[0]<<";"<<y[0]<<endl;
		for(int i=0;i<10;i++){
		yp[i+1]=y[i]+h*f(x[i],y[i]);
		x[i+1]=(i+1)*h;
		y[i+1]=y[i]+h*(f(x[i],y[i])+f(x[i+1],yp[i+1]))/2;
		
		cout<<x[i+1]<<";"<<y[i+1]<<endl;
	}
	
}
double funk4(double x0,double y0, double h){
	int is;
	cout<<"iterasiya sayini daxil edin:";
	cin>>is;
	cout<<endl;
	double y[100][10],x[100];
		y[0][0]=y0;x[0]=x0;
	cout<<x[0]<<";"<<y[0][0]<<endl;
y[0][is-1]=y[0][0];
		for(int i=0;i<10;i++){
	for(int it=0;it<is;it++){
		x[i]=i*h;
			x[i+1]=(i+1)*h;
		y[i+1][it+1]=y[i][is]+h*(f(x[i],y[i][is])+f(x[i+1],y[i][it]))/2;
	}
	cout<<x[i+1]<<";"<<y[i+1][is-1]<<endl;}
}



















