# Write your MySQL query statement below
select distinct Salary as SecondHighestSalary from Employee
order by Salary DESC limit 1 offset 1
