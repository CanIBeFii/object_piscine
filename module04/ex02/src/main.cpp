#include "Course.hpp"
#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "SingletonList.hpp"
#include <iostream>
#include <memory>

int main() {
  SingletonList<Student> *student_list = SingletonList<Student>::get_instance();
  //   SingletonList<Staff> *staff_list = SingletonList<Staff>::get_instance();
  //   SingletonList<Course> *course_list =
  //   SingletonList<Course>::get_instance(); SingletonList<Room> *room_list =
  //   SingletonList<Room>::get_instance();

  FormFactoryRegister factory_register;

  factory_register.register_factory(
      FormType::CourseFinished, std::make_unique<CourseFinishedFormFactory>());
  factory_register.register_factory(
      FormType::NeedMoreClassRoom,
      std::make_unique<NeedMoreClassRoomFormFactory>());
  factory_register.register_factory(
      FormType::NeedCourseCreation,
      std::make_unique<NeedCourseCreationFormFactory>());
  factory_register.register_factory(
      FormType::SubscriptionToCourse,
      std::make_unique<SubscriptionToCourseFormFactory>());

  student_list->add_element(std::make_shared<Student>("Peter"));
  return 0;
}
