#ifndef __CINEMA_BATCH_H
#define __CINEMA_BATCH_H

#include<string>
#include "ticket_receipt_data.h"
#include<vector>

#define CINEMA_BATCH_FILE "cinema.dat"

class CinemaBatchSingleton
{
    protected:
        CinemaBatchSingleton();
        static CinemaBatchSingleton* singleton_;

    public:

        CinemaBatchSingleton(CinemaBatchSingleton &other) = delete;

        void operator=(const CinemaBatchSingleton &) = delete;

        static CinemaBatchSingleton *GetInstance();

        int WriteToBatch(TicketReceiptData trd);
        std::vector<TicketReceiptData> ReadFromBatch();
        int DeleteBatch();
};
        std::istream& operator>>(std::istream& is, TicketReceiptData& trd);
        std::ostream& operator<<(std::ostream& os, const TicketReceiptData& trd);
#endif