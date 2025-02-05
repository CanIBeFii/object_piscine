#pragma once

#include <string>
#include <vector>

class Student;
class Professor;

class Course {
  std::string m_name;
  Professor *m_responsible;
  std::vector<Student *> m_students;
  int m_numberOfClassToGraduate;
  int m_maximumNumberOfStudents;

public:
  Course();
  Course(std::string t_name);
  ~Course();
  void assign(Professor *t_professor);
  void subscribe(Student *t_student);
};
