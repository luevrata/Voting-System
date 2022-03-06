#pragma once
#include <iostream>
#include <vector>
#include "Candidate.h"
#include "Province.h"
#include "Voter.h"

using namespace std;

#ifndef VOTER_H
#define VOTER_H

class Voter {
public:

	//constructs voter with candidate and province and id num
	Voter(Candidate& c, Province& p, int idnum);


	void set_id(int idnum);
	int get_id();
	Candidate* get_candidate();
	Province* get_province();
	Candidate candidate;
	Province province;



private:
	
	int id;
};

#endif

