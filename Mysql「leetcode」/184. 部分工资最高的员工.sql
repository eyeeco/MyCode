# Write your MySQL query statement below
select b.Name as Department, a.Name as Employee, a.Salary
from Employee as a
join Department as b
on a.DepartmentId = b.Id
where a.Salary>=(select max(Salary) from Employee where DepartmentId=a.DepartmentId)
