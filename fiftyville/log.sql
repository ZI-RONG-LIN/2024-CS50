-- Keep a log of any SQL queries you execute as you solve the mystery.

select
    description
from
    crime_scene_reports
where
    month = 7 and day = 28 and street = "Humphrey Street";
--找目擊者回答
select
    *
from
    bakery_security_logs
where
    month = 7 and day = 28 and hour = 10 and minute = 15;

--找機場編號
select
    *
from
    airports
where
    city = 'Fiftyville'

--找從fiftyville出發的最早航班
select
    *
from
    flights
where
    origin_airport_id = 8 and month = 7 and day =29
order by hour, minute
limit 1;

--找從fiftyville出發的最早航班
select
    *
from
    airports
where
    id = 4;

--搭乘fiftyville出發的最早航班的人有誰 找通話紀錄小於1分鐘的電話
select *
from passengers
join people on passengers.passport_number = people. passport_number
where flight_id = 36 and phone_number in (
    select * from phone_calls
where month =7 and day = 28 and duration <60;
);

select * from atm_transactions
join bank_accounts on atm_transactions.account_number = bank_accounts.account_number
join people on bank_accounts.person_id = people.id
where month = 7 and day = 28 and atm_location = "Leggett Street"
