create table entries ( 
name varchar(20),
address varchar(20),
email varchar(20),
floor int,
resources varchar(10));

insert into entries 
values ('A','Bangalore','A@gmail.com',1,'CPU'),('A','Bangalore','A1@gmail.com',1,'CPU'),('A','Bangalore','A2@gmail.com',2,'DESKTOP')
,('B','Bangalore','B@gmail.com',2,'DESKTOP'),('B','Bangalore','B1@gmail.com',2,'DESKTOP'),('B','Bangalore','B2@gmail.com',1,'MONITOR')


-- to find -->  name, total_visits, max_floor_visited, resources_used
select * from entries;

-- first I will find the floor most visited by each person. I can find the count and then rank the records for each name in decreasing order of count. And now I just have to filter out rank 1 record
-- group_concat() aggregates the resource but it doesnt ensure uniqueness --> to handle that 1st 2 cte's
-- first get the unique resources for each person and then aggregate them using group_concat() or string_agg() to get the unique list of resoureces for each person
-- then you just have to join with the rank cte. We also need to count the total_visit for each floor --> for that total_visits cte


-- string_agg(column_name, separtor)  --> aggreagation function that returns a list of elements separated by separator
-- string_agg alternatives group_concat()  --> exactly same as string_agg

with unique_resources as (
  select distinct name, resources from entries
),
unique_agg_resources as (
	select name, group_concat(resources,',') as resources_used from unique_resources group by name
),
total_visits as (
  select name, count(*) as total_visits, group_concat(resources,',') from entries group by name
),
rank_cte as(	-- name, floor, no of times floor visited, rank
	select name, floor, count(*) no_of_visits, rank() over(partition by name order by count(*) desc) rn
	from entries
	group by name,floor
)
select rc.name, rc.floor most_visited_floor, tv.total_visits, ugr.resources_used
from rank_cte rc 
inner join unique_agg_resources ugr on rc.name = ugr.name
inner join total_visits tv on rc.name =  tv.name
where rn = 1;
/*

*/

/*





select name, count(*) as total_visits, group_concat(resources,',') from entries group by name;
*/

	
