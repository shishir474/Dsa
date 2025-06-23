2 tables person(person_id, name, email, score) and friend(person_id, friend_id)

Find all person whose friends score is > 100;

--- each person's score
with person_score as 
(select person_id, sum(score) from person group by person)
-- now I have to get each person's friends score
select person_id
from person_score


-- person_id, name, number of friends, sum of marks of person
-- who have friends with total score greater than 100;

select * from person;
select * from friend;
-- if you want to filter on aggregated value --> use having
-- if you want to filter on row level --> use where
/*
The count(1) part means:

count(1) counts the number of rows returned by the JOIN for each f.pid group.

The 1 is just a placeholder constant. SQL engines treat count(1) the same as count(*) in most cases.

So, count(1) returns the number of friends each person (f.pid) has, after joining with person.

Key Notes:
count(1), count(*), and count(p.personid) are slightly different:

count(*) counts all rows, including those with NULLs.

count(1) also counts all rows (constant 1 is never NULL).

count(column) counts only non-NULL values in that column.

Since you're using an inner join (which excludes NULLs), all three would behave the same here.

*/

select f.pid, p2.name, sum(p1.score) total_friend_score, count(1) as no_of_friends
from friend f 
inner join person p1 on f.fid = p1.personid -- friend info
inner join person p2 on f.pid = p2.personid -- main person info
group by f.pid, p2.name
having sum(p1.score) > 100;
 