#pragma once
#include <crails/cms/controllers/admin/page.hpp>
#include "app/controllers/admin/application.hpp"
#include "app/models/private_page_traits.hpp"

class AdminPrivatePageController : public Crails::Cms::AdminPageController<PrivatePageTraits, AdminApplicationController>
{
  typedef Crails::Cms::AdminPageController<PrivatePageTraits, AdminApplicationController> Super;
public:
  static constexpr const char* scope = "userspace/pages";

  AdminPrivatePageController(Crails::Context& context);

private:
  void render_editor(PrivatePage& model) override;
  void require_groups(PrivatePage& model);
  bool edit_resource(PrivatePage& model, Data data) override;

  std::map<Crails::Odb::id_type, std::string> group_options;
};

