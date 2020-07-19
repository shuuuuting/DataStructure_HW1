#include <iomanip>
#include "student.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void process1() {
	int i,n,sum; /* i is for index and n is the number of record to be read */
	student *s;	
	string tt;
	char temp1,temp2,temp3;
	cin >> n; getline(cin,tt);
//	cout << "n=" << n << endl;
	if(n>1) s=new student[n];  /* dynamic memory allocation */
		
		cout << "now reading the record from the input file....." << endl;
		for(i=0;i<n;i++){
			cin >> s[i].p.name >> s[i].p.pID >> s[i].p.age >> s[i].sID >> s[i].dept >> s[i].score1 >>s[i].score2 >> s[i].score3;
			s[i].ave = (s[i].score1+ s[i].score2 + s[i].score3)/3;
		}
		cout << "output the recorded data "<< endl;
		cout << setw(5) <<"index"<< setw(12) <<"NAME"<< setw(12) <<"P_ID"<< setw(4) <<"AGE"
			<< setw(12) <<"S_ID"<< setw(5) <<"Dept"<< setw(4) <<"S1"<< setw(4) <<"S2"
			<< setw(4) <<"S3"<< setw(8) <<"Ave"<< endl;
		for(i=0;i<n;i++){
			cout << setw(3) <<i<<"  " 
			<< setw(12) << s[i].p.name << setw(12) << s[i].p.pID << setw(4) << s[i].p.age 
			<< setw(12) << s[i].sID << setw(5) << s[i].dept << setw(4) <<s[i].score1 
			<< setw(4) << s[i].score2 << setw(4) << s[i].score3 << setw(8) << s[i].ave << endl;
		}
		for(i=0;i<n;i++){
			int big=i;
			for(int k=i+1;k<n;k++){
				if(s[k].ave>s[big].ave)big=k;
			}
			student temp=s[i];
			s[i]=s[big];
			s[big]=temp;
		}
		cout<<"-------------------------------------------------"<<endl;
		cout<<"キАだ计程蔼: "<< s[0].p.name << "\t"<<s[0].ave << endl;
		cout<<"キАだ计程: "<< s[n-1].p.name << "\t"<<s[n-1].ave << endl;
		cout<<"-------------------------------------------------"<<endl;
		cout<<"Ranking"<<setw(12)<<"Name"<<setw(5)<<"Ave"<<endl;
		for(i=0;i<n;i++){
			cout<<setw(7)<<i+1<<setw(12)<<s[i].p.name<<setw(5)<<s[i].ave<<endl;
		}
}