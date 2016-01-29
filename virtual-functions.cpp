class Person {
  public:
        Person()
        {
        }
       virtual void getdata() const {cout << "Person getdata()";}
       virtual void putdata() const {cout << "Person putdata()";}
       virtual void setage(int theage){
           age = theage;
       }
       virtual int getage() {
           return age;
       }
       virtual void setname(string thename){
           name = thename;
       }
       virtual string getname() {
           return name;
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
    
        void getdata() const {
            string inname;
            int inage;
            int inpublications;
            //professor has name age publications
            cin >> inname;
            cin >> inage;
            cin >> inpublications;
            cout << inname << "here" << inage<< endl;
            //name, age is updated in Person - publications
            //create Person

            //publications = inpublications;
            //id is updated by constructor
    }
    
        virtual void putdata(){
            //print out name age publications id
            cout << "called here";
            cout << Person::getname() << " " << Person::getage() << " " << publications << " " << curid << endl;

        }
 protected:
    int publications;
    static int curid;

};
int Professor::curid = 0;
int Student::curid = 0;
