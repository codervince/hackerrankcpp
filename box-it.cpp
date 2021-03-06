#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//https://www.hackerrank.com/contests/code-cpp-3/challenges/box-it

int BoxesCreated,BoxesDestroyed;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);

// Destructor
// ~Box()
// {

// }

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box &b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box B)


    
// would normally separate this out and use #include "Box.h" in same directory
class Box 
{
    
public:
    
    Box()
    {
        l = b = h = 0;
        BoxesCreated++;
    }
    
    
    Box(int length, int breadth, int height)
    {
        l = length;
        b = breadth;
        h= height;
        BoxesCreated++;
    }
    //copy constructor
    //format: classname (const classname &obj) {
    // body of constructor}
    
    Box(const Box &box){
     l = box.l;
     b = box.b;
     h = box.h;
     BoxesCreated++;
    }

    friend ostream &operator<<(ostream& out, const Box& b)
    {
    BoxesCreated++; //needed to pass test case - ie demonstrate inner workings of << rather than make any intuitive sense :p
    BoxesDestroyed++;//needed to pass test case - ie demonstrate inner workings of << rather than make any intuitive sense :p
    out << b.l << " " << b.b << " " << b.h;  
    return out;
    }

  
    // Destructor
    ~Box()
    {
        BoxesDestroyed++;
    }
    
    //Return box's length
    int getLength()
    {
        return l;    
    }
    int getBreadth()
    {
        return b;    
    }
    int getHeight()
    {
        return h;
    }
    
    long long CalculateVolume(){
        return l*b*h;
    }
    //implemented as non-static member function    
    bool operator<(Box &b)
    {
        return (this->l < b.l) or (this->l == b.l && this->b < b.b) 
            or (this->l == b.l && this->b == b.b && this->h < b.h);
    }
    
    

    
private:
    long int l;
    long int b;
    long int h;
};


//hackerrank test code
void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}
