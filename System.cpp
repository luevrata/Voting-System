#include "system.h"
#include <vector>

// This source file has a header file

System::System() {

	candidates.push_back(Candidate("Barack Obama"));
	candidates.push_back(Candidate("Angela Merkel"));
	candidates.push_back(Candidate("Ellen Johnson"));
	candidates.push_back(Candidate("Justin Trudeau"));


	provinces.push_back(Province("ON", candidates));
	provinces.push_back(Province("QC", candidates));
	provinces.push_back(Province("NS", candidates));
	provinces.push_back(Province("NB", candidates));
	provinces.push_back(Province("MB", candidates));
	provinces.push_back(Province("BC", candidates));
	provinces.push_back(Province("PE", candidates));
	provinces.push_back(Province("SK", candidates));
	provinces.push_back(Province("AB", candidates));
	provinces.push_back(Province("NL", candidates));



	print_main_menu();
}

void System::process_main_option(int& option)
{
	switch (option)
	{
	case 1: {
		print_info_frame();
	}; break;
	case 2: {
		print_view_results_menu();
	}; break;
	case 3: {
		print_cancel_vote();
	}; break;
	case 0: {
		exit(0);
	}; break;
	default: {
		printf("\n Error: Wrong Choice");
		print_main_menu();
	}

	}
}

void System::print_main_menu()
{
	printf("\n\n Please Choose One of the Options below:\n");
	printf("\n 1. Vote");
	printf("\n 2. View results");
	printf("\n 3. Cancel your vote");
	printf("\n 0. Exit\n");

	int choice;

	scanf_s("%d", &choice);

	process_main_option(choice);
}
void System::print_info_frame()
{

	int id;
	int province_choice;
	int candidate_choice;

	printf("\n Enter your id:\n");

	scanf_s("%d", &id);

	bool exists = false;

	for (Voter v : voters) {
		if (id == v.get_id()) {
			printf("\n You have already made your choice\n");

			exists = true;
		}
	}

	if (!exists) {
		printf("\n Chose your province:\n");

		for (int i = 0; i < provinces.size(); i++) {

			printf(" %d. %s\n", i + 1, provinces[i].get_name().c_str());

		}


		scanf_s("%d", &province_choice);
		//Province pr = provinces[province_choice - 1];

		printf("\n Chose your candidate:\n");

		for (int i = 0; i < candidates.size(); i++) {

			printf(" %d. %s\n", i + 1, candidates[i].get_name().c_str());

		}

		scanf_s("%d", &candidate_choice);
		//Candidate can = candidates[candidate_choice - 1];

		voters.push_back(Voter(candidates[candidate_choice - 1], provinces[province_choice - 1], id));

		process_vote_option(candidates[candidate_choice - 1], provinces[province_choice - 1]);

		printf("\n Your choice is made!\n");

		print_main_menu();

	}
	else {

		print_main_menu();
	}
}

void System::print_view_results_menu()
{
	printf("\n\n Please Choose One of the Options below:\n");
	printf("\n 1. View overall results");
	printf("\n 2. View results by province\n");

	int choice;

	scanf_s("%d", &choice);

	process_view_option(choice);

}

void System::process_view_option(int option)
{
	switch (option)
	{
	case 1: {
		print_overall_results();
	}; break;
	case 2: {
		print_province_results();
	}; break;
	default: {
		printf("\n Error: Wrong Choice");
		print_main_menu();
	}

	}

}

void System::process_vote_option(Candidate& can, Province& pr)
{
	can.inc_votes();
	pr.increment_votes(can.get_name());
}

void System::print_overall_results()
{

	for (int i = 0; i < candidates.size(); i++) {

		double percentage = (double) candidates[i].get_votes() / voters.size() * 100;
		printf(" %s : %.0lf %%\n", candidates[i].get_name().c_str(), percentage);

	}

	print_main_menu();
}

void System::print_province_results()
{
	for (int i = 0; i < provinces.size(); i++) {

		printf("\n %s \n", provinces[i].get_name().c_str());
		for (auto& key_value : provinces[i].results) {
			double percentage = (double) key_value.second / voters.size() * 100;
			printf(" %s: %.0lf %%\n", key_value.first.c_str(), percentage);
		}

	}

	print_main_menu();
}

void System::print_cancel_vote()
{
	int id;

	printf("\n Enter your id:\n");

	scanf_s("%d", &id);

	bool id_exist=false;

	int ix;

	for (int i = 0; i < voters.size(); i++) {
		if (id == voters[i].get_id()) {
			//printf("*");
			
			for (Candidate& c : candidates) {
				if (voters[i].candidate.get_name() == c.get_name()) {
					c.dec_votes();
				}
			}
			//printf("*");
			for (Province& v : provinces) {
				if (voters[i].province.get_name() == v.get_name()) {
					v.decrement_votes(voters[i].candidate.get_name());
				}
			}
		
			ix = i;
			id_exist = true;
		}
	}

	if (id_exist) {

		voters.erase(voters.begin() + ix);

		printf("\n Your vote has been cancelled:\n");

		print_main_menu();
	} else {
		printf("\n The user with this id has not been registered:\n");

		print_main_menu();
	}


}






