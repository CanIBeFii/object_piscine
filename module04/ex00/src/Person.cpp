#include "Person.hpp"
#include <iostream>

// Person
Person::Person(std::string p_name) : _name(p_name) {}
Person::~Person() {}
void Person::enterRoom(Room *p_room) {
  p_room->enter(this);
  _currentRoom = p_room;
}

void Person::leaveRoom() {
  _currentRoom->exit(this);
  _currentRoom = NULL;
}

Room *Person::room() { return _currentRoom; }

// Staff
Staff::Staff() : Person(std::string("Staff")) {}
Staff::Staff(std::string p_name) : Person(p_name) {}
Staff::~Staff() {}
void Staff::sign(Form *p_form) { std::cout << "Form was signed" << std::endl; }

// Student
Student::Student() : Person(std::string("Student")) {}
Student::Student(std::string p_name) : Person(p_name) {}
Student::~Student() {}
void Student::subscribeCourse(Course *p_course) {}
void Student::attendClass(Classroom *p_classroom) {
  if (p_classroom->canEnter(this)) {
    enterRoom(p_classroom);
    std::cout << "Entering classroom" << std::endl;
  }
}
void Student::exitClass() { leaveRoom(); }
void graduate(Course *p_course) {}

// Headmaster
Headmaster::Headmaster() : Staff("Headmaster") {}
Headmaster::Headmaster(std::string p_name) : Staff(p_name) {}
Headmaster::~Headmaster() {}

void Headmaster::receiveForm(Form *p_form) { _formToValidate.insert(_formToValidate.begin() ,p_form); }

// Secretary
Secretary::Secretary() : Staff("Secretary") {}
Secretary::Secretary(std::string p_name) : Staff(p_name) {}
Secretary::~Secretary() {}
Form*
