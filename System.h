#pragma once
#include <iostream>
#include <vector>
#include "Candidate.h"
#include "Province.h"
#include "Voter.h"
#include "System.h"

using namespace std;

#ifndef SYSTEM_H
#define SYSTEM_H

class System {
public:
	System();

private:
	vector <Candidate> candidates;
	vector <Province> provinces;
	vector <Voter> voters;

	//processes choice from main menu
	void process_main_option(int& option);

	//prints main menu
	void print_main_menu();

	void print_info_frame();

	void print_view_results_menu();

	void process_view_option(int option);

	//processes choice from vote options
	void process_vote_option(Candidate& can, Province& pr);

	void print_overall_results();

	void print_province_results();

	void print_cancel_vote();

	/*

	//adds voter to the vector
	void add_voter();

	//initializes members
	void init();

	//prints main menu
	void print_main_menu();

	//processes choice from main menu
	void process_main_option(int& option);

	//print names of all candidates
	void print_vote_options();

	//processes choice from vote options
	void process_vote_option(int& option);
	*/
};

#endif

