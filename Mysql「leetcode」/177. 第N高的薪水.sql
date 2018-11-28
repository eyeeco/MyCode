CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set N = N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct Salary from Employee
      order by Salary DESC limit N, 1
  );
END
