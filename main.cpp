//
//  main.cpp
//  programming_practice
//
//  Created by Sergey Nasonov on 25/12/2016.
//  Copyright © 2016 Sergey Nasonov. All rights reserved.
//

#include <iostream>
using namespace std;



int main(int argc, const char * argv[]) {
	int m[]={6,5,1,3,8,4,7,0,2};
	int s = sizeof(m)/sizeof(int);
	
	
	for (int i=0; i<s; i++) {
		std::cout <<m[i]<<", ";
	}
	
	std::cout << "Hello, World!\n";
	return 0;
}
