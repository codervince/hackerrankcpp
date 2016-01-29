#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//my code
//task https://www.hackerrank.com/contests/code-cpp-3/challenges/virtual-functions
class Person {
  public:
        Person()
        {
        }
       virtual void getdata()
       {
           cout << "in Person";
       }
       virtual void putdata()
       {
          cout << "in Person";
       }
      //non virtual but still accessible
      void setvalues (string a, int b)
      {   name=a;
          age=b; 
      }
 
  protected:
    string name;
    int age;
};

class Student: public Person
{
public:
    Student() {curid++;}
    
    void getdata(){
        string inname;
        int inage;
        int i;
        cin >> inname;
        cin >> inage;
        name = inname;
        age = inage;
        for (i= 0; i< 6; i++){
            int val;
            cin >> val;
            summarks = summarks + val;
            marks[i] = val;
        }
    }
    
    void putdata(){
        cout << name << " " << age << " " << summarks << " " << curid << endl;
    }

protected:
    int summarks=0;
    int marks[6];
    static int curid;
};

class Professor: public Person
{
    public:
        Professor(){curid++;}
    
        void getdata() {
            string inname;
            int inage;
            int inpublications;
            //professor has name age publications
            cin >> inname;
            cin >> inage;
            cin >> inpublications;
            name = inname;
            age = inage;
            publications = inpublications;

    }
    
        void putdata(){
            cout << name << " " << age << " " << publications << " " << curid << endl;


        }
 protected:
    int publications;
    static int curid;

};
int Professor::curid = 0;
int Student::curid = 0;

//test driver (given)
int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
