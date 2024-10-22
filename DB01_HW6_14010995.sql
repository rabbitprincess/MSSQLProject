CREATE TABLE DATAMANAGER (
	MANAGER_NUM	INTEGER NOT NULL,
	NAME		CHAR(15),
	PHONENUM	CHAR(15),
	PRIMARY KEY(MANAGER_NUM)
);

CREATE TABLE DATAMINER (
	MIN_NUM			INTEGER NOT NULL,
	NAME			CHAR(10),
	PHONENUM		CHAR(13),
	SUBJECT_FIELD	CHAR(20),
	MANAGER_NO		INTEGER,
	PRIMARY KEY(MIN_NUM),
	FOREIGN KEY(MANAGER_NO) REFERENCES DATAMANAGER(MANAGER_NUM)
			ON DELETE SET NULL ON UPDATE CASCADE
); 

CREATE TABLE LANGUAGEDATA (
	LAN_NUM			INTEGER NOT NULL,
	NATURAL_DATA	VARCHAR(800),
	PROCEED_DATA	NVARCHAR(800),
	SUBJECT			CHAR(10),
	SOURCE_SITE		CHAR(50),
	MINER_NO		INTEGER,
	MANAGER_NO		INTEGER,
	PRIMARY KEY(LAN_NUM),
	FOREIGN KEY(MINER_NO) REFERENCES DATAMINER(MIN_NUM),
	FOREIGN KEY(MANAGER_NO) REFERENCES DATAMANAGER(MANAGER_NUM)
		ON DELETE SET NULL ON UPDATE CASCADE
); 

CREATE TABLE DATAANALIST (
	ANALIST_NUM		INTEGER NOT NULL,
	NAME			CHAR(10),
	PHONE			CHAR(13),
	SUBJECT_FIELD	VARCHAR(100)
	PRIMARY KEY(ANALIST_NUM)
); 

CREATE TABLE PROJECT (
	ANALIST_NO		INTEGER,
	PROJECT_NUM		INTEGER NOT NULL,
	NAME			CHAR(10),
	BUDGET			INTEGER,
	PRIMARY KEY(PROJECT_NUM),
	FOREIGN KEY(ANALIST_NO) REFERENCES DATAANALIST(ANALIST_NUM)
			ON DELETE SET NULL ON UPDATE CASCADE
); 

CREATE TABLE CLIENT (
	CLIENT_NUM	INTEGER,
	NAME		VARCHAR(10),
	PHONE		VARCHAR(13),
	RATE		VARCHAR CHECK(RATE IN('A','B','C'))
	PRIMARY KEY(CLIENT_NUM)
); 

CREATE TABLE SIMILARITY(
	LAN1				INTEGER NOT NULL,
	LAN2				INTEGER NOT NULL,
	RELATION_RATE		FLOAT NOT NULL,
	FOREIGN KEY(LAN1)	REFERENCES LANGUAGEDATA(LAN_NUM),
	FOREIGN KEY(LAN2)	REFERENCES LANGUAGEDATA(LAN_NUM),
	PRIMARY KEY(LAN1,LAN2) --다중 키
);

CREATE TABLE DATAUSES(
	PROJECT_NO		INTEGER NOT NULL,
	LANGUAGE_NO		INTEGER NOT NULL,
	FOREIGN KEY(PROJECT_NO) REFERENCES PROJECT(PROJECT_NUM)
		ON DELETE CASCADE,
	FOREIGN KEY(LANGUAGE_NO) REFERENCES LANGUAGEDATA(LAN_NUM) 		
		ON DELETE CASCADE,
	PRIMARY KEY(PROJECT_NO,LANGUAGE_NO)
		);

CREATE TABLE REQUEST(
	ANALIST_NO		INTEGER NOT NULL,
	CLIENT_NO		INTEGER NOT NULL,
	REQUEST_PRICE	INTEGER, 
	FINAL_PRICE		INTEGER,
	REQUIRMENT		VARCHAR(100)
	PRIMARY KEY(CLIENT_NO,ANALIST_NO),
	FOREIGN KEY(ANALIST_NO) REFERENCES DATAANALIST(ANALIST_NUM)
			ON DELETE CASCADE,
	FOREIGN KEY(CLIENT_NO) REFERENCES CLIENT(CLIENT_NUM)
			ON DELETE CASCADE
);

