// Includes required (headers located in /usr/include)
#include "../include/databaseFunctions.h"
#include <stdlib.h>
#include <iostream>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

int db_clear() {

  sql::Driver *driver; 				// Create a pointer to a MySQL driver object
	sql::Connection *con; 				// Create a pointer to a database connection object
	sql::PreparedStatement *pstmt; 		// Create a pointer to a prepared statement

	// Create a connection
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "ESE", "ese");
	con->setSchema("project");

	// Update database
	// *****************************
	pstmt = con->prepareStatement("DELETE FROM debugLog");
	pstmt->executeUpdate();

	// Clean up pointers
	delete pstmt;
	delete con;

  return(0);


}




int db_getFloorNum() {
	sql::Driver *driver; 			// Create a pointer to a MySQL driver object
	sql::Connection *con; 			// Create a pointer to a database connection object
	sql::Statement *stmt;			// Crealte a pointer to a Statement object to hold statements
	sql::ResultSet *res;			// Create a pointer to a ResultSet object to hold results
	int floorNum;					// Floor number

	// Create a connection
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "ESE", "ese");
	con->setSchema("joinExample");

	// Query database
	// *****************************
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT currentFloor FROM currentStatus WHERE id = 1");	// message query
	while(res->next()){
		floorNum = res->getInt("currentFloor");
	}

	// Clean up pointers
	delete res;
	delete stmt;
	delete con;

	return floorNum;
}



int db_getRequested() {
	sql::Driver *driver; 			// Create a pointer to a MySQL driver object
	sql::Connection *con; 			// Create a pointer to a database connection object
	sql::Statement *stmt;			// Crealte a pointer to a Statement object to hold statements
	sql::ResultSet *res;			// Create a pointer to a ResultSet object to hold results
	int floorNum;					// Floor number

	// Create a connection
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "ESE", "ese");
	con->setSchema("project");

	// Query database
	// *****************************
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT requestedFloor FROM status WHERE id = 1");	// message query
	while(res->next()){
		floorNum = res->getInt("requestedFloor");
	}

	// Clean up pointers
	delete res;
	delete stmt;
	delete con;

	return floorNum;
}


int db_setFloorNum(int floorNum) {
	sql::Driver *driver; 				// Create a pointer to a MySQL driver object
	sql::Connection *con; 				// Create a pointer to a database connection object
	sql::Statement *stmt;				// Crealte a pointer to a Statement object to hold statements
	sql::ResultSet *res;				// Create a pointer to a ResultSet object to hold results
	sql::PreparedStatement *pstmt; 		// Create a pointer to a prepared statement

	// Create a connection
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "ESE", "ese");
	con->setSchema("joinExample");

	// Query database (possibly not necessary)
	// *****************************
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT currentFloor FROM currentStatus WHERE id = 1");	// message query
	while(res->next()){
		res->getInt("currentFloor");
	}

	// Update database
	// *****************************
	pstmt = con->prepareStatement("UPDATE currentStatus SET currentFloor = ? WHERE id = 1");
	pstmt->setInt(1, floorNum);
	pstmt->executeUpdate();

	// Clean up pointers
	delete res;
	delete pstmt;
	delete stmt;
	delete con;

  return(0);
}




int db_setCurrent(int floorNum) {
	sql::Driver *driver; 				// Create a pointer to a MySQL driver object
	sql::Connection *con; 				// Create a pointer to a database connection object
	sql::Statement *stmt;				// Crealte a pointer to a Statement object to hold statements
	sql::ResultSet *res;				// Create a pointer to a ResultSet object to hold results
	sql::PreparedStatement *pstmt; 		// Create a pointer to a prepared statement

	// Create a connection
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "ESE", "ese");
	con->setSchema("project");

	// Query database (possibly not necessary)
	// *****************************
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT currentFloor FROM status WHERE id = 1");	// message query
	while(res->next()){
		res->getInt("currentFloor");
	}

	// Update database
	// *****************************
	pstmt = con->prepareStatement("UPDATE status SET currentFloor = ? WHERE id = 1");
	pstmt->setInt(1, floorNum);
	pstmt->executeUpdate();

  //executeQuery("SELECT * FROM status");

