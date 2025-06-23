Create table  Trips (id int, client_id int, driver_id int, city_id int, status varchar(50), request_at varchar(50));
Create table Users (users_id int, banned varchar(50), role varchar(50));
Truncate table Trips;
insert into Trips (id, client_id, driver_id, city_id, status, request_at) values ('1', '1', '10', '1', 'completed', '2013-10-01');
insert into Trips (id, client_id, driver_id, city_id, status, request_at) values ('2', '2', '11', '1', 'cancelled_by_driver', '2013-10-01');
insert into Trips (id, client_id, driver_id, city_id, status, request_at) values ('3', '3', '12', '6', 'completed', '2013-10-01');
insert into Trips (id, client_id, driver_id, city_id, status, request_at) values ('4', '4', '13', '6', 'cancelled_by_client', '2013-10-01');
insert into Trips (id, client_id, driver_id, city_id, status, request_at) values ('5', '1', '10', '1', 'completed', '2013-10-02');
insert into Trips (id, client_id, driver_id, city_id, status, request_at) values ('6', '2', '11', '6', 'completed', '2013-10-02');
insert into Trips (id, client_id, driver_id, city_id, status, request_at) values ('7', '3', '12', '6', 'completed', '2013-10-02');
insert into Trips (id, client_id, driver_id, city_id, status, request_at) values ('8', '2', '12', '12', 'completed', '2013-10-03');
insert into Trips (id, client_id, driver_id, city_id, status, request_at) values ('9', '3', '10', '12', 'completed', '2013-10-03');
insert into Trips (id, client_id, driver_id, city_id, status, request_at) values ('10', '4', '13', '12', 'cancelled_by_driver', '2013-10-03');
Truncate table Users;
insert into Users (users_id, banned, role) values ('1', 'No', 'client');
insert into Users (users_id, banned, role) values ('2', 'Yes', 'client');
insert into Users (users_id, banned, role) values ('3', 'No', 'client');
insert into Users (users_id, banned, role) values ('4', 'No', 'client');
insert into Users (users_id, banned, role) values ('10', 'No', 'driver');
insert into Users (users_id, banned, role) values ('11', 'No', 'driver');
insert into Users (users_id, banned, role) values ('12', 'No', 'driver');
insert into Users (users_id, banned, role) values ('13', 'No', 'driver');

select * from trips;
select * from users;


-- join with the same table multiple times 
select *
from trips t
inner join users c on t.client_id = c.users_id		-- joining on client_id
inner join users d on t.driver_id = d.users_id		-- joining on driver_id
where c.banned = 'No' and d.banned = 'No';			-- getting rid of banned client and drivers


-- I want the output at request_at level. cancellation rate = No of cancelled rides on that day / Total no of rides on that day
select 
    request_at, 
    count(case when status in ('cancelled_by_client','cancelled_by_driver') then 1 else null end) as cancelled_rides, -- can also use sum, instead of count
    count(1) as total_rides,
    1.0 * sum(case when status in ('cancelled_by_client','cancelled_by_driver') then 1 else 0 end) / count(1) * 100 as cancellation_percent  -- can also use 
from trips t
inner join users c on t.client_id = c.users_id		-- joining on client_id
inner join users d on t.driver_id = d.users_id		-- joining on driver_id
where c.banned = 'No' and d.banned = 'No'
group by request_at;	


-- same query using sum

-- I want the output at request_at level. cancellation rate = No of cancelled rides on that day / Total no of rides on that day
select 
    request_at, 
    sum(case when status in ('cancelled_by_client','cancelled_by_driver') then 1 else 0 end) as cancelled_rides, -- using sum 
    count(1) as total_rides,
    1.0 * sum(case when status in ('cancelled_by_client','cancelled_by_driver') then 1 else 0 end) / count(1) * 100 as cancellation_percent  -- can also use 
from trips t
inner join users c on t.client_id = c.users_id		-- joining on client_id
inner join users d on t.driver_id = d.users_id		-- joining on driver_id
where c.banned = 'No' and d.banned = 'No'
group by request_at;	
