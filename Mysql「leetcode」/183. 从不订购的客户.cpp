# Write your MySQL query statement below
select Name as Customers from
(select a.Name,b.Id from Customers as a
left join Orders as b
on a.Id = b.CustomerId) as t
where Id is null
