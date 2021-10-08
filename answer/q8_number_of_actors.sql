WITH mark_id(person_id) AS (select person_id from people where name='Mark Hamill' and born=1951),
   mvs(title_id) as (select title_id from mark_id join crew on mark_id.person_id=crew.person_id)
   select count(distinct person_id) from mvs join crew on mvs.title_id=crew.title_id where crew.category='actor' or crew.category='actress';

