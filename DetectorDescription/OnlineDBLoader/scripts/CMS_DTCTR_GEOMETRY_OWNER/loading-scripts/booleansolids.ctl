LOAD DATA
INFILE './data/BOOLEANSOLIDS.dat'
BADFILE './data/BOOLEANSOLIDS.bad'
DISCARDFILE './data/BOOLEANSOLIDS.dsc'
INSERT INTO TABLE CMSINTEGRATION.BOOLEANSOLIDS
FIELDS TERMINATED by ","
(
 SOL_NAME CHAR,
 OPERATION CHAR,
 LEFTSOLID_NAME CHAR,
 RIGHTSOLID_NAME CHAR,
 X INTEGER EXTERNAL,
 Y INTEGER EXTERNAL,
 Z INTEGER EXTERNAL,
 ROT_NAME CHAR
 )
 
