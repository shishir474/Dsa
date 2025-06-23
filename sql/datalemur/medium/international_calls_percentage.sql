--- get the percentage of calls that were international,


SELECT 
  -- pc.caller_id,  pi.country_id as caller_ctry
  -- ,pc.receiver_id, pi2.country_id as reciever_ctry,
  -- sum(case when pi.country_id != pi2.country_id then 1 else 0 end) as international_calls,
  -- count(*) as total_calls,
  round(1.0 *  sum(case when pi.country_id != pi2.country_id then 1 else 0 end) /  count(*) * 100, 1) as itnl_percentage
FROM phone_calls pc
left join phone_info pi on pc.caller_id = pi.caller_id
left join phone_info pi2 on pc.receiver_id = pi2.caller_id
-- where pi.country_id != pi2.country_id ;

-- select * from phone_info;