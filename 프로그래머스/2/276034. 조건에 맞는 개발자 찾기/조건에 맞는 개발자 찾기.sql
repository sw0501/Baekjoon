-- 코드를 작성해주세요
SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS D
WHERE D.SKILL_CODE & (
    SELECT CODE
    FROM SKILLCODES S
    WHERE S.NAME = "PYTHON"
) >= 1 OR D.SKILL_CODE & (
    SELECT CODE
    FROM SKILLCODES S
    WHERE S.NAME = "C#"
)  >= 1
ORDER BY ID;