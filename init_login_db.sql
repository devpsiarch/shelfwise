-- THIS SCRIPT IS MENT TO BE RUN ONCE TO INIT THE USERS 
CREATE DATABASE IF NOT EXISTS login_shelfwise;
USE login_shelfwise;


-- This creates the users table in the database 
-- i dont know if adding a new attribute will break this or not but hey
CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT,
    school_email VARCHAR(255) NOT NULL UNIQUE,
    password_hashed VARCHAR(255),
    PRIMARY KEY(id)
);

DESC users;

CREATE ROLE IF NOT EXISTS role_login_dev;
-- we give all privilages to dev , (*) means to all tables
GRANT ALL PRIVILEGES ON login_shelfwise.* TO role_login_dev;
-- check if it was right
SHOW GRANTS FOR role_login_dev;

-- Create a user that will login from the c++ using an sql API
CREATE USER IF NOT EXISTS shelfwisedev1@localhost IDENTIFIED BY 'PICK-PASSWORD-HERE';
GRANT role_login_dev TO shelfwisedev1@localhost;

-- confirmation
SHOW GRANTS FOR shelfwisedev1@localhost;

SET DEFAULT ROLE role_login_dev FOR shelfwisedev1@localhost;
