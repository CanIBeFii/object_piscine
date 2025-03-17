#include "Form.hpp"
#include "Course.hpp"
#include "Room.hpp"
#include "SingletonList.hpp"
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
void CourseFinishedForm::set_course(Course *course) { _course = course; }
void CourseFinishedForm::set_student(Student *student) { _student = student; }
void CourseFinishedForm::execute() {
  if (!_is_signed) {
    return;
  }
  _was_executed = true;
  _course->subscribe(_student);
}

// NeedMoreClassRoomForm
NeedMoreClassRoomForm::NeedMoreClassRoomForm()
    : Form(FormType::NeedMoreClassRoom) {}
NeedMoreClassRoomForm::~NeedMoreClassRoomForm() {}
void NeedMoreClassRoomForm::execute() {
  if (!_is_signed) {
    return;
  }
  _was_executed = true;
  //   SingletonList<Room>::get_instance()->add_element();
}

// NeedCourseCreationForm
NeedCourseCreationForm::NeedCourseCreationForm()
    : Form(FormType::NeedCourseCreation) {}
NeedCourseCreationForm::~NeedCourseCreationForm() {}
void NeedCourseCreationForm::execute() { _was_executed = true; }

// SubscriptionToCourseForm
SubscriptionToCourseForm::SubscriptionToCourseForm()
    : Form(FormType::SubscriptionToCourse) {}
SubscriptionToCourseForm::~SubscriptionToCourseForm() {}
void SubscriptionToCourseForm::execute() { _was_executed = true; }
