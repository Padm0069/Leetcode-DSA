# Write your MySQL query statement below

SELECT employee_id,
IF (employee_id%2 AND name not like "M%", salary, 0) as bonus
FROM Employees order by employee_id;

# // IF(condition, value_if_true, value_if_false)