# Write your MySQL query
select id+1 as id,student from seat
where mod(id,2)=1
and id!= (select max(id) from seat)
union
select id-1,student from seat
where mod(id,2)=0
union
select id,student from seat
where mod(id,2)=1 and
id=(select max(id) from seat)
order by id+1 
