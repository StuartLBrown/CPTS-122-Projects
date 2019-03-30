#include <iostream>
#include <vector>
#include <time.h>
#pragma once
using std::vector;
template <class T>
class MergeSort {
private:
	vector<T> list;
	vector<T> sort(vector<T> &_list, int left, int right);
	void merge(vector<T> &_list, int left, int middle, int right);
	void swap(vector<T> &_list, int left, int right) {
		T temp = _list[left];
		_list[left] = _list[right];
		_list[right] = temp;
	}
public:
	MergeSort(vector<T> _list) {
		list = _list;
	}
	vector<T> getList() { return list; }
	void setList(vector<T> newList) {
		if (newList.size() > 0)
			list = newList;
	}
	bool inOrder() {
		T prev = list[0];
		for (int i = 1; i < list.size(); i++) {
			if (prev > list[i])
				return false;
		}
		return true;
	}
	bool inOrder(vector<T> _list) {
		T prev = _list[0];
		for (int i = 1; i < _list.size(); i++) {
			if (prev > _list[i])
				return false;
		}
		return true;
	}
	bool inOrder(vector<T> _list, int left, int right) {
		T prev = _list[left];
		for (int i = left + 1; i < right; i++) {
			if (prev > _list[i])
				return false;
		}
		return true;
	}
	int getSize() { return this->list.size(); }
	void sort() { sort(this->list, 0, this->list.size()); }
};

template <class T>
vector<T> MergeSort<T>::sort(vector<T> &_list, int left, int right) {
	if (right-left==1)
		return _list;
	else if(right-left==2){
		swap(_list, left, right-1);
		return _list;
	}
	else {
		//going down the left then right side
		sort(_list, left, (right + left) / 2);
		sort(_list, (right + left) / 2, right);
		merge(_list, left, (right + left) / 2, right);
		return _list;
	}
}
//using a modified bubble sort algorithm (most efficient way to sort)
template <class T>
void MergeSort<T>::merge(vector<T> &_list, int left, int middle, int right) {
	int j = 0;
	T iVal;
	for (int i = middle; i < right; i++) {
		iVal = _list[i];
		j = i - 1;
		while (j >= left&&_list[j] > iVal) {
			_list[j + 1] = _list[j];
			j--;
		}
		_list[j + 1] = iVal;
	}
}