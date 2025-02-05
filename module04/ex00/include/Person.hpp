#pragma once

#include "Form.hpp"
#include "Room.hpp"
#include <string>

class Room;
class Form;
class Course;
class Classroom;

class Person {
  std::string _name;
  Room *_currentRoom;

public:
  Person(std::string p_name);
  ~Person();
  void enterRoom(Room *p_room);
  void leaveRoom();
  Room *room();
};

class Staff : public Person {
public:
  Staff();
  Staff(std::string p_name);
  ~Staff();
  void sign(Form *p_form);
};

class Student : public Person {
  std::vector<Course *> _subscribedCourse;

public:
  Student();
  Student(std::string p_name);
  ~Student();
  void subscribeCourse(Course *p_course);
  void attendClass(Classroom *p_classroom);
  void exitClass();
  void graduate(Course *p_course);
};

class Headmaster : public Staff {
  std::vector<Form *> _formToValidate;

public:
  Headmaster();
  Headmaster(std::string p_name);
  ~Headmaster();
  void receiveForm(Form *p_form);
};

class Secretary : public Staff {
public:
  Secretary();
  Secretary(std::string p_name);
  ~Secretary();
  Form *createForm(FormType p_formType);
  void archiveForm();
};

class Professor : public Staff {
  Course *_currentCourse;

public:
  Professor();
  ~Professor();
  void assignCourse(Course *p_course);
  void doClass();
  void closeCourse();
};
