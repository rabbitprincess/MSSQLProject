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
	PRIMARY KEY(LAN1,LAN2) --���� Ű
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

INSERT INTO DATAMINER VALUES(1,'E.KIM','010-2358-7593','����,����',1);
INSERT INTO DATAMINER VALUES(2,'S.LEE','010-2478-7343','��ȭ,���̳�,����',1);
INSERT INTO DATAMINER VALUES(3,'B.PARK','010-2345-1345','����,����',1);
INSERT INTO DATAMINER VALUES(4,'H.ENDY','010-2456-1345','��ȭ,����',2);
INSERT INTO DATAMINER VALUES(5,'H.ENDY','010-2456-1345','��ȭ,����',2);
INSERT INTO DATAMINER VALUES(6,'R.CHOI','010-5565-5693','����,����',3);
INSERT INTO DATAMINER VALUES(7,'G.RYU','010-9334-7455','����,��ȭ',3);
INSERT INTO DATAMINER VALUES(8,'S.LEE','010-9668-4593','��ȭ,����',4);
INSERT INTO DATAMINER VALUES(9,'V.PARK','010-1948-3593','����,��ȭ',4);
INSERT INTO DATAMINER VALUES(10,'B.ENDY','010-7555-7526','����,����',4);
INSERT INTO DATAMINER VALUES(11,'S.CHOI','010-5858-3568','����,��ȭ',4);
INSERT INTO DATAMINER VALUES(12,'Y.KIM','010-1238-9865','����,����',5);
INSERT INTO DATAMINER VALUES(13,'T.LEE','010-2954-9595','����,����',5);
INSERT INTO DATAMINER VALUES(14,'R.JUNG','010-9842-7245','���̳�,����',5);
INSERT INTO DATAMINER VALUES(15,'H.ENDY','010-6858-4673','��ȭ,����',6);

INSERT INTO LANGUAGEDATA VALUES(1,'���ڴ� �Ź�ó��... ���̰� ��ȭ�ϸ� �Ź̰� �ȴ�! ���̷������þ�ü Ź���� ���̽�','3,4,0,0,0,0,0,0,0,0,1,3,4,5,10,0,0,0,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','���̷�','https://blog.naver.com/BlogHome.nhn',1,1)
INSERT INTO LANGUAGEDATA VALUES(2,'�ް��ڽ����� ���� �� ���� �ѵ�, ��. �ް��ڽ��� �׶� ������̱� �׷���, ','3,4,0,0,0,4,6,0,0,0,1,3,4,5,10,0,0,0,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',2,1)
INSERT INTO LANGUAGEDATA VALUES(3,'�� ����, ���� �� �� �� ����. ��, �׷��� ���࿡','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',2,1)
INSERT INTO LANGUAGEDATA VALUES(4,' �޴� �� �̽ʴ� �߹� �����ݾ�. �¾�. ���̰�, ���� ģ�� ����','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',3,1)
INSERT INTO LANGUAGEDATA VALUES(5,' ������ ���ڽ��ϴ�. �̷��ϱ� �����Ե��� ��Ȳ�� ������, �� �׷� ������ �ϰ�','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',4,2)
INSERT INTO LANGUAGEDATA VALUES(6,' ����, ���̶�� �� ���ڷ� �ν����� �ʰ�, ���ϰ���, �������Ϸ� �ν��ϴ� �̴ϴ�.','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','���','https://blog.naver.com/BlogHome.nhn',4,3)
INSERT INTO LANGUAGEDATA VALUES(7,' �̻��ϴ�. �ʹ� �����ϰ� �������� ��. �� �� �ž�. ���� ����','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',4,3)
INSERT INTO LANGUAGEDATA VALUES(8,' �ϴٰ�, �� ���� �� �繫���� ���� �Ͽ� ���Ͽ� ����� �ϰŵ��,','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',5,3)
INSERT INTO LANGUAGEDATA VALUES(9,'�̺�Ʈ ����','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',5,3)
INSERT INTO LANGUAGEDATA VALUES(10,'�ѻ���Ʈ�������� �׳�,���Ⱦ������? žŬ�����̸��Ǳ׳�ͼҰ����ѹ��ؿ�~','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','����','https://blog.naver.com/BlogHome.nhn',6,4)
INSERT INTO LANGUAGEDATA VALUES(11,'#�������弥�ĺ�//ī��VF69//O7O_7575_OO51�������Ⱦ�ü��#��������ư����ı������24������','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','����','https://blog.naver.com/BlogHome.nhn',7,4)
INSERT INTO LANGUAGEDATA VALUES(12,'�� ������, �ϰ��ϰ� ��������. �̰� ���ϴ�. ���� ���⼭ ���̴� ��','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',8,4)
INSERT INTO LANGUAGEDATA VALUES(13,'���� �����̶� ��, ���� �� ��� ����, �ϴ� �Ű� ������','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',8,4)
INSERT INTO LANGUAGEDATA VALUES(14,'����� ��� �Ѹ��� �ž�? �̷��� �� ��, ���� ������. ����','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',8,4)
INSERT INTO LANGUAGEDATA VALUES(15,'�Ǵµ�. �ҸӴ� �˱�� �� ������, �긦 ���������� �ϴµ�. ��. ����','3,4,0,0,0,0,3,0,4,6,1,3,4,5,10,0,0,3,0,0,0,1,0,0,0,0,0,3,4,0,0,0,0,0,0,0,0,0,0','��ȭ','https://blog.naver.com/BlogHome.nhn',10,4)

