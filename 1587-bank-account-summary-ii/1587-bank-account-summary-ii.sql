# Write your MySQL query statement below

select Users.name, sum(amount) as balance
from Transactions, Users
where users.account = Transactions.account
group by users.account
having balance > 10000;