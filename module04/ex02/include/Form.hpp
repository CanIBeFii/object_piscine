#pragma once

#include "Course.hpp"
#include <map>
#include <memory>

class Course;
class Student;
class Room;

enum class FormType {
  CourseFinished,
  NeedMoreClassRoom,
  NeedCourseCreation,
  SubscriptionToCourse,
};

// Forms
class Form {
  FormType _formType;

protected:
  bool _is_signed;
  bool _was_executed;

public:
  Form(FormType p_formType);
  virtual ~Form();
  virtual void execute() = 0;
  bool get_is_signed();
  bool get_was_executed();
  void sign();
};

class CourseFinishedForm : public Form {
  Course *_course;
  Student *_student;

public:
  CourseFinishedForm();
  ~CourseFinishedForm();
  void set_course(Course *course);
  void set_student(Student *student);
  void execute();
};

class NeedMoreClassRoomForm : public Form {
public:
  NeedMoreClassRoomForm();
  ~NeedMoreClassRoomForm();
  void execute();
};

class NeedCourseCreationForm : public Form {
public:
  NeedCourseCreationForm();
  ~NeedCourseCreationForm();
  void execute();
};

class SubscriptionToCourseForm : public Form {
public:
  SubscriptionToCourseForm();
  ~SubscriptionToCourseForm();
  void execute();
};
