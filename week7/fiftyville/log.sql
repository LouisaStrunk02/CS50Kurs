-- get a description of the theft
SELECT description 
FROM crime_scene_reports 
WHERE year = 2021 
AND month = 7 
AND day = 28 
AND street = "Humphrey Street";
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

-- get information from the witnesses
SELECT name, transcript 
FROM interviews 
WHERE year = 2021 
AND month = 7 
AND day = 28
AND transcript 
LIKE "%bakery%";
--Ruth: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
--Eugene: I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emmas bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
--Raymond: As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- checking who exits the bakery between 10:15 and 10:25
SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
FROM people
JOIN bakery_security_logs
ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.year = 2021
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.activity = 'exit'
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25
ORDER BY bakery_security_logs.minute;
-- Vanessa|10|16
-- Bruce|10|18
-- Barry|10|18
-- Luca|10|19
-- Sofia|10|20
-- Iman|10|21
-- Diana|10|23
-- Kelsey|10|23

--checking who made a withdrawal on leggett street that day
SELECT name, atm_transactions.amount
FROM people 
JOIN bank_accounts
ON people.id = bank_accounts.person_id
JOIN atm_transactions
ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2021 
AND atm_transactions.month = 7 
AND atm_transactions.day = 28 
AND atm_transactions.atm_location = "Leggett Street" 
AND atm_transactions.transaction_type = "withdraw";
--Bruce|50
--Diana|35
--Brooke|80
--Kenny|20
--Iman|20
--Luca|48
--Taylor|60
--Benista|30


--select the earliest flight next day 
SELECT destination_airport_id, hour, minute
FROM flights 
JOIN airports 
ON origin_airport_id = airports.id 
WHERE airports.city = "Fiftyville" 
AND year = 2021 
AND month = 7 
AND day = 29
ORDER BY hour, minute
LIMIT 1;
--4|8|20

--checking who was in this flight
SELECT passengers.flight_id, name, passengers.passport_number, passengers.seat
FROM people
JOIN passengers
ON people.passport_number = passengers.passport_number
JOIN flights
ON passengers.flight_id = flights.id
WHERE flights.year = 2021
AND flights.month = 7
AND flights.day = 29
AND flights.hour = 8
AND flights.minute = 20
ORDER BY passengers.passport_number;
--36|Edward|1540955065|5C
--36|Sofia|1695452385|3B
--36|Taylor|1988161715|6D
--36|Bruce|5773159633|4A
--36|Doris|7214083635|2A
--36|Kelsey|8294398571|6C
--36|Luca|8496433585|7B
--36|Kenny|9878712108|7A

--select the thief's destination
SELECT city
FROM airports 
WHERE id = 4;
--New York City

--checking who is the caller
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration <= 60
ORDER BY phone_calls.duration;
--Kelsey|36
--Carina|38
--Taylor|43
--Bruce|45
--Diana|49
--Kelsey|50
--Sofia|51
--Benista|54
--Kenny|55
--Kathryn|60

--checking who is the receiver
SELECT name, phone_calls.duration
FROM people
JOIN phone_calls
ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2021
AND phone_calls.month = 7
AND phone_calls.day = 28
AND phone_calls.duration = 45
ORDER BY phone_calls.duration;
--Robin|45
