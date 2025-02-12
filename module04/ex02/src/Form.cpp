#include "Form.hpp"

// Form
Form::Form(FormType p_formType) : _formType(p_formType) {}
Form::~Form() {}

// CourseFinishedForm
CourseFinishedForm::CourseFinishedForm() : Form(FormType::CourseFinished) {}
CourseFinishedForm::~CourseFinishedForm() {}
void CourseFinishedForm::execute() {}

// NeedMoreClassRoomForm
NeedMoreClassRoomForm::NeedMoreClassRoomForm()
    : Form(FormType::NeedMoreClassRoom) {}
NeedMoreClassRoomForm::~NeedMoreClassRoomForm() {}
void NeedMoreClassRoomForm::execute() {}

// NeedCourseCreationForm
NeedCourseCreationForm::NeedCourseCreationForm()
    : Form(FormType::NeedCourseCreation) {}
NeedCourseCreationForm::~NeedCourseCreationForm() {}
void NeedCourseCreationForm::execute() {}

// SubscriptionToCourseForm
SubscriptionToCourseForm::SubscriptionToCourseForm()
    : Form(FormType::SubscriptionToCourse) {}
SubscriptionToCourseForm::~SubscriptionToCourseForm() {}
void SubscriptionToCourseForm::execute() {}

// Factories
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
void FormFactoryRegister::register_factory(FormType type,
                                           IFormFactory *factory) {
  _factories[type] = factory;
}

Form *FormFactoryRegister::create_form(FormType type) {
  auto iter = _factories.find(type);
  if (iter != _factories.end()) {
    return iter->second->create_form();
  }
  return nullptr;
}