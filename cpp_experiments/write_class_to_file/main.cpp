// C++ program to demonstrate read/write of class
// objects in C++.
#include <iostream>
#include <fstream>
#include "ticket_receipt_data.h"
#include "CinemaBatch.h"
int main()
{

	// Creating object of the class
	TicketReceiptData trd;
	trd.despachador_name = "DAVID MERINOS";
	trd.printing_datetime = "30-04-2023 08:42";
	trd.quantity = "2";
	trd.title_header = "BOLETO CINE";
	trd.totalAmount = "86.00";
	trd.unitAmount = "43.00";

	TicketReceiptData trd2;
	trd2.despachador_name = "EDUARDO MERINOS";
	trd2.printing_datetime = "22-03-1993 08:42";
	trd2.quantity = "1";
	trd2.title_header = "BOLETO CINE 2";
	trd2.totalAmount = "52.00";
	trd2.unitAmount = "43.00";

	CinemaBatchSingleton * cinemaBatch = CinemaBatchSingleton::GetInstance();
	cinemaBatch->DeleteBatch();
	cinemaBatch->WriteToBatch(trd);
	cinemaBatch->WriteToBatch(trd2);

	std::vector<TicketReceiptData> vtrd;
	vtrd = cinemaBatch->ReadFromBatch();
	std::cout << "Read " << vtrd.size() << " entries.\n";
	for(auto & i : vtrd){
		i.print();
		std::cout << std::endl;
	}
	return 0;
}
