select titles.primary_title,count(*) as cnt from titles join akas on titles.title_id=akas.title_id group by titles.title_id order by cnt desc limit 10;
