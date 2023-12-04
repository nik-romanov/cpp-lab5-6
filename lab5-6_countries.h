#ifndef LAB5_6_COUNTRIES
#define LAB5_6_COUNTRIES

class Countries
{
private:
    struct Element
    {
        char name[MAX_LENGTH];
        double sum_iq        ;
        unsigned int count   ;
        double average_iq    ;
    };
    
    static unsigned int partition(Element *array, unsigned int start, unsigned int end)
    {
	    double pivot = array[start].average_iq;
        int count = 0;
	    for (int index = start + 1; index <= end; index++) {
		    if (array[index].average_iq <= pivot){
			    count++;
            }
	    }
        int PivotIndex = start + count;
	    std::swap(array[PivotIndex], array[start]);
	    int index_start = start, index_end = end;
        while (index_start < PivotIndex and index_end > PivotIndex) {
            while (array[index_start].average_iq <= pivot) {
			    index_start++;

		    }while (array[index_end].average_iq > pivot) {
		    	index_end--;

		    }if (index_start < PivotIndex and index_end > PivotIndex) {
			    std::swap(array[index_start], array[index_end]);
		    }
	    }return PivotIndex;
    }

    unsigned int size    ;
    unsigned int max_size;
    Element *spisok      ;

public:
    Countries();

    ~Countries();

    void AddElement(const char *residence, unsigned int iq);

    unsigned int GetSize() const;

    Element *GetSpisok() const;

    void DisplaySpisok() const;

    void SortSpisok(unsigned int start, unsigned int end);
};

#endif