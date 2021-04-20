/*
@author:YiFan Zhao
@time:2021-4-20 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
#include<algorithm>
#include<fstream>
#include "toString.cpp"
using namespace std;

const int MAX_SIZE = 2e6;
int mark = 0,temp[MAX_SIZE + 7],dataNumber = 1,srt[10000],num[10000];
class MinLossTree{
	private :
		int *p;
		int size;
	public :
		MinLossTree(int size) {	 
			this->size = size;
			p = new int[size * 2];
		}
		void initTree(int *a) {	  
			for(int i = size * 2 - 1;i >= 1;--i)
				p[i] = (i >= size)? i - size + 1: 
					(a[p[i * 2]]<a[p[i * 2 + 1]]? p[i * 2]: p[i * 2 + 1]);  
		}
		int get(){	
			return p[1];
		}
		void change(int pos, int *a){	 
			int real = (pos + size - 1)/2;
			while(real) {
				p[real] = a[p[real * 2]]<a[p[real * 2 + 1]]? p[real * 2]: p[real * 2 + 1];
				real /= 2;
			}
		}
};
int main()
{
	 freopen("data.in","r",stdin);
	 int n;cin>>n;
	 ofstream outputSdata;
	 outputSdata.open(toChar(dataNumber),ios::out);
	 while(scanf("%d",&temp[++mark]) != EOF) {
		if(mark >= MAX_SIZE) {
			sort(temp+1,temp+mark+1);
			outputSdata << mark<< endl;
			for(int j = 1;j <= mark ;++j)
				outputSdata << temp[j]<< " ";
			mark = 0;
			outputSdata.close();
	 		outputSdata.open(toChar(++dataNumber),ios::out);
		}  
	 }
	 mark -- ;//È¥³ýEOF 
	 if(mark) {
	 	sort(temp+1,temp+mark+1);
		outputSdata << mark<< endl;
		for(int j = 1;j <= mark ;++j)
			outputSdata << temp[j]<< " ";
	 }
	 else dataNumber --;
	 outputSdata.close();
	 mark = 0;
	 
	 
	 MinLossTree minLossTree(dataNumber);
	 freopen("data.ans","w",stdout);
	 ifstream inputData[100];
	 for(int i = 1;i <= dataNumber; ++i)
	 {
	 	inputData[i].open(toChar(i),ios::in);
	 	inputData[i] >> num[i];
	 	inputData[i] >> srt[i];
	 }
	 minLossTree.initTree(srt);
	 while(mark < n) {
	 	int k = minLossTree.get();
	 	printf("%d ",srt[k]);
	 	if(--num[k] > 0) inputData[k] >> srt[k];
	 	else srt[k] = 1e9+7;
	 	minLossTree.change(k,srt);
	 	mark ++;
	 }
	 for(int i = 1;i <= dataNumber; ++i)
	 	inputData[i].close();
	 return 0;
}
