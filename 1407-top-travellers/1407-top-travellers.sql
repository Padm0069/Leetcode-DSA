# Write your MySQL query statement below

SELECT name, SUM(IFNULL(distance,0)) AS travelled_distance
FROM Users
LEFT JOIN Rides
ON Users.id = Rides.user_id
GROUP BY Users.id
ORDER BY SUM(distance) DESC, name ASC;