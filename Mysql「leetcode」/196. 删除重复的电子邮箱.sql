# Write your MySQL query statement below
delete p1 from Person as p1, Person as p2
where p1.Email = P2.Email and
p1.Id>P2.Id
