with mark_title_id as (select title_id from crew join people on crew.person_id=people.person_id where people.name='Mark Hamill' and born=1951),
   george_title_id as (select title_id from crew join people on crew.person_id=people.person_id where people.name='George Lucas' and born=1944)
   select primary_title as name from titles where titles.title_id in (select * from mark_title_id) and titles.title_id in (select * from george_title_id) and titles.type='movie' order by name asc;
