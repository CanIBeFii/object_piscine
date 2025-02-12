#pragma once

#include <map>

enum class FormType {
  CourseFinished,
  NeedMoreClassRoom,
  NeedCourseCreation,
  SubscriptionToCourse,
};

// Forms
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

// Factories

class IFormFactory {
public:
  virtual ~IFormFactory();
  virtual Form *create_form();
};

class CourseFinishedFormFactory : public IFormFactory {
public:
  Form *create_form();
};

class NeedMoreClassRoomFormFactory : public IFormFactory {
public:
  Form *create_form();
};

class NeedCourseCreationFormFactory : public IFormFactory {
public:
  Form *create_form();
};

class SubscriptionToCourseFormFactory : public IFormFactory {
public:
  Form *create_form();
};

class FormFactoryRegister {
  std::map<FormType, IFormFactory *> _factories;

public:
  FormFactoryRegister();
  ~FormFactoryRegister();
  void register_factory(FormType type, IFormFactory *factory);
  Form *create_form(FormType type);
};