#include <iostream>
#include "lab5-6_human.cpp"
#include "lab5-6_countries.cpp"

using namespace std;

int main(){

   Countries Statistics;
   const char *race = "Negroid";
   unsigned int iq = 100;

   Human humans[] = 
   {
   Human("Teresa", "Female", "Negroid", 25, "Japan", 123),
   Human("Marie", "Female", "Mongoloid", 18, "Russia", 71),
   Human("Christian", "Male", "Capoid", 41, "Australia", 170),
   Human("Jack", "Male", "Negroid", 20, "Great Britain", 96),
   Human("Amely", "Female", "Capoid", 15, "Sri Lanka", 130),
   Human("Patrick", "Male", "Australoid", 30, "Russia", 1),
   };

   unsigned int number_of_humans = sizeof(humans) / sizeof(Human);
   
   for (unsigned int index = 0; index < number_of_humans; index++){
      Statistics.AddElement(humans[index].GetResidence(), humans[index].GetIq());
   }Statistics.SortSpisok(0, Statistics.GetSize()-1);

   cout << "A list of countries sorted in accordance to an average IQ:" << '\n';
   Statistics.DisplaySpisok();
   cout << '\n';
   
   cout << "IQ of an average " << race << ": " << Human::GetAverageIq(humans, number_of_humans, race) << '\n' << '\n';
   cout << "An average age of people with IQ over " << iq << ": " << Human::GetAverageAge(humans, number_of_humans, iq) << '\n' << '\n';

   return 0;
}