with transform(decades,title_id) as (select cast(premiered/10*10 as TEXT)||'s',title_id from titles where premiered is not null),
   decades(decades,cnt) as (select decades,cast(count(*) as float) as cnt from transform group by decades order by cnt desc),
   summary(cnt) as (select cast(sum(cnt) as float) from decades)
   select decades.decades,round(decades.cnt/summary.cnt*100,4) from decades,summary;
