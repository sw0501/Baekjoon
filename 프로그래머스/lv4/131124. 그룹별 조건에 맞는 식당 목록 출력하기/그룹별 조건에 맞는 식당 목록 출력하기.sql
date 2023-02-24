-- 코드를 입력하세요
SELECT A.MEMBER_NAME, B.REVIEW_TEXT, DATE_format(B.REVIEW_DATE,'%Y-%m-%d') as REVIEW_DATE
from MEMBER_PROFILE A
inner JOIN REST_REVIEW  B
on A.MEMBER_ID = B.MEMBER_ID
where A.MEMBER_ID = (
    select member_id from REST_REVIEW group by member_id order by count(review_id) desc limit 1
)
Order by B.REVIEW_DATE asc, B.REVIEW_TEXT asc
