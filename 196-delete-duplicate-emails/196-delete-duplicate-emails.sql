# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

delete temp from person p, person temp where p.email = temp.email and temp.id > p.id