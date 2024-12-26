#include <hw06.h>
#include <gtest/gtest.h>

TEST(Hw06Tests, Test1)
{
    auto rows = 5, seats_per_row = 8;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Die Hard", hall);

    auto avail_seats = get_available_seats(hall);
    auto expected_seats = rows * seats_per_row;
    EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test2)
{
  auto rows = 5, seats_per_row = 15;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 2 seats
  auto reserved_seats = 2;
  reserve_seat(session, 1, 3);
  reserve_seat(session, 2, 5);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row - reserved_seats;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test3)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 1 seat
  reserve_seat(session, 1, 3);
  cancel_reservation(session, 1, 3);

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test4)
{
  auto rows = 3, seats_per_row = 5;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // reserve 1 seat
  reserve_seat(session, 1, 3);
  auto reserve_stat = reserve_seat(session, 1, 3);
  auto expected_stat = false;
  EXPECT_EQ(expected_stat, reserve_stat);
}

TEST(Hw06Tests, Test5) // все места можно зарезервировать
{
    auto rows = 3, seats_per_row = 3;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Die Hard", hall);

    // Reserve all seats
    for (int row = 0; row < rows; ++row) {
      for (int seat_number = 0; seat_number < seats_per_row; ++seat_number) {
        EXPECT_TRUE(reserve_seat(session, row, seat_number));
      }
    }

    auto avail_seats = get_available_seats(hall);
    auto expected_seats = 0;
    EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test76) // проверка на несуществующие места(зарезервировать)
{
    auto rows = 3, seats_per_row = 3;
    Hall hall = create_hall(1, rows, seats_per_row);
    Session session = create_session(1, "Die Hard", hall);

    // Try to reserve a non-existent seat
    auto reserve_stat = reserve_seat(session, 5, 5);
    auto expected_stat = false;
    EXPECT_EQ(expected_stat, reserve_stat);
}

TEST(Hw06Tests, Test7) // места могут быть зарезервированы и отменены
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  int row = 1, seat_number = 1;

  // Reserve and cancel the same seat multiple times
  for (int i = 0; i < 5; ++i) {
    EXPECT_TRUE(reserve_seat(session, row, seat_number));
    EXPECT_TRUE(cancel_reservation(session, row, seat_number));
  }

  auto avail_seats = get_available_seats(hall);
  auto expected_seats = rows * seats_per_row;
  EXPECT_EQ(expected_seats, avail_seats);
}

TEST(Hw06Tests, Test8) // проверка на несуществующие места(отмена резервации)
{
  auto rows = 3, seats_per_row = 3;
  Hall hall = create_hall(1, rows, seats_per_row);
  Session session = create_session(1, "Die Hard", hall);

  // Try to cancel reservation of a non-existent seat
  auto cancel_stat = cancel_reservation(session, 5, 5);
  auto expected_stat = false;
  EXPECT_EQ(expected_stat, cancel_stat);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
