# Write your MySQL query statement below
select distinct s4.id,s4.date,s4.people from stadium as s1,stadium as s2, stadium as s3, stadium as s4
where s1.id = s2.id-1 and s2.id=s3.id-1
and s1.people>=100 and s2.people>=100 and s3.people>=100
and s4.id in (s1.id,s2.id,s3.id)
