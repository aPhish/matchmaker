
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
    Person(string name) {
        m_name = name;
        m_skill = 0;
    }

    void dump() {
        cout << m_name << " (" << m_skill << ")" << endl;
    }

private:

    double m_skill;
    string m_name;
};

int main(int argc, char** argv) {


  vector<Person> people = {
      Person("Steve"),
      Person("Pernille"), 
      Person("Anders"), 
      Person("Katherine"), 
      Person("Bea"), 
      Person("Lun"),
      Person("Ka"),
      Person("Hieng")
  };
 

  for (Person p : people) {
      p.dump();
  }
   
   

}