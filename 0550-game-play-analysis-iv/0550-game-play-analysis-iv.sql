select round(count(a.player_id)/count(t.player_id),2) as fraction
from 
    (select player_id, min(event_date) as first
    from Activity 
    group by player_id ) as t
    
    left join Activity a
    on a.player_id = t.player_id
    and a.event_date = t.first + interval 1 day