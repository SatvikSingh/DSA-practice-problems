# Write your MySQL query statement below

select users.name, sum(transactions.amount) as balance from users left join transactions on users.account = transactions.account group by users.account having balance > 10000