CREATE TABLE OFFER(
	ANALIST_NO			INTEGER NOT NULL,
	CLIENT_NO			INTEGER NOT NULL,
	SUBJECT				VARCHAR(10),
	RESULTS_REPORT		VARCHAR(100)
	PRIMARY KEY(CLIENT_NO,ANALIST_NO) 
	FOREIGN KEY(ANALIST_NO) REFERENCES DATAANALIST(ANALIST_NUM)
			ON DELETE CASCADE,
	FOREIGN KEY(CLIENT_NO) REFERENCES CLIENT(CLIENT_NUM)
			ON DELETE CASCADE
);


INSERT INTO DATAMANAGER VALUES(1,'B.PARK','010-1234-7645');
INSERT INTO DATAMANAGER VALUES(2,'R.CHOI','010-4533-2446');
INSERT INTO DATAMANAGER VALUES(3,'B.PARK','010-2345-1345');
INSERT INTO DATAMANAGER VALUES(4,'H.LEE','010-2345-1345');
INSERT INTO DATAMANAGER VALUES(5,'E.KIM','010-2345-1345');
INSERT INTO DATAMANAGER VALUES(6,'Q.RYU','010-2345-1345');
INSERT INTO DATAMANAGER VALUES(7,'G.JUNG','010-2345-1345');
INSERT INTO DATAMANAGER VALUES(8,'R.KIM','010-2345-1345');
INSERT INTO DATAMANAGER VALUES(9,'Y.LEE','010-2345-1343');
INSERT INTO DATAMANAGER VALUES(10,'E.JUNG','010-2345-1333');
INSERT INTO DATAMANAGER VALUES(11,'B.KIM','010-2345-1365');
INSERT INTO DATAMANAGER VALUES(12,'T.CHOI','010-2345-1345');
INSERT INTO DATAMANAGER VALUES(13,'Y.PARK','010-2345-1345');
INSERT INTO DATAMANAGER VALUES(14,'G.RYU','010-2345-1345');
INSERT INTO DATAMANAGER VALUES(15,'B.JUNT','010-2345-1345');

INSERT INTO DATAMINER VALUES(1,'E.KIM','010-2358-7593','공학,의학',1);
INSERT INTO DATAMINER VALUES(2,'S.LEE','010-2478-7343','대화,세미나,사학',1);
INSERT INTO DATAMINER VALUES(3,'B.PARK','010-2345-1345','사학,역학',1);
INSERT INTO DATAMINER VALUES(4,'H.ENDY','010-2456-1345','대화,감성',2);
INSERT INTO DATAMINER VALUES(5,'H.ENDY','010-2456-1345','대화,감성',2);
INSERT INTO DATAMINER VALUES(6,'R.CHOI','010-5565-5693','문학,공전',3);
INSERT INTO DATAMINER VALUES(7,'G.RYU','010-9334-7455','문학,대화',3);
INSERT INTO DATAMINER VALUES(8,'S.LEE','010-9668-4593','대화,수학',4);
INSERT INTO DATAMINER VALUES(9,'V.PARK','010-1948-3593','수학,대화',4);
INSERT INTO DATAMINER VALUES(10,'B.ENDY','010-7555-7526','논쟁,강의',4);
INSERT INTO DATAMINER VALUES(11,'S.CHOI','010-5858-3568','강연,대화',4);
INSERT INTO DATAMINER VALUES(12,'Y.KIM','010-1238-9865','강연,의학',5);
INSERT INTO DATAMINER VALUES(13,'T.LEE','010-2954-9595','수학,과학',5);
INSERT INTO DATAMINER VALUES(14,'R.JUNG','010-9842-7245','세미나,의학',5);
INSERT INTO DATAMINER VALUES(15,'H.ENDY','010-6858-4673','대화,의학',6);

