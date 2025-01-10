SELECT
  A.machine_id,
  round(
    avg(
      if (
        A.activity_type = "end",
        A.timestamp - (
          SELECT
            B.timestamp
          from
            Activity B
          where
            B.machine_id = A.machine_id
            AND B.process_id = A.process_id
            AND B.activity_type = "start"
        ),
        null
      )
    ),
    3
  ) as processing_time
FROM
  Activity A
group by
  A.machine_id;