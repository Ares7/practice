#include<iostream>

using namespace std;
struct abc { 
    int i;
    int p;

} myabc;

int main() {  
   myabc.i=55;
   //cout<<myabc.i;

   int k=33;
    void* p;
    p= &k;

    int* nn;
    nn = static_cast<int*>(p);

    int fin;
    fin = *(nn);
    cout<<(p) <<'\n';
    cout<<(&p)<<'\n';


    cout<<(nn) <<'\n';  
    cout<<(fin)<<'\n';
}