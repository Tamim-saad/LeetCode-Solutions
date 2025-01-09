SELECT
  w.id
FROM
  Weather w
WHERE
  w.temperature > (
    SELECT
      w2.temperature
    FROM
      Weather w2
    WHERE
      DATE_ADD(w2.recordDate, INTERVAL 1 DAY) = w.recordDate
  );
