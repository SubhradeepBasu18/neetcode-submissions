-- Write your query below
SELECT s.seller_name
FROM seller s
LEFT JOIN orders o
ON s.seller_id = o.seller_id
AND EXTRACT(YEAR FROM sale_date) = 2020
GROUP BY 
    s.seller_id, 
    s.seller_name
HAVING COUNT(o.order_id) = 0
ORDER BY s.seller_name;

