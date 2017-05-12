
#include <iostream>
#include <string>
#include <deque>
#include <array>
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

class WaitingList {
public:

    WaitingList(deque<Person> initial) {
        m_people = initial;

        for (Person p : m_people) {
            p.dump();
        }
    }

    deque<Person> pick_game() {
        // Just the 4 that have been waiting the longest

        deque<Person> output;
        if (m_people.size() < 4) return output;
        
        for (int i = 0; i < 4; ++i) {
            output.push_back(m_people.front());
            m_people.pop_front();
        }
        return output;
    }

private:

  deque<Person> m_people;
};

int main(int argc, char** argv) {


  deque<Person> people = {
      Person("Steve"),
      Person("Pernille"), 
      Person("Anders"), 
      Person("Katherine"), 
      Person("Bea"), 
      Person("Lun"),
      Person("Ka"),
      Person("Hieng")
  };
 

  WaitingList waiting(people);

  cout << "Picking a game" << endl;
  deque<Person> game = waiting.pick_game();
  if (game.size() == 0) {
      cout << "Not enough people" << endl;
      return 1;
  }

  cout << "On: " << endl;
  for (Person p : game) {
      p.dump();
  }

}