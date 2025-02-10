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