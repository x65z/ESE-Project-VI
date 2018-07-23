#ifndef DB_FUNCTIONS

#define DB_FUNCTIONS
int db_getFloorNum();
int db_getRequested();
int db_setFloorNum(int floorNum);
int db_setCurrent(int floorNum);
int db_setRequested(int floorNum);
int db_updateLogger(int NodeID, int message);


#endif
