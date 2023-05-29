#include "ticket_receipt_data.h"
#include <iostream>

TicketReceiptData::TicketReceiptData()
{
    this->totalAmount = "";
    this->unitAmount = "";
    this->despachador_name ="";
    this->printing_datetime ="";
    this->quantity = "0";
    this->ticket_name = "Default Ticket";
    this->title_header = "";
}

TicketReceiptData::TicketReceiptData(std::string totalAmount, std::string unitAmount, std::string quantity, std::string title_header, std::string ticket_name, std::string printing_datetime, std::string despachador_name)
{
    this->totalAmount = totalAmount;
    this->unitAmount = unitAmount;
    this->despachador_name = despachador_name;
    this->printing_datetime = printing_datetime;
    this->quantity = quantity;
    this->ticket_name = ticket_name;
    this->title_header = title_header;
}

void TicketReceiptData::print(void)
{
    std::cout << this->totalAmount<< ",";
    std::cout << this->unitAmount << ",";
    std::cout << this->quantity << ",";
    std::cout << this->title_header << ",";
    std::cout << this->ticket_name << ",";
    std::cout << this->printing_datetime << ",";
    std::cout << this->despachador_name << std::endl;
}