# Write your MySQL query statement below

select users.user_id as buyer_id, users.join_date as join_date, ifnull(count(order_date), 0) as orders_in_2019 from users left join orders on users.user_id = orders.buyer_id and year(order_date) = '2019' group by users.user_id