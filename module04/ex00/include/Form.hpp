#pragma once

enum class FormType {
  CourseFinished,
  NeedMoreClassRoom,
  NeedCourseCreation,
  SubscriptionToCourse,
};

class Form {
  FormType _formType;

public:
  Form(FormType p_formType);
  virtual ~Form();
  virtual void execute() = 0;
};

class CourseFinishedForm : public Form {
public:
  CourseFinishedForm();
  ~CourseFinishedForm();
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
