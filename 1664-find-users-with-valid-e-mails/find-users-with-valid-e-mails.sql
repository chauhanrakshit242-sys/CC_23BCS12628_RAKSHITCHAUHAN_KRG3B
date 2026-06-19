SELECT *
FROM Users
WHERE BINARY RIGHT(mail, 13) = '@leetcode.com'
  AND mail REGEXP '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\\.com$';