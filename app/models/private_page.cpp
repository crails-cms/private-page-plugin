#include <crails/odb/any.hpp>
#include <crails/odb/to_vector.hpp>
#include "private_page.hpp"
#include "lib/plugin-odb.hxx"

using namespace Crails;

odb_instantiable_impl(PrivatePage)

void PrivatePage::set_permissions_from_data(Data data)
{
  Crails::Odb::Connection database;

  if (!permissions)
    permissions = std::make_shared<PermissionRule>();
  permissions->edit(data);
  database.save(*permissions);
  database.rollback_on_destruction = false;
}

