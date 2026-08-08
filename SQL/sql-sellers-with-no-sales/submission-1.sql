-- Write your query below
SELECT s.seller_name
FROM seller s
WHERE NOT EXISTS (
    SELECT 1
    FROM orders o
    WHERE o.seller_id = s.seller_id AND
    EXTRACT(YEAR FROM o.sale_date) = 2020
)
ORDER BY s.seller_name;

