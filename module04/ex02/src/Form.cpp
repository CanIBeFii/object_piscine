#include "Form.hpp"
#include <memory>

// Form
Form::Form(FormType p_formType)
    : _formType(p_formType), _is_signed(false), _was_executed(false) {}
Form::~Form() {}

bool Form::get_is_signed() { return _is_signed; }
bool Form::get_was_executed() { return _was_executed; }
void Form::sign() {
  if (!_is_signed)
    _is_signed = true;
}

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