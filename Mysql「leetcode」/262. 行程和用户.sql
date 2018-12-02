# Write your MySQL
select Request_at as Day, round(count(if(Status!='completed',Status,NULL))/count(Status),2)
as 'Cancellation Rate' from (select Status, Request_at from Trips
join (select Users_id from Users
where Banned='No' and Role = 'client') as t
on Client_Id = Users_Id) as n
where Request_at >= '2013-10-01'
and Request_at <= '2013-10-03'
group by Request_at
