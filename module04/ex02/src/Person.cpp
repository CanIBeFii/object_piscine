#include "Person.hpp"
#include "Form.hpp"
#include <iostream>
#include <ostream>

// Person
Person::Person(std::string p_name) : _name(p_name) {}
Person::~Person() {}
std::string &Person::getName() { return _name; }
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
void Staff::sign(Form *p_form) {
  p_form->execute();
  std::cout << "Form was signed" << std::endl;
}

// Student
Student::Student() : Person(std::string("Student")) {}
Student::Student(std::string p_name) : Person(p_name) {}
Student::~Student() {}
void Student::subscribeCourse(Course *p_course) { p_course->subscribe(this); }
void Student::attendClass(Classroom *p_classroom) {
  if (p_classroom->canEnter(this)) {
    enterRoom(p_classroom);
    std::cout << "Entering classroom" << std::endl;
  }
}
void Student::exitClass() { leaveRoom(); }
void graduate(Course *p_course) {
  std::cout << "Student graduated the course " << p_course->get_name()
            << std::endl;
}

// Headmaster
Headmaster::Headmaster() : Staff("Headmaster") {}
Headmaster::Headmaster(std::string p_name) : Staff(p_name) {}
Headmaster::~Headmaster() {}
void Headmaster::receiveForm(Form *p_form) {
  _formToValidate.insert(_formToValidate.begin(), p_form);
}

// Secretary
Secretary::Secretary() : Staff("Secretary") {}
Secretary::Secretary(std::string p_name) : Staff(p_name) {}
Secretary::~Secretary() {}
Form *Secretary::createForm(FormType p_formType) {
  switch (p_formType) {
  case FormType::CourseFinished:
    return new CourseFinishedForm();
  case FormType::NeedMoreClassRoom:
    return new NeedMoreClassRoomForm();
  case FormType::NeedCourseCreation:
    return new NeedCourseCreationForm();
  case FormType::SubscriptionToCourse:
    return new SubscriptionToCourseForm();
  }
  return nullptr;
}
void Secretary::archiveForm(Form *p_form) { delete p_form; }

// Professor
Professor::Professor() : Staff("Professor") {}
Professor::Professor(std::string p_name) : Staff(p_name) {}
Professor::~Professor() {}
void Professor::assignCourse(Course *p_course) { _currentCourse = p_course; }
void Professor::doClass() {}
void Professor::closeCourse() {}