INSERT INTO DATAANALIST VALUES(1,'E.KIM','010-2345-1345','����,����')
INSERT INTO DATAANALIST VALUES(2,'Q.RYU','010-2345-1345','����,����');
INSERT INTO DATAANALIST VALUES(3,'G.JUNG','010-2345-1345','���̳�,����');
INSERT INTO DATAANALIST VALUES(4,'R.KIM','010-2345-1345','��ȭ,���̳�');
INSERT INTO DATAANALIST VALUES(5,'Y.LEE','010-2345-1343','����,����');
INSERT INTO DATAANALIST VALUES(6,'E.JUNG','010-2345-1333','����,����');
INSERT INTO DATAANALIST VALUES(7,'G.JUNG','010-2345-1345','����,����');
INSERT INTO DATAANALIST VALUES(8,'R.KIM','010-2345-1345','����,����');
INSERT INTO DATAANALIST VALUES(9,'Y.LEE','010-2345-1343','��ȭ,���,����');
INSERT INTO DATAANALIST VALUES(10,'E.JUNG','010-2345-1333','����,����');
INSERT INTO DATAANALIST VALUES(11,'B.KIM','010-2345-1365','����,����');
INSERT INTO DATAANALIST VALUES(12,'T.CHOI','010-2345-1345','����,����');
INSERT INTO DATAANALIST VALUES(13,'Y.PARK','010-2345-1345','����,����');
INSERT INTO DATAANALIST VALUES(14,'G.RYU','010-2345-1345','����,����');
INSERT INTO DATAANALIST VALUES(15,'B.JUNT','010-2345-1345','����,����');

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
-- ����

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


INSERT INTO REQUEST VALUES(1,1,300000,500000,'�� �� �̳��� �ۼ����ּ���');
INSERT INTO REQUEST VALUES(1,2,200000,200000,'��ȭ ������ ��� �־��ּ���');
INSERT INTO REQUEST VALUES(1,3,100000,150000,'�� �� �̳��� �ۼ����ּ���');
INSERT INTO REQUEST VALUES(2,5,200000,300000,'���� ���� ���̵� ������ �� �ְ� �����ּ���');
INSERT INTO REQUEST VALUES(2,10,150000,600000,'�ð�ȭ�� �ڷᰡ �ʿ��ؿ�');
INSERT INTO REQUEST VALUES(2,12,60000,300000,'���信 ���� �ɵ��ְ� �������ּ���');
INSERT INTO REQUEST VALUES(3,8,300000,350000,'���� ���� ���踦 ���� �� �� �ְ� ���ּ���');
INSERT INTO REQUEST VALUES(3,9,100000,150000,'�䱸����');
INSERT INTO REQUEST VALUES(4,4,350000,550000,'�䱸����');
INSERT INTO REQUEST VALUES(4,6,100000,150000,'�䱸����');
INSERT INTO REQUEST VALUES(4,7,100000,150000,'�䱸����');
INSERT INTO REQUEST VALUES(5,11,100000,350000,'�䱸����');
INSERT INTO REQUEST VALUES(5,13,100000,450000,'�䱸����');
INSERT INTO REQUEST VALUES(5,14,100000,750000,'�䱸����');
INSERT INTO REQUEST VALUES(5,15,100000,550000,'�䱸����');
INSERT INTO REQUEST VALUES(6,12,100000,150000,'�䱸����');

INSERT INTO OFFER VALUES(1,1,'����','������1');
INSERT INTO OFFER VALUES(1,2,'����','������2');
INSERT INTO OFFER VALUES(1,3,'��ȭ','������3');
INSERT INTO OFFER VALUES(2,5,'����','������4');
INSERT INTO OFFER VALUES(2,10,'����','������5');
INSERT INTO OFFER VALUES(2,15,'����','������6');
INSERT INTO OFFER VALUES(3,8,'����','������7');
INSERT INTO OFFER VALUES(3,9,'��ȭ','������8');
INSERT INTO OFFER VALUES(4,4,'����','������9');
INSERT INTO OFFER VALUES(4,6,'����','������10');
INSERT INTO OFFER VALUES(4,7,'����','������11');
INSERT INTO OFFER VALUES(5,11,'��ȭ','������12');
INSERT INTO OFFER VALUES(5,13,'����','������13');
INSERT INTO OFFER VALUES(5,14,'����','������14');
INSERT INTO OFFER VALUES(5,15,'����','������15');
INSERT INTO OFFER VALUES(6,12,'����','������16');
