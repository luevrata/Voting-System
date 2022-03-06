#include "Province.h"


Province::Province(string nam, vector<Candidate>& cand)
{
	name = nam;

	for (int i = 0; i < cand.size(); i++) {
		results[cand[i].get_name()] = 0;
	}
}




string Province::get_result()
{
	int result = 0;
	string winner="no votes";

	for (auto& key_value : results) {
		if (key_value.second > result) {
			result = key_value.second;
			winner = key_value.first;
		}
	}


	return winner;
}




void Province::increment_votes(string c)
{
	auto lookup = results.find(c);
	lookup->second += 1;
}

void Province::decrement_votes(string c)
{
	auto lookup = results.find(c);
	lookup->second -= 1;
}



string Province::get_name()
{
	return name;
}

Province::Province()
{
	name = "";
}

Province::Province(string nam)
{
	name = nam;
}