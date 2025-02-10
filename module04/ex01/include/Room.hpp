#pragma once

#include "Course.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include <vector>

enum class Event {
  RingBell,
};

class Person;

class Room {
  static long long m_room_number;
  long long m_ID;
  std::vector<Person *> m_occupants;

public:
  Room();
  virtual ~Room();
  virtual bool canEnter(Person *t_person) = 0;
  long long get_id();
  bool enter(Person *t_person);
  bool exit(Person *t_person);

  void printOccupants();
};

class Classroom : public Room {
  Course *m_currentRoom;

public:
  Classroom();
  ~Classroom();
  bool canEnter(Person *t_person);
  void assignCourse(Course *t_course);
};

class SecretarialOffice : public Room {
  std::vector<Form *> _archivedForms;

public:
  SecretarialOffice();
  ~SecretarialOffice();
  bool canEnter(Person *t_person);
};

class HeadmasterOffice : public Room {
public:
  HeadmasterOffice();
  ~HeadmasterOffice();
  bool canEnter(Person *t_person);
};

class StaffRestRoom : public Room {
public:
  StaffRestRoom();
  ~StaffRestRoom();
  bool canEnter(Person *t_person);
};

class Courtyard : public Room {
public:
  Courtyard();
  ~Courtyard();
  bool canEnter(Person *t_person);
};
