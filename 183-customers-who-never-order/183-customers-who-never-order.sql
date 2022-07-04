# Write your MySQL query statement below

SELECT A.Name AS Customers from Customers A
LEFT JOIN Orders B on  A.Id = B.CustomerId
WHERE B.CustomerId is NULL;