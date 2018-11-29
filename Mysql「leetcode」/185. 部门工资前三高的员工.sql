# Write your MySQL query statement below
select b.Name as Department, a.Name as Employee, a.Salary
from Employee as a
join Department as b
on a.DepartmentId = b.Id
where a.Salary>=ifnull((
    select distinct Salary from Employee
    where DepartmentId = a.DepartmentId
    order by Salary desc
    limit 1 offset 2),0)
order by b.name, a.Salary desc 