INSERT INTO LANGUAGEDATA VALUES(1,'투자는 거미처럼... 개미가 진화하면 거미가 된다! 바이럴마케팅업체 탁월한 초이스','3,4,0,0,0,0,0,0,0,0,1,3,4,5,10,0,0,0,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','바이럴','https://blog.naver.com/BlogHome.nhn',1,1)
INSERT INTO LANGUAGEDATA VALUES(2,'메가박스에서 보는 게 좋긴 한데, 음. 메가박스는 그때 토요일이구 그래서, ','3,4,0,0,0,4,6,0,0,0,1,3,4,5,10,0,0,0,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',2,1)
INSERT INTO LANGUAGEDATA VALUES(3,'못 가네, 유럽 못 갈 것 같애. 아, 그래서 만약에','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',2,1)
INSERT INTO LANGUAGEDATA VALUES(4,' 받는 건 이십대 중반 남자잖아. 맞어. 아이고, 남자 친구 군대','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',3,1)
INSERT INTO LANGUAGEDATA VALUES(5,' 열심히 배우겠습니다. 이러니까 선생님들이 당황해 가지고, 어 그래 열심히 하고','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',4,2)
INSERT INTO LANGUAGEDATA VALUES(6,' 언어는, 에이라는 건 문자로 인식하지 않고, 공일공공, 공공공일로 인식하는 겁니다.','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','언어','https://blog.naver.com/BlogHome.nhn',4,3)
INSERT INTO LANGUAGEDATA VALUES(7,' 이상하다. 너무 초조하게 생각하지 마. 잘 될 거야. 언제 집에','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',4,3)
INSERT INTO LANGUAGEDATA VALUES(8,' 하다가, 음 이제 그 사무실은 이제 일월 사일에 계약을 하거든요,','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',5,3)
INSERT INTO LANGUAGEDATA VALUES(9,'이벤트 도착','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',5,3)
INSERT INTO LANGUAGEDATA VALUES(10,'☞사이트에서만난 그녀,당신횡재했죠? 탑클래스미모의그녀와소개팅한번해요~','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','스팸','https://blog.naver.com/BlogHome.nhn',6,4)
INSERT INTO LANGUAGEDATA VALUES(11,'#평택출장샵후불//카톡VF69//O7O_7575_OO51【검증된업체】#경주출장아가씨후기★전국24시출장','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','스팸','https://blog.naver.com/BlogHome.nhn',7,4)
INSERT INTO LANGUAGEDATA VALUES(12,'그 다음에, 일공일공 공공공일. 이게 갑니다. 지금 여기서 보이는 이','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',8,4)
INSERT INTO LANGUAGEDATA VALUES(13,'공익 공익이랑 어, 면제 그 얘기 몰라, 일단 신검 받으러','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',8,4)
INSERT INTO LANGUAGEDATA VALUES(14,'계란을 어떻게 둘르는 거야? 이렇게 애 아, 무쳐 가지구. 무쳐','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',8,4)
INSERT INTO LANGUAGEDATA VALUES(15,'되는데. 할머니 뵙기로 해 가지구, 얘를 데려갈려구 하는데. 응. 같이','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','대화','https://blog.naver.com/BlogHome.nhn',10,4)

INSERT INTO DATAANALIST VALUES(1,'E.KIM','010-2345-1345','공학,의학')
INSERT INTO DATAANALIST VALUES(2,'Q.RYU','010-2345-1345','사학,의학');
INSERT INTO DATAANALIST VALUES(3,'G.JUNG','010-2345-1345','세미나,강연');
INSERT INTO DATAANALIST VALUES(4,'R.KIM','010-2345-1345','대화,세미나');
INSERT INTO DATAANALIST VALUES(5,'Y.LEE','010-2345-1343','수학,논쟁');
INSERT INTO DATAANALIST VALUES(6,'E.JUNG','010-2345-1333','강연,강의');
INSERT INTO DATAANALIST VALUES(7,'G.JUNG','010-2345-1345','수학,과제');
INSERT INTO DATAANALIST VALUES(8,'R.KIM','010-2345-1345','공학,과학');
INSERT INTO DATAANALIST VALUES(9,'Y.LEE','010-2345-1343','대화,잡담,수학');
INSERT INTO DATAANALIST VALUES(10,'E.JUNG','010-2345-1333','강연,강의');
INSERT INTO DATAANALIST VALUES(11,'B.KIM','010-2345-1365','의학,수학');
INSERT INTO DATAANALIST VALUES(12,'T.CHOI','010-2345-1345','문학,공학');
INSERT INTO DATAANALIST VALUES(13,'Y.PARK','010-2345-1345','사학,문학');
INSERT INTO DATAANALIST VALUES(14,'G.RYU','010-2345-1345','공학,사학');
INSERT INTO DATAANALIST VALUES(15,'B.JUNT','010-2345-1345','문학,공학');

