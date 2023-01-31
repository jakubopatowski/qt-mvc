#pragma once

#include <string>
#include <vector>

class PersonalInfo
{
  public:
    int id;
    std::string name;
    std::string surname;
    int age;

  public:
    static std::vector< PersonalInfo > getSomePersonalInfo();
};
