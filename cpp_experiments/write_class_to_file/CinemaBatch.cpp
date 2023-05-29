#include "CinemaBatch.h"
#include <fstream>
#include <iostream>

CinemaBatchSingleton* CinemaBatchSingleton::singleton_= nullptr;

CinemaBatchSingleton::CinemaBatchSingleton()
{
    ;
}

CinemaBatchSingleton *CinemaBatchSingleton::GetInstance()
{
    if(singleton_==nullptr){
        singleton_ = new CinemaBatchSingleton();
    }
    return singleton_;
}

/// @brief Write Ticket Data to batch file.
/// @param trd 
int CinemaBatchSingleton::WriteToBatch(TicketReceiptData trd)
{
    std::ofstream out(CINEMA_BATCH_FILE, std::ios_base::app);
    std::cout << "Received new TRD write request:" << std::endl;
    trd.print();
    if( !out ){
        std::cout << "Error opening output file";
        return 1;
    }
    out << trd;
    out.close();
    return 0; 
}

int CinemaBatchSingleton::DeleteBatch()
{
    std::remove(CINEMA_BATCH_FILE);
    return 0;
}


/// @brief Read batch data into a vector of TicketReceiptData
/// @param vTrd 
/// @return 0 if everything ok, 1 otherwise
std::vector<TicketReceiptData> CinemaBatchSingleton::ReadFromBatch()
{
    std::ifstream in(CINEMA_BATCH_FILE);
    std::vector<TicketReceiptData> vTrd;
    if (!in){
        return vTrd;
    }
    TicketReceiptData trd;
    while( in >> trd ){
        vTrd.push_back(trd);
    }
    in.close();
    return vTrd;
}

std::istream &operator>>(std::istream &in, TicketReceiptData &trd)
{
    const char comma = ',';
    std::getline(in, trd.totalAmount, comma);
    std::getline(in, trd.unitAmount, comma);
    std::getline(in, trd.quantity, comma);
    std::getline(in, trd.title_header, comma);
    std::getline(in, trd.ticket_name, comma);
    std::getline(in, trd.printing_datetime, comma);
    std::getline(in, trd.despachador_name, '\n');
    return in;
}

std::ostream &operator<<(std::ostream &os, const TicketReceiptData &trd)
{
    os << trd.totalAmount << "," << trd.unitAmount << "," << trd.quantity << "," << trd.title_header << "," << trd.ticket_name << "," << trd.printing_datetime << "," <<  trd.despachador_name << "\n";
    return os;
}
