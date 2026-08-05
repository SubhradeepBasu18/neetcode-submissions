-- Write your query below
SELECT e.student_id, MIN(e.exam_id) as exam_id, e.score
FROM exam_results e
JOIN (
    SELECT student_id, MAX(score) AS max_score
    FROM exam_results
    GROUP BY student_id
) m
ON e.student_id = m.student_id
AND e.score = m.max_score
GROUP BY e.student_id, e.score;