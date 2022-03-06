#pragma once
#include <iostream>
#include<string>


using namespace std;

#ifndef CANDIDATE_H
#define CANDIDATE_H

class Candidate
	//hfhf
{
public:
	//int num_votes;
	Candidate();
	Candidate(string name);
	void inc_votes();
	void dec_votes();
	string get_name();
	int get_votes();
	

private:
	int num_votes;
	string name;
};
#endif

