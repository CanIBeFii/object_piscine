#include "Course.hpp"
#include "Person.hpp"

Course::Course()
    : m_name("Course"), m_maximumNumberOfStudents(15),
      m_numberOfClassToGraduate(20) {}
Course::Course(std::string t_name)
    : m_name(t_name), m_maximumNumberOfStudents(15),
      m_numberOfClassToGraduate(20) {}
Course::~Course() {}
void Course::assign(Professor *t_progessor) { m_responsible = t_progessor; }
void Course::subscribe(Student *t_student) {
  m_students.insert(m_students.begin(), t_student);
}