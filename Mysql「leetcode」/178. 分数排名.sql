# Write your MySQL query statement below
select a.Score, b.Rank from
Scores as a join
(select @row:=@row+1 as Rank, u.* from
(select distinct Score from Scores order by Score desc) as u,
(select @row:=0) as t) as b
on a.Score = b.Score
order by a.score desc
