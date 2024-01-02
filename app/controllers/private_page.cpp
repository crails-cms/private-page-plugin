#include "private_page.hpp"
#include "lib/plugin-odb.hxx"
  
PrivatePageController::PrivatePageController(Crails::Context& context) : Super(context)
{
}

void PrivatePageController::initialize()
{
  if (Super::get_current_user() == nullptr)
    Super::redirect_to_userspace_home();
}

void PrivatePageController::render_page(const PrivatePage& model)
{
  auto user = Super::get_current_user();
  auto permissions = model.get_permissions();

  if (permissions && permissions->can_read(*user))
    Super::render_page(model);
  else
    Super::redirect_to_userspace_home();
}
