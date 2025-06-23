create table players
(player_id int,
group_id int)

insert into players values (15,1);
insert into players values (25,1);
insert into players values (30,1);
insert into players values (45,1);
insert into players values (10,2);
insert into players values (35,2);
insert into players values (50,2);
insert into players values (20,3);
insert into players values (40,3);

create table matches
(
match_id int,
first_player int,
second_player int,
first_score int,
second_score int)

insert into matches values (1,15,45,3,0);
insert into matches values (2,30,25,1,2);
insert into matches values (3,30,15,2,0);
insert into matches values (4,40,20,5,2);
insert into matches values (5,35,50,1,1);


-- for each group you have to find the player who has the max score. if tie, then return the player with lower id
select * from players;
select * from matches;


-- have to find winner of each group

-- first get the score of each player
select player, sum(score) as total_score
from (
select first_player as player, sum(first_score) as score from matches group by first_player
union all
  select second_player as player, sum(second_score) as score from matches group by second_player)
group by player;

-- then join it with players on player_id column to get the group id for each player

with players_score as (
select player, sum(score) as total_score from (
select first_player as player, sum(first_score) as score from matches group by first_player
union all
  select second_player as player, sum(second_score) as score from matches group by second_player)
  group by player)
  select ps.*, p.group_id
  from players_score ps inner join players p on ps.player = p.player_id;


-- now aggregate at the group_id level to calculate the max score for each group


with players_score as (
	select player, sum(score) as total_score from (
    	select first_player as player, sum(first_score) as score from matches 			group by first_player
	 	union all
    	select second_player as player, sum(second_score) as score from matches 		group by second_player
	)
  	group by player
),
group_score as (
  select ps.*, p.group_id
  from players_score ps inner join players p on ps.player = p.player_id
),
players_ranked as (
  select *, rank() over(partition by group_id order by total_score desc, player asc) as rn
  from group_score
)
select group_id, player
from players_ranked
where rn = 1;



