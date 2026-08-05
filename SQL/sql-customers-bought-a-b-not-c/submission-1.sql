-- Write your query below
SELECT c.customer_id, c.customer_name
FROM customers c
WHERE customer_id IN (
    SELECT customer_id
    FROM orders o
    GROUP BY customer_id
    HAVING
        SUM(CASE WHEN product_name = 'A' THEN 1 ELSE 0 END) > 0 and
        SUM(CASE WHEN product_name = 'B' THEN 1 ELSE 0 END) > 0 and
        SUM(CASE WHEN product_name = 'C' THEN 1 ELSE 0 END) = 0
)
ORDER BY c.customer_name;