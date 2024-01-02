#include "lib/plugin-odb.hxx"
#include "private_page.hpp"
  
AdminPrivatePageController::AdminPrivatePageController(Crails::Context& context) : Super(context)
{
  vars["local_route"] = std::string(Super::scope) + '/' + scope;
  vars["extra_partial"] = "admin/private_pages/_permission_rules";
}

void AdminPrivatePageController::render_editor(PrivatePage& model)
{
  require_groups(model);
  Super::render_editor(model);
}

void AdminPrivatePageController::require_groups(PrivatePage& model)
{
  odb::result<UserGroup> models;
  std::vector<Crails::Odb::id_type> read, write, destroy;
  auto permissions = model.get_permissions();

  Super::database.find<UserGroup>(models);
  for (const auto& group : models)
  {
    group_options.emplace(group.get_id(), group.get_name());
    if (permissions && (group.get_flag() & permissions->get_read_flag()))
      read.push_back(group.get_id());
  }
  Super::vars["group_options"] = &group_options;
  Super::vars["read_groups"] = read;
}

bool AdminPrivatePageController::edit_resource(PrivatePage& model, Data data)
{
  if (Super::edit_resource(model, data))
  {
    model.set_permissions_from_data(params["permission_rules"]);
    return true;
  }
  return false;
}
