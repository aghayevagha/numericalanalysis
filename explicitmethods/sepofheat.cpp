#include<iostream>
#include<cmath>
using namespace std;
float u2[100][100],u1[100][100];
int n,m,p;
void chap(int k);
float l(float x,float y){
	return 0.0001;
}
float fi(float x,float y){
	return (pow(2-x,3)+pow(2-y,3));
}
float f(float x, float y, float t ){
	return 0;
}
int main(){
	float t,x,y,dx,dy,dt,u2[100][100],u1[100][100];
	int i,j,k,cap=10;
	x=1;y=1;t=30;
	dx=0.2;dy=0.2;dt=0.2;
	/*	cout<<"Lx-i daxil edin:";
	cin>>x;
	cout<<"Ly-i daxil edin:";
	cin>>y;
	cout<<"t-i daxil edin:";
	cin>>t;
	cout<<"dx-i daxil edin:";
	cin>>dx;
	cout<<"dt-i daxil edin:";
	cin>>dy;
	cout<<"dt-i daxil edin:";
	cin>>dt;*/
	//uzunluq tapilir
	n=x/dx; m=y/dy;p=t/dt;
	//t=0 ucun serhed serti istifade olunur
	cout<<"n="<<n<<";m="<<m<<";p="<<p<<endl;
		for(i=0;i<n;i++){
		u1[i][0]=f(i*dx,0,p*dt);
		u1[i][m]=f(i*dx,m*dy,p*dt);}
	for(i=0;i<m;i++){
		u1[0][i]=f(0,i*dy,p*dt);	
		u1[n][i]=f(n*dx,i*dy,p*dt);}
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
			u1[i][j]=fi(i*dx,j*dy);
		}
	}
	for(int i=0;i<100;i++)	cout<<"-"; 
	cout<<endl<<k<<"-ci iterasiya"<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			printf(" %f |",u1[i][j]);
			}
		cout<<endl;
	}
	for(k=1;k<=p;k++){
		//serhed sertleri tetbiq olunur
	for(i=0;i<n;i++){
		u2[i][0]=f(i*dx,0,p*dt);
		u2[i][m]=f(i*dx,m*dy,p*dt);}
	for(i=0;i<m;i++){
		u2[0][i]=f(0,i*dy,p*dt);	
		u2[n][i]=f(n*dx,i*dy,p*dt);}
		//dovr qurulur
	for(i=1;i<n;i++){
		for(j=1;j<m;j++){
		u2[i][j]= u1[i][j] + dt*(l((i+0.5)*dx,j*dt)*(u1[i+1][j]-u1[i][j])/dx -l((i-0.5)*dx,j*dt)*(u1[i][j]-u1[i-1][j])/dx)/dx+
		dt*(l(i*dx,(j+0.5)*dt)*(u1[i][j+1]-u1[i][j])/dy -l(i*dx,(j-0.5)*dt)*(u1[i][j]-u1[i][j-1])/dy)/dy;
		}}
		//menimsetme
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			u1[i][j]=u2[i][j];
		}
	}
	if(k%cap==0) {
	for(int i=0;i<100;i++)	cout<<"-"; 
	cout<<endl<<k<<"-ci iterasiya"<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			printf(" %f |",u1[i][j]);
			}
		cout<<endl;
	}}
}
return 0;
}
void chap(int k){
	for(int i=0;i<100;i++)	cout<<"-"; 
	cout<<endl<<k<<"-ci iterasiya"<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			printf(" %f |",u1[i][j]);
			}
		cout<<endl;
	}
}