INSERT INTO PROJECT VALUES(1,1,'PROJECT_A',400000);
INSERT INTO PROJECT VALUES(1,2,'PROJECT_B',560000);
INSERT INTO PROJECT VALUES(2,3,'PROJECT_C',500000);
INSERT INTO PROJECT VALUES(2,4,'PROJECT_D',600000);
INSERT INTO PROJECT VALUES(2,5,'PROJECT_E',300000);
INSERT INTO PROJECT VALUES(2,6,'PROJECT_F',800000);
INSERT INTO PROJECT VALUES(2,7,'PROJECT_G',350000);
INSERT INTO PROJECT VALUES(3,8,'PROJECT_H',200000);
INSERT INTO PROJECT VALUES(3,9,'PROJECT_I',450000);
INSERT INTO PROJECT VALUES(3,10,'PROJECT_J',500000);
INSERT INTO PROJECT VALUES(3,11,'PROJECT_K',60000);
INSERT INTO PROJECT VALUES(3,12,'PROJECT_L',700000);
INSERT INTO PROJECT VALUES(4,13,'PROJECT_M',400000);
INSERT INTO PROJECT VALUES(4,14,'PROJECT_N',300000);
INSERT INTO PROJECT VALUES(4,15,'PROJECT_O',300000);
INSERT INTO PROJECT VALUES(5,16,'PROJECT_P',50000);
INSERT INTO PROJECT VALUES(5,17,'PROJECT_Q',600000);
INSERT INTO PROJECT VALUES(6,18,'PROJECT_R',300000);
INSERT INTO PROJECT VALUES(6,19,'PROJECT_S',100000);
INSERT INTO PROJECT VALUES(6,20,'PROJECT_T',900000);

INSERT INTO CLIENT VALUES(1,'K.KIM','010-2365-3456','A')
INSERT INTO CLIENT VALUES(2,'T.LEE','010-2666-5443','B')
INSERT INTO CLIENT VALUES(3,'G.YOHAN','010-2365-4356','A')
INSERT INTO CLIENT VALUES(4,'R.KIM','010-2345-1345','B');
INSERT INTO CLIENT VALUES(5,'Y.LEE','010-2345-1343','A');
INSERT INTO CLIENT VALUES(6,'E.JUNG','010-2345-1333','C');
INSERT INTO CLIENT VALUES(7,'G.JUNG','010-2345-1345','A');
INSERT INTO CLIENT VALUES(8,'R.KIM','010-2345-1345','B');
INSERT INTO CLIENT VALUES(9,'Y.LEE','010-2345-1343','A');
INSERT INTO CLIENT VALUES(10,'E.JUNG','010-2345-1333','A');
INSERT INTO CLIENT VALUES(11,'B.KIM','010-2345-1365','C');
INSERT INTO CLIENT VALUES(12,'T.CHOI','010-2345-1345','B');
INSERT INTO CLIENT VALUES(13,'Y.PARK','010-2345-1345','A');
INSERT INTO CLIENT VALUES(14,'G.RYU','010-2345-1345','B');
INSERT INTO CLIENT VALUES(15,'B.JUNT','010-2345-1345','C');
INSERT INTO CLIENT VALUES(16,'E.JUN','010-2345-1345','A');