//  sleep(10);

	// Clean up pointers
	delete res;
	delete pstmt;
	delete stmt;
	delete con;

  return(0);
}



int db_setRequested(int floorNum) {
	sql::Driver *driver; 				// Create a pointer to a MySQL driver object
	sql::Connection *con; 				// Create a pointer to a database connection object
	sql::Statement *stmt;				// Crealte a pointer to a Statement object to hold statements
	sql::ResultSet *res;				// Create a pointer to a ResultSet object to hold results
	sql::PreparedStatement *pstmt; 		// Create a pointer to a prepared statement

	// Create a connection
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "ESE", "ese");
	con->setSchema("project");

	// Query database (possibly not necessary)
	// *****************************
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT requestedFloor FROM status WHERE id = 1");	// message query
	while(res->next()){
		res->getInt("requestedFloor");
	}

	// Update database
	// *****************************
	pstmt = con->prepareStatement("UPDATE status SET requestedFloor = ? WHERE id = 1");
	pstmt->setInt(1, floorNum);
	pstmt->executeUpdate();


  //executeQuery("SELECT * FROM status");

  //sleep(10);

	// Clean up pointers
	delete res;
	delete pstmt;
	delete stmt;
	delete con;

  return(0);
}


int db_updateLogger(int NodeID, int Message) {
	sql::Driver *driver; 				// Create a pointer to a MySQL driver object
	sql::Connection *con; 				// Create a pointer to a database connection object
//	sql::Statement *stmt;				// Crealte a pointer to a Statement object to hold statements
//	sql::ResultSet *res;				// Create a pointer to a ResultSet object to hold results
	sql::PreparedStatement *pstmt; 		// Create a pointer to a prepared statement

	// Create a connection
	driver = get_driver_instance();
	con = driver->connect("tcp://127.0.0.1:3306", "ESE", "ese");
	con->setSchema("project");

	// Query database (possibly not necessary)
	// *****************************
  /*
	stmt = con->createStatement();
	res = stmt->executeQuery("SELECT currentFloor FROM currentStatus WHERE id = 1");	// message query
	while(res->next()){
		res->getInt("currentFloor");
	}
  */
	// Update database
	// *****************************

  switch (NodeID)
  {
    case 101:
      switch (Message)
      {
        case 0:
          pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x101','Elevator Controller','is moving')");
	        pstmt->executeQuery();
          break;

        case 1:
          pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x101','Elevator Controller','is at floor 1')");
          pstmt->executeQuery();
          break;

        case 2:
          pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x101','Elevator Controller','is at floor 2')");
          pstmt->executeQuery();
          break;

        case 3:
          pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x101','Elevator Controller','is at floor 3')");
          pstmt->executeQuery();
          break;

        default:
          pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x101','Elevator Controller','Message Error')");
          pstmt->executeQuery();
          break;
      }
      break;

    case 200:
      switch (Message)
      {
        case 0:
          pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x200','Elevator Car','Requests stop')");
          pstmt->executeQuery();
          break;

        case 1:
          pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x200','Elevator Car','Requests floor 1')");
          pstmt->executeQuery();
          break;

        case 2:
          pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x200','Elevator Car','Requests floor 2')");
          pstmt->executeQuery();
          break;

        case 3:
          pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x200','Elevator Car','Requests floor 3')");
          pstmt->executeQuery();
          break;

        default:
          pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x200','Elevator Controller','Message Error')");
          pstmt->executeQuery();
          break;
    }
    break;

    case 201:
      pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x201','Floor 1','Requests floor 1')");
      pstmt->executeQuery();
      break;

    case 202:
      pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x202','Floor 2','Requests floor 2')");
      pstmt->executeQuery();
      break;

    case 203:
      pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'0x203','Floor 3','Requests floor 3')");
      pstmt->executeQuery();
      break;

    default:
      pstmt = con->prepareStatement("INSERT INTO debugLog(timestamp, nodeID, node, message) VALUES (NOW(),'Error - Invalid ID','Error - Invalid ID','Unknown')");
      pstmt->executeQuery();
      break;
  }

	// Clean up pointers
	delete pstmt;
	delete con;


  return(0);
}
