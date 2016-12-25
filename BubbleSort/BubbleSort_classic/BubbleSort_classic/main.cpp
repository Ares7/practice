//
//  main.cpp
//  BubbleSort_classic
//
//  Created by Sergey Nasonov on 25/12/2016.
//  Copyright © 2016 Sergey Nasonov. All rights reserved.
//

#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	int m[]={6,5,8,3,7,4,2,1,7,0,4,7,3,4,6,8,2,6,0};
	int s=sizeof(m)/sizeof(int);
	bool swaped = false;
	
	do{
		swaped=false;
		for (int j = 1; j <= s-1; ++j)
			{

			if(m[j-1]<m[j])
				{
				int tmp=m[j-1];
				m[j-1]=m[j];
				m[j]=tmp;
				swaped=true;
				}
			}		
	}
	while (swaped!=false);
	
	cout<<"sorted in descending order: ";
	for (int i = 0; i < s; ++i)
		{
		cout<<m[i]<<", ";
		}
	
	return 0;
	
}
