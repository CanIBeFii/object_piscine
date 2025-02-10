#include "Room.hpp"
#include "Course.hpp"
#include <iostream>
#include <ostream>
long long Room::m_room_number = 0;

Room::Room() : m_ID(m_room_number++) {}

long long Room::get_id() { return m_ID; }
bool Room::enter(Person *t_person) {
  if (canEnter(t_person)) {
    m_occupants.insert(m_occupants.begin(), t_person);
    return true;
  }
  return false;
}
bool Room::exit(Person *t_person) {
  for (std::vector<Person *>::iterator iter = m_occupants.begin();
       iter != m_occupants.end(); ++iter) {
    if (*iter == t_person) {
      m_occupants.erase(iter);
      return true;
    }
  }
  return false;
}
void Room::printOccupants() {
  std::cout << "List of Occupatns of room " << m_ID << ":" << std::endl;
  for (std::vector<Person *>::iterator iter = m_occupants.begin();
       iter != m_occupants.end(); ++iter) {
    std::cout << (*iter)->getName() << "," << std::endl;
  }
}

// Classroom
Classroom::Classroom() : Room() {}
Classroom::~Classroom() {}
bool Classroom::canEnter(Person *t_person) { return true; }
void Classroom::assignCourse(Course *t_course) { m_currentRoom = t_course; }