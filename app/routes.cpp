#include <crails/router.hpp>
#include <crails/cms/routes.hpp>
#include <crails/cms/views/admin_menu.hpp>
#include "lib/plugin-odb.hxx"
#include "app/controllers/admin/private_page.hpp"
#include "app/controllers/private_page.hpp"

void initialize_plugin_routes()
{
  auto& router = Crails::Router::singleton::require();
  auto& cms_routes = Crails::Cms::Routes::singleton::require();
  auto& admin_menu = Crails::Cms::AdminMenu::singleton::require();

  router.scope("/private/pages", [&]()
  {
    cms_routes.register_page_routes<PrivatePageController>(router);
  });
  
  router.scope(AdminApplicationController::scope, [&]()
  {
    router.scope(AdminPrivatePageController::scope, [&]()
    {
      admin_menu.add({3, "private-pages", router.get_current_scope()});
      cms_routes.register_page_admin_routes<PrivatePageController, AdminPrivatePageController>(router);
    });
  });
}
