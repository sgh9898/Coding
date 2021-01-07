# Write your MySQL query statement below
select id,
    sum(case when month='jan' then revenue end) as Jan_revenue,
    sum(case when month='feb' then revenue end) as Feb_revenue,
    sum(case when month='mar' then revenue end) as Mar_revenue,
    sum(case when month='apr' then revenue end) as Apr_revenue,
    sum(case when month='may' then revenue end) as May_revenue,
    sum(case when month='jun' then revenue end) as Jun_revenue,
    sum(case when month='jul' then revenue end) as Jul_revenue,
    sum(case when month='aug' then revenue end) as Aug_revenue,
    sum(case when month='sep' then revenue end) as Sep_revenue,
    sum(case when month='oct' then revenue end) as Oct_revenue,
    sum(case when month='nov' then revenue end) as Nov_revenue,
    sum(case when month='dec' then revenue end) as Dec_revenue
from Department
group by id
order by id;
