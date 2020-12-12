
#include"WSClockPageReplacment.h"

using namespace std;


int main(void) {



PageRing pagering;

	for (int i = 0; i < 4; i++)
		pagering.addPage();
	
	pagering.addPage();
	cout << endl;
	pagering.print();

	return 0;
}