INSERT INTO SIMILARITY VALUES(1,2,76.6);
INSERT INTO SIMILARITY VALUES(1,3,54.4);
INSERT INTO SIMILARITY VALUES(1,4,32.6);
INSERT INTO SIMILARITY VALUES(1,5,64.5);
INSERT INTO SIMILARITY VALUES(1,6,8.7);
INSERT INTO SIMILARITY VALUES(1,7,74.5);
INSERT INTO SIMILARITY VALUES(1,8,76.3);
INSERT INTO SIMILARITY VALUES(1,9,45.5);
INSERT INTO SIMILARITY VALUES(1,10,35.3);
INSERT INTO SIMILARITY VALUES(2,3,69.0);
INSERT INTO SIMILARITY VALUES(2,4,24.4);
INSERT INTO SIMILARITY VALUES(2,5,54.0);
INSERT INTO SIMILARITY VALUES(2,6,98.8);
INSERT INTO SIMILARITY VALUES(2,7,75.5);
INSERT INTO SIMILARITY VALUES(2,8,56.6);
INSERT INTO SIMILARITY VALUES(2,9,55.5);
INSERT INTO SIMILARITY VALUES(2,10,54.2);
INSERT INTO SIMILARITY VALUES(3,4,13.4);
INSERT INTO SIMILARITY VALUES(3,5,32.0);
INSERT INTO SIMILARITY VALUES(3,6,24.4);
INSERT INTO SIMILARITY VALUES(3,7,53.4);
INSERT INTO SIMILARITY VALUES(3,8,64.3);
INSERT INTO SIMILARITY VALUES(3,9,54.6);
INSERT INTO SIMILARITY VALUES(3,10,74.3);
INSERT INTO SIMILARITY VALUES(4,5,24.5);
INSERT INTO SIMILARITY VALUES(4,6,64.3);
INSERT INTO SIMILARITY VALUES(4,7,54.3);
INSERT INTO SIMILARITY VALUES(4,8,48.5);
INSERT INTO SIMILARITY VALUES(4,9,96.4);
INSERT INTO SIMILARITY VALUES(4,10,44.6);
INSERT INTO SIMILARITY VALUES(5,6,41.3);
INSERT INTO SIMILARITY VALUES(5,7,35.4);
INSERT INTO SIMILARITY VALUES(5,8,25.3);
INSERT INTO SIMILARITY VALUES(5,9,10.5);
INSERT INTO SIMILARITY VALUES(5,10,54.3);
INSERT INTO SIMILARITY VALUES(6,7,45.5);
INSERT INTO SIMILARITY VALUES(6,8,75.3);
INSERT INTO SIMILARITY VALUES(6,9,67.4);
INSERT INTO SIMILARITY VALUES(6,10,66.4);
INSERT INTO SIMILARITY VALUES(7,8,24.3);
INSERT INTO SIMILARITY VALUES(7,9,54.3);
INSERT INTO SIMILARITY VALUES(7,10,77.4);
INSERT INTO SIMILARITY VALUES(8,9,54.3);
INSERT INTO SIMILARITY VALUES(8,10,16.0);
INSERT INTO SIMILARITY VALUES(9,10,44.4);
-- 생략

INSERT INTO DATAUSES VALUES(1,1);
INSERT INTO DATAUSES VALUES(1,2);
INSERT INTO DATAUSES VALUES(1,3);
INSERT INTO DATAUSES VALUES(1,5);
INSERT INTO DATAUSES VALUES(1,7);
INSERT INTO DATAUSES VALUES(1,10);
INSERT INTO DATAUSES VALUES(1,13);
INSERT INTO DATAUSES VALUES(2,1);
INSERT INTO DATAUSES VALUES(2,3);
INSERT INTO DATAUSES VALUES(2,4);
INSERT INTO DATAUSES VALUES(3,3);
INSERT INTO DATAUSES VALUES(3,4);
INSERT INTO DATAUSES VALUES(3,5);
INSERT INTO DATAUSES VALUES(3,6);
INSERT INTO DATAUSES VALUES(3,8);
INSERT INTO DATAUSES VALUES(3,9);
INSERT INTO DATAUSES VALUES(3,11);
INSERT INTO DATAUSES VALUES(4,1);
INSERT INTO DATAUSES VALUES(5,1);
INSERT INTO DATAUSES VALUES(5,3);
INSERT INTO DATAUSES VALUES(5,5);
INSERT INTO DATAUSES VALUES(5,6);
INSERT INTO DATAUSES VALUES(5,10);
INSERT INTO DATAUSES VALUES(5,13);
INSERT INTO DATAUSES VALUES(5,14);
INSERT INTO DATAUSES VALUES(6,1);
INSERT INTO DATAUSES VALUES(6,3);
INSERT INTO DATAUSES VALUES(7,2);
INSERT INTO DATAUSES VALUES(7,3);
INSERT INTO DATAUSES VALUES(7,4);
INSERT INTO DATAUSES VALUES(7,6);
INSERT INTO DATAUSES VALUES(7,7);
INSERT INTO DATAUSES VALUES(7,8);
INSERT INTO DATAUSES VALUES(8,1);
INSERT INTO DATAUSES VALUES(8,3);
INSERT INTO DATAUSES VALUES(8,4);
INSERT INTO DATAUSES VALUES(8,6);
INSERT INTO DATAUSES VALUES(8,7);
INSERT INTO DATAUSES VALUES(8,8);
INSERT INTO DATAUSES VALUES(8,10);
INSERT INTO DATAUSES VALUES(8,12);
INSERT INTO DATAUSES VALUES(8,15);
INSERT INTO DATAUSES VALUES(9,3);
INSERT INTO DATAUSES VALUES(9,3);
INSERT INTO DATAUSES VALUES(9,5);
INSERT INTO DATAUSES VALUES(9,7);
INSERT INTO DATAUSES VALUES(9,10);
INSERT INTO DATAUSES VALUES(9,12);
INSERT INTO DATAUSES VALUES(9,13);
INSERT INTO DATAUSES VALUES(9,14);


