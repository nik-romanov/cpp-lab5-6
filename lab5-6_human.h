#ifndef LAB5_6_HUMAN
#define LAB5_6_HUMAN
#define MAX_LENGTH 30
//#include <iostream>
class Human
{
   private:
      char fullname[MAX_LENGTH] ;
      char gender[MAX_LENGTH]   ;
      char race[MAX_LENGTH]     ;
      unsigned int age          ;
      char residence[MAX_LENGTH];
      unsigned int iq           ;
      // char *fullname  ;
      // char *gender    ;
      // char *race      ;
      // unsigned int age;
      // char *residence ;
      // unsigned int iq ;

   public:
      Human();

      Human(const char *fullname, const char *gender, const char *race, unsigned int age, const char *residence, unsigned int iq);

      Human(const Human& other);

      ~Human();
      
   
      void SetFullName(const char *fullname);

      void SetGender(const char *gender);

      void SetRace(const char *race);

      void SetAge(unsigned int age);

      void SetResidence(const char *residence);

      void SetIq(unsigned int iq);


      const char *GetFullName() const;

      const char *GetGender() const;

      const char *GetRace() const;

      unsigned int GetAge() const;

      const char *GetResidence() const;

      unsigned int GetIq() const;


      void DisplayFullName() const;

      void DisplayGender() const;

      void DisplayRace() const;

      void DisplayAge() const;

      void DisplayResidence() const;

      void DisplayIq() const;


      static double GetAverageIq(Human *humans, unsigned int size, const char *race_);

      static double GetAverageAge(Human *humans, unsigned int size, double number);

   //friend std::ostream& operator << (std::ostream& out, const Human& human);
};

#endif