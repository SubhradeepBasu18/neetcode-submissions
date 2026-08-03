-- Write your query below
SELECT name FROM customers
WHERE id IN (
    SELECT c.id FROM customers c
    EXCEPT
    SELECT o.customer_id FROM orders o
);