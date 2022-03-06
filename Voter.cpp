#include "Voter.h"


Voter::Voter(Candidate& c, Province& p, int idnum)
{
	province = p;
	candidate = c;
	id = idnum;

}
void Voter::set_id(int idnum)
{
	id = idnum;

}

int Voter::get_id()
{
	return id;
}

Candidate* Voter::get_candidate()
{
	return &candidate;
}

Province* Voter::get_province()
{
	return &province;
}
