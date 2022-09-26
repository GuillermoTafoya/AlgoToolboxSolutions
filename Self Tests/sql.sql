/*
Given the database
*/
DROP TABLE IF EXISTS users;
DROP TABLE IF EXISTS classes;
DROP TABLE IF EXISTS exams;
DROP TABLE IF EXISTS scores;

CREATE TABLE users (
  id integer PRIMARY KEY AUTOINCREMENT,
  name text NOT NULL
);

CREATE TABLE classes (
  id integer PRIMARY KEY AUTOINCREMENT,
  name text NOT NULL
);

CREATE TABLE exams (
  id integer PRIMARY KEY AUTOINCREMENT,
  class_id integer NOT NULL,
  name text NOT NULL
);

CREATE TABLE scores (
  id integer PRIMARY KEY AUTOINCREMENT,
  user_id integer NOT NULL,
  exam_id integer NOT NULL,
  score integer NOT NULL,
  FOREIGN KEY(user_id) REFERENCES users(id),
  FOREIGN KEY(exam_id) REFERENCES exams(id)
);

/*
Write a query that shows all the rows in the scores table, but only if satisfies the following conditions:
1. The score is greater than or equal to 80
2. The column exam_id is not 1
3. The column score is sorted in descending order
*/
SELECT * FROM scores WHERE score >= 80 AND exam_id != 1 ORDER BY score DESC;
/*
Write a query that shows all the data from an user (id and name) as well as the number of exams that user has taken in each row.
Use the following for column names:
number of exams: num_of_users_exam
Also show when the number of exams is exactly 0.
*/
SELECT users.id, users.name, COUNT(scores.user_id) AS num_of_users_exam FROM users LEFT JOIN scores ON users.id = scores.user_id GROUP BY users.id;
/*
Write a query that shows the exam name, average score, and maximum score for each exam.
Use the following for column names:
average score: average_score
maximum score: high_score
*/
SELECT exams.name, AVG(scores.score) AS average_score, MAX(scores.score) AS high_score FROM exams JOIN scores ON exams.id = scores.exam_id GROUP BY exams.id;
/*
Write a query that shows the user name, exam name, exam class name, and score in each row.
Use the following for column names:
user name: user_name
exam name: exam_name
exam class name: class_name
score: score
*/
SELECT users.name AS user_name, exams.name AS exam_name, classes.name AS class_name, scores.score FROM users JOIN scores ON users.id = scores.user_id JOIN exams ON scores.exam_id = exams.id JOIN classes ON exams.class_id = classes.id;
/*
Write a query that shows the user name, exam name, exam class name, and score in each row.
Use the following for column names:
user name: user_name
exam name: exam_name
exam class name: class_name
score: score
Also satisfy the following conditions:
column score is greater than or equal to 90
excludes user whose id is 1
*/
SELECT users.name AS user_name, exams.name AS exam_name, classes.name AS class_name, scores.score FROM users JOIN scores ON users.id = scores.user_id JOIN exams ON scores.exam_id = exams.id JOIN classes ON exams.class_id = classes.id WHERE scores.score >= 90 AND users.id != 1;
