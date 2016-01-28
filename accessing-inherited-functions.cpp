// https://www.hackerrank.com/contests/code-cpp-3/challenges/accessing-inherited-functions
//given
#include<iostream>

using namespace std;

int callA=0;
int callB=0;
int callC=0;
class A
{
protected:
   
   void func(int  & a)
   {
      a=a*2;
      callA++;
   }
};

class B
{
protected:
   void func(int & a)
   {
      a=a*3;
      callB++;
   }
};

class C
{
protected:
   void func(int & a)
   {
      a=a*5;
      callC++;
   }
};

//own code
// explanation: 
// Task 1 need mult inheritance to access protected member functions
// Use recursion to increase val by 2,3,5 each time until val = new_value (target)
class D: public A, public B, public C 
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val=1;
		 }

		 //Implement this function
		 void update_val(int new_val)
		 {
           //base case
           if (new_val==1){
               return;
           }  
           if (new_val % 2 == 0){
               new_val = new_val/2;
               A::func(val);
               return update_val(new_val);
           }
           if (new_val % 3 == 0){
               new_val = new_val/3;
               B::func(val);
               return update_val(new_val);
           }
           
            if (new_val % 5 == 0){
               new_val = new_val/5;
               C::func(val);
               return update_val(new_val);
             }  
         
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};
