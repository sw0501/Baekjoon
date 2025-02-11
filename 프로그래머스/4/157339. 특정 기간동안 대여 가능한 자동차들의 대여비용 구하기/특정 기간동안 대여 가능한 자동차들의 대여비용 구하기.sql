-- 코드를 입력하세요

SELECT DISTINCT(H1.CAR_ID), C.CAR_TYPE, C.DAILY_FEE * (100-P.DISCOUNT_RATE) / 100 * 30 AS FEE

FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H1

INNER JOIN CAR_RENTAL_COMPANY_CAR C
ON H1.CAR_ID = C.CAR_ID

INNER JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN P
ON C.CAR_TYPE = P.CAR_TYPE AND P.DURATION_TYPE LIKE '30%'

WHERE H1.CAR_ID NOT IN 
(
    SELECT DISTINCT(H2.CAR_ID)
    FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY H2
    WHERE TO_CHAR(H2.START_DATE,'YYYYMMDD') <= '20221130' AND TO_CHAR(H2.END_DATE,'YYYYMMDD') >= '20221101'
) AND (C.CAR_TYPE = '세단' OR C.CAR_TYPE = 'SUV')

AND C.DAILY_FEE * (100 - P.DISCOUNT_RATE) / 100 * 30 >= 500000

AND C.DAILY_FEE * (100 - P.DISCOUNT_RATE) / 100 * 30 < 2000000

ORDER BY FEE DESC, C.CAR_TYPE ASC, H1.CAR_ID DESC;