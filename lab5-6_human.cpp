#include "lab5-6_human.h"
#include <iostream>
#include <cstring>

//конструктор без параметров
Human::Human()
   :fullname("---"), gender("---"), race("---"), age(0), residence("---"), iq(0)
   {}

Human::Human(const char *fullname_, const char *gender_, const char *race_, unsigned int age_, const char *residence_, unsigned int iq_)
   {
   strncpy(fullname, fullname_, MAX_LENGTH); fullname[sizeof(fullname) - 1] = '\0';
   strncpy(gender, gender_, MAX_LENGTH); gender[sizeof(gender) - 1] = '\0';
   strncpy(race, race_, MAX_LENGTH); race[sizeof(race) - 1] = '\0';
   age = age_;
   strncpy(residence, residence_, MAX_LENGTH); residence[sizeof(residence) - 1] = '\0';
   iq = iq_;
   }

//конструктор копирования
Human::Human(const Human& other)
   {
   strncpy(fullname, other.fullname, MAX_LENGTH);
   strncpy(gender, other.gender, MAX_LENGTH);
   strncpy(race, other.race, MAX_LENGTH);
   age = other.age;
   strncpy(residence, other.residence, MAX_LENGTH);
   iq = other.iq;
   }

//деконструктор
Human::~Human()
   {}

//сеттеры
void Human::SetFullName(const char *fullname_)
{
   strncpy(fullname, fullname_, MAX_LENGTH); fullname[sizeof(fullname) - 1] = '\0';
}

void Human::SetGender(const char *gender_)
{
   strncpy(gender, gender_, MAX_LENGTH); gender[sizeof(gender) - 1] = '\0';
}

void Human::SetRace(const char *race_)
{
   strncpy(race, race_, MAX_LENGTH); race[sizeof(race) - 1] = '\0';
}

void Human::SetAge(unsigned int age_)
{
   age = age_;
}

void Human::SetResidence(const char *residence_)
{
   strncpy(residence, residence_, MAX_LENGTH); residence[sizeof(residence) - 1] = '\0';
}

void Human::SetIq(unsigned int iq_)
{
   iq = iq_;
}

//геттеры
const char *Human::GetFullName() const
{
   return fullname;
}

const char *Human::GetGender() const
{
   return gender;
}

const char *Human::GetRace() const
{
   return race;
}

unsigned int Human::GetAge() const
{
   return age;
}

const char *Human::GetResidence() const
{
   return residence;
}

unsigned int Human::GetIq() const
{
   return iq;  
}

//вывод в консоль
void Human::DisplayFullName() const
{
   std::cout << "Full name: " << fullname << '\n';
}

void Human::DisplayGender() const
{
   std::cout << "Gender: " << gender << '\n';
}

void Human::DisplayRace() const
{
   std::cout << "Race: " << race << '\n';
}

void Human::DisplayAge() const
{
   std::cout << "Age: " << age << '\n';
}

void Human::DisplayResidence() const 
{
   std::cout << "Residence: " << residence << '\n';
}

void Human::DisplayIq() const
{
   std::cout << "IQ: " << iq << '\n';
}

double Human::GetAverageIq(Human *humans, unsigned int size, const char *race)
{
   unsigned int count = 0, sum = 0;
   for (unsigned int current = 0; current < size; current++){
      if (!strncmp(humans[current].GetRace(), race, MAX_LENGTH)){
         sum += humans[current].GetIq();
         count++;
      }
   }return (count == 0 ? 0.0 : (double)sum / count);
}

double Human::GetAverageAge(Human *humans, unsigned int size, double iq)
{
   unsigned int count = 0, sum = 0;
   for (unsigned int current = 0; current < size; current++){
      if (humans[current].GetIq() > iq){
            sum += humans[current].GetAge();
            count++;
      }
   }return (count == 0 ? 0.0 : sum / count);
}