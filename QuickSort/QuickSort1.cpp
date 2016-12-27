//
//  main.cpp
//  programming_practice
//
//  Created by Sergey Nasonov on 25/12/2016.
//  Copyright © 2016 Sergey Nasonov. All rights reserved.
//

#include <iostream>
using namespace std;


//void qsort(int m[], int *pvt, int* iwall, int* icur, int* iright, int* itest)
//{
//    cout<<*itest<<"; ";
//    while ((*icur) != (*pvt))
//    {
//        //std::cout <<icur<<", "<< pvt << "; ";
//
//        if (m[*icur]<=m[*pvt])
//        {
//            int tmp=m[*iright];
//            m[*iright]=m[*icur];
//            m[*icur]=tmp;
//
//            (*iwall)++;
//            (*iright)++;
//            (*icur)++;
//        }
//        else
//        {
//            (*icur)++;
//        }
//    }
//    int tmp=m[*iright];
//    m[*iright]=m[*pvt];
//    m[*pvt]=tmp;
//
//    qsort(m, &pvt,&iwall, &icur, &iright, &itest);//problem!=> reverse to regular pass by value.
//}

int qsort(int m[], int pvt, int iwall, int icur, int iright)
{

	int size = sizeof(m)/sizeof(int);
	
	if (pvt==icur)
		{
		return 0;
		}
	else
		{
		while (icur != pvt)
		{
			if (m[icur]<=m[pvt])
			{
				int	tmp=m[iright];
				m[iright]=m[icur];
				m[icur]=tmp;

				iwall++;
				iright++;
				icur++;
			}
			else
			{
				icur++;
			}
		}
	
		int tmp=m[iright];
		m[iright]=m[pvt];
		m[pvt]=tmp;
		
//		for (int i=0; i<9; i++) {
//			std::cout <<m[i]<<", ";
//		}
		
		pvt=iwall-1;//gof for left part
		size=iwall;
		int istart=iwall+ 1; // s predidushei iteracyi.
		int iend = iwall;
		
		qsort(m, pvt, istart, istart, istart);// i need to make pvt the last element of the passing array
		
		/////////
		
		//iwall++;
		//iright++;
		
		
		qsort(m, pvt, iend, iend, iend +1);
		}
	return 0;
}


int main(int argc, const char * argv[]) {
	int m[]={6,5,1,3,8,4,7,0,2};
	int s = sizeof(m)/sizeof(int);
	
	int iwall=0;
	int pvt=s-1;
	int icur=0;
	int iright=0;
	
	qsort(m, pvt, iwall, icur, iright);

	
	for (int i=0; i<s; i++) {
		std::cout <<m[i]<<", ";
	}
	
	std::cout << "Hello, World!\n";
	return 0;
}
