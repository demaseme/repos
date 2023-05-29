#ifndef __TICKET_RECEIPT_DATA_H
#define __TICKET_RECEIPT_DATA_H


#include <string> 
#include <time.h>

class TicketReceiptData {
    public: 
        std::string totalAmount;
        std::string unitAmount;
        std::string quantity;
        std::string title_header;
        std::string ticket_name;
        std::string printing_datetime;
        std::string despachador_name;
        TicketReceiptData(void);
        TicketReceiptData(  std::string totalAmount,
                            std::string unitAmount,
                            std::string quantity,
                            std::string title_header,
                            std::string ticket_name,
                            std::string printing_datetime,
                            std::string despachador_name);
        void print(void);
};

#endif