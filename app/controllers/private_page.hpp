#pragma once
#include <crails/cms/controllers/page.hpp>
#include <crails/cms/models/page.hpp>
#include "app/controllers/userspace.hpp"
#include "../models/private_page_traits.hpp"

class PrivatePageController : public Crails::Cms::PageController<PrivatePageTraits, UserspaceBaseController>
{
  typedef Crails::Cms::PageController<PrivatePageTraits, UserspaceBaseController> Super;
public:
  PrivatePageController(Crails::Context&);

  void initialize();

private:
  void render_page(const PrivatePage&);
};
