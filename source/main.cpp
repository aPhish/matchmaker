
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



class Session {
public:

    Session(deque<Person> initial) {
        people = initial;

        size_t i = 0;
        for (Person p : people) {
            waiting.push_back(i++);
        }
    }

    void create_game() {

        if (waiting.size() < 4) return;

        deque<size_t> game;
        for (int i = 0; i < 4; ++i) {
            game.push_back(waiting.front());
            waiting.pop_front();
        }
        games.push_back(game);
    }

    void dump() {
        cout << " Waiting List:" << endl;
        for (size_t i : waiting) {
            cout << "  ";
            people[i].dump();
        }
        cout << endl << " Games: " << endl;
        
        for (size_t i = 0; i < games.size(); ++i) {
            cout << "   Game " << i << ":" << endl;
            for (size_t player_idx : games[i]) {
                cout << "     ";
                people[player_idx].dump();
            }
        }
    }

private:

  deque<Person> people;
  deque<size_t> waiting;
  deque<deque<size_t>> games;
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
 

  Session session(people);

  cout << "Picking a game" << endl;
  session.create_game();

  cout << "Session Dump: " << endl;
  session.dump();

}