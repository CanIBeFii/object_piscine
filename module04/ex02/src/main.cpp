#include "Course.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "SingletonList.hpp"
#include <iostream>

int main() {
  SingletonList<Student> *student_list = SingletonList<Student>::get_instance();
  SingletonList<Staff> *staff_list = SingletonList<Staff>::get_instance();
  SingletonList<Course> *course_list = SingletonList<Course>::get_instance();
  SingletonList<Room> *room_list = SingletonList<Room>::get_instance();

  {
    Student *new_student = new Student("Peter");
    student_list->add_element(new_student);

    if (student_list->add_element(new_student)) {
      std::cout << "THere was some problem student added 2 times" << std::endl;
    }
    student_list->add_element(new Student("Jack"));
    student_list->add_element(new Student("Melissa"));

    for (auto iter : student_list->get_list()) {
      std::cout << "Student name: " << iter->getName() << std::endl;
    }
    std::cout << std::endl;
    student_list->delete_element(new_student);
    for (auto iter : student_list->get_list()) {
      std::cout << "Student name: " << iter->getName() << std::endl;
    }
    std::cout << std::endl;
  }
  {
    Staff *new_staff = new Staff("Peter");
    staff_list->add_element(new_staff);

    if (staff_list->add_element(new_staff)) {
      std::cout << "THere was some problem staff added 2 times" << std::endl;
    }
    staff_list->add_element(new Staff("Jack"));
    staff_list->add_element(new Staff("Melissa"));

    for (auto iter : staff_list->get_list()) {
      std::cout << "Staff name: " << iter->getName() << std::endl;
    }
    std::cout << std::endl;
    staff_list->delete_element(new_staff);
    for (auto iter : staff_list->get_list()) {
      std::cout << "Staff name: " << iter->getName() << std::endl;
    }
    std::cout << std::endl;
  }
  {
    Course *new_course = new Course("Math 1");
    course_list->add_element(new_course);

    if (course_list->add_element(new_course)) {
      std::cout << "THere was some problem course added 2 times" << std::endl;
    }
    course_list->add_element(new Course("Portuguese"));
    course_list->add_element(new Course("Science"));

    for (auto iter : course_list->get_list()) {
      std::cout << "Course name: " << iter->get_name() << std::endl;
    }
    std::cout << std::endl;
    course_list->delete_element(new_course);
    for (auto iter : course_list->get_list()) {
      std::cout << "Course name: " << iter->get_name() << std::endl;
    }
    std::cout << std::endl;
  }
  {
    Room *new_room = new Classroom();
    room_list->add_element(new_room);

    if (room_list->add_element(new_room)) {
      std::cout << "THere was some problem room added 2 times" << std::endl;
    }
    room_list->add_element(new SecretarialOffice());
    room_list->add_element(new StaffRestRoom());

    for (auto iter : room_list->get_list()) {
      std::cout << "Room id: " << iter->get_id() << std::endl;
    }
    std::cout << std::endl;
    room_list->delete_element(new_room);
    for (auto iter : room_list->get_list()) {
      std::cout << "Room id: " << iter->get_id() << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
