#include "Factory.hpp"

// Factories
IFormFactory::~IFormFactory() {}

Form *CourseFinishedFormFactory::create_form() {
  return new CourseFinishedForm();
}

Form *NeedMoreClassRoomFormFactory::create_form() {
  return new NeedMoreClassRoomForm();
}

Form *NeedCourseCreationFormFactory::create_form() {
  return new NeedCourseCreationForm();
}

Form *SubscriptionToCourseFormFactory::create_form() {
  return new SubscriptionToCourseForm();
}

FormFactoryRegister::FormFactoryRegister() {}
FormFactoryRegister::~FormFactoryRegister() {}
void FormFactoryRegister::register_factory(
    FormType type, std::unique_ptr<IFormFactory> factory) {
  _factories[type] = std::move(factory);
}

Form *FormFactoryRegister::create_form(FormType type) {
  auto iter = _factories.find(type);
  if (iter != _factories.end()) {
    return iter->second->create_form();
  }
  return nullptr;
}