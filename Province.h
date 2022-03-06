#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "Candidate.h"

using namespace std;

#ifndef PROVINCE_H
#define PROVINCE_H

class Province {

public:

	//return name of province
	string get_name();

	Province();
	Province(string n);
	//increment vote for a particular candidate
	void increment_votes(string c);
	void decrement_votes(string c);


	//sets up the name of province and constructs map where keys are candidates (from given vector) and values are set to 0
	Province(string nam, vector<Candidate>& cand);

	//return candidate with biggest number of votes
	string get_result();

	//map candidate-number of votes
	map <string, unsigned int> results;



private:

	

	//name of province
	string name;

};

#endif

