#pragma once
#include<iostream>
#include<list>

using namespace std;

struct Page {


	int time; //��������� ����� �������������
	bool R; // ��� R
	bool M; // ��� M
	Page(int _time, bool _R, bool _M) : time(_time), R(_R), M(_M) {};

	void writeToDisk() { cout << "was written" << endl; }
};

class PageRing {

	bool all_Pages_Havent_changed();
	void displace_First_Unchanged_Page(Page& page);

	const int max = 4;
	const int t = 10;
	list<Page> pageList;
	int currentTime = 0;
	int times[4] = { 0 };
	int count = 0;

public:
	void addPage();
	void print();
};


bool PageRing::all_Pages_Havent_changed() {

	auto iter = pageList.begin();
	int countPlan = 0;

	while (iter != pageList.end()) {

		if ((*iter).M == 1)
			countPlan++;
		iter++;
	}

	return countPlan == max;

}

void PageRing:: displace_First_Unchanged_Page( Page& page) {

	auto iter = pageList.begin();

	while (iter != pageList.end()) {

		if ((*iter).M == 0) {
			(*iter) = page;
			return;
		}


	}

}

void PageRing::addPage() {

	Page page(0, 0, 0);
	int time; 
	bool _R, _M;
	count++;

	cout << "Enter last usage time" << endl;
	do {

		cin >> time;

		for (int i = 0; i < count; i++)
			if (time < times[i]) {
				cout << "incorrect time, last time one of other page more than that" << endl;
				time = -1;
				continue;
			}
		if (time <= 0)
			cout << "incorrect data" << endl;
		
	} while (time <= 0);
	
	cout << "Enter R " << endl;
	
		cin >> _R;
		
	cout << "Enter M" << endl;
	
	cin >> _M;

	page.time = time;
	page.R = _R;
	page.M = _M;
	times[count] = time;

	currentTime = time;

	if (count <= 4) {

		pageList.push_back(page);
		return;
	}
	
	else {

		auto arrow = pageList.begin();
		bool wasCircle = false;
		bool wasPlannedWriteToDisk = false;

		while (true) {

			if (arrow == pageList.end()) {
				arrow = pageList.begin();
				wasCircle = true;
			}

			if (((*arrow).R == 0) && ((*arrow).M == 0) && ((currentTime - (*arrow).time) > t)) {
				(*arrow) = page;
				break;
			}

			else if (((*arrow).R == 0) && ((*arrow).M == 0) && ((currentTime - (*arrow).time) > t)) {
				(*arrow).M = 0;
				arrow++;
				wasPlannedWriteToDisk = true;
				continue;
			}
			else if ((*arrow).R == 1) {
				(*arrow).R = 0;
				arrow++;
				continue;
			}

			if (wasCircle) {

				if (wasPlannedWriteToDisk) {
					wasCircle = false;
					continue;
				}
				else {
					if (all_Pages_Havent_changed()) {
						arrow->writeToDisk();
						(*arrow) = page;
						break;
					}
					else {

						displace_First_Unchanged_Page(page);
						break;

					}
				}


			}

		}

	}

	count = 4;
}

void PageRing::print() {

	auto iter = pageList.begin();

	while (iter!=pageList.end())
	{

		cout << "Time " << iter->time << endl << "R = " << iter->R << endl << "M = " << iter->M << endl;

	}


}