-- 코드를 작성해주세요

SELECT B.DEPT_ID, B.DEPT_NAME_EN, (ROUND(AVG(A.SAL))) AS AVG_SAL
FROM HR_EMPLOYEES A
LEFT OUTER JOIN HR_DEPARTMENT B
ON A.DEPT_ID = B.DEPT_ID
GROUP BY B.DEPT_ID
ORDER BY AVG_SAL DESC;