#include<iostream>
#include<list>
#include"WSClockPageReplacment.h"

using namespace std;



//#define MAXCOUNT 8
//#define t 50
//
//struct Page {
//
//
//	int time; //последнее время использования
//	bool R; // Бит R
//	bool M; // Бит M
//	bool wasPlanToWriteToDisk = false;
//	Page(int _time, bool _R, bool _M) : time(_time), R(_R), M(_M) {};
//
//	void writeToDisk() { cout << "was written" << endl; }
//};
//
//int currentTime = 0;
//int countIn = 0;
//
//bool all_Pages_Havent_changed(const list<Page>& pageList) {
//
//	auto iter = pageList.begin();
//	int countPlan = 0;
//
//	while (iter != pageList.end()) {
//
//		if ((*iter).M == 1)
//			countPlan++;
//		iter++;
//	}
//
//	return countPlan == MAXCOUNT;
//
//}
//
//void displace_First_Unchanged_Page(list<Page>& pageList, Page &page) {
//
//	auto iter = pageList.begin();
//
//	while (iter != pageList.end()) {
//
//		if ((*iter).M == 0) {
//			(*iter) = page;
//			return;
//		}
//			
//
//	}
//
//}

int main(void) {


	//list<Page> pageList;
	//
	//pageList.push_back(Page(2014, 1, 0));
	//pageList.push_back(Page(1213, 0, 0));
	//pageList.push_back(Page(1980, 1, 0));
	//pageList.push_back(Page(2003, 1, 0));
	//pageList.push_back(Page(2084, 1, 0));
	//pageList.push_back(Page(1620, 0, 0));
	//pageList.push_back(Page(2032, 1, 0));
	//pageList.push_back(Page(2020, 1, 0));
	//
	//countIn = MAXCOUNT;


	//currentTime = 2204;

	//auto arrow = pageList.begin();
	//auto begin = pageList.begin();
	//bool wasCircle = false;
	//bool wasPlannedWriteToDisk = false;
	//
	//
	//Page newpage(2204, 1, 0);
	//countIn++;
	//// 
	//	while (true) {

	//		if (arrow == pageList.end()) {
	//			arrow = pageList.begin();
	//			wasCircle = true;
	//		}

	//		if (countIn > MAXCOUNT) {

	//			if (((*arrow).R == 0) && ((*arrow).M == 0) && ((currentTime - (*arrow).time) > t)) {
	//				(*arrow) = newpage;
	//				break;
	//			}

	//			else if (((*arrow).R == 0) && ((*arrow).M == 0) && ((currentTime - (*arrow).time) > t)) {
	//				(*arrow).wasPlanToWriteToDisk = true;
	//				arrow++;
	//				wasPlannedWriteToDisk = true;
	//				continue;
	//			}
	//			else if ((*arrow).R == 1) {
	//				(*arrow).R = 0;
	//				arrow++;
	//				continue;
	//			}

	//			else if (arrow->wasPlanToWriteToDisk) {

	//				if (rand() % 3 == 2) {
	//					arrow->M = 0;
	//					arrow->wasPlanToWriteToDisk = false;
	//				}
	//			}

	//		}
	//	
	//		if (wasCircle) {

	//			if (wasPlannedWriteToDisk) {
	//				wasCircle = false;
	//				continue;
	//			}
	//			else {
	//				if (all_Pages_Havent_changed(pageList)) {
	//					arrow->writeToDisk();
	//					(*arrow) = newpage;
	//					break;
	//				}
	//				else {
	//				
	//					displace_First_Unchanged_Page(pageList, newpage);
	//					break;
	//				
	//				}
	//			}

	//		}


	//	}

	//auto iter = pageList.begin();

	//while (iter!=pageList.end())
	//{

	//	cout << "  " << iter->time << endl;

	//	iter++;
	//}

	PageRing pagering;

	for (int i = 0; i < 4; i++)
	pagering.addPage();

	pagering.addPage();

	return 0;
}