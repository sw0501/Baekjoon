-- 코드를 작성해주세요
SELECT ITEM_ID, ITEM_NAME
FROM ITEM_INFO A
WHERE (
    SELECT B.PARENT_ITEM_ID 
    FROM ITEM_TREE B
    WHERE A.ITEM_ID = B.ITEM_ID
) IS NULL
ORDER BY ITEM_ID;