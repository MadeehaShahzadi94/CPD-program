-- ***********************
-- Name: Madeeha Shahzadi
-- ID: 130638182
-- Date: September 11, 19
-- Purpose: Lab 1 DBS301
-- ***********************


----Question1: Which one of these tables appeared to be the widest? or longest? ------------------
    SELECT * FROM EMPLOYEES;
    
    SELECT * FROM DEPARTMENTS;
    
 SELECT * FROM JOB_HISTORY;

---- Answer: The employee table have 15 rows and 1 colums that is a widest table of this query.

----Question 2: If the following SELECT statement does NOT execute successfully, how would you fix it?----
----SELECT last_name �LName�, job_id �Job Title�,------- 
 ----Hire_Date �Job Start�-------
 -----FROM employees;-----------
-----Answer: 2 -----------------
SELECT last_name  LName , job_id   "Job Title"  , Hire_Date  "Job Start"
       FROM employees;

---- underscore missing
---------------------------------------------------------------------------------------------------------------
       
-----Question 3: There are THREE coding errors in this statement. Can you identify them?----------------------
 ---------SELECT employee_id, last name, commission_pct Emp Comm,
       FROM employees; ----------------------
       
---Answer

SELECT employee_id, last_name, commission_pct "Emp Comm"
       FROM employees;
----There was one underscore missing between last_name, 
----Emp comm is an alias with spaces in between, so around we use the double qout-----
---------------------------------------------------------------------------------------------------------------

-------Question 4: What command would show the structure of the LOCATIONS table? --------------------------------
-------Answer

SELECT *
FROM locations

------------------------------------------------------------------------------------------------------------------

-------Question 5: 5.	Create a query to display the output shown below. with country code, city, province with country code--------

------Answer

SELECT location_id "City#", city "City", state_province || ' IN THE ' || country_id AS "Province with Country Code" 

FROM locations

---------------------------------------------------------------------------------------------------------------------



