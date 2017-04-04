#ifndef _PARENTS_H_
#define _PARENTS_H_
#include"People.h"
class Parents :virtual public People {
public:
	Parents(char *, int);
	~Parents();
private:
	const int m_idea;
};
#endif