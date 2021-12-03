-- Keep a log of any SQL queries you execute as you solve the mystery.

-- What we know:
-- the theft took place on July 28, 2020 and that it took place on Chamberlin Street.

-- Goal:
-- Who the thief is,
-- What city the thief escaped to, and
-- Who the thief’s accomplice is who helped them escape

-- List of Suspects:

-- Log of queires
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = "Chamberlin Street";
    -- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.

    -- Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

SELECT transcript FROM interviews
WHERE transcript LIKE "%courthouse%";
    -- I work at the courthouse, and I saw the hit-and-run on my way into work this morning.
    -- I saw him talking on the phone outside the courthouse at 3:00pm.

        SELECT * FROM phone_calls
        WHERE year = 2020 AND month = 7 AND day = 28;

        -- POSSIBLE phone numbers of thief
            -- As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.

                SELECT * FROM phone_calls
                WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60;

                -- POSIBLE phone numbers of the accomplice
                        -- The thief then asked the person on the other end of the phone to purchase the flight ticket.

                        SELECT receiver FROM phone_calls
                        WHERE caller = 'name of the thief'
                        AND year = 2020 AND month = 7 AND day = 28 AND duration < 60;


    -- Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
    -- If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

        SELECT * FROM courthouse_security_logs
        WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15;

        -- POSSIBLE license_plate of the thief

    -- I don't know the thief's name, but it was someone I recognized.
    -- Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

        SELECT * FROM atm_transactions
        WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = "Fifer Street" AND transaction_type = withdraw;

        -- POSSIBLE account number of the thief


    -- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.

        SELECT * FROM flights
        JOIN airports ON flights.origin_airport_id = airports.id
        WHERE city = "Fiftyville" AND year = 2020 AND month = 7 AND day = 29
        ORDER BY hour LIMIT 1;

        -- CONCLUSION: The accomplice booked the earliest flight from Fiftyville for the thief


                            --- CROSS LINK GATHERED EVIDENCE ---


-- Find the thief

-- 1. The thief drove away between 10:15 - 10:25 from courthouse

SELECT name FROM people
WHERE people.license_plate IN
(SELECT license_plate FROM courthouse_security_logs
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND minute > 15 AND minute < 25)

-- 2. The thief withdrew the money before the 10:15

INTERSECT
SELECT name FROM people
WHERE people.id IN
(SELECT person_id FROM bank_accounts
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND transaction_type = "withdraw"
AND atm_transactions.atm_location = "Fifer Street")

-- 3. The thief was taking on the phone at 3pm for less than a minute

INTERSECT
SELECT name FROM people
WHERE people.phone_number IN
(SELECT caller FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28
AND duration < 60)

-- 4. The thief had the earliest flight booked from fiftyville the next day

INTERSECT
SELECT name FROM people
WHERE people.passport_number IN
(SELECT passport_number FROM passengers
WHERE flight_id IN
(SELECT id FROM flights WHERE year = 2020 AND month = 7 AND day = 29
ORDER BY hour, minute ASC LIMIT 1));

                -------- ERNEST is the thief -------------


-- Find the city Ernest escaped to

-- 1. Ernest had the earliest flight booked the next day from Fiftyville

SELECT city FROM airports
WHERE id IN
(SELECT destination_airport_id FROM flights WHERE year = 2020 AND month = 7 AND day = 29
ORDER BY hour, minute ASC LIMIT 1);

                -------- ERNEST booked a flight to LONDON -------------


-- Get the accomplice's name

-- 1. Ernest called his accomplice on the day of theft to book the flight

SELECT name FROM people
WHERE phone_number IN
(SELECT receiver FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28
AND caller =
(SELECT phone_number FROM people WHERE name = "Ernest")
AND duration < 60);

                -------- BERTHOLD booked a flight for ERNEST -------------
