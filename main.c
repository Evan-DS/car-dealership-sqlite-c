
#include <stdio.h>
#include <sqlite3.h>

static int callback(void* _, int argc, char** argv, char** col){
    for(int i = 0; i < argc; i++){
        printf("%s=%s ", col[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int exec_sql(sqlite3* db, const char* sql){
    char* err = 0;
    int rc = sqlite3_exec(db, sql, callback, 0, &err);
    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", err);
        sqlite3_free(err);
        return 0;
    }
    return 1;
}

int main(){
    sqlite3* db;

    if(sqlite3_open("car.db", &db)){
        fprintf(stderr, "Failed to open database\n");
        return 1;
    }

    exec_sql(db,
        "CREATE TABLE IF NOT EXISTS Customer ("
        "Id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "Name TEXT NOT NULL,"
        "Gender TEXT NOT NULL);"
    );

    exec_sql(db, "INSERT INTO Customer (Name, Gender) VALUES ('Alice', 'F');");
    exec_sql(db, "INSERT INTO Customer (Name, Gender) VALUES ('Bob', 'M');");

    printf("Customers in database:\n");
    exec_sql(db, "SELECT * FROM Customer;");

    sqlite3_close(db);
    return 0;
}
