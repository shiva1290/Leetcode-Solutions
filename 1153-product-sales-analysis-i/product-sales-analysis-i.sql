-- Write your PostgreSQL query statement below
Select p.product_name, s.year , s.price
FROM Sales S
JOIN Product P
ON p.product_id=s.product_id;