INSERT INTO REQUEST VALUES(1,1,300000,500000,'세 장 이내로 작성해주세요');
INSERT INTO REQUEST VALUES(1,2,200000,200000,'대화 내용을 모두 넣어주세요');
INSERT INTO REQUEST VALUES(1,3,100000,150000,'한 장 이내로 작성해주세요');
INSERT INTO REQUEST VALUES(2,5,200000,300000,'전공 지식 없이도 이해할 수 있게 적어주세요');
INSERT INTO REQUEST VALUES(2,10,150000,600000,'시각화한 자료가 필요해요');
INSERT INTO REQUEST VALUES(2,12,60000,300000,'개념에 대해 심도있게 설명해주세요');
INSERT INTO REQUEST VALUES(3,8,300000,350000,'국가 간의 관계를 재대로 알 수 있게 해주세요');
INSERT INTO REQUEST VALUES(3,9,100000,150000,'요구사항');
INSERT INTO REQUEST VALUES(4,4,350000,550000,'요구사항');
INSERT INTO REQUEST VALUES(4,6,100000,150000,'요구사항');
INSERT INTO REQUEST VALUES(4,7,100000,150000,'요구사항');
INSERT INTO REQUEST VALUES(5,11,100000,350000,'요구사항');
INSERT INTO REQUEST VALUES(5,13,100000,450000,'요구사항');
INSERT INTO REQUEST VALUES(5,14,100000,750000,'요구사항');
INSERT INTO REQUEST VALUES(5,15,100000,550000,'요구사항');
INSERT INTO REQUEST VALUES(6,12,100000,150000,'요구사항');

INSERT INTO OFFER VALUES(1,1,'공학','보고서1');
INSERT INTO OFFER VALUES(1,2,'과학','보고서2');
INSERT INTO OFFER VALUES(1,3,'대화','보고서3');
INSERT INTO OFFER VALUES(2,5,'수학','보고서4');
INSERT INTO OFFER VALUES(2,10,'강연','보고서5');
INSERT INTO OFFER VALUES(2,15,'공학','보고서6');
INSERT INTO OFFER VALUES(3,8,'의학','보고서7');
INSERT INTO OFFER VALUES(3,9,'대화','보고서8');
INSERT INTO OFFER VALUES(4,4,'수학','보고서9');
INSERT INTO OFFER VALUES(4,6,'사학','보고서10');
INSERT INTO OFFER VALUES(4,7,'공학','보고서11');
INSERT INTO OFFER VALUES(5,11,'대화','보고서12');
INSERT INTO OFFER VALUES(5,13,'의학','보고서13');
INSERT INTO OFFER VALUES(5,14,'강연','보고서14');
INSERT INTO OFFER VALUES(5,15,'공학','보고서15');
INSERT INTO OFFER VALUES(6,12,'공학','보고서16');

