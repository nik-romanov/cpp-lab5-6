#include "lab5-6_countries.h"
#include <iostream>
#include <cstring>

//Конструктор
Countries::Countries(){
    size = 0;
    max_size = 1;
    spisok = new Element[max_size];
}

//Деструктор
Countries::~Countries(){
    delete[] spisok;
}

void Countries::AddElement(const char *residence, unsigned int iq){
   for (unsigned int index = 0; index < size; index++){
      if ( !strncmp(spisok[index].name, residence, MAX_LENGTH) ){
         spisok[index].sum_iq += iq;
         spisok[index].count++;
         spisok[index].average_iq = (double)spisok[index].sum_iq / spisok[index].count;
         return;
      }
   }
   if (size == max_size){
      max_size += 1;
      Element *newspisok = new Element[max_size];
      for (unsigned int count = 0; count < size; count++) {
         newspisok[count] = spisok[count];
      }delete[] spisok;
      spisok = newspisok;
   }
   strncpy(spisok[size].name, residence, MAX_LENGTH);
   spisok[size].sum_iq = iq;
   spisok[size].count = 1;
   spisok[size].average_iq = iq;
   size += 1;
}

unsigned int Countries::GetSize() const {
    return size;
}

Countries::Element *Countries::GetSpisok() const {
    return spisok;
}

void Countries::DisplaySpisok() const{
    for (unsigned int count = 1; count <= size; count++) {
        std::cout << count << "  " << spisok[count-1].name << "  " << spisok[count-1].average_iq << '\n';
    }
}

void Countries::SortSpisok(unsigned int start, unsigned int end) {
	if (start >= end)
		return;
   int pivot_position = Countries::partition(spisok, start, end);
	SortSpisok(start, pivot_position - 1);
	SortSpisok(pivot_position + 1, end);
}
