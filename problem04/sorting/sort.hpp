#ifndef _SORT_HPP
#define _SORT_HPP

#include "list.hpp"

template<typename T> List<T> sort(List<T> list)
{
	int last1 = list.getLength()-1;
	quicksort(list,0,last1);
	return list;
}

template<typename T> void quicksort(List<T>& list, int first, int last)
{
	if(first < last){
		int pivpos = first;
		T pivot = list.getEntry(first);
		for(int i = first+1; i <= last; i++){
			T holder = list.getEntry(i);
			if(pivot > holder){
				list.remove(i);
				list.insert(first,holder);
				pivpos += 1;
			}

		}
		quicksort(list,first,pivpos);
		if(pivpos != last){
			quicksort(list,pivpos + 1,last);
		}

	}
}

#endif
