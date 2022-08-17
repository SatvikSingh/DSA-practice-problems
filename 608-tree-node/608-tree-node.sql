# Write your MySQL query statement below

SELECT id,
    CASE 
        WHEN id = (select id from tree where p_id is null) THEN 'Root'
        when id in (select p_id from tree) then 'Inner'
        ELSE 'Leaf'
        END AS type
From Tree