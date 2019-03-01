#include "data.h"
Data::Data(const Data *copy) {
	this->cNumber = copy->cNumber;
	this->sTime = copy->sTime;
	this->tTime = copy->tTime;
}
Data::Data(int _cNumber, int _sTime, int _tTime) {
	this->cNumber = _cNumber;
	this->sTime = _sTime;
	this->tTime = _tTime;
}
int Data::getCNumber() const{
	return this->cNumber;
}
int Data::getSTime() const{
	return this->sTime;
}
int Data::getTTime() const{
	return this->tTime;
}
void Data::setCNumber(int num) {
	this->cNumber = num;
}
void Data::setSTime(int time) {
	this->sTime = time;
}
void Data::setTTime(int time) {
	this->tTime = time;
}

ostream &operator<<(ostream &lhs, const Data &rhs) {
	lhs << "Customer Number: " << rhs.getCNumber() << "\nService Time: " << rhs.getSTime() << " mins\nTotal Time: " << rhs.getTTime() << " mins" << std::endl;
	return lhs
}