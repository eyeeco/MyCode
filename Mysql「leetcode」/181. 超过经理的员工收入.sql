# Write your MySQL query statement below
select Name as Employee from
(select a.Name,a.Salary as s1,b.Salary as s2 from Employee as a
join Employee as b
on a.ManagerId = b.id) as t
where s1>s2
