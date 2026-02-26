-- Write your PostgreSQL query statement below
SELECT DISTINCT author_id AS id from VIEWS
where author_id=viewer_id
ORDER BY author_id;