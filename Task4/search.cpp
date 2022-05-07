#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void init(int **,int);
void print(int **,int);
int random(int);
double calculator_dir(int **,int);
double calculator_rand(int **,int);
int main(){

	int **mat,number,range;
    double sum_dir=0,sum_rand=0;
	cout<<"Enter a number  for row & column : ";cin>>number;
	cout<<"Enter repetition number : ";cin>>range;
	mat = new int*[number];
	for(int i = 0; i < number; ++i)
	    mat[i] = new int[number];


	for(int i=1;i<=range;i++){
		init(mat,number);
		sum_dir += calculator_dir(mat,number);
	}
	for(int i=1;i<=range;i++){
		init(mat,number);
		sum_rand += calculator_rand(mat,number);	
	}


	print(mat,number);
	cout<<"Total tome of direction search in range "<<range<<" is : "<<sum_dir<<" sec";
	cout<<"\nThe average of direction search in range "<<range<<" is : "<<sum_dir/range<<" sec";
	cout<<"\n\nTotal tome of random search in range "<<range<<" is : "<<sum_rand<<" sec";
	cout<<"\nThe average of random search in range "<<range<<" is : "<<sum_rand/range<<" sec";
	cout<<"\n\nResult\n\n";
	if((sum_dir/range)<(sum_rand/range))
		cout<<"Direction search was faster ";
	else cout<<" Random search was faster ";	
   	return 0;
}
//=============================
int random(int number){
	int random;
	random = rand() % number + 0;
	
	return random;
}
//============================
void init(int** mat,int number){
	
  	int x = random(number);
  	int y = random(number);
	for(int i=0;i<number;i++){
		for(int j=0;j<number;j++){
			mat[i][j]=0;
			if(i==x && j==y){
				mat[i][j]=1;
			}
		}
	}	
		
}
//=============================

void print(int** mat,int number){
	int x,y;
	cout<<"\n\n Last matrix in range \n\n";
	cout<<"The matrix is : "<<number<<"*"<<number<<endl<<endl;
	if(number<=40){
	for(int i=0;i<number;i++){
		for(int j=0;j<number;j++){
			cout<<mat[i][j]<<" ";
		}                      
			
		cout<<endl;
	}
}
	else{
		cout<<"\n Too much for printing ...\n";
}

	cout<<"\n===============================\n\n";	
}
//=================================
double calculator_rand(int **mat,int number){

	int x,y,flag; 
	
	clock_t t;
	t = clock();
	while(true){	
	x = random(number);
	y = random(number);
				
	if(mat[x][y]==1){
			flag =1;
			break;					
		}
	else continue;
}
	
   	t = clock() - t;
   	double time = ((double)t)/CLOCKS_PER_SEC;  	
   	return time;
}
//=================================
double calculator_dir(int **mat,int number){
	int flag=0;
	clock_t t;
	t = clock();
	
	for(int i=0;i<number;i++){
		for(int j=0;j<number;j++){
			if(mat[i][j]==1){
				flag=1;
				break;
			}
		}
	}			
   	t = clock() - t;
   	double time = ((double)t)/CLOCKS_PER_SEC;
   	
   	return time;
}