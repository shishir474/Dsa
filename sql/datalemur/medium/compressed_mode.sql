-- we've to find the mode and then get the item count corresponding to the mode 
select item_count from items_per_order
where order_occurrences = ( -- this subquery gives us the mode
  SELECT max(order_occurrences)
  FROM items_per_order
)
order by item_count;


