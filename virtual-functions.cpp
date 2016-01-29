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

protected:
    int marks[6];
    static int curid;
};

class Professor: public Person
{
    public:
        Professor(){}
    
        void getdata() {
            string inname;
            int inage;
            int inpublications;
            //professor has name age publications
            cin >> inname;
            cin >> inage;
            cin >> inpublications;
            cout << inname << "here " << inage<< endl;
            name = inname;
            age = inage;
            
            //name, age is updated in Person - publications
            //create Person

            //publications = inpublications;
            //id is updated by constructor
    }
    
        void putdata(){
            //print out name age publications id
            cout << "called here";
            cout << name << " " << age << endl;
            //cout << getname() << " " << getage() << " " << publications << " " << curid << endl;

        }
 protected:
    int publications;
    static int curid;

};
int Professor::curid = 0;
int Student::curid = 0;
