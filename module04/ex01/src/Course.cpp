#include "Course.hpp"
#include "Person.hpp"

Course::Course()
    : m_name("Course"), m_numberOfClassToGraduate(20),
      m_maximumNumberOfStudents(15) {}
Course::Course(std::string t_name)
    : m_name(t_name), m_numberOfClassToGraduate(20),
      m_maximumNumberOfStudents(15) {}
Course::~Course() {}
std::string Course::get_name() { return m_name; }
void Course::assign(Professor *t_progessor) { m_responsible = t_progessor; }
void Course::subscribe(Student *t_student) {
  m_students.insert(m_students.begin(), t_student);
}
bool Course::studentSubcribed(Student *t_student) {
  (void)t_student;
  return true;
}