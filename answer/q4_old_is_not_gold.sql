with transform(decades,title_id) as (select cast(premiered/10*10 as TEXT)||'s',title_id from titles where premiered is not null)
 select decades,count(*) as cnt from transform group by decades order by cnt desc;

