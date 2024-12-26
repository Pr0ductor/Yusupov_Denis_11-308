#pragma once

#include <memory>
#include <string>
#include <vector>

struct Seat {
    int row;
    int number;
    bool is_reserved = false;
};

struct Hall {
    int id;
    int rows;
    int seats_per_row;
    std::vector<Seat> seats;
};

struct Session {
    int id;
    std::string movie_title;
    Hall& hall;
};



Hall create_hall(int hall_id, int rows, int seats_per_row);
Session create_session(int session_id, const std::string& movie_title, Hall& hall);
bool reserve_seat(Session& session, int row, int seat_number);
bool cancel_reservation(Session& session, int row, int seat_number);
int get_available_seats(const Hall& hall);
void display_hall(const Hall& hall);