#include <crails/odb/connection.hpp>

const char* drop_page_query =
  "DROP TABLE IF EXISTS \"private-page_PrivatePage\" CASCADE;";
const char* create_page_query = 
  "CREATE TABLE \"private-page_PrivatePage\" ("
    "\"id\" BIGSERIAL NOT NULL PRIMARY KEY,"
    "\"deleted\" BOOLEAN NOT NULL DEFAULT FALSE,"
    "\"created_at\" BIGINT NULL,"
    "\"updated_at\" BIGINT NULL,"
    "\"title\" TEXT NOT NULL,"
    "\"slug\" TEXT NOT NULL,"
    "\"body\" TEXT NOT NULL,"
    "\"description\" TEXT NOT NULL,"
    "\"thumbnail\" TEXT NOT NULL,"
    "\"preview\" BOOLEAN NOT NULL,"
    "\"layout_name\" TEXT NOT NULL,"
    "\"has_footer\" BOOLEAN NOT NULL,"
    "\"permissions\" BIGINT NULL);";
const char* alter_page_query =
  "ALTER TABLE \"private-page_PrivatePage\""
    "ADD CONSTRAINT \"permissions_fk\""
      "FOREIGN KEY (\"permissions\")"
      "REFERENCES \"private-page_PermissionRule\" (\"id\")"
      "INITIALLY DEFERRED;";

void install_plugin_database()
{
  Crails::Odb::Connection database;

  database.transaction.require("odb");
  database.transaction.get_database().execute(create_page_query);
  database.transaction.get_database().execute(alter_page_query);
  database.commit();
}

void uninstall_plugin_database()
{
  Crails::Odb::Connection database;

  database.transaction.require("odb");
  database.transaction.get_database().execute(drop_page_query);
  database.commit();
}
