#pragma once

#include "Form.hpp"

// Factories

class IFormFactory {
public:
  virtual ~IFormFactory();
  virtual Form *create_form() = 0;
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
  std::map<FormType, std::unique_ptr<IFormFactory>> _factories;

public:
  FormFactoryRegister();
  ~FormFactoryRegister();
  void register_factory(FormType type, std::unique_ptr<IFormFactory> factory);
  Form *create_form(FormType type);
};