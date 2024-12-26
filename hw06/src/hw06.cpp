#include <hw06.h>
#include <iostream>

Hall create_hall(int id, int rows, int seats_per_row) {
  Hall hall;
  hall.id = id;
  hall.rows = rows;
  hall.seats_per_row = seats_per_row;

  for (int row = 0; row < rows; ++row) {
    for (int seat_number = 0; seat_number < seats_per_row; ++seat_number) {
      hall.seats.push_back({row, seat_number, false});
    }
  }

  return hall;
}

Session create_session(int id, const std::string &movie_title, Hall &hall) {

  return {id, movie_title, hall};
}


bool reserve_seat(Session& session, int row, int seat_number) {
  for (Seat& seat : session.hall.seats) {
    if (seat.row == row && seat.number == seat_number) {
      if (!seat.is_reserved) {
        seat.is_reserved = true;
        return true;
      }

      else {
        return false;
      }
    }
  }

  return false;
}

bool cancel_reservation(Session& session, int row, int seat_number) {
  for (Seat& seat : session.hall.seats) {
    if (seat.row == row && seat.number == seat_number) {
      if (seat.is_reserved) {
        seat.is_reserved = false;

        return true;
      }

      else {
        return false;
      }
    }
  }

  return false;
}

int get_available_seats(const Hall& hall) {
  int available_seats = 0;

  for (const Seat& seat : hall.seats) {
    if (!seat.is_reserved) {
      ++available_seats;
    }
  }

  return available_seats;
}

void display_hall(const Hall& hall) {
  std::cout << get_available_seats(hall) << std::endl;
}