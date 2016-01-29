class Person {
  public:
       virtual void getdata() const {}
       virtual void putdata() const {}
  protected:
    string name;
    int age;
};

class Professor: public Person
{
 public:
    Professor(){
        cur_{id}++;
    }

    void getdata() {
        string inname;
        int inage;
        int inpublications;
        //professor has name age publications
        cin >> inname;
        cin >> inage;
        cin >> inpublications;
        //name, age is updated in Person - publications
        Person::get
        publications = inpublications;
        //id is updated by constructor
    }
    
    void putdate(){
        //print out name age publications id
        
    }
 protected:
    int publications;
    static int cur_{id};
};
