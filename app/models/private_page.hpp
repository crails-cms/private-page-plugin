#pragma once
#include <crails/cms/models/page.hpp>
#include "app/models/permission_rule.hpp"

#pragma db object
class PrivatePage : public Crails::Cms::Page
{
  odb_instantiable()
public:
  #pragma db view object(PrivatePage)
  struct Count
  {
    #pragma db column("count(" + PrivatePage::id + ")")
    size_t value;
  };

  void set_permissions_from_data(Data);
  std::shared_ptr<PermissionRule> get_permissions() const { return permissions; }

private:
  std::shared_ptr<PermissionRule> permissions;
};
