#include <iostream>
using std::ostream;
class Data {
private:
	int cNumber;//customer number
	int sTime;//service time
	int tTime;//total time
public:
	Data(const Data *copy);
	Data(int _cNumber, int _sTime, int _tTime);
	int getCNumber() const;
	int getSTime() const;
	int getTTime() const;
	void setCNumber(int num);
	void setSTime(int time);
	void setTTime(int time);
};
ostream &operator<<(ostream &lhs, const Data &rhs);