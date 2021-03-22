![](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

# Reflex game with Qt and PostgreSQL

<p align="center">
  <img src="https://user-images.githubusercontent.com/54184905/111908264-9b802d80-8a69-11eb-863e-bda97af59987.png" />
</p>

This game has been written to measure your reaction time, that is, your reflexes. The game was written visually with the Qt (c ++) module, score histories and users data are kept in the Postgresql database..

**The gameplay logic of the game :** To summarize the game in general, you should not click on the buttons with bombs, you will lose points if you click, you can click on the pizza buttons and you will earn points. Pizza buttons will appear gradually when the game starts, it will start to accelerate towards the end of the game and your reaction time will be measured. If you want, you can stop the game yourself or wait for the game to end, at the end of all games, you can see how much you've improved yourself by looking at your leaderboard.

**Postgresql infrastructure :** The users in the game are kept in the table named "users". There are 3 columns in this table, the first one keeps the user's ID, the second one keeps the users 'name and the third one keeps the users' passwords encrypted with SHA256.

The scores of the players are kept in the table named "score", the ID of each player is associated with the row here, the highest score of the player and the other 6 highest scores are also kept in this table.

~~~~sql
CREATE TABLE IF NOT EXISTS users (
	id SERIAL PRIMARY KEY, 
	username VARCHAR(100), 
	password VARCHAR(100)
);
~~~~

~~~~sql
CREATE TABLE IF NOT EXISTS score (
	id SERIAL PRIMARY KEY, 
	highest INT, 
	score0 INT, 
	score1 INT, 
	score2 INT, 
	score3 INT, 
	score4 INT, 
	score5 INT
);
~~~~

### **Requirements**

[Qt 5.9](https://www.qt.io/download-open-source?hsCtaTracking=9f6a2170-a938-42df-a8e2-a9f0b1d6cdce%7C6cb0de4f-9bb5-4778-ab02-bfb62735f3e5)

[Postgresql 12.6](https://www.postgresql.org/download/)

All table operations in the database, etc. It will be created by itself, your only task is to provide the connection between the database (local and server) and Qt.

![Screenshot_2021-03-21_16-46-24](https://user-images.githubusercontent.com/54184905/111908744-696fcb00-8a6b-11eb-9f7a-cec380217097.jpg)

![Screenshot_2021-03-21_17-35-26](https://user-images.githubusercontent.com/54184905/111908876-f155d500-8a6b-11eb-9e94-ff9fa5ee7b3f.png)

### **In-game visuals and gameplay video**

##### [**Video Link**](https://user-images.githubusercontent.com/54184905/112054019-1dee1780-8b66-11eb-88fc-6af269cd6849.mp4)

##### **Images**

![Untitled](https://user-images.githubusercontent.com/54184905/112053932-01ea7600-8b66-11eb-9f3f-c6f28cdfc9ab.png)


![Untitled0](https://user-images.githubusercontent.com/54184905/111909883-12202980-8a70-11eb-8ddc-7553e9d0926f.png)

![Untitled1](https://user-images.githubusercontent.com/54184905/111909882-11879300-8a70-11eb-973f-240ff9795d75.png)

![Untitled2](https://user-images.githubusercontent.com/54184905/111909880-0fbdcf80-8a70-11eb-8347-0b76a73f2324.png)
