#include "Candidate.h"

Candidate::Candidate()
{
	num_votes = 0;
	name = "";
}

Candidate::Candidate(string new_name)
{
	num_votes = 0;
	name = new_name;
}

void Candidate::inc_votes()
{
	num_votes++;

}
void Candidate::dec_votes()
{
	num_votes--;
}
//

string Candidate::get_name()
{
	return name;
}

int Candidate::get_votes()
{
	return num_votes;
}

//can you hear me??
